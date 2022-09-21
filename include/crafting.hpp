#pragma once
#include "lang.hpp"
#include "player.hpp"
#include "fs.h"
#include <sstream>
#include <iterator>
#include <string>

InventoryItemID strToIID(std::string &sid);

class CraftingRecipe
{
private:
    u8 id, count;
    s8 texid;
    InventoryItemID output;
    std::string nameEn, nameRu;
    std::vector<InventoryItem> recipe;

public:
    explicit CraftingRecipe(const char *recipeFile);

    std::string getFullName(Language lang, Player *pThis);
    u8 getID(void) const;
    s8 getTexID(void);
    u8 getCount(void);
    InventoryItemID getOutput(void);
    std::vector<InventoryItem> *getRecipe(void);
};