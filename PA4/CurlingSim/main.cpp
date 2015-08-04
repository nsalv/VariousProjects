#include <SFML/Graphics.hpp>
#include "stone.hpp"
#include <vector>
#include <iostream>

//Need to work on physics between stones.
//Make function for each individual scenario

//void bounceStone(std::vector<sf::CircleShape> stones, std::vector<int>&xmove, std::vector<int>& ymove){
//    sf::Vector2f stonePos;
//    std::vector<sf::Vector2f> Pos;
//    for (int i=0; i<stones.size(); i++){
//        stonePos = stones[i].getPosition();
//        Pos.push_back(stonePos);
//    }
//
//    //comparing x and y positions of each stone
//    for (int p=0; p<Pos.size(); p++){
//        for (int l=0; l<Pos.size(); l++){
//
//        if (l==p){
//        continue;
//        }
//
//        //determines the distance between the x and y coordinates of each stone
//        int x = Pos[l].x - Pos[p].x;
//        int y = Pos[l].y - Pos[p].y;
//
//        //if two stones are within a diameter of each other, the stones are colliding
//        if (abs(x) <= 60 && abs(y) <= 60 && abs(x) + abs(y) <=60){
//
//        int lvec = pow(xmove[l],2) + pow(ymove[l],2);
//        lvec = sqrt(lvec);
//        int pvec = pow(xmove[p],2) + pow(ymove[p],2);
//        pvec = sqrt(pvec);
//
//
//
////            int temp = xmove[l];
////            int temp1 = ymove[l];
//
//            xmove[l] = -lvec;
//            ymove[l] = -pvec;
//            xmove[p] = lvec;
//            ymove[p] = pvec;
//        }
//        }
//    }
//
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
        float a = rand() % 970;
        float b = rand() % 970;
        float x = rand() % 5;
        float y = rand() % 5;
        stones.push_back(Stone(x,y,a,b));
    }
collide = false;
rep = false;
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

std::vector<Stone> replace(std::vector<Stone> stones){
    sf::Vector2f Pos;
    for (int i=0; i<stones.size(); i++){
        Pos = stones[i].getPosition();
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
    return stones;
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
    if(rep){
        stones = replace(stones);
    }
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
