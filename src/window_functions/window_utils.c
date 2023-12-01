#include "window_utils.h"

void removeExpandButton(HWND hwnd){
    LONG_PTR style = GetWindowLongPtr(hwnd, GWL_STYLE);
    style = style & ~WS_MAXIMIZEBOX; 
    SetWindowLongPtr(hwnd, GWL_STYLE, style);
    SetWindowPos(hwnd, NULL, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE | SWP_NOZORDER | SWP_FRAMECHANGED);
                }

void set_icon(HWND hwnd, char* path){

    HICON hIcon = (HICON)LoadImage(NULL, path, IMAGE_ICON, 0, 0, LR_LOADFROMFILE);
    if (hIcon != NULL)
        SendMessage(hwnd, WM_SETICON, ICON_BIG, (LPARAM)hIcon);           
    else
         printf("Window Debug: Icone nao encontrado\n");
}

void rmvBin() {
    int result = confirm_message("Deseja apagar os arquivos binarios?", "Aviso");

    if (result == IDYES) {
        int deleteResult = system("del src\\bin\\*.dat");
        int deleteResult2 = system("del src\\bin\\partitions\\*.dat");
    }
}


#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wint-to-pointer-cast" 
#pragma GCC diagnostic ignored "-Wimplicit-function-declaration"

void createButton(HWND hwnd, const char* text, int id, int x, int y) {
    CreateWindow("BUTTON", text, WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, x, y, SIZE_BUTTONS_Y, 30, hwnd, (HMENU)id, NULL, NULL);
}

void create_Input_Label(HWND hwnd, const char* text, int id, int x, int y) {
    CreateWindow("STATIC", text, WS_VISIBLE | WS_CHILD, x, y, 100, 20, hwnd, NULL, NULL, NULL);
    CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, x + 100, y, x+200, 20, hwnd, (HMENU)id, NULL, NULL);
}

void create_Static_Label(HWND hwnd, const char* text, int x, int y, int width, int height, int id) {
    CreateWindow("STATIC", text, WS_VISIBLE | WS_CHILD, x, y, width, height, hwnd, NULL, NULL, (HMENU)id);
}

void error_message(char* message, char* title) {
    MessageBox(NULL, message, title, MB_ICONERROR | MB_OK);
}

void hideConsoleWindow() {
    HWND hWnd = GetConsoleWindow();

    if (hWnd != NULL) {
        ShowWindow(hWnd, SW_HIDE);
    }
}

int confirm_message(char* message, char* title) {
    return MessageBox(NULL, message, title, MB_ICONQUESTION | MB_YESNO);
    
}

HWND create_and_run_window(WNDPROC wndProc, const char* className, const char* windowTitle, DWORD windowStyle, int x, int y, int width, int height) {


    //FreeConsole();
    WNDCLASS wc = {0};
    wc.lpfnWndProc = wndProc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = className;
    RegisterClass(&wc);

    HWND hwnd = CreateWindow(wc.lpszClassName, windowTitle, windowStyle, x, y, width, height, NULL, NULL, GetModuleHandle(NULL), NULL);
    removeExpandButton(hwnd);
    set_icon(hwnd, "./assets/images/appIcon.ico");
    ShowWindow(hwnd, SW_SHOWDEFAULT);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return hwnd;
}

#pragma GCC diagnostic pop 