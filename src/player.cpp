#include "player.h"
#include <cmath>

constexpr int PLAYER_HIT_DAMAGE = 10;

Player::Player() : m_Speed(START_SPEED), m_Health(START_HEALTH), m_MaxHealth(START_HEALTH), m_Texture(), m_Sprite()

{

    m_Texture.loadFromFile("assets/graphics/player.png");
    m_Sprite.setTexture(m_Texture);
    m_Sprite.setOrigin(25, 25);
}



void Player::spawn(sf::Vector2f resolution, sf::IntRect arena, int tileSize)
{
    m_Position.x = arena.width / 2;
    m_Position.y = arena.height / 2;

    m_Resolution.x = resolution.x;
    m_Resolution.y = resolution.y;

    m_Arena.width = arena.width;
    m_Arena.height = arena.height;  
    m_Arena.left = arena.left;
    m_Arena.top = arena.top;

    m_TileSize = tileSize;

}

    void Player::resetPlayerStats()

    {
        m_Speed = START_SPEED;
        m_Health = START_HEALTH;
        m_MaxHealth = START_HEALTH;
    }

    bool Player::hit(sf::Time timeHit)
    {
        if(timeHit.asMilliseconds() - m_LastHit.asMilliseconds() >200)
        {
            m_LastHit = timeHit;
            m_Health -= PLAYER_HIT_DAMAGE;
            return true;
        }

        else
        {
            return false;
        }
    }

    sf::Sprite Player::getSprite() const

    {
        return m_Sprite;
    }

    sf::Time Player::getLastHitTime() const
    {
        return m_LastHit;
    }   

    sf::FloatRect Player::getPosition() const
    {
        return  m_Sprite.getGlobalBounds();
    }

    sf::Vector2f Player::getCenter() const
    {
        return m_Position;
    }

    float Player::getRotation() const
    {
        return m_Sprite.getRotation();
    }

    int Player::getHealth() const
    {
        return m_Health;
    }


    void Player::moveUp()
    {
        m_UpPressed = true;
    }   
    void Player::moveDown()
    {
        m_DownPressed = true;
    }
    void Player::moveLeft()
    {
        m_LeftPressed = true;   
    }    
    void Player::moveRight()
    {
        m_RightPressed = true;
    }


    void Player::stopUp()
    {
        m_UpPressed = false;
    }
    void Player::stopDown()
    {
        m_DownPressed = false;
    }        
    void Player::stopLeft()
    {
        m_LeftPressed = false;
    }

    void Player::stopRight()
    {
        m_RightPressed = false;
    }

    void Player::update(float elapsedTime, sf::Vector2i mousePosition)
    {
        // Move the player
        if (m_UpPressed)
        {
            m_Position.y -= m_Speed * elapsedTime;
        }
        if (m_DownPressed)
        {
            m_Position.y += m_Speed * elapsedTime;
        }
        if (m_LeftPressed)
        {
            m_Position.x -= m_Speed * elapsedTime;
        }
        if (m_RightPressed)
        {
            m_Position.x += m_Speed * elapsedTime;
        }

        // Keep the player within the arena
        if (m_Position.x < m_Arena.left + m_TileSize / 2) { m_Position.x = m_Arena.left + m_TileSize / 2; }
        if (m_Position.x > m_Arena.left + m_Arena.width - m_TileSize / 2) { m_Position.x = m_Arena.left + m_Arena.width - m_TileSize / 2; }
        if (m_Position.y < m_Arena.top + m_TileSize / 2) { m_Position.y = m_Arena.top + m_TileSize / 2; }
        if (m_Position.y > m_Arena.top + m_Arena.height - m_TileSize / 2) { m_Position.y = m_Arena.top + m_Arena.height - m_TileSize / 2; }

        // Update sprite position and rotation
        m_Sprite.setPosition(m_Position);
        
        float rotation = std::atan2(mousePosition.y - m_Position.y, mousePosition.x - m_Position.x) * 180 / 3.14159f;
        m_Sprite.setRotation(rotation);
    }

    void Player::upgradeSpeed()
    {
        m_Speed += (START_SPEED * 0.2);
    }
    void Player::upgradeHealth()
    {
        m_MaxHealth += (START_HEALTH * 0.2f);
        m_Health = m_MaxHealth;
    }

    void Player::increaseHealth(int amount)
    {
        m_Health += amount;
        if (m_Health > m_MaxHealth)
        {
            m_Health = m_MaxHealth;
        }
    }


