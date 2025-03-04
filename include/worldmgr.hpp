/**
 * @file worldmgr.hpp
 * @brief Class for managing worlds
*/

#pragma once

#include <string>
#include <vector>

/**
 * @brief Class for managing worlds
 */
class WorldManager
{
public:
    WorldManager() = delete;
    WorldManager(WorldManager &) = delete;
    ~WorldManager() = delete;

    /**
     * @brief Struct for representing basic world info
     */
    struct WorldInfo
    {
        /**
         * @brief name of world
         */
        std::string name;

        /**
         * @brief Size of the world in bytes
         */
        int size;
    };

    /**
     * @brief Type for list of worlds
     */
    typedef std::vector<WorldInfo> WorldList;

    /**
     * @brief Get info about worlds stored in the worlds directory
     */
    static WorldList getWorlds(void);

    static std::vector<std::string> getFavoriteWorlds(void);
};
