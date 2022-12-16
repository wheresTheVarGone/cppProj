#ifndef USERCHOICE_H
#define USERCHOICE_H

#include <iostream>
#include <typeinfo>

using namespace std;

void displayMenu(){

    cout << "1 - Unesi novi zapis\n2 - Izmijeni postojeci zapis\n3 - Pregledaj postojece zapise\n4 - Obrisi postojeci zapis\n";
}

int getUserChoiceNum(){

    displayMenu();

    int choice;
    cout << "Unesite cijeli broj kao svoj izbor -> ";
    while ( !(cin >> choice) ) {
        cin.clear();
        cin.ignore(256,'\n');
        cout << "\nMolimo unesite cijeli broj umjesto karaktera.\n\n";
        displayMenu();
        cout << "Unesite cijeli broj kao svoj izbor -> ";
    }
    return choice;
}

bool checkIsInRange(int number, int bottomBorder, int topBorder){

    if(number < bottomBorder || number > topBorder)
        return true;
    return false;
}

int userChoiceCheck(){

    int choiceNum;
    do {

        choiceNum = getUserChoiceNum();

        if( checkIsInRange(choiceNum, 1, 4) )
            cout << "\nMolimo ponovite unos (1-4).\n\n";

    } while( checkIsInRange(choiceNum, 1, 4));
    return choiceNum;
}


#endif // USERCHOICE_H




