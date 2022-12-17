#include "libIncludes.h"

int main(){

    string pW;
    // inputData("Password");

    string uName = inputData("Username");

    checkData(inputData("Password"), pW = inputData("Password"));

    admins.push_back(Admin(uName, pW));

    for(Admin admn: admins) {

        cout << admn.getUsername() << ", " <<admn.getPassword() << endl;

    }

    // userChoiceCheck();


    return 0;
}
