#pragma once

using namespace std;

class Admin{

    private:
        string username, password;
        bool isAdmin;
    public:

        Admin(string username, string password, bool isAdmin);
        string getUsername();
        string getPassword();
        void setUsername(string username);
        void setPassword(string password);
};

Admin::Admin(string username, string password, bool isAdmin){

    setUsername(username);
    setPassword(password);
    this->isAdmin = isAdmin;
}

string Admin::getUsername(){

    return this->username;
}

string Admin::getPassword(){

    return this->password;
}

void Admin::setUsername(string username){

    this->username = username;
}

void Admin::setPassword(string password){

    this->password = password;
}
