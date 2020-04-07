//============================================================================
// Name        : This.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "../Character.cpp"
#include "../Combat.cpp"
#include "../Dialogue.cpp"

#include <iostream>

using namespace std;

int main(){

	Character playerCharacter;
	Dialogue d;

	string userMenuInput;

string userSetName;

	cout << d.getWelcome() << endl;

	while(true){//SET UP LOOP

		while(true){//NAME LOOP
			cin >> userSetName;
	
		cout << userSetName << d.getVerifyName() << endl;
			cin >> userMenuInput;

		if(userMenuInput.find('y') != string::npos){//string::npos = -1 || IF TRUE sets name
			playerCharacter.setCharacterName(userSetName);
				cout << "You are now known as " << playerCharacter.getCharacterName() << "!" << endl;
				cout << endl;
				cout << endl;
				cout << endl;
			break;
		}
		else{
			cout << "What would you like to be called?" << endl;
		}

		}//END OF NAME LOOP
		break;
		//TODO ADD BACK STORY OPTIONS WITH SOME EFFECT 

	}//END OF SET UP LOOP


	Combat combat;
	Character NPC;
	string playerDirectionChoice;
	int playerCurrentSwing = 0;
	int NPCCurrentSwing = 0;
	bool swingTopMissChance = false;//TRUE IF HIT

	while(true){//COMBAT LOOP

		cout << "It is Round " << combat.getTurn() << endl;
			cout << endl;
		cout << d.playerChooseDirection() << endl;
			cin >> playerDirectionChoice;//USER ENTERS LEFT, OVERHEAD, RIGHT 

			cout << endl; 
			cout << endl;//THIS IS FOR FORMATTING
			cout << endl;

				if(playerDirectionChoice.find("overhead") != string::npos){
					playerCurrentSwing = combat.swingTop();
					swingTopMissChance = combat.overheadMissChance();
						cout << "You viscously swing your weapon at the enemies head..."<< endl;
				}
				else if(playerDirectionChoice.find("left") != string::npos){
					playerCurrentSwing = combat.swingLeft();
						cout << "You swing your weapon at the enemies left side..." << endl;
				}
				else if(playerDirectionChoice.find("right") != string::npos){
					playerCurrentSwing = combat.swingRight();
						cout << "You swing your weapon at the enemies left side..." << endl;
				}
				else{
					playerCurrentSwing = 1;
				}
			NPCCurrentSwing = combat.getAnotherRandom();
			//cout << "NPC BLOCK: " << NPCCurrentSwing << endl;
			//cout << "PLAYER SWING: " << playerCurrentSwing << endl;

			if(combat.blockCheck(playerCurrentSwing, NPCCurrentSwing) && !swingTopMissChance){//IF BLOCKED OR MISS
				if(combat.blockCheck(playerCurrentSwing, NPCCurrentSwing)){
					cout << "The enemy brings their shield up and blocks!" << endl;
				}
			}else if(combat.blockCheck(playerCurrentSwing, NPCCurrentSwing) && playerCurrentSwing == 2){
				cout << "The enemy parries your blow!" << endl;
			}
			else if(playerCurrentSwing == 2 && !swingTopMissChance){
					cout << "You swing wide and miss!" << endl;
			}
			else if(!combat.blockCheck(playerCurrentSwing, NPCCurrentSwing)){
				cout << "You hit the enemy!" << endl;
			}
			
			cout << endl;
			cout << endl;
			
			
			
		combat.increTurn();//TURN INCREMENT

		if(combat.getTurn() == 50){//BASE CASE TO END FIGHT
			break;
		}

	}//END OF COMBAT LOOP

		
}
