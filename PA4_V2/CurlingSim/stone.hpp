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

        if (Pos.x >= 960 || Pos.x <=40){
            velocity.x= -velocity.x;
        }

        if (Pos.y >=960 || Pos.y <=40){
            velocity.y = -velocity.y;
        }
}
void bounceStone(std::vector<Stone>& stones){
    sf::Vector2f loc = s.getPosition();
    sf::Vector2f stonePos;
    bool collide = 0;
    std::vector<sf::Vector2f> Pos;
    for (int i=0; i<stones.size(); i++){
        stonePos = stones[i].s.getPosition();
        Pos.push_back(stonePos);
    }

    //comparing x and y positions of each stone


        //determines the distance between the x and y coordinates of each stone

    for(int i=0; i<Pos.size(); i++){
    float d = sqrt(pow((loc.x-Pos[i].x),2)+pow((loc.y-Pos[i].y),2));
        if (d<=80 && loc!=Pos[i]){

            float newVelX1 = stones[i].velocity.x;
            float newVelY1 = stones[i].velocity.y;
            float newVelX2 = velocity.x;
            float newVelY2 = velocity.y;

            stones[i].velocity.x = newVelX2;
            stones[i].velocity.y = newVelY2;
            velocity.x = newVelX1;
            velocity.y = newVelY1;
        }
    }
}

private:
float radius = 40.f;

};
