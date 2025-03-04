/**
 * @file entity.hpp
 * @brief Entity classes and functions
*/

#pragma once

#include "camera.h"
#include "block.hpp"
#include "animsprite.hpp"
#include "facing.hpp"

class Entity;

typedef std::vector<std::unique_ptr<Entity>> EntityList;

/**
 * @brief Class representing an entity
*/
class Entity
{
public:
    /**
     * @brief X position of the entity
    */
    s16 x;

    /**
     * @brief Y position of the entity
    */
    s16 y;

    /**
     * @brief X velocity of the entity
    */
    float velX;

    /**
     * @brief Y velocity of the entity
    */
    float velY;

    /**
     * @brief Whether the entity is falling or not
    */
    bool falling;

    /**
    * @brief Whether the entity is jumping or not
    */
    bool jumping;

    /**
     * @brief The entity's health
    */
    s16 health;

    /**
     * @brief Load entity textures
    */
    static void loadTextures(void);

    /**
     * @brief Unload entity textures
    */
    static void unloadTextures(void);

    /**
     * @brief Load entity sounds
    */
    static void loadSounds(void);

    /**
     * @brief Unload entity sounds
    */
    static void unloadSounds(void);

    /**
     * @brief Entity constructor
     * @param x X position of the entity
     * @param y Y position of the entity
    */
    Entity(s16 x, s16 y);

    /**
     * @brief Entity destructor
    */
    virtual ~Entity() = default;

    /**
     * @brief Draw the entity
     * @param camera camera to use
    */
    virtual void draw(const Camera &camera) = 0;

    /**
     * @brief Update the entity
     * @param blocks list of blocks
     * @param camera camera (used for culling)
     * @param frames frame counter
    */
    virtual void update(Block::List &blocks, const Camera &camera, const u16 &frames) = 0;

    /**
     * @brief Get bottom hitbox of the entity
    */
    virtual Rect getRectBottom(void) = 0;

    /**
     * @brief Get top hitbox of the entity
    */
    virtual Rect getRectTop(void) = 0;

    /**
     * @brief Get left hitbox of the entity
    */
    virtual Rect getRectLeft(void) = 0;

    /**
     * @brief Get right hitbox of the entity
    */
    virtual Rect getRectRight(void) = 0;

    /**
     * @brief Get overall hitbox of the entity
    */
    virtual Rect getRect(void) = 0;

    /**
     * @brief Get entity's ID
     * I think it's a string because of the save system.
    */
    virtual std::string id(void) = 0;

    /**
     * @brief This function is called when the entity gets damaged
    */
    virtual void onDealDamage(void);

    /**
     * @brief This function is called when the entity dies
     * @param entities list of entities
    */
    virtual void onDeath(EntityList &entities);

    /**
     * @brief Check if the entity is dead
    */
    bool dead(void);

    /**
     * @brief Deal damage to the entity
     * @param amount the amount of damage to deal
    */
    void damage(u8 amount);
};

/**
 * @brief Class representing a pig entity
*/
class PigEntity : public Entity
{
private:
    /**
     * @brief Where the pig is facing
    */
    Facing facing;

    /**
     * @brief Whether the pig is moving or not
    */
    bool moving;

    /**
     * @brief Timer for damage overlay
    */
    u8 damageOverlayTimer;

    /**
     * @brief Timer for panic mode
    */
    u16 panicModeTimer;

public:
    PigEntity(s16 x, s16 y);

    void draw(const Camera &camera) override;
    void update(Block::List &blocks, const Camera &camera, const u16 &frames) override;
    Rect getRectBottom(void) override;
    Rect getRectTop(void) override;
    Rect getRectLeft(void) override;
    Rect getRectRight(void) override;
    Rect getRect(void) override;
    std::string id(void) override;
    void onDealDamage(void) override;
    void onDeath(EntityList &entities) override;
};

class DropEntity : public Entity
{
private:
    /**
     * @brief The drop's item ID
    */
    InventoryItem::ID itemid;

    /**
     * @brief Spin counter
     *
     * Basically this thing controls which frame the spinning animation is at
    */
    u8 spin;

    /**
     * @brief If this is set to true, then `spin` will be incremented, or decremented if false.
    */
    bool increment;

    /**
     * @brief If true, the drop will appear to be a bit higher than normal
    */
    bool upOffset;

public:
    /**
     * @brief Drop entity constructor
     * @param itemid drop's item ID
    */
    DropEntity(s16 x, s16 y, InventoryItem::ID itemid);

    void draw(const Camera &camera) override;
    void update(Block::List &blocks, const Camera &camera, const u16 &frames) override;
    Rect getRectBottom(void) override;
    Rect getRectTop(void) override;
    Rect getRectLeft(void) override;
    Rect getRectRight(void) override;
    Rect getRect(void) override;
    std::string id(void) override;

    /**
     * @brief Get the drop's item ID
    */
    InventoryItem::ID getItemID(void);
};
