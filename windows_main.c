
#include "./src/window_functions/window_book_functions.h"
#include "src/window_functions/window_database_functions.h"
#include "./src/window_functions/window_employee_functions.h"
#include "./src/window_functions/window_utils.h"


//gcc -o window ./src/*.c ./src/buscas/*.c ./src/metodos_ordenacao/*.c ./src/window_functions/*.c ./windows_main.c

LRESULT CALLBACK WindowProc_Main(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
void createButton(HWND hwnd, const char* text, int id, int x, int y);

int main() {
    printf("\033[H\033[JShell Debug: Iniciando o programa");
    //get_current_path(); 

    WNDCLASS wc = {0};
    wc.lpfnWndProc = WindowProc_Main;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "Main_Window";
    RegisterClass(&wc);

    // Create the window
    HWND hwnd = CreateWindow(wc.lpszClassName, "Sistema Biblioteca", WS_OVERLAPPEDWINDOW, 100, 100, 
    SIZE_MAIN_WINDOW_X, SIZE_MAIN_WINDOW_Y, NULL, NULL, GetModuleHandle(NULL), NULL);
    ShowWindow(hwnd, SW_SHOWDEFAULT);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK WindowProc_Main(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CREATE: {
            set_icon(hwnd, "./assets/images/appIcon.ico");
            removeExpandButton(hwnd);

            createButton(hwnd, "Adicionar Livro", ID_ADD_BOOK, DISTANCE_BUTTONS_X, 1);
            createButton(hwnd, "Buscar Livro", ID_SEARCH_BOOK, DISTANCE_BUTTONS_X, DISTANCE_BUTTONS_Y * 1);
            createButton(hwnd, "Realizar Emprestimo", ID_LOAN_BOOK, DISTANCE_BUTTONS_X, DISTANCE_BUTTONS_Y * 2);
            createButton(hwnd, "Renovar Emprestimo", ID_RENEW_LOAN, DISTANCE_BUTTONS_X, DISTANCE_BUTTONS_Y * 3);
            createButton(hwnd, "Realizar Devolucao", ID_RETURN_BOOK, DISTANCE_BUTTONS_X, DISTANCE_BUTTONS_Y * 4);

            createButton(hwnd, "Registrar Funcionario", ID_ADD_EMPLOYEE, DISTANCE_BUTTONS_X * 20, 1);
            createButton(hwnd, "Buscar Funcionario", ID_SEARCH_EMPLOYEE, DISTANCE_BUTTONS_X * 20, DISTANCE_BUTTONS_Y * 1);

            createButton(hwnd, "Criar Base Desordenada", ID_CREATE_UNSORTED_DB, DISTANCE_BUTTONS_X * 40, 1);
            createButton(hwnd, "Criar Base Ordenada", ID_CREATE_SORTED_DB, DISTANCE_BUTTONS_X * 40, DISTANCE_BUTTONS_Y);
            createButton(hwnd, "Resetar Banco de Dados", ID_RESET_DB, DISTANCE_BUTTONS_X * 40, DISTANCE_BUTTONS_Y * 2);

            CreateWindow("STATIC", "Guilherme Santos - Mateus Diniz | Algoritmos e Estruturas de Dados II",
                WS_VISIBLE | WS_CHILD, SIZE_MAIN_WINDOW_X / 5, SIZE_MAIN_WINDOW_Y - 60, SIZE_BUTTONS_Y * 10, 20, hwnd, NULL, NULL, NULL);

            break;
        }

        case WM_COMMAND: {
            int wmId = LOWORD(wParam);
            switch (wmId) {
                case ID_ADD_BOOK:
                    insert_Book();
                    break;

                case ID_SEARCH_BOOK:
                    search_Book();
                    break;

                case ID_LOAN_BOOK:
                    loan_book();
                    break;

                case ID_RENEW_LOAN:
                    loan_book();
                    break;

                case ID_RETURN_BOOK:
                    return_book();
                    break;

                case ID_ADD_EMPLOYEE:
                    insert_employee();
                    break;

                case ID_SEARCH_EMPLOYEE:
                    search_employee();
                    break;

                case ID_CREATE_UNSORTED_DB:
                    Window_Unsorted_DataBase();
                    break;

                case ID_CREATE_SORTED_DB:
                    Window_Sorted_DataBase();
                    break;

                case ID_RESET_DB:
                    rmvBin();
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
