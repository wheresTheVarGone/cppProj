#pragma once

class Admin{

    private:

        string username, password;
        bool isAdmin;
    public:

        Admin(string username, string password);
        string getUsername();
        string getPassword();
        void setUsername(string username);
        void setPassword(string password);
};

Admin::Admin(string username, string password){

    setUsername(username);
    setPassword(password);
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
