#pragma once

#include "player.hpp"
#include "entity.hpp"
#include "blockparticle.hpp"
#include "uvcoord_font_si.h"
#include "save.hpp"
#include "gamever.hpp"
#include "help.hpp"
#include <sstream>
#include <regex>

class Game
{
public:
    class WorldManager
    {
    public:
        WorldManager() = delete;
        WorldManager(WorldManager &) = delete;
        ~WorldManager() = delete;

        struct WorldInfo
        {
            std::string name;
            int size; // in bytes
        };
        typedef std::vector<WorldInfo> WorldList;

        static WorldList getWorlds(void);
    };

    class SettingsManager
    {
    public:
        static bool transparentLeaves;
        static bool autoSave;
        static bool smoothCamera;
        static bool autoJump;

        // 0 = off
        // 1 = left-handed (abxy=abxy)
        // 2 = right-handed (abxy=d-pad)
        static u8 touchToMove;

        SettingsManager() = delete;
        SettingsManager(SettingsManager &) = delete;
        ~SettingsManager() = delete;

        static void loadSettings(void);
    };

    class ControlsManager
    {
    public:
        static inline constexpr u8 BUTTON_GO_LEFT = 0;
        static inline constexpr u8 BUTTON_GO_RIGHT = 1;
        static inline constexpr u8 BUTTON_JUMP = 2;
        static inline constexpr u8 BUTTON_SNEAK = 3;
        static inline constexpr u8 BUTTON_DPAD_AIM = 4;
        static inline constexpr u8 BUTTON_OPEN_INVENTORY = 5;
        static inline constexpr u8 BUTTON_PAUSE = 6;
        static inline constexpr u8 BUTTON_INTERACT = 7;
        static inline constexpr u8 BUTTON_ATTACK = 8;
        static inline constexpr u8 BUTTON_UNKNOWN = UINT8_MAX;

        static inline constexpr u8 NUM_BUTTONS = 9;

        static inline constexpr u32 DEFAULT_GO_LEFT = KEY_LEFT;
        static inline constexpr u32 DEFAULT_GO_RIGHT = KEY_RIGHT;
        static inline constexpr u32 DEFAULT_JUMP = KEY_UP;
        static inline constexpr u32 DEFAULT_SNEAK = KEY_DOWN;
        static inline constexpr u32 DEFAULT_DPAD_AIM = KEY_Y;
        static inline constexpr u32 DEFAULT_OPEN_INVENTORY = KEY_SELECT;
        static inline constexpr u32 DEFAULT_PAUSE = KEY_START;
        static inline constexpr u32 DEFAULT_INTERACT = KEY_A;
        static inline constexpr u32 DEFAULT_ATTACK = KEY_B;

        ControlsManager() = delete;
        ControlsManager(ControlsManager &) = delete;
        ~ControlsManager() = delete;

        static void loadControls(void);
        static void saveControls(void);
        static u32 getButton(u8 button);
        static void setButton(u8 button, u32 key);

    private:
        static u32 buttons[NUM_BUTTONS];

        static void writeDefaultControls(void);
        static u8 buttonIDIndex(const std::string &buttonID);
    };

    enum class GameState
    {
        Game,
        TitleScreen,
        Credits,
        WorldSelect,
        CreateWorld,
        LanguageSelect,
        VersionInfo,
        Settings,
        DeleteWorld,
        DeleteAllWorlds,
        WorldSettings,
        RenameWorld,
        EditControls,
    };

private:
    BlockList blocks;
    EntityList entities;
    BlockParticleList blockParticles;
    Player player;

    glImage fontSmallImg[FONT_SI_NUM_IMAGES];
    glImage fontSmallRuImg[FONT_SI_NUM_IMAGES];

    GameState gameState;
    Camera camera;
    u16 frameCounter;
    u8 saveTextTimer;
    u16 worldSelectSelected;
    u8 langSelectSelected;
    u16 deleteWorldSelected;
    u16 renameWorldSelected;
    WorldManager::WorldList worldSelectWorlds;
    bool showSaveText;
    bool paused;
    std::string worldName;
    std::string createWorldName;
    std::string createWorldSeed;
    std::string renameWorldName;
    bool createWorldError;
    u8 settingsSelect;
    u8 titleScreenSelect;
    bool createWorldShowCursor = false;
    u8 createWorldSelect = 0;
    u8 worldSettingsSelect = 0;
    s16 currentLocation = 0;
    bool logoFall = false;
    u16 logoY;

    void gameQuit(void);
    void playPopSound(void);
    void loadFonts(void);
    void init(void);
    void showHelpScreen(const std::string &setting);
    void enterWorldSelect(void);
    void loadLocation(s16 oldLocation);
    void cameraFollowPlayer(bool smooth);

public:
    static Game *instance;

    static u8 fontSmallCharWidthHandler(char ch);
    static u8 fontBigCharWidthHandler(char ch);
    static u8 fontSmallRuCharWidthHandler(char ch);
    static u8 fontBigRuCharWidthHandler(char ch);

    glImage sprLogo[1];
    glImage sprAButton[1];
    glImage sprBButton[1];
    glImage sprXButton[1];
    glImage sprYButton[1];
    glImage sprSelectButton[1];

    glImage sprWorldLabel[1];
    glImage sprWorldLabelSelect[1];

    glImage sprLangEnglish[1];
    glImage sprLangRussian[1];

    mm_sound_effect sndClick;
    mm_sound_effect sndPop;

    Font font, fontRu;

    Language lang;

    class AssetManager
    {
    public:
        AssetManager() = delete;
        AssetManager(AssetManager &) = delete;
        ~AssetManager() = delete;

        static void loadDirtBlock(void);
        static void loadGeneralAssets(void);
        static void loadGameAssets(void);
        static void unloadGameAssets(void);
        static void loadMenuAssets(void);
        static void unloadMenuAssets(void);
    };

    Game();

    void drawMovingBackground(void);
    void draw(void);
    void update(void);
    void run(void);
};
