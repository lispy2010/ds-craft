#include "block.hpp"
#include "game.hpp"

glImage sprGrass[1];
glImage sprSnowyGrass[1];
glImage sprDirt[1];
glImage sprStone[1];
glImage sprWood[1];
glImage sprBirchWood[1];
glImage sprSpruceWood[1];
glImage sprLeaves[1];
glImage sprBirchLeaves[1];
glImage sprSpruceLeaves[1];
glImage sprSand[1];
glImage sprSandstone[1];
glImage sprCactus[1];
glImage sprDeadBush[1];
glImage sprDandelion[1];
glImage sprPoppy[1];
glImage sprRedTulip[1];
glImage sprDoor[1];
glImage sprBirchDoor[1];
glImage sprSpruceDoor[1];
glImage sprPlanks[1];
glImage sprBirchPlanks[1];
glImage sprSprucePlanks[1];
glImage sprSapling[1];
glImage sprBirchSapling[1];
glImage sprSpruceSapling[1];
glImage sprBedrock[1];
glImage sprCobblestone[1];
glImage sprCoalOre[1];
glImage sprCoalBlock[1];
glImage sprGlass[1];
glImage sprOakTrapdoor[1];
glImage sprBirchTrapdoor[1];
glImage sprSpruceTrapdoor[1];
glImage sprLadder[1];
glImage sprChest[1];
glImage sprSign[1];
glImage sprIronOre[1];
glImage sprIronBlock[1];
glImage sprStoneBricks[1];

glImage sprBlockBreak[10][1];
glImage sprGrassOverlay[1];

declsfx4(DoorOpen);
declsfx4(DoorClose);

extern bool transparentLeaves;

void Block::loadTextures(void)
{
    loadImage(sprGrass, 16, 16, grassBitmap);
    loadImage(sprSnowyGrass, 16, 16, snowy_grassBitmap);
    loadImage(sprStone, 16, 16, stoneBitmap);
    loadImage(sprWood, 16, 16, oak_logBitmap);
    loadImage(sprBirchWood, 16, 16, birch_logBitmap);
    loadImage(sprSpruceWood, 16, 16, spruce_logBitmap);
    loadImage(sprSand, 16, 16, sandBitmap);
    loadImage(sprSandstone, 16, 16, sandstoneBitmap);
    loadImage(sprPlanks, 16, 16, planksBitmap);
    loadImage(sprBirchPlanks, 16, 16, birch_planksBitmap);
    loadImage(sprSprucePlanks, 16, 16, spruce_planksBitmap);
    loadImage(sprBedrock, 16, 16, bedrockBitmap);
    loadImage(sprCobblestone, 16, 16, cobblestoneBitmap);
    loadImage(sprCoalOre, 16, 16, coal_oreBitmap);
    loadImage(sprCoalBlock, 16, 16, coal_blockBitmap);
    loadImage(sprBirchTrapdoor, 16, 16, birch_trapdoorBitmap);
    loadImage(sprSpruceTrapdoor, 16, 16, spruce_trapdoorBitmap);
    loadImage(sprChest, 16, 16, chestBitmap);
    loadImage(sprIronOre, 16, 16, iron_oreBitmap);
    loadImage(sprIronBlock, 16, 16, iron_blockBitmap);
    loadImage(sprStoneBricks, 16, 16, stone_bricksBitmap);

    loadImageAlpha(sprCactus, 16, 16, cactus_sidePal, cactus_sideBitmap);
    loadImageAlpha(sprDeadBush, 16, 16, dead_bushPal, dead_bushBitmap);
    loadImageAlpha(sprDandelion, 16, 16, dandelionPal, dandelionBitmap);
    loadImageAlpha(sprPoppy, 16, 16, poppyPal, poppyBitmap);
    loadImageAlpha(sprRedTulip, 16, 16, red_tulipPal, red_tulipBitmap);
    loadImageAlpha(sprDoor, 32, 32, doorPal, doorBitmap);
    loadImageAlpha(sprBirchDoor, 32, 32, birchdoorPal, birchdoorBitmap);
    loadImageAlpha(sprSpruceDoor, 32, 32, sprucedoorPal, sprucedoorBitmap);
    loadImageAlpha(sprSapling, 16, 16, oak_saplingPal, oak_saplingBitmap);
    loadImageAlpha(sprBirchSapling, 16, 16, birch_saplingPal, birch_saplingBitmap);
    loadImageAlpha(sprSpruceSapling, 16, 16, spruce_saplingPal, spruce_saplingBitmap);
    loadImageAlpha(sprGlass, 32, 16, glassPal, glassBitmap);
    loadImageAlpha(sprOakTrapdoor, 16, 16, oak_trapdoorPal, oak_trapdoorBitmap);
    loadImageAlpha(sprLadder, 16, 16, ladderPal, ladderBitmap);
    loadImageAlpha(sprSign, 16, 16, signPal, signBitmap);

    loadImageAlpha(sprBlockBreak[0], 16, 16, destroy_stage_0Pal, destroy_stage_0Bitmap);
    loadImageAlpha(sprBlockBreak[1], 16, 16, destroy_stage_1Pal, destroy_stage_1Bitmap);
    loadImageAlpha(sprBlockBreak[2], 16, 16, destroy_stage_2Pal, destroy_stage_2Bitmap);
    loadImageAlpha(sprBlockBreak[3], 16, 16, destroy_stage_3Pal, destroy_stage_3Bitmap);
    loadImageAlpha(sprBlockBreak[4], 16, 16, destroy_stage_4Pal, destroy_stage_4Bitmap);
    loadImageAlpha(sprBlockBreak[5], 16, 16, destroy_stage_5Pal, destroy_stage_5Bitmap);
    loadImageAlpha(sprBlockBreak[6], 16, 16, destroy_stage_6Pal, destroy_stage_6Bitmap);
    loadImageAlpha(sprBlockBreak[7], 16, 16, destroy_stage_7Pal, destroy_stage_7Bitmap);
    loadImageAlpha(sprBlockBreak[8], 16, 16, destroy_stage_8Pal, destroy_stage_8Bitmap);
    loadImageAlpha(sprBlockBreak[9], 16, 16, destroy_stage_9Pal, destroy_stage_9Bitmap);

    loadImageAlpha(sprGrassOverlay, 16, 8, grass_overlayPal, grass_overlayBitmap);

    if (Game::SettingsManager::transparentLeaves)
    {
        loadImageAlpha(sprLeaves, 16, 16, oak_leaves_aPal, oak_leaves_aBitmap);
        loadImageAlpha(sprBirchLeaves, 16, 16, birch_leaves_aPal, birch_leaves_aBitmap);
        loadImageAlpha(sprSpruceLeaves, 16, 16, spruce_leaves_aPal, spruce_leaves_aBitmap);
    }
    else
    {
        loadImage(sprLeaves, 16, 16, oak_leavesBitmap);
        loadImage(sprBirchLeaves, 16, 16, birch_leavesBitmap);
        loadImage(sprSpruceLeaves, 16, 16, spruce_leavesBitmap);
    }
}

void Block::unloadTextures(void)
{
    unloadImage(sprGrass);
    unloadImage(sprSnowyGrass);
    unloadImage(sprStone);
    unloadImage(sprWood);
    unloadImage(sprBirchWood);
    unloadImage(sprSpruceWood);
    unloadImage(sprLeaves);
    unloadImage(sprBirchLeaves);
    unloadImage(sprSpruceLeaves);
    unloadImage(sprSand);
    unloadImage(sprSandstone);
    unloadImage(sprCactus);
    unloadImage(sprDeadBush);
    unloadImage(sprDandelion);
    unloadImage(sprPoppy);
    unloadImage(sprRedTulip);
    unloadImage(sprDoor);
    unloadImage(sprBirchDoor);
    unloadImage(sprSpruceDoor);
    unloadImage(sprPlanks);
    unloadImage(sprBirchPlanks);
    unloadImage(sprSprucePlanks);
    unloadImage(sprSapling);
    unloadImage(sprBirchSapling);
    unloadImage(sprSpruceSapling);
    unloadImage(sprBedrock);
    unloadImage(sprCobblestone);
    unloadImage(sprCoalOre);
    unloadImage(sprCoalBlock);
    unloadImage(sprGlass);
    unloadImage(sprOakTrapdoor);
    unloadImage(sprBirchTrapdoor);
    unloadImage(sprSpruceTrapdoor);
    unloadImage(sprLadder);
    unloadImage(sprChest);
    unloadImage(sprSign);
    unloadImage(sprIronOre);
    unloadImage(sprIronBlock);
    unloadImage(sprStoneBricks);
    unloadImage(sprBlockBreak[0]);
    unloadImage(sprBlockBreak[1]);
    unloadImage(sprBlockBreak[2]);
    unloadImage(sprBlockBreak[3]);
    unloadImage(sprBlockBreak[4]);
    unloadImage(sprBlockBreak[5]);
    unloadImage(sprBlockBreak[6]);
    unloadImage(sprBlockBreak[7]);
    unloadImage(sprBlockBreak[8]);
    unloadImage(sprBlockBreak[9]);
    unloadImage(sprGrassOverlay);
}

void Block::loadSounds(void)
{
    loadsfx4(DOOROPEN);
    loadsfx4(DOORCLOSE);

    setsfx4(DoorOpen, DOOROPEN);
    setsfx4(DoorClose, DOORCLOSE);
}

void Block::unloadSounds(void)
{
    unloadsfx4(DOOROPEN);
    unloadsfx4(DOORCLOSE);
}

//----------------------------------------

Block::Block(s16 x, s16 y, u8 maxBrokenLevel) : x(x), y(y), brokenLevel(0), maxBrokenLevel(maxBrokenLevel)
{
}

void Block::drawBreaking(Camera camera)
{
    if (!brokenLevel)
        return;

    float textureIndex = ((float)brokenLevel / (float)maxBrokenLevel) * 10 - 1;
    textureIndex = std::max(0, std::min((int)textureIndex, 10 - 1));
    glSprite(x - camera.x, y - camera.y, GL_FLIP_NONE, sprBlockBreak[(int)textureIndex]);
}

void Block::hit(void)
{
    hit(1);
}

void Block::hit(u8 times)
{
    brokenLevel += times;
}

bool Block::broken(void)
{
    return brokenLevel >= maxBrokenLevel;
}

void Block::interact(void)
{
}

bool Block::solid(void)
{
    return true;
}

bool Block::isSlab(void)
{
    return false;
}

// generic block implementations

GENERIC_BLOCK_IMPL(SnowyGrassBlock, sprSnowyGrass, BID_SNOWY_GRASS, 14)
GENERIC_BLOCK_IMPL(DirtBlock, sprDirt, BID_DIRT, 13)
GENERIC_BLOCK_IMPL(StoneBlock, sprStone, BID_STONE, 16)
GENERIC_BLOCK_IMPL(SandBlock, sprSand, BID_SAND, 13)
GENERIC_BLOCK_IMPL(SandstoneBlock, sprSandstone, BID_SANDSTONE, 12)
GENERIC_BLOCK_IMPL(PlanksBlock, sprPlanks, BID_PLANKS, 7)
GENERIC_BLOCK_IMPL(BirchPlanksBlock, sprBirchPlanks, BID_BIRCH_PLANKS, 7)
GENERIC_BLOCK_IMPL(SprucePlanksBlock, sprSprucePlanks, BID_SPRUCE_PLANKS, 7)
GENERIC_BLOCK_IMPL(BedrockBlock, sprBedrock, BID_BEDROCK, (u8)-1)
GENERIC_BLOCK_IMPL(CobblestoneBlock, sprCobblestone, BID_COBBLESTONE, 15)
GENERIC_BLOCK_IMPL(CoalOreBlock, sprCoalOre, BID_COAL_ORE, 18)
GENERIC_BLOCK_IMPL(CoalBlock, sprCoalBlock, BID_COAL_BLOCK, 18)
GENERIC_BLOCK_IMPL(IronOreBlock, sprIronOre, BID_IRON_ORE, 20)
GENERIC_BLOCK_IMPL(IronBlock, sprIronBlock, BID_IRON_BLOCK, 20)
GENERIC_BLOCK_IMPL(StoneBricksBlock, sprStoneBricks, BID_STONE_BRICKS, 16)

NONSOLID_BLOCK_IMPL(WoodBlock, sprWood, BID_WOOD, 7)
NONSOLID_BLOCK_IMPL(BirchWoodBlock, sprBirchWood, BID_BIRCH_WOOD, 7)
NONSOLID_BLOCK_IMPL(SpruceWoodBlock, sprSpruceWood, BID_SPRUCE_WOOD, 7)
NONSOLID_BLOCK_IMPL(CactusBlock, sprCactus, BID_CACTUS, 4)
NONSOLID_BLOCK_IMPL(DeadBushBlock, sprDeadBush, BID_DEAD_BUSH, 1);
NONSOLID_BLOCK_IMPL(LadderBlock, sprLadder, BID_LADDER, 2);

DoorBlock::DoorBlock(s16 x, s16 y, s16 px, DoorType type) : Block(x, y, 7), open(true), facing(px > x), type(type)
{
}

DoorBlock::DoorBlock(s16 x, s16 y, bool open, bool facing, DoorType type) : Block(x, y, 7), open(open), facing(facing), type(type)
{
}

void DoorBlock::draw(Camera camera)
{
    glImage *spr;
    switch (type)
    {
    case DoorType::Oak:
    default:
        spr = sprDoor;
        break;
    case DoorType::Birch:
        spr = sprBirchDoor;
        break;
    case DoorType::Spruce:
        spr = sprSpruceDoor;
        break;
    }

    if (open)
        glSprite(x - camera.x - 1, y - camera.y, GL_FLIP_NONE, spr);
    else
        glSpriteScaleXY(x - camera.x - 1 + (facing ? 0 : 8), y - camera.y, 1 << 10, 1 << 12, (facing ? GL_FLIP_NONE : GL_FLIP_H), spr);
}

bool DoorBlock::solid(void)
{
    return !open;
}

void DoorBlock::interact(void)
{
    if (open)
    {
        open = false;
        playsfx(4, sndDoorClose1, sndDoorClose2, sndDoorClose3, sndDoorClose4);
    }
    else
    {
        open = true;
        playsfx(4, sndDoorOpen1, sndDoorOpen2, sndDoorOpen3, sndDoorOpen4);
    }
}

u16 DoorBlock::id(void)
{
    switch (type)
    {
    case DoorType::Oak:
    default:
        return BID_DOOR;
    case DoorType::Birch:
        return BID_BIRCH_DOOR;
    case DoorType::Spruce:
        return BID_SPRUCE_DOOR;
    }
}

Rect DoorBlock::getRect(void) const
{
    if (open)
        return Rect(x, y, 16, 32);
    return Rect(x + (facing ? 0 : 11), y, 4, 32);
}

bool DoorBlock::isOpen(void)
{
    return open;
}

bool DoorBlock::getFacing(void)
{
    return facing;
}

SAPLING_IMPL(, sprSapling, BID_SAPLING)
SAPLING_IMPL(Birch, sprBirchSapling, BID_BIRCH_SAPLING)
SAPLING_IMPL(Spruce, sprSpruceSapling, BID_SPRUCE_SAPLING)

TRAPDOOR_IMPL(Oak, sprOakTrapdoor, BID_OAK_TRAPDOOR)
TRAPDOOR_IMPL(Birch, sprBirchTrapdoor, BID_BIRCH_TRAPDOOR)
TRAPDOOR_IMPL(Spruce, sprSpruceTrapdoor, BID_SPRUCE_TRAPDOOR)

// non-generic implementations

GrassBlock::GrassBlock(s16 x, s16 y) : Block(x, y, 14), type(GrassType::Normal)
{
}

GrassBlock::GrassBlock(s16 x, s16 y, GrassType type) : Block(x, y, 14), type(type)
{
}

void GrassBlock::draw(Camera camera)
{
    glSprite(x - camera.x, y - camera.y, GL_FLIP_NONE, sprGrass);

    switch (type)
    {
    case GrassType::Normal:
        glColor(RGB15(15, 23, 13));
        break;
    case GrassType::Spruce:
        glColor(RGB8(32, 138, 83));
        break;
    }

    glSprite(x - camera.x, y - camera.y, GL_FLIP_NONE, sprGrassOverlay);
    glColor(RGB15(31, 31, 31));
}

u16 GrassBlock::id(void)
{
    return BID_GRASS;
}

Rect GrassBlock::getRect(void) const
{
    return Rect(x, y, 16, 16);
}

bool GrassBlock::solid(void)
{
    return true;
}

GrassType GrassBlock::getGrassType(void)
{
    return type;
}

//-----------------------------------------

LeavesBlock::LeavesBlock(s16 x, s16 y, LeavesType type, bool natural) : Block(x, y, 5), natural(natural), type(type)
{
}

void LeavesBlock::draw(Camera camera)
{
    switch (type)
    {
    case LeavesType::Oak:
        glColor(RGB15(0, 22, 0));
        glSprite(x - camera.x, y - camera.y, GL_FLIP_NONE, sprLeaves);
        break;
    case LeavesType::Birch:
        glColor(RGB15(20, 26, 19));
        glSprite(x - camera.x, y - camera.y, GL_FLIP_NONE, sprBirchLeaves);
        break;
    case LeavesType::Spruce:
        glColor(RGB15(0, 11, 0));
        glSprite(x - camera.x, y - camera.y, GL_FLIP_NONE, sprSpruceLeaves);
        break;
    }
    glColor(RGB15(31, 31, 31)); // reset color
}

bool LeavesBlock::solid(void)
{
    return false;
}

u16 LeavesBlock::id(void)
{
    return BID_LEAVES;
}

Rect LeavesBlock::getRect(void) const
{
    return Rect(x, y, 16, 16);
}

bool LeavesBlock::isNatural(void)
{
    return natural;
}

//-----------------------------------------

FlowerBlock::FlowerBlock(s16 x, s16 y) : Block(x, y, 1), type(FlowerType::Poppy)
{
    switch (randomRange(1, 3))
    {
    case 1:
        type = FlowerType::Poppy;
        break;
    case 2:
        type = FlowerType::Dandelion;
        break;
    case 3:
        type = FlowerType::RedTulip;
        break;
    }
}

FlowerBlock::FlowerBlock(s16 x, s16 y, FlowerType type) : Block(x, y, 1), type(type)
{
}

void FlowerBlock::draw(Camera camera)
{
    switch (type)
    {
    case FlowerType::Dandelion:
        glSprite(x - camera.x, y - camera.y, GL_FLIP_NONE, sprDandelion);
        break;
    case FlowerType::Poppy:
        glSprite(x - camera.x, y - camera.y, GL_FLIP_NONE, sprPoppy);
        break;
    case FlowerType::RedTulip:
        glSprite(x - camera.x, y - camera.y, GL_FLIP_NONE, sprRedTulip);
        break;
    }
}

bool FlowerBlock::solid(void)
{
    return false;
}

u16 FlowerBlock::id(void)
{
    switch (type)
    {
    default:
        return (u16)-1;
    case FlowerType::Poppy:
        return BID_POPPY;
    case FlowerType::Dandelion:
        return BID_DANDELION;
    case FlowerType::RedTulip:
        return BID_RED_TULIP;
    }
}

Rect FlowerBlock::getRect(void) const
{
    return Rect(x, y, 16, 16);
}

//---------------------------------------------

GlassBlock::GlassBlock(s16 x, s16 y) : Block(x, y, 6)
{
}

void GlassBlock::draw(Camera camera)
{
    glSprite(x - camera.x - 1, y - camera.y, GL_FLIP_NONE, sprGlass);
}

u16 GlassBlock::id(void)
{
    return BID_GLASS;
}

Rect GlassBlock::getRect(void) const
{
    return Rect(x, y, 16, 16);
}

bool GlassBlock::solid(void)
{
    return true;
}

//---------------------------------------------

static u16 _nextChestID = 0;

void ChestBlock::initItems(void)
{
    for (u8 i = 0; i < 10; ++i)
        items[i] = {InventoryItemID::None, 0};
}

ChestBlock::ChestBlock(s16 x, s16 y) : Block(x, y, 7), chid(_nextChestID++)
{
    initItems();
}

ChestBlock::ChestBlock(s16 x, s16 y, u16 id) : Block(x, y, 7), chid(id)
{
    _nextChestID = id + 1;
    initItems();
}

void ChestBlock::draw(Camera camera)
{
    glSprite(x - camera.x, y - camera.y, GL_FLIP_NONE, sprChest);
}

bool ChestBlock::solid(void)
{
    return false;
}

void ChestBlock::interact(void)
{
}

u16 ChestBlock::id(void)
{
    return BID_CHEST;
}

Rect ChestBlock::getRect(void) const
{
    return Rect(x, y, 16, 16);
}

std::array<InventoryItem, 10> ChestBlock::getItems(void)
{
    std::array<InventoryItem, 10> inv;
    for (u8 i = 0; i < 10; ++i)
        inv[i] = items[i];
    return inv;
}

void ChestBlock::setItem(u8 i, InventoryItem item)
{
    items[i] = item;
}

u16 ChestBlock::getChestID(void)
{
    return chid;
}

void resetNextChestID(void)
{
    _nextChestID = 0;
}

//----------------------------------------

SignBlock::SignBlock(s16 x, s16 y, const std::string &text) : Block(x, y, 6), text(text), showText(false)
{
}

void SignBlock::draw(Camera camera)
{
    glSprite(x - camera.x, y - camera.y, GL_FLIP_NONE, sprSign);
}

void SignBlock::drawText(Camera camera)
{
    if (showText)
    {
        glBoxFilled(x - camera.x - 2, y - camera.y - 10, x - camera.x - 2 +
                    Game::instance->font.getTextWidth(getText()) + 1, y - camera.y, RGB15(4, 4, 4));
        glBoxStroke(x - camera.x - 2, y - camera.y - 10, Game::instance->font.getTextWidth(getText()) + 2, 11,
                    RGB15(11, 11, 11));
        Game::instance->font.print(x - camera.x, y - camera.y - 9, getText(), 0, 0, NULL, SCALE_NORMAL, true);
    }
}

bool SignBlock::solid(void)
{
    return false;
}

void SignBlock::interact(void)
{
}

u16 SignBlock::id(void)
{
    return BID_SIGN;
}

Rect SignBlock::getRect(void) const
{
    return Rect(x, y, 16, 16);
}

const std::string SignBlock::getText(void) const
{
    return text;
}

void SignBlock::setText(const std::string &text)
{
    this->text = text;
}

//----------------------------------------

SlabBlock::SlabBlock(s16 x, s16 y, SlabID slabID, u8 maxBrokenLevel) : Block(x, y, maxBrokenLevel), slabID(slabID)
{
}

bool SlabBlock::solid(void)
{
    return true;
}

bool SlabBlock::isSlab(void)
{
    return true;
}

Rect SlabBlock::getRect(void) const
{
    return Rect(x, y + 8, 16, 8);
}

SlabID SlabBlock::getSlabID(void) const
{
    return slabID;
}

SLAB_IMPL(Oak, sprPlanks, BID_OAK_SLAB, 6)
SLAB_IMPL(Cobblestone, sprCobblestone, BID_COBBLESTONE_SLAB, 12)
SLAB_IMPL(Birch, sprBirchPlanks, BID_BIRCH_SLAB, 6)
SLAB_IMPL(Spruce, sprSprucePlanks, BID_SPRUCE_SLAB, 6)
