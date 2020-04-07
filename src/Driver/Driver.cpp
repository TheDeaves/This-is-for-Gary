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
			cin >> playerDirectionAttackChoice;	//USER ENTERS LEFT, OVERHEAD, RIGHT
												//IF USER ENTERS 'OTHER' THEY SWING LEFT

			cout << endl; 
			cout << endl;//THIS IS FOR FORMATTING
			cout << endl;

				combat.playerAttackturn(playerDirectionAttackChoice);
			
			cout << endl;
			cout << endl;//THIS IS FOR FORMATTING
			cout << endl;
			
			cout << d.playerChooseBlockDirection() << endl;
				cin >> playerDirectionBlockChoice;	//USER ENTERS LEFT, OVERHEAD, RIGHT
													//IF USER ENTERS 'OTHER' THEY SWING LEFT
			cout << endl;
			cout << endl;//THIS IS FOR FORMATTING
			cout << endl;

				combat.playerDefendTurn(playerDirectionBlockChoice);


			cout << endl;
			cout << endl;//THIS IS FOR FORMATTING
			cout << endl;

			
		combat.increTurn();//TURN INCREMENT

		if(combat.getTurn() == 50){//BASE CASE TO END FIGHT
			break;
		}

	}//END OF COMBAT LOOP

		
}
