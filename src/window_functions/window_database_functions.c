#include "window_database_functions.h"

char char_tamanho_base[10];
int int_tamanho_base;
int codigo_verificacao;
FILE* book_file;
FILE* log_file;
FILE* employee_file;

LRESULT CALLBACK Window_Unsorted_DataBase_Search(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CREATE: {
            
            createButton(hwnd, "Fazer Base", 1, DISTANCE_BUTTONS_X, DISTANCE_BUTTONS_Y - 40);
            create_Input_Label(hwnd, "Tamanho:", 2, DISTANCE_BUTTONS_X, DISTANCE_BUTTONS_Y);
            createButton(hwnd, "Iniciar", 13, DISTANCE_BUTTONS_X, DISTANCE_BUTTONS_Y * 4);
            createButton(hwnd, "Cancelar", 14, DISTANCE_BUTTONS_X * 20, DISTANCE_BUTTONS_Y * 4);

            break;
        }

        case WM_COMMAND: {
            int wmId = LOWORD(wParam);
            switch (wmId) {
                case 13: 
                    
                    GetDlgItemText(hwnd, 2, char_tamanho_base, sizeof(char_tamanho_base));
                    int_tamanho_base = atoi(char_tamanho_base); printf("\nTamanho da base: %d\n", int_tamanho_base);
                    
                    book_file = fopen("src/bin/window_books.dat", "ab+");
                    log_file = fopen("src/bin/window_log.dat", "ab+");
                    employee_file = fopen("src/bin/window_employee.dat", "ab+");


                    codigo_verificacao = criar_base_desordenada(employee_file, book_file, log_file, int_tamanho_base);

                    //printLivroCodes(book_file, tamanho_arquivo_de_livros(book_file)); // Debug only

                    if (codigo_verificacao != 0) {
                        error_message("Erro ao criar a base desordenada", "Erro"); } 
                    fclose(book_file); fclose(log_file); fclose(employee_file);

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
            
            createButton(hwnd, "Fazer Base", 1, DISTANCE_BUTTONS_X, DISTANCE_BUTTONS_Y - 40);
            create_Input_Label(hwnd, "Tamanho:", 2, DISTANCE_BUTTONS_X, DISTANCE_BUTTONS_Y);
            createButton(hwnd, "Iniciar", 13, DISTANCE_BUTTONS_X, DISTANCE_BUTTONS_Y * 4);
            createButton(hwnd, "Cancelar", 14, DISTANCE_BUTTONS_X * 20, DISTANCE_BUTTONS_Y * 4);
            break;
        }

        case WM_COMMAND: {
            int wmId = LOWORD(wParam);
            switch (wmId) {
                case 13: 
                    
                    GetDlgItemText(hwnd, 2, char_tamanho_base, sizeof(char_tamanho_base));
                    int_tamanho_base = atoi(char_tamanho_base);
                    
                    book_file = fopen("src/bin/window_books.dat", "ab+");
                    log_file = fopen("src/bin/window_log.dat", "ab+");
                    employee_file = fopen("src/bin/window_employee.dat", "ab+");


                    codigo_verificacao = criar_base_ordenada(employee_file, book_file, log_file, int_tamanho_base);
                    if (codigo_verificacao != 0) {
                        error_message("Erro ao criar a base ordenada", "Erro"); }
                    fclose(book_file); fclose(log_file); fclose(employee_file); 

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
