#pragma once

#include "register.h"
#include "dataCheck.h"
#include "delay.h"

void greetUser(bool userStatus, string username){

    if(userStatus)
        cout << "Dobrodosao sistemski administratore, " << username << "\n";
    else
        cout << "Dobrodosao, " << username << "\n";
}


bool login(){

    char *tempUName = new char[20];
    char *tempPWord = new char[20];

    while(true) {

        cout << "Molimo unesite odgovarajuce podatke kako bi se ulogovali kao postojeci korisnik." << endl;
        straightLine();

        strcpy(tempUName, inputData("K. ime ").c_str());
        strcpy(tempPWord, inputData("Lozinka").c_str());

        if(isUserExistant(tempUName)){

            for(User usr : users) {

                if(usr.getUsername() == tempUName) {

                    if(usr.getPassword() == hashF(tempPWord)) {

                        straightLine();
                        free(tempUName);
                        free(tempPWord);
                        bool status = usr.getAdminStatus();

                        if(status) {
                            clearDelay(*dTPtr);
                            greetUser(status, usr.getUsername());
                            straightLine();
                            return true;
                        } else {

                            clearDelay(*dTPtr);
                            greetUser(status, usr.getUsername());
                            straightLine();
                            return false;
                        }
                    }
                }
            }
        }
        straightLine();
        cout << "Pogresna lozinka ili korisnicko ime. Pokusajte ponovno." << endl;
        clearDelay(*dTPtr);

    }
}

