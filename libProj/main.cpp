#include "libIncludes.h"

int main(){

    Admin admin1("Boris", "12345");

    string tempUsername = "";

    do {

    cout << "Please enter your username -> ";
    getline(cin, tempUsername);

    if(admin1.getUsername() == tempUsername)
        cout << "Success!" << endl;
    else
        cout << "Please reconsider." << endl;


    } while (true);





    return 0;
}
