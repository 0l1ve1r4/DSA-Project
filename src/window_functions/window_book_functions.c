#include "window_book_functions.h"

double double_preco;
int int_livro_cod;
int int_funcionario_id;
int int_cliente_id_int;

char char_cod[50];
char char_nome[50];
char char_num_paginas[50];
char char_autor[50];
char char_editora[50];
char char_data_emprestimo[50];
char char_preco[50];
char char_funcionario_id[50];
char char_cliente_id[50];

TLivro *registro;
TFunc *registro_employee;

FILE *bookFile;
FILE *employeeFile; 
FILE *LogFileBinary;

LRESULT CALLBACK Window_Print_Book(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CREATE: {

            if (registro != NULL){
            createButton(hwnd, "Livro encontrado!", 1, 10, 10);
            
            sprintf(char_cod, "Codigo: %i", registro->cod);
            sprintf(char_nome, "Nome: %s", registro->nome);
            sprintf(char_num_paginas, "Numero Paginas: %s", registro->numero_paginas);
            sprintf(char_autor, "Autor: %s", registro->autor);
            sprintf(char_editora, "Editora: %s", registro->editora);
            sprintf(char_preco, "Preco: %.2lf", registro->preco);
            sprintf(char_data_emprestimo, "Data Emprestimo: %s", registro->data_emprestimo);
            sprintf(char_cliente_id, "Cliente: %i", registro->cliente->nome);

            create_Static_Label(hwnd, char_cod, 10, 50, TAMANHO_LABEL_INSERT_Y*2, 20, 1);
            create_Static_Label(hwnd, char_nome, 10, 70, TAMANHO_LABEL_INSERT_Y*2, 20, 2);
            create_Static_Label(hwnd, char_num_paginas, 10, 90, TAMANHO_LABEL_INSERT_Y*2, 20, 3);
            create_Static_Label(hwnd, char_autor, 10, 110, TAMANHO_LABEL_INSERT_Y*2, 20, 4);
            create_Static_Label(hwnd, char_editora, 10, 130, TAMANHO_LABEL_INSERT_Y*2, 20, 5);
            create_Static_Label(hwnd, char_preco, 10, 150, TAMANHO_LABEL_INSERT_Y*2, 20, 6);
            create_Static_Label(hwnd, char_data_emprestimo, 10, 170, TAMANHO_LABEL_INSERT_Y*2, 20, 7);
            //create_Static_Label(hwnd, char_funcionario_id, 10, 190, TAMANHO_LABEL_INSERT_Y*2, 20, 8);

            free(registro); free(registro_employee);
            break;
            
            }

            else {
            MessageBox(NULL, "Livro nao encontrado.", "Error", MB_ICONERROR | MB_OK);
            free(registro); free(registro_employee);
            DestroyWindow(hwnd); 
            break;
            
            }
        
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

LRESULT CALLBACK Window_Insert_Book(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CREATE: {

            createButton(hwnd, "Inserir Livro", 1, 100, 10);
            create_Input_Label(hwnd, "Codigo:", 2, 10, 50);
            create_Input_Label(hwnd, "Nome:", 3, 10, 70);
            create_Input_Label(hwnd, "Paginas:", 4, 10, 90);
            create_Input_Label(hwnd, "Autor:", 5, 10, 110);
            create_Input_Label(hwnd, "Editora:", 6, 10, 130);
            create_Input_Label(hwnd, "Preco:", 7, 10, 150);
            create_Input_Label(hwnd, "Funcionario ID:", 8, 10, 170);

            createButton(hwnd, "Adicionar", 13, 10, 220);
            createButton(hwnd, "Cancelar", 14, 200, 220);

            break;
        }
        case WM_COMMAND: {
            int wmId = LOWORD(wParam);
            switch (wmId) {
                case 13: //CreateWindow("BUTTON", "Adicionar") (HMENU)13
                    
                    GetDlgItemText(hwnd, 2, char_cod, sizeof(char_cod));
                    GetDlgItemText(hwnd, 3, char_cod, sizeof(char_cod));
                    GetDlgItemText(hwnd, 4, char_num_paginas, sizeof(char_num_paginas));
                    GetDlgItemText(hwnd, 5, char_autor, sizeof(char_autor));
                    GetDlgItemText(hwnd, 6, char_editora, sizeof(char_editora));
                    GetDlgItemText(hwnd, 7, char_preco, sizeof(char_preco));
                    GetDlgItemText(hwnd, 8, char_funcionario_id, sizeof(char_funcionario_id));
                    GetDlgItemText(hwnd, 9, char_cliente_id, sizeof(char_cliente_id));
                    
                    double_preco = strtod(char_preco, NULL);
                    int_livro_cod = atoi(char_cod);
                    int_funcionario_id = atoi(char_funcionario_id);
                    
                    employeeFile = fopen(EMPLOYEE_FILE_PATH, "rb");
                    LogFileBinary = fopen(LOG_FILE_PATH, "w");

                    if (int_funcionario_id == 23){
                            registro_employee = criar_funcionario(int_funcionario_id, "Administrador", "", "", 0);
                        }
                    else{

                    int tamanho_base = tamanho_arquivo_de_funcionarios(employeeFile);
                    registro_employee = buscarFuncionario_binariamente(int_funcionario_id, employeeFile, tamanho_base , LogFileBinary);
                    }
                    
                    if (registro_employee == NULL) {
                        MessageBox(NULL, "Funcionario Nao Encontrado.", "Error", MB_ICONERROR | MB_OK);
                        break;
                                 }
                   
                    bookFile = fopen(BOOK_FILE_PATH, "ab+");
                    TLivro *temp = criar_livro(int_livro_cod, char_nome, char_num_paginas, char_autor, char_editora, "Disponivel", double_preco, registro_employee, NULL);
                    salvar_livro(temp, bookFile);
                    
                    quicksort_books(bookFile, tamanho_arquivo_de_livros(bookFile));
                    
                    fclose(bookFile); fclose(employeeFile); fclose(LogFileBinary); free(temp); 
                    DestroyWindow(hwnd); 
                    break;
                    

                case 14:
                    DestroyWindow(hwnd);
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

LRESULT CALLBACK Window_Search_Book(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CREATE: {
            createButton(hwnd, "Procurar Livro", 1, 10, 10);
            create_Input_Label(hwnd, "Codigo:", 2, 10, 50);
            createButton(hwnd, "Procurar", 13, 10, 220);
            createButton(hwnd, "Cancelar", 14, 200, 220);
            break;
        }

        case WM_COMMAND: {
            int wmId = LOWORD(wParam);
            switch (wmId) {
                case 13: 

                    GetDlgItemText(hwnd, 2, char_cod, sizeof(char_cod));
                    int_livro_cod = atoi(char_cod);

                    bookFile = fopen(BOOK_FILE_PATH, "rb");
                    LogFileBinary = fopen(LOG_FILE_PATH, "w");

                    int tamanho_base = tamanho_arquivo_de_livros(bookFile);
                    registro = buscarLivro_binariamente(int_livro_cod, bookFile, tamanho_base, LogFileBinary);
                    if (registro == NULL){ 
                        error_message("Livro nao encontrado", "Error 404");
                        break;
                    }

                    create_and_run_window(Window_Print_Book, "Window_Print_Book", "Livro Encontrado", WS_OVERLAPPEDWINDOW, 100, 100, SIZE_SUB_WINDOW_X, SIZE_SUB_WINDOW_Y);
                    fclose(bookFile); fclose(LogFileBinary); 
                    break;
                
                case 14:
                    DestroyWindow(hwnd);
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


LRESULT CALLBACK Windwow_Loan_book(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CREATE: {
            createButton(hwnd, "Emprestar Livro", 1, 10, 10);
            create_Input_Label(hwnd, "Codigo:", 2, 10, 50);
            create_Input_Label(hwnd, "Funcionario ID:", 3, 10, 70);
            create_Input_Label(hwnd, "Cliente Nome:", 4, 10, 90);
            create_Input_Label(hwnd, "Cliente CPF:", 5, 10, 110);
            createButton(hwnd, "Emprestar", 13, 10, 220);
            createButton(hwnd, "Cancelar", 14, 200, 220);
            break;
        }

        case WM_COMMAND: {
            int wmId = LOWORD(wParam);
            switch (wmId) {
                case 13:

                    GetDlgItemText(hwnd, 2, char_cod, sizeof(char_cod));
                    GetDlgItemText(hwnd, 3, char_funcionario_id, sizeof(char_funcionario_id));
                    GetDlgItemText(hwnd, 4, char_nome, sizeof(char_nome));
                    GetDlgItemText(hwnd, 5, char_cliente_id, sizeof(char_cliente_id));
   
                    int_livro_cod = atoi(char_cod); int_funcionario_id = atoi(char_funcionario_id);
                    int_funcionario_id = atoi(char_funcionario_id);

                    bookFile = fopen(BOOK_FILE_PATH, "rb+");
                    employeeFile = fopen(EMPLOYEE_FILE_PATH, "rb+");
                    LogFileBinary = fopen(LOG_FILE_PATH, "rb+");

                    int tam_file_book = tamanho_arquivo_de_livros(bookFile);  
                    TLivro* livro = buscarLivro_binariamente(int_livro_cod, bookFile, tam_file_book, LogFileBinary);
                    TFunc* funcionario = buscarFuncionario_binariamente(int_funcionario_id, employeeFile, tamanho_arquivo_de_funcionarios(employeeFile), LogFileBinary);
                    TCliente *cliente = criar_cliente(char_cliente_id, "");

                     if (livro != NULL && funcionario != NULL) {
                        strcpy(livro->data_emprestimo, "Emprestado");
                        livro->funcionario = NULL;
                        livro->cliente = NULL;
                        livro->funcionario = funcionario;
                        livro->funcionario->cod = int_funcionario_id;
                        livro->cliente = cliente;

                        #pragma GCC diagnostic push
                        #pragma GCC diagnostic ignored "-Woverflow"
                        fseek(bookFile, -sizeof(TLivro), SEEK_CUR);
                        fwrite(livro, sizeof(TLivro), 1, bookFile);
                        #pragma GCC diagnostic pop

                        

                    } else {

                        error_message("Livro ou funcionario nao encontrado", "Error");
                    }

                    free(livro); free(funcionario); free(cliente);
                    fclose(bookFile); fclose(LogFileBinary); fclose(employeeFile);

                    DestroyWindow(hwnd);
                    break;

                case 14:   
                    DestroyWindow(hwnd);
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

LRESULT CALLBACK Window_return_book(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CREATE: {
            createButton(hwnd, "Devolver Livro", 1, 10, 10);
            create_Input_Label(hwnd, "Codigo:", 2, 10, 50);
            createButton(hwnd, "Devolver", 13, 10, 220);
            createButton(hwnd, "Cancelar", 14, 200, 220);
            break;
        }

        case WM_COMMAND: {
            int wmId = LOWORD(wParam);
            switch (wmId) {
                case 13:

                    

                    GetDlgItemText(hwnd, 2, char_cod, sizeof(char_cod));
                    int_livro_cod = atoi(char_cod);

                    

                    bookFile = fopen(BOOK_FILE_PATH, "rb+");
                    LogFileBinary = fopen(LOG_FILE_PATH, "rb+");

                    int tam_file_book = tamanho_arquivo_de_livros(bookFile);  
                    TLivro *livro = buscarLivro_binariamente(int_livro_cod, bookFile, tam_file_book, LogFileBinary);
                    

                     if (livro != NULL) {

                        #pragma GCC diagnostic push
                        #pragma GCC diagnostic ignored "-Woverflow"

                        strcpy(livro->data_emprestimo, "NULL");
                        fseek(bookFile, -sizeof(TLivro), SEEK_CUR);
                        fwrite(livro, sizeof(TLivro), 1, bookFile);

                        #pragma GCC diagnostic pop

                        free(livro);
                    } else {
                        error_message("Livro nao encontrado", "Error");
                    }

                    fclose(bookFile);
                    fclose(LogFileBinary);
                    DestroyWindow(hwnd);
                    break;
            
            case 14:
                DestroyWindow(hwnd);
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
