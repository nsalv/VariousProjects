#include <SFML/Graphics.hpp>
#include <vector>

std::vector<sf::RectangleShape> build(){

std::vector<sf::RectangleShape> recs (15,sf::RectangleShape (sf::Vector2f(200,100)));

int xPos = 0;
int yPos = 0;
int counter = 1;

for (int j=0; j<recs.size(); j++){
        recs[j].setOutlineThickness(10);
        recs[j].setOutlineColor(sf::Color::Black);
        recs[j].setFillColor(sf::Color::Red);
    }

for (int k=0; k<recs.size(); k++){

    recs[k].setPosition(xPos,yPos);
    xPos+=200;

    if (counter % 5 == 0 && counter > 1){
        yPos+=110;
        xPos=0;
    }
    counter++;
}

return recs;
}

int main()
{
    // Create the main window
    sf::RenderWindow app(sf::VideoMode(1000, 1000), "Brick Breaker");
    sf::RectangleShape background (sf::Vector2f(1000,1000));
    background.setFillColor(sf::Color::White);

    std::vector<sf::RectangleShape> recs = build();



	// Start the game loop
    while (app.isOpen())
    {
        // Process events
        sf::Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                app.close();
        }

        // Clear screen
        app.clear();
        app.draw(background);

        for (int i=0; i<recs.size(); i++){
            app.draw(recs[i]);
        }

        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}
