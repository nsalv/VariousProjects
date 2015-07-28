#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

//Why does the stone only move when I move the mouse?
//Need to work on physics between stones.
//Need to divide things into functions for increased modularity (word?)
//need to adjust bounceStones so that it takes into account entire area of stones
//Make function for each individual scenario

//class stone: public sf::CircleShape{
//
//public:
//sf::Vector2f Pos = stone.getPosition();
//
//
//private:
//int radius = 15;
//
//}

void bounce(const std::vector<sf::CircleShape> stones, std::vector<int>& xmove,std::vector<int>& ymove){
    sf::Vector2f stonePos;

    for (int i=0; i<stones.size(); i++){
        stonePos = stones[i].getPosition();
        if (stonePos.x >= 965 || stonePos.x <=0){
            xmove[i]= -xmove[i];
        }

        if (stonePos.y >=965 || stonePos.y <=0){
            ymove[i] = -ymove[i];
        }
    }
}

void bounceStone(std::vector<sf::CircleShape> stones, std::vector<int>&xmove, std::vector<int>& ymove){
    sf::Vector2f stonePos;
    std::vector<sf::Vector2f> Pos;
    for (int i=0; i<stones.size(); i++){
        stonePos = stones[i].getPosition();
        Pos.push_back(stonePos);
    }

    //comparing x and y positions of each stone
    for (int p=0; p<Pos.size(); p++){
        for (int l=0; l<Pos.size(); l++){

        if (l==p){
        continue;
        }
        int x = Pos[l].x - Pos[p].x;
        int y = Pos[l].y - Pos[p].y;
//        int px = Pos[p].x;
//        int py = Pos[p].y;

        if (abs(x) <= 30 && abs(y) <= 30){
            int temp = xmove[l];
            int temp1 = ymove[l];
            stones[2].setFillColor(sf::Color::Green);

            xmove[l] = ymove[p];
            ymove[l] = xmove[p];
            xmove[p] = temp1;
            ymove[p] = temp;
        }
        }
        }
//
//        if (Pos[l].x - Pos[p].x >= -30 && Pos[l].y - Pos[p].y >= -30){
//            int temp = xmove[l];
//            int temp1 = ymove[l];
//            stones[2].setFillColor(sf::Color::Green);
//
//            xmove[l] = ymove[p];
//            ymove[l] = xmove[p];
//            xmove[p] = temp1;
//            ymove[p] = temp;
//        }
//
//        if (Pos[l].x == Pos[p].x + 30 && Pos[l].y == Pos[p].y - 30){
//            int temp = xmove[l];
//            int temp1 = ymove[l];
//            stones[2].setFillColor(sf::Color::Green);
//
//            xmove[l] = ymove[p];
//            ymove[l] = xmove[p];
//            xmove[p] = temp1;
//            ymove[p] = temp;
//        }
//
//        if (Pos[l].x == Pos[p].x - 30 && Pos[l].y == Pos[p].y + 30){
//            int temp = xmove[l];
//            int temp1 = ymove[l];
//            stones[2].setFillColor(sf::Color::Green);
//
//            xmove[l] = ymove[p];
//            ymove[l] = xmove[p];
//            xmove[p] = temp1;
//            ymove[p] = temp;
//        }
//
//        }
//    }


}

//void random(std::vector<sf::CircleShape> stones){}
int main()
{
    //std::vector<Object> stones (1,CircleShape(50));
    sf::RenderWindow window(sf::VideoMode(1000,1000), "Curling Simulation");

    sf::RectangleShape background;
    background.setSize(sf::Vector2f(1000,1000));
    std::vector<sf::CircleShape> stones(2,sf::CircleShape(30.f));

    sf::CircleShape shape(500.f);
    sf::CircleShape target(375.f);
    sf::CircleShape target1(200.f);
    sf::CircleShape bullseye(75.f);

    background.setFillColor(sf::Color::White);
    shape.setFillColor(sf::Color::Blue);
    target.setFillColor(sf::Color::White);
    target1.setFillColor(sf::Color::Red);
    bullseye.setFillColor(sf::Color::White);

    for (int i=0; i<stones.size();i++){
        stones[i].setFillColor(sf::Color::Black);
        stones[i].setOrigin(10,10);
    }



    target.setPosition(125,125);
    target1.setPosition(300,300);
    bullseye.setPosition(425,425);
    stones[1].setPosition(470,470);

    sf::Vector2f stonePos;
    std::vector<int> xmove;
    xmove.push_back(1);
    xmove.push_back(2);
    std::vector<int> ymove;
    ymove.push_back(3);
    ymove.push_back(4);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {

        //passes a vector of velocities to the stones.
        for (int k=0; k<stones.size(); k++){
            stones[k].move(xmove[k],ymove[k]);

        }
        bounce (stones, xmove, ymove);
        bounceStone (stones, xmove, ymove);

            if(event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(background);
        window.draw(shape);
        window.draw(target);
        window.draw(target1);
        window.draw(bullseye);

        for (int j=0; j<stones.size(); j++){
            window.draw(stones[j]);
        }
        window.display();

    }

    return 0;

}
