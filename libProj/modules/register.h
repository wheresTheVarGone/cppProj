#pragma once

#include <iostream>
#include <string>
#include <string.h>

#include "delay.h"
#include "dataCheck.h"
#include "classes/user.h"
#include "classes/data/userList.h"
#include "formatting.h"

using namespace std;

int userNum = 0;
int * ptr = &userNum;

string inputData(string msg){

    return ensureData(msg, 5, 20);
}

bool initReg(bool isAdmin){

    char *tempUName = new char[20];
    char *tempPWord = new char[20];

    while(true){

        cout << "Registruj novog korisnika:" << endl;
        straightLine();

        strcpy(tempUName, inputData("K. ime ").c_str());

        if(isUserExistant(tempUName)){
            do {

                cout << "Korisnicko ime zauzeto." << endl;
                clearDelay(*dTPtr);
                cout << "Registruj novog korisnika:" << endl;
                strcpy(tempUName, inputData("K. ime ").c_str());

            } while(isUserExistant(tempUName));
        }

        strcpy(tempPWord, inputData("Lozinka").c_str());

        cout << "Ponovno unesite lozinku." << endl;

        if(checkData(tempPWord, inputData("Lozinka"))){

            users.push_back(User(tempUName, tempPWord, isAdmin, userNum));
            *ptr = *ptr + 1;
            straightLine();
            cout << "Uspjesno registrovan korisnik " << tempUName << endl;
            free(tempUName);
            free(tempPWord);
            clearDelay(*dTPtr);
            return true;
        } else {
            straightLine();
            cout << "Lozinke se ne poklapaju, probajte ponovno." << endl;
            clearDelay(*dTPtr);
        }
    }
}


