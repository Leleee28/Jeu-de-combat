#ifndef PERSO_H
#define PERSO_H

#include <string>
using namespace std;

class Perso
{
    public:
        Perso(string name, int life, int damage, int potion);

        string getName() const;
        void setName(const string name);

        int getLife() const;
        void setLife(const int life);

        int getDamage() const;
        void setDamage(const int name);

        int getPotion() const;
        void usePotion();

        bool canHeal() const;
        bool isLive() const;

        void attack(Perso &cible);

    protected:

    private:
        string p_Name;
        int p_Life;
        int p_Damage;
        int p_Potion;
};

#endif
