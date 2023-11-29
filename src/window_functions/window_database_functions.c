#include "window_database_functions.h"

#define TAMANHO_LABEL_INSERT_Y 400
#define DISTANCIA_BOTOES_Y 50

LRESULT CALLBACK Window_Unsorted_DataBase_Search(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CREATE: {
            
            createButton(hwnd, "Fazer Base", 1, 10, 10);
            create_Input_Label(hwnd, "Tamanho:", 2, 10, 50);
            createButton(hwnd, "Iniciar", 13, 10, 200);
            createButton(hwnd, "Cancelar", 14, 200, 200);

            break;
        }

        case WM_COMMAND: {
            int wmId = LOWORD(wParam);
            char cod_tamanhoBase[100];
            int tamanho_base;
            switch (wmId) {
                case 13: 
                    
                    GetDlgItemText(hwnd, 2, cod_tamanhoBase, sizeof(cod_tamanhoBase));
                    tamanho_base = atoi(cod_tamanhoBase);

                    if (tamanho_base == 0 && cod_tamanhoBase[0] != '0') {
                        error_message("Erro ao converter o texto do inteiro", "Erro");
                        break; 
                    } 

                    

                    FILE *bookFile = fopen("src/bin/window_books.dat", "ab+");
                    FILE *LogFileBinary = fopen("src/bin/window_log.dat", "ab+");
                    FILE *employeeFile = fopen("src/bin/window_employee.dat", "ab+");


                    int verify = criar_base_desordenada(employeeFile, bookFile, LogFileBinary, tamanho_base);
                    if (verify != 0) {
                        error_message("Erro ao criar a base ordenada", "Erro");
                        
                        } 

                    DestroyWindow(hwnd);

                    break;


                case 14:
                    DestroyWindow(hwnd);
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





//############################################################################################################################################################################

LRESULT CALLBACK Window_Sorted_DataBase_Search(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CREATE: {
            
            createButton(hwnd, "Fazer Base", 1, 10, 10);
            create_Input_Label(hwnd, "Tamanho:", 2, 10, 50);
            createButton(hwnd, "Iniciar", 13, 10, 200);
            createButton(hwnd, "Cancelar", 14, 200, 200);
            break;
        }

        case WM_COMMAND: {
            int wmId = LOWORD(wParam);
            char cod_tamanhoBase[100];
            int tamanho_base;
            switch (wmId) {
                case 13: 
                    
                    GetDlgItemText(hwnd, 2, cod_tamanhoBase, sizeof(cod_tamanhoBase));
                    tamanho_base = atoi(cod_tamanhoBase);

                    if (tamanho_base == 0 && cod_tamanhoBase[0] != '0') {
                        error_message("Erro ao converter o texto do inteiro", "Erro");
                        break; 
                    } 
                    
                    FILE* bookFile_database = fopen("src/bin/window_books.dat", "ab+");
                    FILE* LogFileBinary = fopen("src/bin/window_log.dat", "ab+");
                    FILE* employeeFile_database = fopen("src/bin/window_employee.dat", "ab+");

                    int verify = criar_base_ordenada(employeeFile_database, bookFile_database, LogFileBinary, tamanho_base);
                    if (verify != 0) {
                        error_message("Erro ao criar a base ordenada", "Erro");
                        
                        } 

                    DestroyWindow(hwnd);

                    break;

                case 14:
                    DestroyWindow(hwnd);
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

