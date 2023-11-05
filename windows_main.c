
/*
    GNU General Public License (GPL) version 3:

    This is a free and open-source software license designed to protect and ensure the freedom of software users.

    It guarantees the freedom to share, modify, and distribute both the original and modified versions of a program.

    When you distribute a GPL-licensed program, you must provide the source code to recipients, ensuring they have the same freedoms you received.

    Guilherme Oliveira Santos, 2023. Sistemas de Informação, UFOP.

*/


//Para compilar, use: gcc -o window ./src/*.c ./src/buscas/*.c ./windows_main.c
//Isso vai compilar todos os arquivos .c dentro das pastas depois o windows_main.c no diretório atual. 
//(Voce deve alterar o ./windows_main.c para o nome do seu arquivo main.c, caso queira fazer o projeto somente em terminal) 

#include <windows.h>
#include <stdio.h>

#include "./src/window_functions/window_book_functions.c"
#include "./src/window_functions/window_employee_functions.c"
#include "./src/window_functions/window_database_functions.c"
#include "./src/window_functions/window_utils.c"

#define DISTANCIA_BOTOES_Y 50
#define DISTANCIA_BOTOES_X 10
#define TAMANHO_BOTOES_Y 170
#define TAMANHO_MAIN_WINDOW_X 1000
#define TAMANHO_MAIN_WINDOW_Y 900




LRESULT CALLBACK WindowProc_Main(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        
        case WM_CREATE: {

            set_icon(hwnd, "./assets/images/appIcon.ico");
            removeExpandButton(hwnd);

            CreateWindow("BUTTON", "Adicionar Livro", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, DISTANCIA_BOTOES_X, 1, TAMANHO_BOTOES_Y, 30, hwnd, (HMENU)101, NULL, NULL);
            CreateWindow("BUTTON", "Buscar Livro", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, DISTANCIA_BOTOES_X, DISTANCIA_BOTOES_Y*1, TAMANHO_BOTOES_Y, 30, hwnd, (HMENU)102, NULL, NULL);
            CreateWindow("BUTTON", "Realizar Emprestimo", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, DISTANCIA_BOTOES_X, DISTANCIA_BOTOES_Y*2, TAMANHO_BOTOES_Y, 30, hwnd, (HMENU)103, NULL, NULL);
            CreateWindow("BUTTON", "Renovar Emprestimo", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, DISTANCIA_BOTOES_X, DISTANCIA_BOTOES_Y*3, TAMANHO_BOTOES_Y, 30, hwnd, (HMENU)104, NULL, NULL);
            CreateWindow("BUTTON", "Realizar Devolucao", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, DISTANCIA_BOTOES_X, DISTANCIA_BOTOES_Y*4, TAMANHO_BOTOES_Y, 30, hwnd, (HMENU)105, NULL, NULL);
            
            CreateWindow("BUTTON", "Registrar Funcionario", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, DISTANCIA_BOTOES_X*20, 1, TAMANHO_BOTOES_Y, 30, hwnd, (HMENU)201, NULL, NULL);
            CreateWindow("BUTTON", "Buscar Funcionario", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, DISTANCIA_BOTOES_X*20, DISTANCIA_BOTOES_Y*1, TAMANHO_BOTOES_Y, 30, hwnd, (HMENU)202, NULL, NULL);

            CreateWindow("BUTTON", "Gerar Relatorio", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, DISTANCIA_BOTOES_X*40, 1, TAMANHO_BOTOES_Y, 30, hwnd, (HMENU)301, NULL, NULL);


            CreateWindow("BUTTON", "Criar Base Desordenada ", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, DISTANCIA_BOTOES_X*80, 1, TAMANHO_BOTOES_Y, 30, hwnd, (HMENU)001, NULL, NULL);
            CreateWindow("BUTTON", "Criar Base Ordenada ", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, DISTANCIA_BOTOES_X*80, DISTANCIA_BOTOES_Y, TAMANHO_BOTOES_Y, 30, hwnd, (HMENU)002, NULL, NULL);
        
            CreateWindow("STATIC", "Guilherme Santos - Mateus Diniz | Algoritmos e Estruturas de Dados II",
            WS_VISIBLE | WS_CHILD, TAMANHO_MAIN_WINDOW_X/2, TAMANHO_MAIN_WINDOW_Y-60, TAMANHO_BOTOES_Y*10, 20, hwnd, NULL, NULL, NULL);


            break;
        }
        case WM_COMMAND: {
            int wmId = LOWORD(wParam);
            switch (wmId) {
                case 101:
                    insert_Book();
                    break;

                case 102:
                    search_Book();
                    break;


                case 201:
                    insert_employee();
                    break;

                case 202:
                    search_employee();
                    break;

                case 001:
                    Window_Unsorted_DataBase();
                    break;
                
                case 002:
                    Window_Sorted_DataBase();
                    break;

                default:
                    MessageBox(NULL, "Funcao nao Implementada.", "Error", MB_ICONERROR | MB_OK);
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
    printf("\033[H\033[J");
    // Registrar a classe da janela
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WindowProc_Main;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "MyWindowClass";
    RegisterClass(&wc);

    // Criar a janela
    HWND hwnd = CreateWindow("MyWindowClass", "Sistema Biblioteca", WS_OVERLAPPEDWINDOW, 100, 100, TAMANHO_MAIN_WINDOW_X, TAMANHO_MAIN_WINDOW_Y, NULL, NULL, GetModuleHandle(NULL), NULL);

    ShowWindow(hwnd, SW_SHOWDEFAULT);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
