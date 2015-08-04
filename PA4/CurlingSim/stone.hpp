// stone_class.h
#include <SFML/Graphics.hpp>

class Stone : public sf::CircleShape {


public:
sf::CircleShape s;
sf::Vector2f velocity;
Stone (float x, float y, float a, float b)
{
    velocity.x = x;
    velocity.y = y;
    s.setRadius(radius);
    s.setOrigin(radius,radius);
    s.setFillColor(sf::Color::Black);
    s.setPosition(a,b);

}
void move(){
    s.move(velocity);
}
void bounce(){
    sf::Vector2f Pos = s.getPosition();

        if (Pos.x >= 970 || Pos.x <=30){
            velocity.x= -velocity.x;
        }

        if (Pos.y >=970 || Pos.y <=30){
            velocity.y = -velocity.y;
        }
}


private:
float radius = 30.f;

};
