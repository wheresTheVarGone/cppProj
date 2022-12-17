#include "libIncludes.h"

int main(){

    string pW;


    Admin admin1("Hehe", "112345", 1);

    Admin *ptr = &admin1;

    cout << ptr->getUsername() << endl;
    cout << ptr->getPassword() << endl;

    admins.push_back(admin1);


    // inputData("Password");


    /*
    string uName = inputData("Username");

    if(checkData(inputData("Password"), pW = inputData("Password")))
        cout << "Dobrodosli." << endl;
    else
        cout << "Passwordi se ne poklapaju." << endl;
    */

    for(Admin admn: admins)
        cout << admn.getUsername() << " && " << admn.getPassword() << endl;

    if(admin1.getStatus()){
        cout << "Welcome Admin!";
    }


    return 0;
}
