#pragma once

#include <iostream>
#include <string>

#include "classes/admin.h"

using namespace std;

bool checkIsInRange(int number, int bottomBorder, int topBorder){

    if(number < bottomBorder || number > topBorder)
        return true;
    return false;
}

string ensureData(string msg, int bottomBorder, int topBorder){

    string temp = "";
    do {
        cout << msg << " -> ";
        getline(cin, temp);

        if(checkIsInRange(temp.size(), bottomBorder, topBorder))
            cout << msg << " treba ciniti 5 do 20 karaktera.\n";

    }while(checkIsInRange(temp.size(), bottomBorder, topBorder));
    return temp;
}

string inputData(string msg){

    if(msg == "Username")
        return ensureData(msg, 5, 20);
    else if(msg == "Password")
        return ensureData(msg, 5, 20);
    else
        cout << "Doslo je do neocekivane greske.\n";
        return "Please be patient.";
}

bool checkData(string inData, string existData){

    if(inData == existData)
        return true;
    return false;
}


