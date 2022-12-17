#include "libIncludes.h"

int main(){

    string pW;
    /*

    Admin admin1("Hehe", "112345", 1);

    Admin *ptr = &admin1;

    cout << ptr->getUsername() << endl;
    cout << ptr->getPassword() << endl;

    inputData("Password");

    */

    string uName = inputData("Username");

    if(checkData(inputData("Password"), pW = inputData("Password")))
        cout << "Dobrodosli." << endl;
    else
        cout << "Passwordi se ne poklapaju." << endl;


    return 0;
}
