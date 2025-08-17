#pragma once
#include <SFML/Graphics.hpp>

// Player class represents the main character controlled by the user
class Player {

    private:
    
    // Initial speed and health constants
    static constexpr float START_SPEED = 200.0f;
    static constexpr float START_HEALTH = 100.0f;

    // Current speed of the player
    float m_Speed;
    // Current health of the player
    int m_Health;
    // Maximum health the player can have
    int m_MaxHealth;

    // Player's position in the game world
    sf::Vector2f m_Position;
    // Sprite used to draw the player
    sf::Sprite m_Sprite;
    // Texture for the player sprite
    sf::Texture m_Texture;

    // Screen resolution
    sf::Vector2f m_Resolution;
    // Arena boundaries
    sf::IntRect m_Arena;
    // Size of a single tile in the arena
    int m_TileSize;

    // Movement flags
    bool m_UpPressed;
    bool m_DownPressed;
    bool m_RightPressed;       
    bool m_LeftPressed;

    // Time when the player was last hit
    sf::Time m_LastHit;


    public:

    // Constructor
    Player();

    // Initializes the player in the arena
    void spawn(sf::Vector2f resolution, sf::IntRect arena, int tileSize);

    // Resets player stats to initial values
    void resetPlayerStats();

    // Registers a hit on the player, returns true if hit is successful
    bool hit(sf::Time timeHit);

    // Returns the time of the last hit
    sf::Time getLastHitTime() const;
    // Returns the global bounds of the player sprite
    sf::FloatRect getPosition() const;
    // Returns a copy of the player sprite
    sf::Sprite getSprite() const;
    // Returns the center position of the player
    sf::Vector2f getCenter() const;
    // Returns the rotation of the player sprite
    float getRotation() const;
    // Returns the current health of the player
    int getHealth() const;

    // Movement controls
    void moveUp();
    void moveDown();
    void moveLeft();    
    void moveRight();

    // Stops movement in a direction
    void stopUp();
    void stopDown();        
    void stopLeft();
    void stopRight();

    // Updates the player's position and rotation
    void update(float elapsedTime, sf::Vector2i mousePosition);

    // Upgrades the player's speed
    void upgradeSpeed();
    // Upgrades the player's maximum health
    void upgradeHealth();

    // Increases the player's health by a specified amount
    void increaseHealth(int amount);