#include <SFML/Graphics.hpp>
#include "stone.hpp"
#include <vector>
#include <iostream>
#include <cmath>

//fix the trig for collisions
//make sure that when stones are randomly generated they don't overlap.

//void bounceStone(std::vector<Stone>& stones){
//    sf::Vector2f stonePos;
//    std::vector<sf::Vector2f> Pos;
//    for (int i=0; i<stones.size(); i++){
//        stonePos = stones[i].s.getPosition();
//        Pos.push_back(stonePos);
//    }
//
//    //comparing x and y positions of each stone
//    for (int p=0; p<Pos.size(); p++){
//        for (int l=0; l<Pos.size(); l++){
//
//        if (p==l){
//            continue;
//        }
//
//        //determines the distance between the x and y coordinates of each stone
//        float d = sqrt(pow((Pos[l].x-Pos[p].x),2)+pow((Pos[l].y-Pos[p].y),2));
//
//        if (d<=80){
//
////            stones[p].s.setFillColor(sf::Color::Yellow);
////            stones[l].s.setFillColor(sf::Color::Green);
//
//            sf::Vector2f n = (Pos[p]-Pos[l]);
//            float unitnx = n.x/d;
//            float unitny = n.y/d;
//            float a1 = stones[p].velocity.x*unitnx+stones[p].velocity.y*unitny;
//            float a2 = stones[l].velocity.x*unitnx+stones[l].velocity.y*unitny;
//            float optP = (2.0*(a1-a2)/20);
//
//            sf::Vector2f temp = stones[l].velocity;
//
//            stones[l].velocity = stones[l].velocity; //sf::Vector2f(10,10);
//            stones[p].velocity = stones[p].velocity;
//
//            std::cout<<"P:"<<stones[p].velocity.x<<" "<<stones[p].velocity.y<<std::endl;
//            std::cout<<"L:"<<stones[l].velocity.x<<" "<<stones[l].velocity.y<<std::endl;
//
//
//
//
//
//        }
//        }
//    }
//
////    for (int j=0; j<stones.size(); j++){
////        stones[j].s.setFillColor(sf::Color::Black);
////    }
//}
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
        float a = rand() % 930 + 35;
        float b = rand() % 930 + 35;
        float x = rand() % 20 + -10;
        float y = rand() % 20 + -10;
        stones.push_back(Stone(x,y,a,b));
    }
collide = false;
rep = true;
return stones;
}

std::vector<Stone> bounce(bool& collide, bool& rep){

std::vector<Stone> stones;
    for (int i=0; i<10; i++){
        float a = rand() % 930 + 35;
        float b = rand() % 930 + 35;
        float x = rand() % 20 + -10;
        float y = rand() % 20 + -10;
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
            float a = rand() % 930 + 35;
            float b = rand() % 930 + 35;
            float x = rand() % 20 + -10;
            float y = rand() % 20 + -10;
            stones.push_back(Stone(x,y,a,b));
        }
        if (Pos.y > 990 || Pos.y < -10){
            stones.erase(stones.begin() + i);
            float a = rand() % 930 + 35;
            float b = rand() % 930 + 35;
            float x = rand() % 20 + -10;
            float y = rand() % 20 + -10;
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
        stones[i].bounceStone(stones);
        if (collide)
        stones[i].bounce();
    }
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
