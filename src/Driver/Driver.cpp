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
	bool characterSetupLoop = false;

	string userSetName;

	cout << d.getNextStory() << endl;
		d.incrementStory();
	cout << d.getNextStory() << endl;

	cout << d.getWelcome() << endl;

	while(!characterSetupLoop){//SET UP LOOP

		while(!characterSetupLoop){//NAME LOOP
			cin >> userSetName;
	
		cout << d.getVerifyName() << userSetName << "? \" he mutters, the fear apparent on his face. You notice no one else in the arena with the two of you... (yes to continue)" << endl;
			cin >> userMenuInput;

		if(userMenuInput.find('y') != string::npos || userMenuInput.find('Y') != string::npos){//string::npos = -1 || IF TRUE sets name
			playerCharacter.setCharacterName(userSetName);
				cout << "Before you can ask him his name in return, the man screams and lunges at you! Defend yourself!" << "!" << endl;
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
	bool playerDidDamage = false;
	bool playerBlockedDamage = true;
	bool levelUp = false;

	while(true){//COMBAT LOOP
	

		cout << "Round " << combat.getTurn() << endl;
		cout << d.playerChooseAttackDirection() << endl;
			cin >> playerDirectionAttackChoice;	//USER ENTERS LEFT, OVERHEAD, RIGHT
												//IF USER ENTERS 'OTHER' THEY SWING LEFT

			cout << endl; 
			cout << endl;//THIS IS FOR FORMATTING
			cout << endl;

				playerDidDamage = combat.playerAttackturn(playerDirectionAttackChoice);

				if(playerDidDamage){
					cout << "Amount of damage dealt: "<< NPC.takeDamage(playerCharacter.getAttack(), NPC.getDefense()) << endl; //Test to see damage dealt
					NPC.takeDamage(playerCharacter.getAttack(), NPC.getDefense()); //changed from the base of 3.
						if(NPC.getCurrentHP() <= 0){
							cout << "You won the fight!" << endl;
								NPC.healthMax();
									break; 
					}
				}
			
			cout << endl;
			cout << endl;//THIS IS FOR FORMATTING
			cout << endl;
			
			cout << d.playerChooseBlockDirection() << endl;
				cin >> playerDirectionBlockChoice;	//USER ENTERS LEFT, OVERHEAD, RIGHT
													//IF USER ENTERS 'OTHER' THEY SWING LEFT
			cout << endl;
			cout << endl;//THIS IS FOR FORMATTING
			cout << endl;

				playerBlockedDamage = combat.playerDefendTurn(playerDirectionBlockChoice);

				if(!playerBlockedDamage){
					cout << "Amount of damage taken: "<< playerCharacter.takeDamage(NPC.getAttack(), playerCharacter.getDefense()) << endl; //Test to see damage taken
					playerCharacter.takeDamage(NPC.getAttack(), playerCharacter.getDefense());
						if(playerCharacter.getCurrentHP() <= 0){
							cout << "GAME OVER." << endl;
								exit;
						}
				}

			cout << endl;
			cout << endl;//THIS IS FOR FORMATTING
			cout << endl;

			
		combat.increTurn();//TURN INCREMENT

		if(combat.getTurn() == 50){//BASE CASE TO END FIGHT
			break;
		}

	}//END OF COMBAT LOOP

	//LEVEL UP LOOP
	while (levelUp) //levelup loop added
	{
		
	}
	
	//STORY LOOP 
		/*story loop maybe for player actions? Moving on map buying gear etc.*/		
}
