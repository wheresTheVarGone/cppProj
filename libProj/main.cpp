#include "libIncludes.h"

int main(){

    applyConsoleFont();

    initReg(true);

    while(true){

    if(login())
        adminFeatureSelection();
    else
        userFeatureSelection();
    }
    return 0;
}
