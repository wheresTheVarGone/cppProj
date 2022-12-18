#include "libIncludes.h"

int main(){

    while(true){
        if(initReg(true)){
            cout << users[*ptr - 1].getUserId() << endl;
        }
        cout << users[*ptr-1].getPassword() << endl;
    }

    return 0;
}
