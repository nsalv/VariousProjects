#include <SFML/Graphics.hpp>

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML window");
    sf::RectangleShape background(sf::Vector2f(1000,1000));
    sf::CircleShape stone(30.f);

    background.setFillColor(sf::Color::White);
    stone.setFillColor(sf::Color::Black);
    stone.setOrigin(30,30);


	// Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear screen
        window.clear();
        window.draw(background);
        window.draw(stone);


        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
