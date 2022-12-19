#pragma once

#include <iostream>
#include <string>
#include <string.h>

#include "dataCheck.h"
#include "classes/user.h"
#include "classes/data/userList.h"


using namespace std;

int userNum = 0;
int *ptr = &userNum;

string inputData(string msg){

    if(msg == "Username")
        return ensureData(msg, 5, 20);
    else if(msg == "Password")
        return ensureData(msg, 5, 20);
    else
        cout << "Doslo je do neocekivane greske.\n";
        return "Please be patient.";
}

bool initReg(bool isAdmin){

    char *tempUName = new char[20];
    char *tempPWord = new char[20];

    while(true){

        cout << "Registruj novog korisnika:" << endl;

        strcpy(tempUName, inputData("Username").c_str());

        if(isUserExistant(tempUName)){
            do {

                cout << "Korisnicko ime zauzeto." << endl;
                strcpy(tempUName, inputData("Username").c_str());

            } while(isUserExistant(tempUName));
        }

        strcpy(tempPWord, inputData("Password").c_str());

        cout << "Ponovite password." << endl;

        if(checkData(tempPWord, inputData("Password"))){

            users.push_back(User(tempUName, tempPWord, isAdmin, userNum));
            *ptr = *ptr + 1;
            cout << "Uspjesno registrovan korisnik " << tempUName << endl;
            free(tempUName);
            free(tempPWord);
            return true;
        } else {
            cout << "Lozinke se ne poklapaju, probajte ponovno." << endl;
        }
    }
}


