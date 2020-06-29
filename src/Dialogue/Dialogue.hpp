#ifndef DIALOGUE_HPP
#define DIALOGUE_HPP

#include <iostream>
#include <fstream>

using namespace std;

class Dialogue{
    public:
        Dialogue();
        string getNextStory();
        void incrementStory();
        void loadStoryLineFile();
        void setCurrentStoryPos(int pos);
        int getCurrentStoryPos();
        int getInGameDay();
        void incrementInGameDay();
        string getWelcome();
        string getVerifyName();
        string playerChooseAttackDirection();
        string playerChooseBlockDirection();
        string mainMenuPrompt();
        string campHealth();
        string campEndOfDay();
        string checkGold(int amount);

    private:
    string storyLine[25];
    int currentStoryPos = 0;
    int storyLineLength = 0;
    int inGameDay = 0;

};

#endif