#pragma once

#include "classes/data/bookList.h"
#include "classes/book.h"
#include "adminFeatures.h"

char *strUName = new char[20];

void userAddBook(){

    cout << "Molimo unesite ime knjige koju zelite iznajmiti (ako postoji)." << endl;
    straightLine();

    string bookName = inputData("Ime knjige");
    string uName;

    cout << "Molimo potvrdite svoje korisnicko ime." << endl;
    straightLine();

    do {

        uName = inputData("K. ime");

        if(!isUserExistant(uName)){
            cout << "Nepostojece korisnicko ime, molimo unesite ponovno." << endl;
            straightLine();
        }

    } while(!isUserExistant(uName));


    strcpy(strUName, uName.c_str());


    if (isBookNameExistant(bookName)){

        for(Book &book : books){

            if(bookName == book.getName()){

                if(book.getQuantityAvailable() > 0){
                    book.decreaseQuantityAvailable();
                    for(User & usr : users){

                        if(uName == usr.getUsername()){
                            usr.addBook(bookName);
                        }
                    }
                } else {
                    cout << "Knjiga vise nije dostupna." << endl;
                    straightLine();
                }
            }
        }
    } else {
        cout << "Knjiga sa unesenim imenom ne postoji" << endl;
    }
}

void checkMyBooks(){

    int i = 1;

    for(User usr : users){

        if(strUName == usr.getUsername()){

            if(usr.myBooks.size() == 0) {

                cout << "Trenutno nemate iznajmljenih knjiga." << endl;
                straightLine();
            } else {

                for( auto book : usr.myBooks ) {
                    cout << i << ". - " << book << endl;
                    i++;
                    straightLine();
                }
                cout << "Kraj pregleda vasih knjiga." << endl;
                straightLine();
                cout << "0 - Nazad" << endl;
                while(getUserChoiceNum(0, 0) != 0){
                    straightLine();
                }
            }

        }

    }

}

void userFeatureSelection(){

    int choiceVar;

    bool logoutInitiated = true;

    while(logoutInitiated){

        cout << "Dostupne korisnicke opcije: " << endl;
        straightLine();
        displayMenu(false);
        straightLine();
        choiceVar = getUserChoiceNum(1, 5);

        clearDelay(*dTPtr);

        switch(choiceVar){

        case 1:
            checkMyBooks();
            break;
        case 2:
            viewExistingBooks();
            break;
        case 3:
            userAddBook();
            break;
        case 4:

            break;
        case 5:
            logoutInitiated = !logoutInitiated;
            cout << "Uspjesno ste odjavljeni." << endl;
            break;
        }
        clearDelay(*dTPtr);
    }
}
