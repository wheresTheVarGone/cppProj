#pragma once

#include "register.h"
#include "userChoice.h"
#include "delay.h"

using namespace std;

void registerNewUser(){

    int smallChoiceVar = 0;

    straightLine();
    cout << "Kreirate novog korisnika." << endl;
    cout << "Da li ce novi korisnik biti administrator sistema? (1 - Ne, 2 - Da)" << endl;

    smallChoiceVar = getUserChoiceNum();

    if(smallChoiceVar == 1)
        initReg(false);
    else if(smallChoiceVar == 2)
        initReg(true);
}

void featureSelection(){

    int choiceVar;

    bool logoutInitiated = true;

    while(logoutInitiated){

        displayMenu(true);
        choiceVar = getUserChoiceNum();

        switch(choiceVar){
        case 1:
            registerNewUser();
            break;
        case 7:

            logoutInitiated = !logoutInitiated;
            cout << "Zelim ti sve najgore!" << endl;
            clearDelay(1);
            break;
        }
    }
}
