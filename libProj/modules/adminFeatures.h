#pragma once

#include "login.h"
#include "register.h"
#include "userChoice.h"
#include "delay.h"
#include "formatting.h"
#include "dataCheck.h"
#include "classes/data/userList.h"
#include "classes/data/bookList.h"

#include <algorithm>

using namespace std;

void registerNewUser(){

    int smallChoiceVar = 0;

    cout << "Kreirate novog korisnika." << endl;
    straightLine();
    cout << "Da li ce novi korisnik biti administrator sistema? (1 - Ne, 2 - Da)" << endl;

    smallChoiceVar = getUserChoiceNum(1, 2);

    if(smallChoiceVar == 1)
        initReg(false);
    else if(smallChoiceVar == 2)
        initReg(true);
}

void viewExistingUsers(){

    cout << "Postojeci korisnici: " << endl;
    straightLine();

    for(User usr : users){
        cout << "Korisnicko ime -> " << usr.getUsername() << endl;
        cout << "Identifikacioni broj -> " << usr.getUserId() << endl;
        if(usr.getAdminStatus())
            cout << "Korisnik je administrator." << endl;
        else
            cout << "Korisnik nije administrator." << endl;
        straightLine();
    }
    cout << "0 - Nazad" << endl;
    while(getUserChoiceNum(0, 0) != 0){
            straightLine();
    }
}

void deleteExistingUser(){

    string username;
    bool erased = true;
    do {
        cout << "Unesite korisnicko ime korisnika kojeg zelite ukloniti iz sistema." << endl;
        straightLine();
        cout << "Unesite \"X\" da prekinete operaciju." << endl;
        cout << "K. ime -> ";
        getline(cin, username);

        if(username == "X"){

            erased = false;
        } else {

            if(isUserExistant(username)){

                if(getUserAdminStatus(username)){

                    cout << "Brisanje admina iz sistema nije dozvoljeno." << endl;
                    erased = false;
                } else {

                    users.erase(find_if(users.begin(), users.end(),
                    [&](User u){ return u.getUsername() == username; }));
                    erased = false;
                    cout << "Korisnik " << username << " je usjpesno obrisan iz sistema." << endl;
                }

            } else {
                cout << "Uneseni korisnik ne postoji." << endl;
                erased = true;
            }

        }
    } while(erased);
}

void addBook(){

    string name;
    string uniqueCode;
    int quantity;

    cout << "Unesite relevantne podatke o knjizi koju dodajete u sistem." << endl;

    straightLine();

    name = inputData("Ime knjige");

    uniqueCode = inputData("Unikatni kod");

    if(isBookExistant(uniqueCode)){

        cout << "Knjiga sa tim unikatnim kodom vec postoji!" << endl;
    } else {

        cout << "Primjeraka dostupno -> ";
        cin >> quantity;

        fflush(stdin);

        books.push_back(Book(name, uniqueCode, true, quantity));

    }
}

void viewExistingBooks(){

    cout << "Postojece knjige u sistemu:" << endl;
    straightLine();

    for(Book book : books){
        cout << "Naziv knjige -> " << book.getName() << endl;
        cout << "Unikatni kod -> " << book.getUniqueId() << endl;
        cout << "Broj dostupnih primjeraka -> " << book.getQuantityAvailable() << endl;
        straightLine();
    }
    cout << "0 - Nazad" << endl;
    while(getUserChoiceNum(0, 0) != 0){
            straightLine();
    }
}

void deleteExistingBook(){

    string code;
    bool erased = true;
    do {
        cout << "Unesite unikatni kod knjige koju zelite ukloniti iz sistema." << endl;
        straightLine();
        cout << "Unesite \"X\" da prekinete operaciju." << endl;
        cout << "Unikatni kod -> ";
        getline(cin, code);

        if(code == "X"){

            erased = false;
        } else {

            if(isBookExistant(code)){

                books.erase(find_if(books.begin(), books.end(),
                [&](Book b){ return b.getUniqueId() == code; }));
                erased = false;
                cout << "Knjiga sa kodom \"" << code << "\" je usjpesno obrisana iz sistema." << endl;
            } else {
                cout << "Knjiga sa unesenim unikatnim kodom ne postoji." << endl;
                erased = true;
            }
        }
    } while(erased);
}

void adminFeatureSelection(){

    int choiceVar;

    bool logoutInitiated = true;

    while(logoutInitiated){

        cout << "Dostupne administratorske opcije: " << endl;
        straightLine();
        displayMenu(true);
        straightLine();
        choiceVar = getUserChoiceNum(1, 7);

        clearDelay(*dTPtr);

        switch(choiceVar){

        case 1:

            registerNewUser();
            continue;
            break;
        case 2:

            viewExistingUsers();
            break;
        case 3:

            deleteExistingUser();
            break;
        case 4:

            addBook();
            break;
        case 5:

            viewExistingBooks();
            break;
        case 6:

            deleteExistingBook();
            break;
        case 7:
            logoutInitiated = !logoutInitiated;
            cout << "Uspjesno ste odjavljeni." << endl;
            break;
        }
        clearDelay(*dTPtr);
    }
}


