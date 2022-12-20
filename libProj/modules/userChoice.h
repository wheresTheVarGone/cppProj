#pragma once

#include <iostream>
#include <typeinfo>

string adminFeatures = "1 - Dodaj novog korisnika\n2 - Pregledaj postojece korisnike\n3 - Izmijeni postojeceg korisnika\n4 - Obrisi postojeceg korisnika\n7 - Odjavi se\n";
string userFeatures = "Coming soon.\n";

int adminFeaturesNum;
int userFeaturesNum;

using namespace std;

void displayMenu(bool isAdmin){
    if(isAdmin)
        cout << adminFeatures;
    else
        cout << userFeatures;
}

int getUserChoiceNum(){

    int choice;
    cout << "Unesite cijeli broj kao svoj izbor -> ";
    while ( !(cin >> choice) ) {
        cin.clear();
        cin.ignore(256,'\n');
        cout << "\nMolimo unesite cijeli broj umjesto karaktera.\n\n";
        cout << "Unesite cijeli broj kao svoj izbor -> ";
    }
    fflush(stdin);
    return choice;
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




