#pragma once

#include "login.h"
#include "register.h"
#include "userChoice.h"
#include "delay.h"
#include "classes/data/userList.h"
#include "formatting.h"
#include "dataCheck.h"

#include <algorithm>

using namespace std;

void registerNewUser(){

    int smallChoiceVar = 0;

    cout << "Kreirate novog korisnika." << endl;
    straightLine();
    cout << "Da li ce novi korisnik biti administrator sistema? (1 - Ne, 2 - Da)" << endl;

    smallChoiceVar = getUserChoiceNum(1, 2);

    if(smallChoiceVar == 1)
        initReg(false);
    else if(smallChoiceVar == 2)
        initReg(true);
}

void viewExistingUsers(){

    cout << "Postojeci korisnici: " << endl;
    straightLine();

    for(User usr : users){
        cout << "Korisnicko ime -> " << usr.getUsername() << endl;
        cout << "Identifikacioni broj -> " << usr.getUserId() << endl;
        if(usr.getAdminStatus())
            cout << "Korisnik je administrator." << endl;
        else
            cout << "Korisnik nije administrator." << endl;
        straightLine();
    }
    cout << "0 - Nazad" << endl;
    while(getUserChoiceNum(0, 0) != 0){
            straightLine();
    }
    clearDelay(*dTPtr);
}

void deleteExistingUser(){

    string username;
    bool erased = true;
    do {
        cout << "Unesite korisnicko ime korisnika kojeg zelite ukloniti iz sistema." << endl;
        straightLine();
        cout << "K. ime -> ";
        getline(cin, username);

        if(isUserExistant(username)){

            if(getUserAdminStatus(username)){

                cout << "Brisanje admina iz sistema nije dozvoljeno." << endl;
                erased = false;
            } else {

                users.erase(find_if(users.begin(), users.end(),
                [&](User u){ return u.getUsername() == username; }));
                erased = false;
                cout << "Korisnik " << username << " je usjpesno obrisan iz sistema." << endl;
            }

        } else {
            cout << "Uneseni korisnik ne postoji." << endl;
            erased = true;
        }

    } while(erased);
    clearDelay(*dTPtr);
}

void changePassword(){


}

void adminFeatureSelection(){

    int choiceVar;

    bool logoutInitiated = true;

    while(logoutInitiated){

        cout << "Dostupne administratorske opcije: " << endl;
        straightLine();
        displayMenu(true);
        straightLine();
        choiceVar = getUserChoiceNum(1, 7);

        switch(choiceVar){
        case 1:
            clearDelay(*dTPtr);
            registerNewUser();
            break;
        case 2:
            clearDelay(*dTPtr);
            viewExistingUsers();
            break;
        case 3:
            clearDelay(*dTPtr);
            deleteExistingUser();
            break;
        case 7:
            logoutInitiated = !logoutInitiated;
            cout << "Uspjesno ste odjavljeni." << endl;
            clearDelay(*dTPtr);
            break;
        }
    }
}


