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

    public:
        Character();
        void setCharacterName(string userSetName);
        string getCharacterName();
        int getGold();

        //COMBAT
        void healthMax();//CURRENTLY HEAL AFTER EVERY FIGHT TO MAX
        int takeDamage(int amount);//RETURNS CURRENTHEALTH AFTER DAMAGE FOR DEATH CHECK
        int getCurrentHP();
        void gainXP(int amount);
        bool levelUp();//LEVELS UP ATTRIBUTES
        void gainGold(int amount);
};