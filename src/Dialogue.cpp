#include "Dialogue.hpp"

using namespace std;

Dialogue::Dialogue(){
    this->currentStoryPos = 0;
    loadStoryLineFile();
}

string Dialogue::getNextStory(){
        return this->storyLine[this->currentStoryPos];
}

void Dialogue::loadStoryLineFile(){
    ifstream storyInFile;
    string storyString;

    storyInFile.open("Texts/Storyline.txt");

    if(!storyInFile.is_open()){
        cout << "Storyline file failed to open." << endl;
    }

    if(storyInFile.is_open()){
        int i = 0;

        while(getline(storyInFile, storyString)){
                this->storyLine[i] = storyString;
                    this->storyLineLength =+ 1;
                        i++;
        }
    }
    storyInFile.close();
}

void Dialogue::setCurrentStoryPos(int pos){
    this->currentStoryPos = pos;
}

int Dialogue::getCurrentStoryPos(){
    return this->currentStoryPos;
}

void Dialogue::incrementStory(){
    this->currentStoryPos = this->currentStoryPos + 1;
}

string Dialogue::getWelcome(){
    return "A dirty man walks out beside you into the desert coliseum and he quickly asks your name...";
}

string Dialogue::getVerifyName(){
    return "\"Did you say ";
}

string Dialogue::playerChooseAttackDirection(){
    return "Which direction would you like to swing? (left, overhead, right, F for fast Forward)";
}

string Dialogue::playerChooseBlockDirection(){
    return "Which direction would you like to block? (left, overhead, right, F for fast Forward)";
}

string Dialogue::mainMenuPrompt(){
    return "Welcome! Would you like to start a new game or load a previous save?";
}