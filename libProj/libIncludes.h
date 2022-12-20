#pragma once

#include <windows.h>
#include <cwchar>

#include "modules/register.h"
#include "modules/login.h"
#include "modules/userChoice.h"
#include "modules/dataCheck.h"
#include "modules/classes/user.h"
#include "modules/classes/data/userList.h"
#include "modules/adminFeatures.h"

using namespace std;

void applyConsoleFont(){

    CONSOLE_FONT_INFOEX csSet;
    csSet.cbSize = sizeof(csSet);
    csSet.nFont = 0;
    csSet.dwFontSize.X = 0;
    csSet.dwFontSize.Y = 24;
    csSet.FontFamily = FF_DONTCARE;
    csSet.FontWeight = FW_NORMAL;
    std::wcscpy(csSet.FaceName, L"Lucida Console");
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &csSet);
}
