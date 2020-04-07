#include "Combat.hpp"

using namespace std;

Combat::Combat(){
    srand(time(0));
        this->randomNum = rand() % 3 + 1;
}

void Combat::increTurn(){
    this->turn = this->turn + 1;
}

int Combat::getTurn(){
    return this->turn;
}

int Combat::getAnotherRandom(){
    srand(time(NULL));
        int temp = this->randomNum;
            this->randomNum = rand() % 3 + 1;
           // cout << "FIRST RANDOM: " << this->randomNum << endl;

    if(this->randomNum == temp){
        this->randomNum = rand() % 3 + 1;
      //  cout << "SECOND RANDOM: " << this->randomNum << endl;
    }
    return this->randomNum;
}

int Combat::getRandomNum(){
    return this->randomNum;
}

int Combat::swingLeft(){
    return 1;
}

int Combat::swingTop(){
    return 2;
}

int Combat::swingRight(){
    return 3;
}

int Combat::blockLeft(){
    return 3;
}

int Combat::blockTop(){
    return 2;
}

int Combat::blockRight(){
    return 1;
}

bool Combat::blockCheck(int playerCurrentSwing, int NPCCurrentBlock){
    if(playerCurrentSwing == NPCCurrentBlock){
        return true;
    }
    else{
        return false;
    }
}

bool Combat::overheadMissChance(){//TRUE IF HIT
    srand(time(NULL));
        this->swingTopMissChance = rand() % 10 + 1;
    if(this->swingTopMissChance >= 7){
        return true;
    }
    else{
        return false;
    }
}