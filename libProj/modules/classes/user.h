#pragma once

class User{

    private:

        string username, password;
    public:

        User(string username, string password);
        string getUsername();
        string getPassword();
        void setUsername(string username);
        void setPassword(string password);
};

User::User(string username, string password){

    setUsername(username);
    setPassword(password);
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
