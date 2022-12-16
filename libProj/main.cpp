
#include "modules/login/register.h"
#include "modules/login/login.h"
#include "modules/userChoice/userChoice.h"

using namespace std;

int main(){

    inputData("Username");

    checkData( inputData("Password"), inputData("Password") );

    return 0;
}
