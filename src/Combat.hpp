#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <windows.h>

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

        bool blockCheck(int playerCurrentSwing, int NPCCurrentBlock);//TRUE IF BLOCK
        bool overheadMissChance();//70% chance to miss TRUE IF HIT

        bool playerAttackturn(string playerDirectionAttackChoice);//TRUE IF PLAYER HITS
        bool playerDefendTurn(string playerDirectionBlockChoice);//TRUE IF PLAYER BLOCKS
    private:
        int turn = 0;
        int playerCurrentSwing = 0;
        int NPCCurrentSwing = 0;
        int randomNum = 0;
        int swingTopMissChanceNum = 0;
        int NPCCurrentBlock = 0;
        bool swingTopMissChance = false;
        int playerCurrentBlock = 0;
};