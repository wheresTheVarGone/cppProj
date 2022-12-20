#pragma once

#include <iostream>
#include <typeinfo>

string adminFeatures = "1 - Dodaj novog korisnika\n2 - Pregledaj postojece korisnike\n3 - Obrisi postojeceg korisnika\n7 - Odjavi se\n";
string userFeatures = "Coming soon.\n";

using namespace std;

void displayMenu(bool isAdmin){

    if(isAdmin)
        cout << adminFeatures;
    else
        cout << userFeatures;
}

int getUserChoiceNum(int bottomBorder, int topBorder){

    int choice;

    do{

        cout << "Unesite cijeli broj kao svoj izbor -> ";
        while ( !(cin >> choice) ) {
            cin.clear();
            cin.ignore(256,'\n');
            cout << "\nMolimo unesite cijeli broj umjesto karaktera.\n";
            straightLine();
            cout << "Unesite cijeli broj kao svoj izbor -> ";
        }
        fflush(stdin);

        if(checkIsInRange(choice, bottomBorder, topBorder))
            cout << "Molimo ponovite unos (" << bottomBorder << " - " << topBorder << ")." << endl;

    } while (checkIsInRange(choice, bottomBorder, topBorder));
    return choice;
}





