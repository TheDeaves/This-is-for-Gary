#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>

using namespace std;

class Combat{
    public:
        Combat();
        void increTurn();
        int getTurn();
        int getAnotherRandom();
        int getRandomNum();

        int swingLeft();//LEFT IS 1
        int swingTop();//TOP IS 2
        int swingRight();//RIGHT IS 3
                                        //OPPOSITE BECAUSE THEY ARE FACING EACH OTHER 
                                        // IF THEY == IT IS A BLOCK
        int blockLeft();//RETURNS 3
        int blockTop();//RETURNs 2
        int blockRight();//RETURNS 1

        bool blockCheck(int playerCurrentSwing, int NPCCurrentSwing);//TRUE IF BLOCK
        bool overheadMissChance();//70% chance to miss TRUE IF HIT
    private:
        int turn = 0;
        int playerCurrentSwing;
        int NPCCurrentSwing;
        int randomNum = 0;
        int swingTopMissChance;
};