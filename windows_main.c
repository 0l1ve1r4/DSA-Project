#include <windows.h>
#include <stdio.h>

#include "./window_functions/window_book_functions.c"
#include "./window_functions/window_employee_functions.c"

#define DISTANCIA_BOTOES_X 50
#define TAMANHO_BOTOES_Y 160


/*
    Aqui jaz, um pedaço de minha alma, que nunca mais voltará.

    Guilherme Oliveira Santos, 2023. Sistemas de Informação, UFOP.

    Para compilar, use o comando abaixo no terminal: gcc -o window ./*.c

*/

LRESULT CALLBACK WindowProc_Main(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CREATE: {
        
            CreateWindow("BUTTON", "Adicionar Livro", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 10, 0, TAMANHO_BOTOES_Y, 30, hwnd, (HMENU)1, NULL, NULL);
            CreateWindow("BUTTON", "Buscar Livro", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 10, DISTANCIA_BOTOES_X*1, TAMANHO_BOTOES_Y, 30, hwnd, (HMENU)2, NULL, NULL);
            CreateWindow("BUTTON", "Registrar Funcionario", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 10, DISTANCIA_BOTOES_X*2, TAMANHO_BOTOES_Y, 30, hwnd, (HMENU)3, NULL, NULL);
            CreateWindow("BUTTON", "Buscar Funcionario", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 10, DISTANCIA_BOTOES_X*3, TAMANHO_BOTOES_Y, 30, hwnd, (HMENU)4, NULL, NULL);
            break;
        }
        case WM_COMMAND: {
            int wmId = LOWORD(wParam);
            switch (wmId) {
                case 1:
                    insert_Book();
                    break;

                case 2:
                    search_Book();
                    break;


                case 3:
                    insert_employee();
                    break;



            }
            break;
        }
        case WM_DESTROY: {
            PostQuitMessage(0);
            break;
        }
        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}

int main() {
    // Registrar a classe da janela
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WindowProc_Main;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "MyWindowClass";
    RegisterClass(&wc);

    // Criar a janela
    HWND hwnd = CreateWindow("MyWindowClass", "Sistema Biblioteca", WS_OVERLAPPEDWINDOW, 100, 100, 400, 300, NULL, NULL, GetModuleHandle(NULL), NULL);

    ShowWindow(hwnd, SW_SHOWDEFAULT);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
