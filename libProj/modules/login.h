#pragma once

#include "register.h"
#include "dataCheck.h"

void greetUser(bool userStatus, string username){

    if(userStatus)
        cout << "Dobrodosao sistemski administratore, " << username;
    else
        cout << "Dobrodosao, " << username;
}


bool login(){

    char *tempUName = new char[20];
    char *tempPWord = new char[20];

    while(true) {

        cout << "Molimo unesite svoje podatke kako bi se ulogovali kao postojeci korisnik." << endl;

        strcpy(tempUName, inputData("Username").c_str());
        strcpy(tempPWord, inputData("Password").c_str());

        if(isUserExistant(tempUName)){

            for(User usr : users) {

                if(usr.getUsername() == tempUName) {

                    if(usr.getPassword() == hashF(tempPWord)) {

                        free(tempUName);
                        free(tempPWord);

                        bool status = usr.getAdminStatus();

                        if(status) {
                            greetUser(status, usr.getUsername());
                            return true;
                        } else {
                            greetUser(status, usr.getUsername());
                            return false;
                        }
                    }
                }
            }
        }
        cout << "Pogresan password ili username." << endl;
    }
}

