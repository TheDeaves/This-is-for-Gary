#include <string>

using namespace std;

class Character{
    private:
        string characterName;
        int maxHealth;
        int currentHealth;
        int currentXP;
        int level;
        int neededXP;
        int gold;
        int attack;
        int defense;

    public:
        Character();
        void setCharacterName(string userSetName);
        int getCurrentXP();
        string getCharacterName();
        int getGold();

        //COMBAT
        void healthMax();//CURRENTLY HEAL AFTER EVERY FIGHT TO MAX
        int takeDamage(int amount);//RETURNS CURRENTHEALTH AFTER DAMAGE FOR DEATH CHECK
        int takeDamage(int attack, int defense);
        int getCurrentHP();
        int getAttack();
        int getDefense();
        void gainXP(int amount);
        bool levelUp();//LEVELS UP ATTRIBUTES
        void gainGold(int amount);
};