
#include <iostream>
#include <fstream>

using namespace std;

class Dialogue{
    public:
        Dialogue();
        string getNextStory();
        void incrementStory();
        void loadStoryLineFile();
        string getWelcome();
        string getVerifyName();
        string playerChooseAttackDirection();
        string playerChooseBlockDirection();

    private:
    string storyLine[25];
    int currentStoryPos = 0;
    int storyLineLength = 2;

};