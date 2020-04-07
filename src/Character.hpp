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

    public:
        Character();
        void setCharacterName(string userSetName);
        string getCharacterName();

};