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
        this->swingTopMissChanceNum = rand() % 10 + 1;
    if(this->swingTopMissChanceNum >= 7){
        return true;
    }
    else{
        return false;
    }
}

void Combat::playerAttackturn(string playerDirectionAttackChoice){
	if(playerDirectionAttackChoice.find("overhead") != string::npos){
		this->playerCurrentSwing = swingTop();
			this->swingTopMissChance = overheadMissChance();
				cout << "You viscously swing your weapon at the enemies head..."<< endl;
	}
	else if(playerDirectionAttackChoice.find("left") != string::npos){
		this->playerCurrentSwing = swingLeft();
			cout << "You swing your weapon at the enemies left side..." << endl;
	}
	else if(playerDirectionAttackChoice.find("right") != string::npos){
		this->playerCurrentSwing = swingRight();
			cout << "You swing your weapon at the enemies right side..." << endl;
	}
	else{
		cout << "You swing your weapon at the enemies left side..." << endl;
			this->playerCurrentSwing = 1;
	}
		this->NPCCurrentBlock = getAnotherRandom();

		cout << "NPC BLOCK: " << this->NPCCurrentBlock << endl;
		cout << "PLAYER SWING: " << this->playerCurrentSwing << endl;


	if(blockCheck(playerCurrentSwing, NPCCurrentBlock) && !this->swingTopMissChance){//IF BLOCKED OR MISS
		if(blockCheck(playerCurrentSwing, NPCCurrentBlock)){//BLOCK
			cout << "The enemy brings their shield up and blocks!" << endl;
		}
	}else if(blockCheck(playerCurrentSwing, NPCCurrentBlock) && playerCurrentSwing == 2){//BLOCK OVERHEAD
		cout << "The enemy parries your blow away from their head!" << endl;
	}
	else if(playerCurrentSwing == 2 && !swingTopMissChance){//MISS OVERHEAD
		cout << "You swing wide and miss!" << endl;
	}
	else if(!blockCheck(playerCurrentSwing, NPCCurrentBlock)){//HIT
		cout << "You hit the enemy!" << endl;
	}
}

void Combat::playerDefendTurn(string playerDirectionBlockChoice){
    if(playerDirectionBlockChoice.find("overhead") != string::npos){
		this->playerCurrentBlock = blockTop();
			cout << "You attempt to protect your head..."<< endl;
	}
	else if(playerDirectionBlockChoice.find("left") != string::npos){
		this->playerCurrentBlock = blockLeft();
		    cout << "You attempt to protect your left side..." << endl;
	}
	else if(playerDirectionBlockChoice.find("right") != string::npos){
		this->playerCurrentBlock = blockRight();
			cout << "You attempt to protect your right side..." << endl;
	}
	else{
		cout << "You attempt to protect your left side..." << endl;
			this->playerCurrentBlock = 1;
	}
		this->NPCCurrentSwing = getAnotherRandom();

		cout << "NPC SWING: " << this->NPCCurrentSwing << endl;
		cout << "PLAYER BLOCK: " << this->playerCurrentBlock << endl;

			if(blockCheck(this->NPCCurrentSwing, this->playerCurrentBlock) && !this->swingTopMissChance){//IF BLOCKED OR MISS
				if(blockCheck(this->NPCCurrentSwing, this->playerCurrentBlock)){//BLOCK
					cout << "You bring your shield up at the last second and block!" << endl;
				}
			}else if(blockCheck(this->NPCCurrentSwing, this->playerCurrentBlock) && this->playerCurrentSwing == 2){//BLOCK OVERHEAD
				cout << "You parry the enemy blade away from your head!" << endl;
			}
			else if(this->NPCCurrentSwing == 2 && !this->swingTopMissChance){//MISS OVERHEAD
					cout << "The enemy wildly misses!" << endl;
			}
			else if(!blockCheck(this->NPCCurrentSwing, this->playerCurrentBlock)){//HIT
				cout << "They enemy hits you!" << endl;
			}

}