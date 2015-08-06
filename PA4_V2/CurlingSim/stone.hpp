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

            sf::Vector2f n = (loc-Pos[i]);
            float unitnx = n.x/d;
            float unitny = n.y/d;
            float a1 = velocity.x*unitnx+velocity.y*unitny;
            float a2 = stones[i].velocity.x*unitnx+stones[i].velocity.y*unitny;
            float optP = (2.0*(a1-a2)/20);
            velocity.x = velocity.x - optP*10*unitnx;
            velocity.y = velocity.y - optP*10*unitny;
            stones[i].velocity.x = stones[i].velocity.x+optP*10*unitnx;
            stones[i].velocity.y = stones[i].velocity.y+optP*10*unitnx;

//            sf::Vector2f temp = velocity;
//
//            velocity = stones[i].velocity; //sf::Vector2f(10,10);
//            stones[i].velocity = temp;

        }
    }
}

private:
float radius = 40.f;

};
