#include "Character.hpp"

Character::Character()
{
    this->characterName = "Billy";
    this->maxHealth = 15;
    this->attack = 1;
    this->defense = 1;
    this->currentHealth = maxHealth;
    this->currentXP = 0;
    this->neededXP = 2;
    this->level = 1;
    this->gold = 0;
    this->currentStoryPosForLoad = 0;
}

string Character::getCharacterName()
{
    return this->characterName;
}

int Character::getCurrentXP(){
    return this->currentXP;
}

void Character::setCharacterName(string userSetName)
{
    this->characterName = userSetName;
}

int Character::getGold()
{
    return this->gold;
}

int Character::getCurrentStoryPosForLoad(){
    return this->currentStoryPosForLoad;
}
void Character::healthMax()
{ //CURRENTLY HEAL AFTER EVERY FIGHT TO MAX
    this->currentHealth = maxHealth;
}

int Character::takeDamage(int amount)
{ //RETURNS CURRENTHEALTH AFTER DAMAGE FOR DEATH CHECK
    this->currentHealth -= amount;
    return this->currentHealth;
}

//Take Damage action using a passed in attack and defense
int Character::takeDamage(int attack, int defense)
{
    int amount = 0;
    int baseAmount = 3;            //Our base amount of damage is 3
    amount = (attack - defense) + baseAmount; //Our total amount of damage being dealt is the attack - the defense + the base amount
    if (amount < 0)
    { //If attack is negative. Use base amount.
        amount = baseAmount;
    }
    this->currentHealth -= amount; // Subtract the damage from the current health
    return amount; //Retun the amount of damage dealt for testing purposes
}

int Character::getCurrentHP()
{
    return this->currentHealth;
}

int Character::getDefense()
{
    return this->defense;
}

int Character::getAttack()
{
    return this->attack;
}

void Character::gainXP(int amount)
{
    this->currentXP = +amount;
}

bool Character::levelUp()
{  
    if (this->currentXP >= this->neededXP)
    {
        this->level = +1;                                           //CHANGES LEVEL
        this->neededXP = this->neededXP + (this->neededXP / 2) + 1; //CHANGES REQUIRED AMOUNT OF XP

        //UPGRADE PER LEVEL  WILL NEED TO SCALE IN FUTURE
        //MORE ATTRIBUTES IN FUTURE
        this->maxHealth = +3;
        this->attack = +1;  //added attack and defense
        this->defense = +1; //needs to scale better
        return true;
    }
    else
    {
        return false;
    }
}

void Character::gainGold(int amount)
{
    this->gold = +amount;
}

bool Character::Save(int currentStoryPos){
    ofstream saveFile;
        saveFile.open("save1.txt");

        if(!saveFile.is_open()){
            cout << "failed! :(" << endl;
                return false;
        }
        else{
            saveFile << characterName << endl;
            saveFile << maxHealth << endl;
            saveFile << currentHealth << endl;
            saveFile << currentXP << endl;
            saveFile << level << endl;
            saveFile << neededXP << endl;
            saveFile << gold << endl;
            saveFile << attack << endl;
            saveFile << defense << endl;
            saveFile << currentStoryPos << endl;

            cout << "Success!" << endl;

            saveFile.close();

            return true;
        }
}

void Character::Load(){
    ifstream loadFile;

    loadFile.open("save1.txt");

    if(!loadFile.is_open()){
        cout << "failed! :( " << endl;
    }
    else{
        string loadCharacter[10];
        string temp;
        int i = 0;

        while(getline(loadFile, temp)){
            loadCharacter[i] = temp;
                i++;
        }
        this->characterName = loadCharacter[0];
        this->maxHealth = stoi(loadCharacter[1]);
        this->currentHealth = stoi(loadCharacter[2]);
        this->currentXP = stoi(loadCharacter[3]);
        this->level = stoi(loadCharacter[4]);
        this->neededXP = stoi(loadCharacter[5]);
        this->gold = stoi(loadCharacter[6]);
        this->attack = stoi(loadCharacter[7]);
        this->defense = stoi(loadCharacter[8]);
        this->currentStoryPosForLoad = stoi(loadCharacter[9]);

        cout << "Success!" << endl;
        cout << this->characterName << endl;
    }
}