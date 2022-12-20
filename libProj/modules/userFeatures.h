#pragma once

#include "classes/data/bookList.h"
#include "classes/book.h"
#include "adminFeatures.h"

void userFeatureSelection(){

    int choiceVar;

    bool logoutInitiated = true;

    while(logoutInitiated){

        cout << "Dostupne korisnicke opcije: " << endl;
        straightLine();
        displayMenu(false);
        straightLine();
        choiceVar = getUserChoiceNum(1, 4);

        switch(choiceVar){
        case 1:

            break;
        case 2:
            viewExistingBooks();
            break;
        case 3:


            break;
        case 4:


            break;
        case 5:
            logoutInitiated = !logoutInitiated;
            cout << "Uspjesno ste odjavljeni." << endl;
            clearDelay(*dTPtr);
            break;
        }
        clearDelay(*dTPtr);
    }
}
