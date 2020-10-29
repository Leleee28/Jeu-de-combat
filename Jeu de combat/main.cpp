#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Perso.h"

using namespace std;

int main()
{
    srand(time(0));

    Perso P1 {"El Destructor", 100, 35, 3};
    Perso P2 {"El Tanker", 200, 20, 2};

    cout << "--------------------" << endl;

    bool stop = false;

    while(stop == false) {

        int random = rand() % 2;
        char rep;
        if (random == 0) {

            cout << "A votre tour " << P1.getName() << " !" << endl;
            cout << "Souhaitez vous attaquer ? (A) " << endl;
            cout << "Souhaitez vous vous soignez ? (P) (" << P1.getLife() << "/100) (reste : " << P1.getPotion() << " potions)" << endl;

            cin >> rep;

            while (rep != 'A' && rep != 'a' && rep != 'P' && rep != 'p' ) {

                cout << "Souhaitez vous attaquer ? (A) " << endl;
                cout << "Souhaitez vous vous soignez ? (P) (" << P1.getLife() << "/100) (reste : " << P1.getPotion() << " potions)" << endl;
                cin >> rep;
            }
            if (rep == 'A' || rep == 'a') {
                P1.attack(P2);
                if (P2.isLive() == false) {
                    cout << "P1 a gagné !";
                    stop = true;
                }
            } else if (rep == 'P' || rep == 'p') {
                if (P1.canHeal()) {P1.usePotion();}
                else {cout << "P1 n'as plus de potions ! Tu dois attaquer";}

            }

        } else if (random == 1) {

            cout << "A votre tour " << P2.getName() << " !" << endl;
            cout << "Souhaitez vous attaquer ? (A) " << endl;
            cout << "Souhaitez vous vous soignez ? (P) (" << P2.getLife() << "/200) (reste : " << P2.getPotion() << " potions)" << endl;

            cin >> rep;

            while (rep != 'A' && rep != 'a' && rep != 'P' && rep != 'p' ) {

                cout << "Souhaitez vous attaquer ? (A) " << endl;
                cout << "Souhaitez vous vous soignez ? (P) (" << P2.getLife() << "/200) (reste : " << P2.getPotion() << " potions)" << endl;
                cin >> rep;
            }
            if (rep == 'A' || rep == 'a') {
                P2.attack(P1);
                if (P1.isLive() == false) {
                    cout << "P2 a gagné !";
                    stop = true;
                }
            } else if (rep == 'P' || rep == 'p') {
                if (P2.canHeal()) {P2.usePotion();}
                else {cout << "P2 n'as plus de potions ! Tu dois attaquer";}

            }

        } else {
            cout << "BUG : Détermination du personnage à commencer.";
        }

    }

    cout << endl << "PARTIE TERMINEE !";

    return 0;
}

