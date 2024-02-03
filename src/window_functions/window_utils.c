#include "../estruturas.h"


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
         printf("[+] Debug: Icone nao encontrado\n");
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
    HINSTANCE hInstance = GetModuleHandle(NULL);
    HWND hButton = CreateWindowEx(
        0,                              // Extended styles
        "BUTTON",                       // Predefined class
        text,                           // Button text
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, // Styles
        x,                              // x position
        y,                              // y position
        SIZE_BUTTONS_Y,                 // Button width
        30,                             // Button height
        hwnd,                           // Parent window
        (HMENU)id,                      // Button ID
        hInstance,                      // Instance handle
        NULL                            // Pointer not needed
    );

    // Set button font to default GUI font
    SendMessage(hButton, WM_SETFONT, (WPARAM)GetStockObject(DEFAULT_GUI_FONT), TRUE);

    // Set button visual styles
    LONG_PTR style = GetWindowLongPtr(hButton, GWL_STYLE);
    style |= BS_FLAT; // Add flat button style
    SetWindowLongPtr(hButton, GWL_STYLE, style);

}

void create_Input_Label(HWND hwnd, const char* text, int id, int x, int y) {
    // Create a static label
    HWND hLabel = CreateWindow(
        "STATIC",                   // Predefined class; static label
        text,                       // Label text
        WS_VISIBLE | WS_CHILD,      // Styles; visible and child window
        x,                          // X position
        y,                          // Y position
        100,                        // Label width
        20,                         // Label height
        hwnd,                       // Parent window
        NULL,                       // No menu
        (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), // Instance handle
        NULL                        // Additional parameters
    );

    // Create an input field
    HWND hInput = CreateWindow(
        "EDIT",                     // Predefined class; edit control
        "",                         // Default text; empty
        WS_VISIBLE | WS_CHILD | WS_BORDER, // Styles; visible, child window, with border
        x + 110,                    // X position; right after the label
        y,                          // Y position; same as label
        200,                        // Input field width
        20,                         // Input field height
        hwnd,                       // Parent window
        (HMENU)id,                  // Control identifier
        (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), // Instance handle
        NULL                        // Additional parameters
    );

    // Set font to the label and input field for a consistent look
    SendMessage(hLabel, WM_SETFONT, (WPARAM)GetStockObject(DEFAULT_GUI_FONT), TRUE);
    SendMessage(hInput, WM_SETFONT, (WPARAM)GetStockObject(DEFAULT_GUI_FONT), TRUE);
}

void create_Static_Label(HWND hwnd, const char* text, int x, int y, int width, int height, int id) {
    // Create a static control for the label
    HWND hLabel = CreateWindow(
        "STATIC",                   // Predefined class; static label
        text,                       // Label text
        WS_VISIBLE | WS_CHILD,      // Styles; visible and child window
        x,                          // X position
        y,                          // Y position
        width,                      // Label width
        height,                     // Label height
        hwnd,                       // Parent window
        (HMENU)id,                  // Control identifier
        (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), // Instance handle
        NULL                        // Additional parameters
    );

    // Set font to the label for a consistent look
    SendMessage(hLabel, WM_SETFONT, (WPARAM)GetStockObject(DEFAULT_GUI_FONT), TRUE);
}

// Function to display an error message
void error_message(char* message, char* title) {
    // Display an error message box
    MessageBox(
        NULL,                       // No owner window
        message,                    // Message to display
        title,                      // Title of the message box
        MB_ICONERROR | MB_OK        // Style; error icon and OK button
    );
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

    // Define and register the window class
    WNDCLASS wc = {0};
    wc.lpfnWndProc = wndProc;          // Window procedure
    wc.hInstance = GetModuleHandle(NULL); // Instance handle
    wc.lpszClassName = className;      // Class name
    RegisterClass(&wc);                // Register the class

    // Create the window
    HWND hwnd = CreateWindow(
        wc.lpszClassName,              // Class name
        windowTitle,                   // Window title
        windowStyle,                   // Window style
        x,                             // X position
        y,                             // Y position
        width,                         // Width
        height,                        // Height
        NULL,                          // Parent window
        NULL,                          // Menu
        wc.hInstance,                  // Instance handle
        NULL                           // Additional parameters
    );

    // Customize the window
    removeExpandButton(hwnd);         // Remove the expand button
    set_icon(hwnd, "./assets/images/appIcon.ico"); // Set the window icon
    // FreeConsole(); // Hide the console window 

    // Then show the window
    ShowWindow(hwnd, SW_SHOWNORMAL); // Show the window with normal state

    // Message loop
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);       // Translate virtual-key messages
        DispatchMessage(&msg);        // Dispatch messages to the window procedure
    }

    // Return the handle to the created window
    return hwnd;
}

#pragma GCC diagnostic pop 