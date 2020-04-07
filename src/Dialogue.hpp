
#include <iostream>
#include <fstream>

using namespace std;

class Dialogue{
    public:
        Dialogue();
        string getNextStory();
        void loadStoryLineFile();
        string getWelcome();
        string getVerifyName();
        string playerChooseAttackDirection();
        string playerChooseBlockDirection();

    private:
    string storyLine[25];
    int currentStoryPos;
    int storyLineLength = 1;

};