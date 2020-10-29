#include "Perso.h"
#include <iostream>

Perso::Perso(string name, int life, int damage, int potion) : p_Name(name), p_Life(life), p_Damage(damage), p_Potion(potion)
{
    cout << "Création personnage..." << endl << "Nom : " << name << endl << "Vie : " << life << endl << "Dégats : " << damage << endl << "Potions : " << potion << " x 50HP" << endl << endl;
}

string Perso::getName() const {
    return p_Name;
}
void Perso::setName(const string name) {
    p_Name = name;
}

int Perso::getLife() const {
    return p_Life;
}
void Perso::setLife(const int life) {
    p_Life = life;
}

int Perso::getDamage() const {
    return p_Damage;
}
void Perso::setDamage(const int damage) {
    p_Damage = damage;
}

int Perso::getPotion() const {
    return p_Potion;
}
void Perso::usePotion() {
    p_Potion--;
    p_Life += 50;
    cout << p_Name << " n'a plus que " << p_Potion << " potions." <<endl;
    cout << "--------------------" << endl;
}

bool Perso::canHeal() const {
    if (p_Potion != 0) {return true;}
    else {return false;}
}
bool Perso::isLive() const {
    if (p_Life > 0) {return true;}
    else {return false;}
}

void Perso::attack(Perso &cible) {
    cout << p_Name << "a attaqué " << cible.p_Name << endl;
    cible.p_Life -= p_Damage;
    if (cible.isLive()) {
        cout << cible.p_Name << " a désormais " << cible.p_Life << " HP." << endl;
        cout << "--------------------" << endl;
    }

}
