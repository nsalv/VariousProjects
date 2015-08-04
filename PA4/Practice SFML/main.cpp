#include <SFML/Graphics.hpp>


class Stone : public sf::CircleShape {


public:
sf::CircleShape s;
sf::Vector2f velocity;
Stone (float x, float y)
{
    velocity.x = 7;
    velocity.y = 5;
    s.setRadius(radius);
    s.setOrigin(radius,radius);
    s.setFillColor(sf::Color::Black);
    s.setPosition(x,y);

}

void bounce(){
    sf::Vector2f Pos = s.getPosition();

        if (Pos.x >= 970 || Pos.x <=30){
            velocity.x= -velocity.x;
        }

        if (Pos.y >=970 || Pos.y <=30){
            velocity.y = -velocity.y;
        }
    s.move(velocity);
}


private:
float radius = 30.f;

};


int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML window");
    sf::RectangleShape background(sf::Vector2f(1000,1000));

    sf::CircleShape blah(30.f);
    Stone stone(470.f,470.f);

    background.setFillColor(sf::Color::White);


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

        stone.bounce();

        // Clear screen
        window.clear();
        window.draw(background);
        window.draw(stone.s);


        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
