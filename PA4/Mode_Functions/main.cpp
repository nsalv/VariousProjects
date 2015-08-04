

//The inputs for my stone class are (velocity.x, velocity.y, position.x, position.y)
//This function creates the test mode where there are only two stones, one in the middle with no velocity and one with a velocity towards the stone.
//it creates a vector of stoones that fulfill this and takes a boolean input to determine whether or not the stones bounce of the boudnaries of the window
std::vector<Stone> test(bool& collide, bool& rep) {

    std::vector<Stone> stones;
    stones.push_back(Stone(0,0,500,500));
    stones.push_back(Stone(10,10,50,50));

    collide = true;
    rep = false;
    return stones;

}

//random mode where 10 stones are given a velocity in a random direction
//if a stone leaves the ice, the stone is replaced by a new one
//takes two bools as input, one to determine if the stones bounce off the walls and the other to determine if the replace function should be called
//in the while loop
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

//Same basic principle as the random functione except this time the stones bounce off the wall instead of leaving the window
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

//function to replace the stones that leave the window in the random mode.
//still buggy, could be an issue of when I call it in the while loop or an issue with the code here. Not sure yet.
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
