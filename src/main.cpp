// src/main.cpp
#include <SFML/Graphics.hpp>

int main() {
    // Create window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Empty Window + Square");
    window.setFramerateLimit(60);

    // Make a square (120x120), colored, with a thin outline
    const float side = 120.f;
    sf::RectangleShape square({side, side});
    square.setFillColor(sf::Color(100, 180, 255));
    square.setOutlineThickness(3.f);
    square.setOutlineColor(sf::Color::White);

    // Center the square in the window
    auto centerSquare = [&](sf::Vector2u size) {
        square.setPosition(
            size.x * 0.5f - side * 0.5f,
            size.y * 0.5f - side * 0.5f
        );
    };
    centerSquare(window.getSize());

    // Main loop
    while (window.isOpen()) {
        sf::Event e{};
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed) {
                window.close();   // 👈 actually close the window
            }
            else if (e.type == sf::Event::Resized) {
                centerSquare({e.size.width, e.size.height}); // re-center on resize
            }
        }

        // Clear screen
        window.clear(sf::Color::Black);

        // Draw the square
        window.draw(square);

        // Display
        window.display();
    }

    return 0;
}
