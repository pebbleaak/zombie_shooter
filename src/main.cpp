#include "player.h"
#include <SFML/Graphics.hpp>

int main() {
    

    enum class State {
        PAUSED,
        PLAYING,
        GAME_OVER,
        LEVELING_UP
    };

    State state = State::GAME_OVER;

    sf::Vector2f resolution;

    resolution.x = sf::VideoMode::getDesktopMode().width;
    resolution.y = sf::VideoMode::getDesktopMode().height;

    sf::RenderWindow window(sf::VideoMode(resolution.x, resolution.y),"Zombie Arena",sf::Style::Default);

    sf::View mainView(sf::FloatRect(0,0,resolution.x, resolution.y));


    sf::Vector2f mouseWorldPosition;
    sf::Vector2i mouseScreenPosition;

    Player player;

    sf::IntRect arena;

    sf::Time totalGameTime;

    sf::Clock clock;

    while (window.isOpen())
    {

        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Enter && state  == State::PLAYING)
                {
                    state = State::PAUSED;
                }

                else if (event.key.code == sf::Keyboard::Enter && state == State::PAUSED)

                {
                    state = State::PLAYING:
                    clock.restar();
                }

                else if (event.key.code == sf::Keyboard::Escape && state != State::GAME_OVER)
                {
                    state = State::LEVELING_UP;
                }

                if (state == State::PLAYING)
                {
                    // Fill This Code
                }

            }
        }
    }


    return 0;
}
