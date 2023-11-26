#include "window_database_functions.h"

#define TAMANHO_LABEL_INSERT_Y 400
#define DISTANCIA_BOTOES_Y 50

LRESULT CALLBACK Window_Unsorted_DataBase_Search(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CREATE: {
            
            CreateWindow("BUTTON", "Fazer Base", WS_VISIBLE | WS_CHILD, 10, 10, 150, 30, hwnd, (HMENU)1, NULL, NULL);
            CreateWindow("STATIC", "Tamanho:", WS_VISIBLE | WS_CHILD, 10, 50, 100, 20, hwnd, NULL, NULL, NULL);
            CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 110, 50, 100, 20, hwnd, (HMENU)2, NULL, NULL);

            CreateWindow("BUTTON", "Iniciar", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 10, 200, 100, 30, hwnd, (HMENU)13, NULL, NULL);
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
                        printf("Window Debug: Erro ao converter o texto do inteiro \n");
                        break; 
                    } 
                    else {
                         printf("Window Debug: Sucesso ao converter o inteiro do codigo: %d\n", tamanho_base);
                    }
                    

                    FILE *bookFile, *LogFileBinary, *employeeFile;
                    bookFile = fopen("src/bin//shell_books.dat", "w");
                    LogFileBinary = fopen("src/bin//shell_log.dat", "w");
                    employeeFile = fopen("src/bin//shell_funcionarios.dat", "w");

                    #pragma GCC diagnostic push
                    #pragma GCC diagnostic ignored "-Wimplicit-function-declaration" 
                    #pragma GCC diagnostic ignored "-Wint-conversion"   

                    
                    //bases_buscas_sequenciais(employeeFile ,bookFile, LogFileBinary, tamanho_base);

                    #pragma GCC diagnostic pop // Volta a mostrar os warnings

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





//############################################################################################################################################################################

LRESULT CALLBACK Window_Sorted_DataBase_Search(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CREATE: {
            
            CreateWindow("BUTTON", "Fazer Base", WS_VISIBLE | WS_CHILD, 10, 10, 150, 30, hwnd, (HMENU)1, NULL, NULL);
            CreateWindow("STATIC", "Tamanho:", WS_VISIBLE | WS_CHILD, 10, 50, 100, 20, hwnd, NULL, NULL, NULL);
            CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 110, 50, 100, 20, hwnd, (HMENU)2, NULL, NULL);

            CreateWindow("BUTTON", "Iniciar", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 10, 200, 100, 30, hwnd, (HMENU)13, NULL, NULL);
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
                        printf("Window Debug: Erro ao converter o texto do inteiro \n");
                        break; 
                    } 
                    else {
                         printf("Window Debug: Sucesso ao converter o inteiro do codigo: %d\n", tamanho_base);
                    }
                    

                    FILE *bookFile, *LogFileBinary, *employeeFile;
                    bookFile = fopen("src/bin//shell_books.dat", "w");
                    LogFileBinary = fopen("src/bin//shell_log.dat", "w");
                    employeeFile = fopen("src/bin//shell_funcionarios.dat", "w");

                    #pragma GCC diagnostic push
                    #pragma GCC diagnostic ignored "-Wimplicit-function-declaration" 
                    #pragma GCC diagnostic ignored "-Wint-conversion"   

                    
                    //bases_buscas_binarias(employeeFile ,bookFile, LogFileBinary, tamanho_base);

                    #pragma GCC diagnostic pop // Volta a mostrar os warnings

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

