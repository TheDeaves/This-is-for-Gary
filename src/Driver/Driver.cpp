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

		if(userMenuInput.find('y') != string::npos || userMenuInput.find('Y') != string::npos){//string::npos = -1 || IF TRUE sets name
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
	string playerDirectionAttackChoice;
	string playerDirectionBlockChoice;
	int playerCurrentSwing = 0;
	int NPCCurrentSwing = 0;
	int playerCurrentBlock = 0;
	int NPCCurrentBlock = 0;
	bool swingTopMissChance = false;//TRUE IF HIT

	while(true){//COMBAT LOOP

		cout << "Round " << combat.getTurn() << endl;
		cout << d.playerChooseAttackDirection() << endl;
			cin >> playerDirectionAttackChoice;//USER ENTERS LEFT, OVERHEAD, RIGHT 

			cout << endl; 
			cout << endl;//THIS IS FOR FORMATTING
			cout << endl;

				if(playerDirectionAttackChoice.find("overhead") != string::npos){
					playerCurrentSwing = combat.swingTop();
					swingTopMissChance = combat.overheadMissChance();
						cout << "You viscously swing your weapon at the enemies head..."<< endl;
				}
				else if(playerDirectionAttackChoice.find("left") != string::npos){
					playerCurrentSwing = combat.swingLeft();
						cout << "You swing your weapon at the enemies left side..." << endl;
				}
				else if(playerDirectionAttackChoice.find("right") != string::npos){
					playerCurrentSwing = combat.swingRight();
						cout << "You swing your weapon at the enemies right side..." << endl;
				}
				else{
						cout << "You swing your weapon at the enemies left side..." << endl;
					playerCurrentSwing = 1;
				}
			NPCCurrentBlock = combat.getAnotherRandom();
			cout << "NPC BLOCK: " << NPCCurrentBlock << endl;
			cout << "PLAYER SWING: " << playerCurrentSwing << endl;


			if(combat.blockCheck(playerCurrentSwing, NPCCurrentBlock) && !swingTopMissChance){//IF BLOCKED OR MISS
				if(combat.blockCheck(playerCurrentSwing, NPCCurrentBlock)){//BLOCK
					cout << "The enemy brings their shield up and blocks!" << endl;
				}
			}else if(combat.blockCheck(playerCurrentSwing, NPCCurrentBlock) && playerCurrentSwing == 2){//BLOCK OVERHEAD
				cout << "The enemy parries your blow away from their head!" << endl;
			}
			else if(playerCurrentSwing == 2 && !swingTopMissChance){//MISS OVERHEAD
					cout << "You swing wide and miss!" << endl;
			}
			else if(!combat.blockCheck(playerCurrentSwing, NPCCurrentBlock)){//HIT
				cout << "You hit the enemy!" << endl;
			}
			
			cout << endl;
			cout << endl;//THIS IS FOR FORMATTING
			cout << endl;
			
			//cout << d.playerChooseBlockDirection() << endl;
			//	cin >> playerDirectionBlockChoice;
			
		combat.increTurn();//TURN INCREMENT

		if(combat.getTurn() == 50){//BASE CASE TO END FIGHT
			break;
		}

	}//END OF COMBAT LOOP

		
}
