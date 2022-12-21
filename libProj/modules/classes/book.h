#pragma once

class Book{

    private:
        string name, uniqueId;
        bool isAvailable;
        int quantityAvailable;
    public:
        Book(string name, string uniqueId, bool isAvailable, int quantityAvailable);
        string getName();
        string getUniqueId();
        int getQuantityAvailable();
        void setName(string name);
        void setUniqueId(string uniqueId);
        void setQuantityAvailable(int quantity);
        void decreaseQuantityAvailable();
        void increaseQuantityAvailable();
};

Book::Book(string name, string uniqueId, bool isAvailable, int quantityAvailable){

    setName(name);
    setUniqueId(uniqueId);
    setQuantityAvailable(quantityAvailable);
    this->isAvailable = isAvailable;
}

string Book::getName(){

    return this->name;
}

string Book::getUniqueId(){

    return this->uniqueId;
}

int Book::getQuantityAvailable(){

    return this->quantityAvailable;
}

void Book::setName(string name){

    this->name = name;
}

void Book::setUniqueId(string uniqueId){

    this->uniqueId = uniqueId;
}

void Book::setQuantityAvailable(int quantity){

    this->quantityAvailable = quantity;
}

void Book::decreaseQuantityAvailable(){

    this->quantityAvailable -= 1;
}

void Book::increaseQuantityAvailable(){

    this->quantityAvailable += 1;
}
