#include <SFML/Graphics.hpp>
#include "stone.hpp"
#include <vector>
#include <iostream>
#include <cmath>

//Need to work on physics between stones.
//Make function for each individual scenario

void bounceStone(std::vector<Stone>& stones){
    sf::Vector2f stonePos;
    std::vector<sf::Vector2f> Pos;

    for (int i=0; i<stones.size(); i++){
        stonePos = stones[i].s.getPosition();
        Pos.push_back(stonePos);
    }

    //comparing x and y positions of each stone
    for (int p=0; p<Pos.size(); p++){
        for (int l=0; l<Pos.size(); l++){

        if (l==p){
        continue;
        }

        //determines the distance between the x and y coordinates of each stone
        int d = sqrt(pow((Pos[l].x-Pos[p].x),2)+pow((Pos[l].y-Pos[p].y),2));

        //when the two stones collide the stones shoot off the screen and reset.
        //something is very wrong with the trig....
        if (d<=80){

            float dot = Pos[l].x*Pos[p].x + Pos[l].y*Pos[p].y;
            float magpPos = sqrt(pow(Pos[p].x,2)+pow(Pos[p].y,2));
            float maglPos = sqrt(pow(Pos[l].x,2)+pow(Pos[l].y,2));
            float theta = dot/(magpPos*maglPos);

            float magpVel = sqrt(pow(stones[p].velocity.x,2)+pow(stones[p].velocity.y,2));
            float maglVel = sqrt(pow(stones[l].velocity.x,2)+pow(stones[l].velocity.y,2));



            sf::Vector2f sub = (Pos[p]-Pos[l]);
            //distance between stones
            float subMag = sqrt(pow(sub.x,2)+pow(sub.y,2));
            //dot product for velocities of stones parallel to distance between stones
            float pV1 = (sub.x*stones[p].velocity.x + sub.y*stones[p].velocity.y);
            float pV2 = (sub.x*stones[l].velocity.x + sub.y*stones[l].velocity.y);
            //vector addition to determine normal vectors
            float nV1 = subMag - pV1;
            float nV2 = subMag - pV2;

            float phi = 90-theta;
            float ang = atan(nV2/pV1); //could be wrong.
            float alpha = ang - phi;

            float VF1 = sqrt(pow(pV1,2)+pow(nV2,2));
            stones[p].velocity.x = VF1*cos(theta);
            stones[p].velocity.y = VF1*sin(theta);

            float VF2 = maglVel + magpVel - VF1;
            stones[l].velocity.x = (VF2*cos(theta));
            stones[l].velocity.y = (VF2*sin(theta));
//
//            temp = stones[p].velocity.y;
//            stones[p].velocity.x = magpVel*cos(theta);
//            stones[l].velocity.x = magpVel*sin(theta);
//            stones[p].velocity.y = stones[l].velocity.y;
//            stones[l].velocity.y = temp;

        }
        }
    }

}
std::vector<Stone> test(bool& collide, bool& rep) {

    std::vector<Stone> stones;
    stones.push_back(Stone(0,0,500,500));
    stones.push_back(Stone(10,10,50,100));

    collide = true;
    rep = false;
    return stones;

}

//random mode where 10 stones are given a velocity in a random direction
//if a stone leaves the ice, the stone is replaced by a new one
std::vector<Stone> random(bool& collide, bool& rep){

std::vector<Stone> stones;
    for (int i=0; i<10; i++){
        float a = rand() % 970;
        float b = rand() % 970;
        float x = rand() % 5;
        float y = rand() % 5;
        stones.push_back(Stone(x,y,a,b));
    }
collide = false;
rep = true;
return stones;
}

std::vector<Stone> bounce(bool& collide, bool& rep){

std::vector<Stone> stones;
    for (int i=0; i<10; i++){
        float a = rand() % 970;
        float b = rand() % 970;
        float x = rand() % 5;
        float y = rand() % 5;
        stones.push_back(Stone(x,y,a,b));
    }
collide = true;
rep = false;
return stones;
}

void replace(std::vector<Stone>& stones){
    sf::Vector2f Pos;
    for (int i=0; i<stones.size(); i++){
        Pos = stones[i].s.getPosition();
        if (Pos.x > 990 || Pos.x < -10){
            stones.erase(stones.begin() + i);
            float a = rand() % 970;
            float b = rand() % 970;
            float x = rand() % 5;
            float y = rand() % 5;
            stones.push_back(Stone(x,y,a,b));
        }
        if (Pos.y > 990 || Pos.y < -10){
            stones.erase(stones.begin() + i);
            float a = rand() % 970;
            float b = rand() % 970;
            float x = rand() % 5;
            float y = rand() % 5;
            stones.push_back(Stone(x,y,a,b));
        }
    }

}

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000,1000), "Curling Simulation");
    bool collide;
    bool rep;
    std::vector<Stone> stones;

    sf::RectangleShape background;
    background.setSize(sf::Vector2f(1000,1000));
    //std::vector<Stone> stones(1,Stone(3,5,60,60));

    sf::CircleShape shape(500.f);
    sf::CircleShape target(375.f);
    sf::CircleShape target1(200.f);
    sf::CircleShape bullseye(75.f);

    background.setFillColor(sf::Color::White);
    shape.setFillColor(sf::Color::Blue);
    target.setFillColor(sf::Color::White);
    target1.setFillColor(sf::Color::Red);
    bullseye.setFillColor(sf::Color::White);

    target.setPosition(125,125);
    target1.setPosition(300,300);
    bullseye.setPosition(425,425);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
        //bounceStone (stones, xmove, ymove);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::T)){
                stones = test(collide, rep);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)){
                stones = bounce(collide, rep);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)){
                stones = random(collide, rep);
            }
            if(event.type == sf::Event::Closed)
                window.close();
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
                window.close();
            }
        }
    for (int i=0; i<stones.size(); i++){
        stones[i].move();
        if (collide)
        stones[i].bounce();
    }
        bounceStone(stones);
        replace(stones);

        window.clear();
        window.draw(background);
        window.draw(shape);
        window.draw(target);
        window.draw(target1);
        window.draw(bullseye);

        for (int j=0; j<stones.size(); j++){
            window.draw(stones[j].s);
        }
        window.display();

    }

    return 0;

}
