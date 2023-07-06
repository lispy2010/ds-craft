#pragma once
#include "lang.hpp"
#include "player.hpp"
#include "fs.h"
#include <sstream>
#include <iterator>
#include <string>

InventoryItemID strToIID(std::string &sid); // why is this here?

class CraftingRecipe
{
private:
    u8 count;
    InventoryItemID output;
    std::string fileName;
    std::vector<InventoryItem> recipe;

    void construct(const char *recipeFile);

public:
    // constructors are marked as explicit because cppcheck said so

    explicit CraftingRecipe(const char *recipeFile);
    explicit CraftingRecipe(const std::string &recipeFile);

    std::string getFullName(Language lang, Player *player);
    std::string getFileName(void);
    u8 getCount(void);
    InventoryItemID getOutput(void);
    std::vector<InventoryItem> *getRecipe(void);
};
