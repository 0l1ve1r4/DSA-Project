#include "../estruturas.h"

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

NEW_WINDOW Window_delete_hash(WINDOW_PARAMS) {
    switch (uMsg) {
        case WM_CREATE: {
            createButton(hwnd, "Apagar Livro", 1, 10, 10);
            create_Input_Label(hwnd, "Codigo:", 2, 10, 50);
            createButton(hwnd, "Apagar", 13, 10, 220);
            createButton(hwnd, "Cancelar", 14, 200, 220);
            break;
        }

        case WM_COMMAND: {
            int wmId = LOWORD(wParam);
            switch (wmId) {
                case 13:

                    
                    bookFile = fopen(HASH_TABLE_PATH, "ab+");
                    GetDlgItemText(hwnd, 2, char_cod, sizeof(char_cod));
                    int_livro_cod = atoi(char_cod);

                    bookFile = fopen(BOOK_FILE_PATH, "rb+");
                    LogFileBinary = fopen(LOG_FILE_PATH, "rb+");

                    int tam_file_book = tamanho_arquivo_de_livros(bookFile);  
                    TLivro *livro = buscarLivro_sequencialmente(bookFile, int_livro_cod, LogFileBinary);
                    

                     if (livro != NULL) {

                        #pragma GCC diagnostic push
                        #pragma GCC diagnostic ignored "-Woverflow"

                        livro->cod = -1;
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


//############################################################################################################################################################################

NEW_WINDOW Window_Insert_Hash(WINDOW_PARAMS) {
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
                case 13: 
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

                    if (int_funcionario_id != 23){
                            int tamanho_base = tamanho_arquivo_de_funcionarios(employeeFile);
                            registro_employee = buscarFuncionario_binariamente(int_funcionario_id, employeeFile, tamanho_base , LogFileBinary);

                            if (registro_employee == NULL) {
                            MessageBox(NULL, "Funcionario Nao Encontrado.", "Error", MB_ICONERROR | MB_OK);
                            return 0;
                                 }
                        }



                    HashTable *ht = (HashTable*) malloc(sizeof(HashTable));

                    for (int i = 0; i < TABLE_SIZE; i++) {
                        ht->table[i] = NULL;
                    }

                    saveHashTable(ht);

                    HashTable *loadedHt = loadHashTable();

                    TFunc func1 = {23, "Adm", "", "", 0.0};
                    TCliente cliente1 = {"", ""};
                    TLivro livro1 = {int_livro_cod, char_nome, char_num_paginas, char_autor, char_editora, "05/02/23", double_preco, &func1, &cliente1};
                    insert_hash(loadedHt, livro1.cod, &livro1);
                    saveHashTable(loadedHt);
                    
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



NEW_WINDOW Window_Search_Hash(WINDOW_PARAMS) {
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
                        printf("Debug: %d\n", int_livro_cod);
                        HashTable *loadedHt = loadHashTable();
                        TLivro *livroBuscado = (TLivro*) search_hash(loadedHt, int_livro_cod);
                        if (livroBuscado != NULL) {
                            printf("Livro encontrado: %s\n", livroBuscado->nome);
                        } else {
                            printf("Livro não encontrado.\n");
                        }
                
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
