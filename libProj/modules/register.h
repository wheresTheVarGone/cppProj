#pragma once

#include <iostream>
#include <string>

#include "dataCheck.h"
#include "classes/user.h"
#include "classes/data/userList.h"
#include <string.h>

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

    char *tempStr1 = new char[20];
    char *tempStr2 = new char[20];

    strcpy(tempStr1, inputData("Username").c_str());
    strcpy(tempStr2, inputData("Password").c_str());

    if(checkData(tempStr2, inputData("Password"))){

        users.push_back(User(tempStr1, tempStr2, isAdmin, userNum));
        *ptr = *ptr + 1;
        free(tempStr1);
        free(tempStr2);
        return true;
    }
    cout << "Lozinke se ne poklapaju." << endl;
    return false;
}


