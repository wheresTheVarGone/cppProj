#ifndef REGISTER_H
#define REGISTER_H

#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

const string ADMIN_UNAME = "hehexd";
const string ADMIN_PW = "12345";




string inputData(string msg){

    string temp;
    cout << msg << " -> ";
    getline(cin, temp);
    return temp;
}

void checkData(string username, string password){

    string hehe = "hehexd";
    string hehePw = "12345";


    cout << endl;

    if(password.size() != hehePw.size()){
        cout << password << " " << hehePw << endl;
    }

}

#endif // REGISTER_H
