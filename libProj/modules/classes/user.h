#pragma once

class User{

    private:

        string username, password;
        bool isAdmin;
    public:

        User(string username, string password, bool isAdmin);
        string getUsername();
        string getPassword();
        bool getAdminStatus();
        void setUsername(string username);
        void setPassword(string password);
};

User::User(string username, string password, bool isAdmin){

    setUsername(username);
    setPassword(password);
    this->isAdmin = isAdmin;
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

    this->password = password;
}

bool User::getAdminStatus(){

    return this->isAdmin;
}
