#include <crafting.hpp>
#include <algorithm>

InventoryItemID strToIID(std::string &sid)
{
    sid.erase(std::remove_if(sid.begin(), sid.end(), ::isspace), sid.end());
    if (sid == "grass")
        return InventoryItemID::Grass;
    else if (sid == "dirt")
        return InventoryItemID::Dirt;
    else if (sid == "stone")
        return InventoryItemID::Stone;
    else if (sid == "wood")
        return InventoryItemID::Wood;
    else if (sid == "birchwood")
        return InventoryItemID::BirchWood;
    else if (sid == "sand")
        return InventoryItemID::Sand;
    else if (sid == "sandstone")
        return InventoryItemID::Sandstone;
    else if (sid == "cactus")
        return InventoryItemID::Cactus;
    else if (sid == "deadbush")
        return InventoryItemID::DeadBush;
    else if (sid == "poppy")
        return InventoryItemID::Poppy;
    else if (sid == "dandelion")
        return InventoryItemID::Dandelion;
    else if (sid == "door")
        return InventoryItemID::Door;
    else if (sid == "birchdoor")
        return InventoryItemID::BirchDoor;
    else if (sid == "planks")
        return InventoryItemID::Planks;
    else if (sid == "birchplanks")
        return InventoryItemID::BirchPlanks;
    else if (sid == "stick")
        return InventoryItemID::Stick;
    else if (sid == "snowygrass")
        return InventoryItemID::SnowyGrass;
    else if (sid == "sapling")
        return InventoryItemID::Sapling;
    else if (sid == "cobblestone")
        return InventoryItemID::Cobblestone;
    else if (sid == "coalore")
        return InventoryItemID::CoalOre;
    else if (sid == "coal")
        return InventoryItemID::Coal;
    else if (sid == "coalblock")
        return InventoryItemID::CoalBlock;
    else if (sid == "rawporkchop")
        return InventoryItemID::RawPorkchop;
    else if (sid == "cookedporkchop")
        return InventoryItemID::CookedPorkchop;
    else if (sid == "apple")
        return InventoryItemID::Apple;
    else if (sid == "glass")
        return InventoryItemID::Glass;
    else
        printf("%s not a valid item string id\n");

    return InventoryItemID::None;
}

CraftingRecipe::CraftingRecipe(const char *recipeFile)
{
    std::string path = "nitro:/crafting/" + std::string(recipeFile) + ".rcp";

    // check if file exists
    if (!fsFileExists(path.c_str()))
    {
        printf("crafting recipe %s not found (full path: %s)", recipeFile, path.c_str());
        while (true)
            ;
    }

    std::string contents = std::string(fsReadFile(path.c_str()));
    std::istringstream iss(contents);
    std::string line;
    bool recipeMode = false;
    while (std::getline(iss, line))
    {
        // split the line
        std::vector<std::string> split;
        std::stringstream ss(line);
        std::string line2;
        while (std::getline(ss, line2, ' '))
            split.push_back(line2);

        // switch to recipe mode
        if (line.rfind("RECIPE", 0) == 0)
        {
            recipeMode = true;
            continue;
        }

        // add item if recipe mode
        if (recipeMode)
        {
            InventoryItem item = {strToIID(split[0]), (u8)std::stoi(split[1])};
            recipe.push_back(item);
        }
        else
        {
            std::string key = split[0];

            // id
            if (key == "id")
                id = (u8)std::stoi(split[1]);
            // name english
            else if (key == "nameEn")
            {
                split.erase(split.begin()); // remove key
                const char *const delim = " ";

                // implode name with space as delim
                std::ostringstream imploded;
                std::copy(split.begin(), split.end(),
                          std::ostream_iterator<std::string>(imploded, delim));
                std::string str = imploded.str();
                str.pop_back(); // remove last space
                nameEn = str;
            }
            else if (key == "nameRu")
            {
                // same as nameEn
                split.erase(split.begin());
                const char *const delim = " ";

                std::ostringstream imploded;
                std::copy(split.begin(), split.end(),
                          std::ostream_iterator<std::string>(imploded, delim));
                std::string str = imploded.str();
                str.pop_back();
                nameRu = str;
            }
            // count
            else if (key == "count")
                count = (u8)std::stoi(split[1]);
            // texture id
            else if (key == "texid")
                texid = (s8)std::stoi(split[1]);
            // output
            else if (key == "output")
                output = strToIID(split[1]);
            else
            {
                // oof
                printf("unknown key in recipe %s: %s (line: \"%s\")", recipeFile, key.c_str(), line.c_str());
                while (true)
                    ;
            }
        }
    }
}

std::string CraftingRecipe::getFullName(Language lang, Player *pThis)
{
    // get name
    std::string nm = nameEn;
    if (lang == Language::Russian)
        nm = nameRu;
    std::string name;
    if (count > 1)
        name = std::to_string(count) + " " + nm;
    else
        name = nm;

    // create item strings
    std::vector<std::string> itemVec;
    for (auto item : recipe)
        itemVec.push_back(
            std::to_string(pThis->countItems(item.id)) + "/" + std::to_string(item.amount) +
            " " + std::string(getItemStr(lang, item.id)));

    // join with semicolon and space
    const char *const delim = "; ";
    std::ostringstream imploded;
    std::copy(itemVec.begin(), itemVec.end(),
              std::ostream_iterator<std::string>(imploded, delim));
    std::string recipeStr = imploded.str();

    // remove last '; '
    recipeStr.pop_back();
    recipeStr.pop_back();

    return name + " - " + recipeStr;
}

u8 CraftingRecipe::getID(void) const
{
    return id;
}

s8 CraftingRecipe::getTexID(void)
{
    return texid;
}

u8 CraftingRecipe::getCount(void)
{
    return count;
}

InventoryItemID CraftingRecipe::getOutput(void)
{
    return output;
}

std::vector<InventoryItem> *CraftingRecipe::getRecipe(void)
{
    return &recipe;
}