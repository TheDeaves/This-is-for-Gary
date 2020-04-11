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
        string getWelcome();
        string getVerifyName();
        string playerChooseAttackDirection();
        string playerChooseBlockDirection();
        string mainMenuPrompt();

    private:
    string storyLine[25];
    int currentStoryPos = 0;
    int storyLineLength = 0;

};

#endif