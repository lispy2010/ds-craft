#include <nds.h>
#include <nds/arm9/console.h>
#include <nds/arm9/input.h>
#include <nds/arm9/keyboard.h>
#include <gl2d.h>
#include <maxmod9.h>
#include <fat.h>
#include <images.h>
#include <fs.h>
#include <uvcoord_font_16x16.h>
#include <uvcoord_font_si.h>
#include <soundbank.h>
#include <soundbank_bin.h>
#include <camera.h>
#include <time.h>
#include <stdio.h>
#include <block.hpp>
#include <player.hpp>
#include <font.hpp>
#include <gamestate.hpp>
#include <terrain.hpp>
#include <entity.hpp>
#include <algorithm>
#include <sstream>

extern glImage sprDirt[1]; // from block.cpp

extern mm_sound_effect sndClick; // from player.cpp

BlockList blocks;
EntityList entities;
Player player;

typedef struct world_info
{
    std::string name;
    int size; // in bytes
} WorldInfo;

void drawMovingBackground(glImage dirt[1], u8 frames)
{
    glColor(RGB15(15, 15, 15));
    for (u8 i = 0; i < SCREEN_WIDTH / 32 + 2; ++i)
    {
        for (u8 j = 0; j < SCREEN_HEIGHT / 32 + 1; ++j)
        {
            glSpriteScale(i * 32 - frames % 64, j * 32, (1 << 12) * 2, GL_FLIP_NONE, dirt);
        }
    }
    glColor(RGB15(31, 31, 31));
}

std::vector<WorldInfo> getWorlds(void)
{
    DIR *dp;
    dp = opendir("worlds");
    struct dirent *ep;
    std::string dls; // directory list string
    while ((ep = readdir(dp)) != NULL)
    {
        dls += std::string(ep->d_name) + "\n";
    }
    (void)closedir(dp);

    std::vector<WorldInfo> worlds;
    std::stringstream ss(dls);
    std::string line;
    while (std::getline(ss, line))
    {
        if (line == "." || line == "..")
        {
            continue;
        }

        // world name = world file name wothout extension
        size_t li = line.find_last_of(".");
        int size = fsGetFileSize(line.c_str());
        std::string noext = line.substr(0, li);
        worlds.push_back({noext.c_str(), size});
    }

    return worlds;
}

void saveWorld(const std::string &name)
{
    if (!fsFileExists(std::string("worlds/" + name + ".wld").c_str()))
    {
        blocks = generateTerrain();
    }

    fsCreateFile(std::string("worlds/" + name + ".wld").c_str());
    std::string wld;
    
    wld += "player " + std::to_string(player.getX()) + " " + std::to_string(player.getY()) + "\n";
    std::array<InventoryItem, 20> playerInventory = player.getInventory();
    for (u8 i = 0; i < 20; ++i)
    {
        std::string id;
        // i hate switch statements
        switch (playerInventory[i].id)
        {
        case InventoryItemID::None:
            id = "none";
            break;
        case InventoryItemID::Grass:
            id = "grass";
            break;
        case InventoryItemID::Dirt:
            id = "dirt";
            break;
        case InventoryItemID::Stone:
            id = "stone";
            break;
        case InventoryItemID::Wood:
            id = "wood";
            break;
        case InventoryItemID::Leaves:
            id = "leaves";
            break;
        case InventoryItemID::Sand:
            id = "sand";
            break;
        case InventoryItemID::Sandstone:
            id = "sandstone";
            break;
        case InventoryItemID::Cactus:
            id = "cactus";
            break;
        case InventoryItemID::DeadBush:
            id = "deadbush";
            break;
        case InventoryItemID::Poppy:
            id = "poppy";
            break;
        case InventoryItemID::Dandelion:
            id = "dandelion";
            break;
        case InventoryItemID::Door:
            id = "door";
            break;
        case InventoryItemID::Planks:
            id = "planks";
            break;
        case InventoryItemID::Stick:
            id = "stick";
            break;
        case InventoryItemID::SnowyGrass:
            id = "snowygrass";
            break;
        case InventoryItemID::Sapling:
            id = "sapling";
            break;
        }

        wld += "inventory " + std::to_string(i) + " " + id + " " + std::to_string(playerInventory[i].amount) + "\n";
    }
    for (auto &block : blocks)
    {
        std::string id = block->id();

        if (block->id() == "door")
        {
            Block *b = block.get();
            DoorBlock *door = reinterpret_cast<DoorBlock *>(b);
            wld += "door " + std::to_string(block->x) + " " + std::to_string(block->y) + " " + std::to_string(door->isOpen()) + " " + std::to_string(door->getFacing()) + "\n";
        }
        else
        {
            if (id == "snowy grass")
            {
                wld += "block " + std::to_string(block->x) + " " + std::to_string(block->y) + " snowygrass\n";
            }
            else if (id == "dead bush")
            {
                wld += "block " + std::to_string(block->x) + " " + std::to_string(block->y) + " deadbush\n";
            }
            else
            {
                wld += "block " + std::to_string(block->x) + " " + std::to_string(block->y) + " " + id + "\n";
            }
        }
    }

    fsWrite(std::string("worlds/" + name + ".wld").c_str(), wld.c_str());
}

void loadWorld(const std::string &name)
{
    if (!fsFileExists(std::string("worlds/" + name + ".wld").c_str()))
    {
        return;
    }

    std::string contents = std::string(fsReadFile(std::string("worlds/" + name + ".wld").c_str()));
    std::istringstream iss(contents);
    std::string line;
    while (std::getline(iss, line))
    {
        std::vector<std::string> split;
        std::stringstream ss(line);
        std::string line2;
        while (std::getline(ss, line2, ' '))
        {
            split.push_back(line2);
        }
        
        if (split[0] == "player")
        {
            player.setX(atoi(split[1].c_str()));
            player.setY(atoi(split[2].c_str()));
        }
        if (split[0] == "door")
        {
            s16 x = atoi(split[1].c_str());
            s16 y = atoi(split[2].c_str());
            bool open = split[3] == "1";
            bool facing = split[4] == "1";
            blocks.emplace_back(new DoorBlock(x, y, open, facing));
        }
        if (split[0] == "block")
        {
            s16 x = atoi(split[1].c_str());
            s16 y = atoi(split[2].c_str());
            std::string id = split[3];
            // oh boi
            if (id == "grass")
            {
                blocks.emplace_back(new GrassBlock(x, y));
            }
            else if (id == "dirt")
            {
                blocks.emplace_back(new DirtBlock(x, y));
            }
            else if (id == "stone")
            {
                blocks.emplace_back(new StoneBlock(x, y));
            }
            else if (id == "wood")
            {
                blocks.emplace_back(new WoodBlock(x, y));
            }
            else if (id == "leaves")
            {
                blocks.emplace_back(new LeavesBlock(x, y));
            }
            else if (id == "sand")
            {
                blocks.emplace_back(new SandBlock(x, y));
            }
            else if (id == "sandstone")
            {
                blocks.emplace_back(new SandstoneBlock(x, y));
            }
            else if (id == "cactus")
            {
                blocks.emplace_back(new CactusBlock(x, y));
            }
            else if (id == "deadbush")
            {
                blocks.emplace_back(new DeadBushBlock(x, y));
            }
            else if (id == "poppy")
            {
                blocks.emplace_back(new FlowerBlock(x, y, FlowerType::Poppy));
            }
            else if (id == "dandelion")
            {
                blocks.emplace_back(new FlowerBlock(x, y, FlowerType::Dandelion));
            }
            else if (id == "planks")
            {
                blocks.emplace_back(new PlanksBlock(x, y));
            }
            else if (id == "snowygrass")
            {
                blocks.emplace_back(new SnowyGrassBlock(x, y));
            }
            else if (id == "sapling")
            {
                blocks.emplace_back(new SaplingBlock(x, y));
            }
        }
        if (split[0] == "inventory")
        {
            u8 i = atoi(split[1].c_str());
            u8 amount = atoi(split[3].c_str());
            std::string sid = split[2];
            InventoryItemID id = InventoryItemID::None;
            // not again
            if (sid == "none")
            {
                id = InventoryItemID::None;
            }
            else if (sid == "grass")
            {
                id = InventoryItemID::Grass;
            }
            else if (sid == "dirt")
            {
                id = InventoryItemID::Dirt;
            }
            else if (sid == "stone")
            {
                id = InventoryItemID::Stone;
            }
            else if (sid == "wood")
            {
                id = InventoryItemID::Wood;
            }
            else if (sid == "leaves")
            {
                id = InventoryItemID::Leaves;
            }
            else if (sid == "sand")
            {
                id = InventoryItemID::Sand;
            }
            else if (sid == "sandstone")
            {
                id = InventoryItemID::Sandstone;
            }
            else if (sid == "cactus")
            {
                id = InventoryItemID::Cactus;
            }
            else if (sid == "deadbush")
            {
                id = InventoryItemID::DeadBush;
            }
            else if (sid == "poppy")
            {
                id = InventoryItemID::Poppy;
            }
            else if (sid == "dandelion")
            {
                id = InventoryItemID::Dandelion;
            }
            else if (sid == "door")
            {
                id = InventoryItemID::Door;
            }
            else if (sid == "planks")
            {
                id = InventoryItemID::Planks;
            }
            else if (sid == "stick")
            {
                id = InventoryItemID::Stick;
            }
            else if (sid == "snowygrass")
            {
                id = InventoryItemID::SnowyGrass;
            }
            else if (sid == "sapling")
            {
                id = InventoryItemID::Sapling;
            }
            
            player.setItem(i, {id, amount});
        }
    }
}

int main(int argc, char **argv)
{
    time_t curtime = time(NULL);
    srand(curtime);
    consoleDemoInit();
    keyboardDemoInit();
    keyboardHide();
    videoSetMode(MODE_5_3D);
    glScreen2D();
    fsInit();
    mmInitDefaultMem((mm_addr)soundbank_bin);
    fsCreateDir("worlds");

    vramSetBankA(VRAM_A_TEXTURE);
    vramSetBankB(VRAM_B_TEXTURE);
    vramSetBankF(VRAM_F_TEX_PALETTE);
    vramSetBankE(VRAM_E_TEX_PALETTE);
    loadBlockTextures();
    loadBlockSounds();
    loadPlayerGUI();
    loadPlayerSounds();

    glImage font16x16Img[FONT_16X16_NUM_IMAGES];
    glImage fontSmallImg[FONT_SI_NUM_IMAGES];
    Font font, fontSmall;
    font.load(font16x16Img, FONT_16X16_NUM_IMAGES, font_16x16_texcoords, GL_RGB256,
              TEXTURE_SIZE_64, TEXTURE_SIZE_512,
              GL_TEXTURE_WRAP_S | GL_TEXTURE_WRAP_T | TEXGEN_OFF | GL_TEXTURE_COLOR0_TRANSPARENT,
              256, font_16x16Pal, reinterpret_cast<const u8 *>(font_16x16Bitmap));
    fontSmall.load(fontSmallImg, FONT_SI_NUM_IMAGES, font_si_texcoords, GL_RGB256,
                   TEXTURE_SIZE_64, TEXTURE_SIZE_128,
                   GL_TEXTURE_WRAP_S | GL_TEXTURE_WRAP_T | TEXGEN_OFF | GL_TEXTURE_COLOR0_TRANSPARENT,
                   256, font_smallPal, reinterpret_cast<const u8 *>(font_smallBitmap));

    glImage logo[1];
    glImage abtn[1];
    glImage bbtn[1];
    glImage xbtn[1];
    glImage ybtn[1];
    glImage worldLabel[1];
    glImage grayCircle[1];
    glImage direntGames[1];
    loadImageAlpha(logo, 128, 32, logoPal, logoBitmap);
    loadImageAlpha(abtn, 16, 16, abtnPal, abtnBitmap);
    loadImageAlpha(bbtn, 16, 16, bbtnPal, bbtnBitmap);
    loadImageAlpha(xbtn, 16, 16, xbtnPal, xbtnBitmap);
    loadImageAlpha(ybtn, 16, 16, ybtnPal, ybtnBitmap);
    loadImageAlpha(worldLabel, 128, 32, world_labelPal, world_labelBitmap);
    loadImageAlpha(grayCircle, 16, 16, gray_circlePal, gray_circleBitmap);

    loadImage(direntGames, 64, 64, dirent_gamesBitmap);

    GameState gameState = 
#if SKIP_SPLASH_SCREEN
        GameState::Menu
#else
        GameState::SplashScreen
#endif
        ;
    Camera camera = {0, 0};
    u16 frames = 0;
    u8 saveTextTimer = 0;
    s16 direntx = SCREEN_WIDTH / 2 - 32;
    s16 direnty = -64;
    u8 direntColor = 31;
    u8 wsSelected = 0; // selected world
    std::vector<WorldInfo> wsWorlds; // worlds in world select
    bool saveTextShow = false;
    std::string worldName = "";
    std::string createWorldName = "";
    while (true)
    {
        scanKeys();
        u32 down = keysDown();
        // TODO rewrite into a switch
        if (gameState == GameState::Game)
        {
            if (frames % 900 == 0)
            {
                saveWorld(worldName);
                saveTextShow = true;
            }

            if (saveTextShow)
            {
                ++saveTextTimer;
                if (saveTextTimer == 120)
                {
                    saveTextShow = false;
                }
            }

            for (size_t i = 0; i < blocks.size(); ++i)
            {
                auto &block = blocks[i];
                if (block->getRect().x - camera.x < -16 ||
                    block->getRect().y - camera.y < -16)
                {
                    continue;
                }
                if (block->getRect().x - camera.x > SCREEN_WIDTH + 48)
                {
                    break;
                }
                if (block->id() == "sapling")
                {
                    Block *b = block.get();
                    SaplingBlock *sapling = (SaplingBlock *)b; // here i dont use reinterpret_cast
                                                               // because it makes the game break
                    sapling->update();
                    if (sapling->hasGrown())
                    {
                        s16 x = sapling->x;
                        s16 y = sapling->y;
                        blocks.erase(blocks.begin() + i);
                        blocks.emplace_back(new WoodBlock(x, y));
                        blocks.emplace_back(new WoodBlock(x, y - 16));
                        blocks.emplace_back(new WoodBlock(x, y - 32));
                        blocks.emplace_back(new LeavesBlock(x, y - 48));
                        blocks.emplace_back(new LeavesBlock(x - 16, y - 48));
                        blocks.emplace_back(new LeavesBlock(x - 32, y - 48));
                        blocks.emplace_back(new LeavesBlock(x + 16, y - 48));
                        blocks.emplace_back(new LeavesBlock(x + 32, y - 48));
                        blocks.emplace_back(new LeavesBlock(x, y - 64));
                        blocks.emplace_back(new LeavesBlock(x - 16, y - 64));
                        blocks.emplace_back(new LeavesBlock(x + 16, y - 64));
                        blocks.emplace_back(new LeavesBlock(x, y - 80));
                        blocks.emplace_back(new LeavesBlock(x - 16, y - 80));
                        blocks.emplace_back(new LeavesBlock(x + 16, y - 80));
                        std::sort(blocks.begin(), blocks.end(), BlockCompareKey());
                    }
                }
            }

            for (auto &entity : entities)
            {
                entity->update(blocks);
            }

            if (player.update(camera, &blocks, &frames))
            {
                std::sort(blocks.begin(), blocks.end(), BlockCompareKey());
            }

            camera.x = lerp(camera.x, player.getX() - SCREEN_WIDTH / 2, 0.1f);
            camera.y = lerp(camera.y, player.getY() - SCREEN_HEIGHT / 2, 0.1f);
        }
        else if (gameState == GameState::Menu)
        {
            if (down & KEY_A)
            {
                gameState = GameState::WorldSelect;
                wsWorlds = getWorlds();
                wsSelected = 0;
                mmEffectEx(&sndClick);
            }
            else if (down & KEY_B)
            {
                gameState = GameState::Credits;
                mmEffectEx(&sndClick);
            }
            ++frames;
        }
        else if (gameState == GameState::Credits)
        {
            if (down & KEY_B)
            {
                mmEffectEx(&sndClick);
                gameState = GameState::Menu;
            }
            ++frames;
        }
        else if (gameState == GameState::WorldSelect)
        {
            if (down & KEY_B)
            {
                mmEffectEx(&sndClick);
                gameState = GameState::Menu;
            }
            else if (down & KEY_X)
            {
                worldName = wsWorlds[wsSelected].name;
                loadWorld(worldName);
                mmEffectEx(&sndClick);
                gameState = GameState::Game;
            }
            else if (down & KEY_Y)
            {
                // TODO add a confirmation screen for delete
                wsSelected = 0;
                fsDeleteFile(std::string("worlds/" + wsWorlds[wsSelected].name + ".wld").c_str());
                wsWorlds = getWorlds();
                mmEffectEx(&sndClick);
            }
            else if (down & KEY_A)
            {
                gameState = GameState::CreateWorld;
                createWorldName = "";
                keyboardShow();
                mmEffectEx(&sndClick);
            }
            else if (down & KEY_DOWN)
            {
                if ((std::vector<WorldInfo>::size_type)(wsSelected + 1) < wsWorlds.size())
                {
                    ++wsSelected;
                }
            }
            else if (down & KEY_UP)
            {
                if (wsSelected - 1 >= 0)
                {
                    --wsSelected;
                }
            }
            ++frames;
        }
        else if (gameState == GameState::CreateWorld)
        {
            if (down & KEY_B)
            {
                keyboardHide();
                gameState = GameState::WorldSelect;
                mmEffectEx(&sndClick);
            }
            else if (down & KEY_A)
            {
                // trim the string
                createWorldName.erase(createWorldName.begin(), std::find_if(createWorldName.begin(),
                                      createWorldName.end(), [](unsigned char ch) {
                    return !std::isspace(ch);
                }));
                createWorldName.erase(std::find_if(createWorldName.rbegin(), createWorldName.rend(),
                                      [](unsigned char ch) {
                    return !std::isspace(ch);
                }).base(), createWorldName.end());

                keyboardHide();
                worldName = createWorldName.c_str();
                saveWorld(worldName);
                gameState = GameState::Game;
                frames = 0;
                mmEffectEx(&sndClick);
            }

            char ch = keyboardUpdate();
            if (ch > 0 && ch != 255)
            {
                if (ch == '\b')
                {
                    if (createWorldName.size() > 0)
                    {
                        createWorldName.pop_back();
                    }
                }
                else
                {
                    createWorldName += ch;
                }
            }

            ++frames;
        }
        else if (gameState == GameState::SplashScreen)
        {
            if (frames >= 70)
            {
                if (direntColor - 1 >= 0)
                {
                    --direntColor;
                }
            }
            if (frames == 135)
            {
                gameState = GameState::Menu;
            }

            direnty = lerp(direnty, SCREEN_HEIGHT / 2 - 32, 0.07f);
            ++frames;
        }

        //--------------------------------------------------
        glBegin2D();

        // TODO rewrite into a switch
        if (gameState == GameState::Game)
        {
            glBoxFilledGradient(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, RGB15(10, 17, 26), RGB15(15, 23, 31), RGB15(15, 23, 31), RGB15(10, 17, 26));

            for (auto &block : blocks)
            {
                if (block->getRect().x - camera.x < -16 ||
                    block->getRect().y - camera.y < -16)
                {
                    continue;
                }
                if (block->getRect().x - camera.x > SCREEN_WIDTH + 48)
                {
                    break;
                }

                block->draw(camera);
            }

            for (auto &entity : entities)
            {
                entity->draw(camera);
            }

            player.draw(camera, fontSmall, font);

            if (saveTextShow)
            {
                fontSmall.printfShadow(2, SCREEN_HEIGHT - 11, "Saved!");
            }

            glPolyFmt(POLY_ALPHA(15) | POLY_CULL_NONE | POLY_ID(4));
            fontSmall.printf(3, 3, "%s%d.%d", VERSION_PREFIX, VERSION_MAJOR, VERSION_MINOR);
            glPolyFmt(POLY_ALPHA(31) | POLY_CULL_NONE | POLY_ID(4));
        }
        else if (gameState == GameState::Menu)
        {
            glColor(RGB15(15, 15, 15));
            for (u8 i = 0; i < SCREEN_WIDTH / 32 + 2; ++i)
            {
                for (u8 j = 0; j < SCREEN_HEIGHT / 32 + 1; ++j)
                {
                    glSpriteScale(i * 32 - frames % 64, j * 32, (1 << 12) * 2, GL_FLIP_NONE, sprDirt);
                }
            }
            glColor(RGB15(31, 31, 31));

            glSpriteScale(SCREEN_WIDTH / 2 - 96, 16, (1 << 12) * 2, GL_FLIP_NONE, logo);

            glSprite(SCREEN_WIDTH / 2 - 30, 96, GL_FLIP_NONE, abtn);
            fontSmall.printCentered(0, 98, "Play");

            glSprite(SCREEN_WIDTH / 2 - 41, 116, GL_FLIP_NONE, bbtn);
            fontSmall.printCentered(0, 118, "Credits");
        }
        else if (gameState == GameState::Credits)
        {
            drawMovingBackground(sprDirt, frames);

            font.printCentered(0, 16, "Credits");
            
            fontSmall.printCentered(0, 70, "Textures by Mojang");
            fontSmall.printCentered(0, 120, "(C) 2022 dirent games");
            fontSmall.printCentered(0, 129, "Built with devkitARM");

            glSprite(2, SCREEN_HEIGHT - 17, GL_FLIP_NONE, bbtn);
            fontSmall.print(15, SCREEN_HEIGHT - 15, "Back");
        }
        else if (gameState == GameState::WorldSelect)
        {
            drawMovingBackground(sprDirt, frames);

            for (u8 i = 0; i < SCREEN_WIDTH / 32; ++i)
            {
                glSpriteScale(i * 32, 0, (1 << 12) * 2, GL_FLIP_NONE, sprDirt);
                glSpriteScale(i * 32, SCREEN_HEIGHT - 32, (1 << 12) * 2, GL_FLIP_NONE, sprDirt);
            }

            glSprite(2, SCREEN_HEIGHT - 30, GL_FLIP_NONE, bbtn);
            fontSmall.print(15, SCREEN_HEIGHT - 28, "Back");

            glSprite(2, SCREEN_HEIGHT - 17, GL_FLIP_NONE, abtn);
            fontSmall.print(15, SCREEN_HEIGHT - 15, "New world");

            glSprite(93, SCREEN_HEIGHT - 30, GL_FLIP_NONE, xbtn);
            fontSmall.print(106, SCREEN_HEIGHT - 28, "Play world");

            glSprite(93, SCREEN_HEIGHT - 17, GL_FLIP_NONE, ybtn);
            fontSmall.print(106, SCREEN_HEIGHT - 15, "Delete world");

            if (wsWorlds.size() == 0)
            {
                fontSmall.printCentered(0, 100, "No worlds yet...");
            }
            else
            {
                for (size_t i = 0; i < wsWorlds.size(); ++i)
                {
                    WorldInfo worldInfo = wsWorlds[i];
                    std::string str = worldInfo.name + " - " + std::string(fsHumanreadFileSize(worldInfo.size));
                    glSprite(SCREEN_WIDTH / 2 - 121, 48 + i * 40, GL_FLIP_NONE, worldLabel);
                    glSprite(SCREEN_WIDTH / 2 - 121 + 113, 48 + i * 40, GL_FLIP_H, worldLabel);
                    fontSmall.print(SCREEN_WIDTH / 2 - 121 + 7, 48 + i * 40 + 12, str.c_str());

                    if (i == wsSelected)
                    {
                        glSprite(SCREEN_WIDTH / 2 - 121 + 121 * 2 - 24, 48 + i * 40 + 32 / 2 - 8, GL_FLIP_NONE, grayCircle);
                    }
                }
            }

            font.printCentered(0, 5, "World select");
        }
        else if (gameState == GameState::CreateWorld)
        {
            drawMovingBackground(sprDirt, frames);
            for (u8 i = 0; i < SCREEN_WIDTH / 32; ++i)
            {
                glSpriteScale(i * 32, 0, (1 << 12) * 2, GL_FLIP_NONE, sprDirt);
                glSpriteScale(i * 32, SCREEN_HEIGHT - 32, (1 << 12) * 2, GL_FLIP_NONE, sprDirt);
            }

            glSprite(2, SCREEN_HEIGHT - 30, GL_FLIP_NONE, abtn);
            fontSmall.print(15, SCREEN_HEIGHT - 28, "Create");

            glSprite(2, SCREEN_HEIGHT - 17, GL_FLIP_NONE, bbtn);
            fontSmall.print(15, SCREEN_HEIGHT - 15, "Back");

            fontSmall.printCentered(0, 71, "World name:");
            fontSmall.printCentered(0, 80, std::string(createWorldName + "_").c_str());

            font.printCentered(0, 5, "Create world");
        }
        else if (gameState == GameState::SplashScreen)
        {
            glClearColor(0, 0, 0, 31);
            glColor(RGB15(direntColor, direntColor, direntColor));
            glSprite(direntx, direnty, GL_FLIP_NONE, direntGames);
            glColor(RGB15(31, 31, 31));
        }

        glEnd2D();
        glFlush(0);

        swiWaitForVBlank();
    }
}