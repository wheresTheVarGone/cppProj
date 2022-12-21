#pragma once

#include "ops/hash.h"
#include "book.h"

#include <vector>

class User{

    private:

        int userId;
        string username, password;
        bool isAdmin;



    public:
        vector<string> myBooks;
        User(string username, string password, bool isAdmin, int userNum);
        string getUsername();
        string getPassword();
        bool getAdminStatus();
        int getUserId();
        void setUsername(string username);
        void setPassword(string password);
        void addBook(string name);
};

User::User(string username, string password, bool isAdmin, int userNum){

    setUsername(username);
    setPassword(password);
    this->isAdmin = isAdmin;
    this->userId = userNum;
}

string User::getUsername(){

    return this->username;
}

string User::getPassword(){

    return this->password;
}

void User::setUsername(string username){

    this->username = username;
}

void User::setPassword(string password){

    this->password = hashF(password);
}

bool User::getAdminStatus(){

    return this->isAdmin;
}

int User::getUserId(){

    return this->userId;
}

void User::addBook(string name){

    this->myBooks.push_back(name);
}
