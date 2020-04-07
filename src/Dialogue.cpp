#include "Dialogue.hpp"

using namespace std;

Dialogue::Dialogue(){
    this->currentStoryPos = 0;
    loadStoryLineFile();
}

string Dialogue::getNextStory(){
    return storyLine[currentStoryPos];
}

void Dialogue::loadStoryLineFile(){
    ifstream storyInFile;
    string storyString;

    storyInFile.open("Texts/Storyline.txt");

    if(!storyInFile.is_open()){
        cout << "Storyline file failed to open." << endl;
    }

    if(storyInFile.is_open()){
        while(getline(storyInFile, storyString)){
                this->storyLine[this->currentStoryPos] = storyString;

                cout << storyString << endl;
                    this->currentStoryPos =+ 1;
        }
    }
    storyInFile.close();
}

string Dialogue::getWelcome(){
    return "Welcome! What would you like to be called?";
}

string Dialogue::getVerifyName(){
    return ". Is this correct?";
}

string Dialogue::playerChooseDirection(){
    return "Which direction would you like to swing? (left, overhead, right)";
}