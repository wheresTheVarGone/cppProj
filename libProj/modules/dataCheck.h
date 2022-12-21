#pragma once

using namespace std;

#include "classes/user.h"
#include "classes/book.h"
#include "classes/data/userList.h"
#include "classes/data/bookList.h"

bool checkIsInRange(int number, int bottomBorder, int topBorder){

    if(number < bottomBorder || number > topBorder)
        return true;
    return false;
}

string ensureData(string msg, int bottomBorder, int topBorder){

    string temp = "";
    do {
        cout << msg << "\t-> ";
        getline(cin, temp);

        if(checkIsInRange(temp.size(), bottomBorder, topBorder)){
            cout << msg << " treba ciniti " << bottomBorder << " do " << topBorder << " karaktera.\n";
            straightLine();
        }


    }while(checkIsInRange(temp.size(), bottomBorder, topBorder));
    return temp;
}

bool checkData(string inData, string existData){

    if(inData == existData)
        return true;
    return false;
}

bool isUserExistant(string username){

    for(User usrs: users){
        if(username == usrs.getUsername())
            return true;
    }
    return false;
}

int getUserId(string username){

    for(User usrs: users){
        if(username == usrs.getUsername())
            return usrs.getUserId();
    }
    return -1;

}

bool getUserAdminStatus(string username){

    for(User usrs: users){
        if(username == usrs.getUsername())
            return usrs.getAdminStatus();
    }
    return false;
}

bool isBookExistant(string name){

    for(Book book : books){
        if(name == book.getUniqueId())
            return true;
    }
    return false;
}

bool isBookNameExistant(string name){

    for(Book book : books){
        if(name == book.getName())
            return true;
    }
    return false;
}
