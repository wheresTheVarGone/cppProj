#pragma once

#include <chrono>
#include <thread>
#include <iostream>
#include <windows.h>

using namespace std;

using namespace std::this_thread;
using namespace std::chrono;

int defaultDelayTime = 3; // Broj sekundi koje ce korisnik cekati nakon izvrsenih operacija
int * dTPtr = &defaultDelayTime;


void clearDelay(int numberOfSeconds){

    while(numberOfSeconds > 0){
        cout << numberOfSeconds << "... ";
        Sleep(1000);
        numberOfSeconds -= 1;
    }

    system("cls");
}
