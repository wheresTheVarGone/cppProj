#include "libIncludes.h"

int main(){
    applyConsoleFont();

    initReg(true);

    while(true){

    if(login())
        adminFeatureSelection();
    else
        return 0;
    }




    return 0;
}
