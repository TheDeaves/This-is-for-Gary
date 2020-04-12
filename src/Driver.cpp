//============================================================================
// Name        : This.cpp
// Author      : TheDeaves, Ryley
// Version     : .01
// Copyright   : Your copyright notice
// Description : :candle: Gary
//============================================================================

#include "Character.cpp"
#include "Combat.cpp"
#include "Dialogue.cpp"
#include "Shop.cpp"
#include "Item.cpp"

#include<iostream>

using namespace std;

int main(){

	Character playerCharacter;
	Dialogue d;

	playerCharacter.setAttack(50);// H A X


	string userMenuInput;//FOR USER INPUT IN MENUS
	string playerChoice;// FOR USER INPUT IN GAME LOOP

	bool characterSetupLoop = true;//THE GREAT BOOLEAN WALL OF GAME LOOP MANIPULATION
	bool mainMenuLoop = true;
	bool combatLoop = false;
	bool shopLoop = false;
	bool mapLoop = false;
	bool characterLevelUpLoop = false;
	bool saveLoop = false;
	bool errorCatchUserChoice = false;
	bool campLoop = false;
	

	string userSetName;


while(true){//GAME PLAY LOOP

	while(mainMenuLoop){//MAIN MENU LOOP FOR LOADING
		cout << d.mainMenuPrompt() << endl;
			cin >> userMenuInput;

		if(userMenuInput.find('L') != string::npos || userMenuInput.find('l') != string::npos){
			cout << "Loading..." << endl;
				playerCharacter.Load();
					d.setCurrentStoryPos(playerCharacter.getCurrentStoryPosForLoad());
						characterSetupLoop = false;
							mainMenuLoop = false;
								break;
		}
		else{
				cout << d.getNextStory() << endl;
					d.incrementStory();
				cout << d.getNextStory() << endl;

				cout << d.getWelcome() << endl;

				mainMenuLoop = false;

				break;// STARTS NEW GAME
		}
	}//END OF MAIN MENU LOOP

	while(characterSetupLoop){//SET UP LOOP

		while(characterSetupLoop){//NAME LOOP
			cin >> userSetName;
	
		cout << d.getVerifyName() << userSetName << "? \" he mutters, the fear apparent on his face. You notice no one else in the arena with the two of you... (yes to continue)" << endl;
			cin >> userMenuInput;

		if(userMenuInput.find('y') != string::npos || userMenuInput.find('Y') != string::npos){//string::npos == -1 || IF TRUE sets name
			playerCharacter.setCharacterName(userSetName);
				cout << "Before you can ask him his name in return, the man screams and lunges at you! Defend yourself!" << "!" << endl;
					characterSetupLoop = true;

				cout << endl;
				cout << endl;//THIS IS FOR FORMATTING
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

	while(true){//START OF USER CHOOSING WHAT TO DO NEXT
	d.incrementInGameDay();
		cout << "Day " << d.getInGameDay() << endl;

		cout << "What would you like to do? " << endl;//USER INPUTS CHOICE, ELSE GETS ERRONEOUS INPUT
			cin >> playerChoice;

		//STARTING HERE IS THE TREE OF IF() TO LET THE PLAYER CHOOSE WHAT TO DO
		if(playerChoice.find("fight") != string::npos || playerChoice.find("combat") != string::npos){
			combatLoop = true;
		}else if(playerChoice.find("save") != string::npos || playerChoice.find("Save") != string::npos){
			saveLoop = true;
		}else if(playerChoice.find("camp") != string::npos){
			campLoop = true;
		}else if(playerChoice.find("shop") != string::npos){
			shopLoop = true;
		}else{
			errorCatchUserChoice = true;
		}

		while(saveLoop){//SAVE LOOP
			cout << "Saving..." << endl;
				playerCharacter.Save(d.getCurrentStoryPos());
					saveLoop = false;
						errorCatchUserChoice = false;
		}//END OF SAVE LOOP

		Combat combat;
		Character NPC;
		string playerDirectionAttackChoice;
		string playerDirectionBlockChoice; // THESE STAY
		bool playerDidDamage = false;
		bool playerBlockedDamage = true;
		bool levelUp = false;

		while(combatLoop){//COMBAT LOOP

			cout << d.getNextStory() << endl;
				d.incrementStory();				//TWO LINES FROM STORY FILE PER COMBAT LOOP
			cout << d.getNextStory() << endl;
				d.incrementStory();

				cout << endl; 
				cout << endl;//THIS IS FOR FORMATTING
				cout << endl;

			cout << "Round " << combat.getTurn() << endl;
				Sleep(1000);

			cout << d.playerChooseAttackDirection() << endl;
				cin >> playerDirectionAttackChoice;	//USER ENTERS LEFT, OVERHEAD, RIGHT
													//IF USER ENTERS 'OTHER' THEY SWING LEFT
				if(playerDirectionAttackChoice == "f" || playerDirectionAttackChoice == "F") { //If choice is F toggle fast forward
					combat.toggleFastForward();
				}
				cout << endl; 
				cout << endl;//THIS IS FOR FORMATTING
				cout << endl;

					playerDidDamage = combat.playerAttackturn(playerDirectionAttackChoice);//TREAT AS BLACK BOX
																							// COUTS COME FROM HERE
					Sleep(1000);
					
					if(playerDidDamage){
						cout << "Amount of damage dealt: "<< NPC.takeDamage(playerCharacter.getAttack(), NPC.getDefense()) << endl; //Test to see damage dealt
						cout << "Current HP: " << playerCharacter.getCurrentHP() << endl;
						cout << "Enemy HP: " << NPC.getCurrentHP() << endl;
						NPC.takeDamage(playerCharacter.getAttack(), NPC.getDefense()); //changed from the base of 3.
							if(NPC.getCurrentHP() <= 0){
								cout << "You won the fight!" << endl;
									NPC.healthMax();
										playerCharacter.healthMax();
											playerCharacter.levelUp(); //Need to look more into leveling
												//playerCharacter.gainXP(15);
													break; 
							}
					}
				
				cout << endl;
				cout << endl;//THIS IS FOR FORMATTING
				cout << endl;

					Sleep(1000);
				
				cout << d.playerChooseBlockDirection() << endl;
					cin >> playerDirectionBlockChoice;	//USER ENTERS LEFT, OVERHEAD, RIGHT
														//IF USER ENTERS 'OTHER' THEY SWING LEFT
				if(playerDirectionBlockChoice == "f" || playerDirectionBlockChoice == "F") { //If choice is F toggle fast forward
					combat.toggleFastForward();
				}
				cout << endl;
				cout << endl;//THIS IS FOR FORMATTING
				cout << endl;

					playerBlockedDamage = combat.playerDefendTurn(playerDirectionBlockChoice);

					Sleep(1000);

					if(!playerBlockedDamage){
						cout << "Amount of damage taken: "<< playerCharacter.takeDamage(NPC.getAttack(), playerCharacter.getDefense()) << endl; //Test to see damage taken
						cout << "Current HP: " << playerCharacter.getCurrentHP() << endl; // Needed to see HP values
						cout << "Enemy HP: " << NPC.getCurrentHP() << endl; 
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
	
			/*Maybe add a level up menu and allow the player to choose to level a specific attribute or skill*/	
		while(characterLevelUpLoop){//LEVEL UP LOOP
			
			
		}//END OF LEVEL UP LOOP

		while(campLoop){
			playerCharacter.healthMax();
				cout << d.campHealth() << endl;

				//ADD OPTIONS HERE
				//MOAR LOOPS

				cout << d.campEndOfDay() << endl;
					campLoop = false;
		}
		//STORY LOOP 
			/*story loop maybe for player actions? Moving on map buying gear etc.*/		

		while(shopLoop){
			Shop s;
				s.listItems();
			
			cout << d.checkGold(playerCharacter.getGold()) << endl;
			
			shopLoop = false;
		}
	
		while(errorCatchUserChoice){
			cout << "Nothing happens..." << endl;
				errorCatchUserChoice = false;
		}

	}//END OF USER CHOOSE WHAT TO DO NEXT


}//END OF GAMEPLAY OVERLOOP
}
