#pragma once

#include "ops/hash.h"
#include "book.h"

#include <vector>
#include <algorithm>

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
        int ammountOfBooks();
        void setUsername(string username);
        void setPassword(string password);
        void addBook(string name);
        bool hasBook(string name);
        void removeBook(string name);
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

void User::removeBook(string name){

    this->myBooks.erase(find_if(this->myBooks.begin(), this->myBooks.end(),
    [&](string bookName){ return bookName == name; }));

}

bool User::hasBook(string name){

    for( auto book : this->myBooks ) {
        if(name == book)
            return true;
    }
    return false;
}

int User::ammountOfBooks(){

    return this->myBooks.size();
}
