#include "../estruturas.h"
#include "../functions_macros.h"

int int_livro_cod;

char char_cod[50];
char char_nome[50];
char char_num_paginas[50];
char char_autor[50];
char char_editora[50];
char char_data_emprestimo[50];
char char_preco[50];
char char_funcionario_id[50];

HashTable *myHashTable;
TLivro *registro;

NEW_WINDOW Window_Print_Hash(WINDOW_PARAMS) {
    switch (uMsg) {
        case WM_CREATE: {
            if (registro != NULL){
                createButton(hwnd, "Livro encontrado!", 1, 10, 10);
                
                CREATE_LABEL_AND_PRINT(hwnd, "Codigo: %i", registro->cod, 50, 1);
                CREATE_LABEL_AND_PRINT(hwnd, "Nome: %s", registro->nome, 70, 2);
                CREATE_LABEL_AND_PRINT(hwnd, "Numero Paginas: %s", registro->numero_paginas, 90, 3);
                CREATE_LABEL_AND_PRINT(hwnd, "Autor: %s", registro->autor, 110, 4);
                CREATE_LABEL_AND_PRINT(hwnd, "Editora: %s", registro->editora, 130, 5);
                CREATE_LABEL_AND_PRINT(hwnd, "Preco: %.2lf", registro->preco, 150, 6);
                CREATE_LABEL_AND_PRINT(hwnd, "Data Emprestimo: %s", registro->data_emprestimo, 170, 7);

                free(registro);
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


NEW_WINDOW Window_Delete_Hash(WINDOW_PARAMS) {
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
                case 13: {
                    GetDlgItemText(hwnd, 2, char_cod, sizeof(char_cod));
                    printf("[+] Debug: Codigo a ser removido: [%d]\n", atoi(char_cod));

                    remove_hash(myHashTable, atoi(char_cod));
                    saveHashTable(myHashTable);
                    free(myHashTable);
                    DestroyWindow(hwnd);
                    break;
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



//############################################################################################################################################################################

NEW_WINDOW Window_Insert_Hash(WINDOW_PARAMS) {
    switch (uMsg) {
        case WM_CREATE: {

            char* labels[] = {"Codigo:", "Nome:", "Paginas:", "Autor:", "Editora:", "Preco:", "Funcionario ID:"};
            char *ids[] = {"2", "3", "4", "5", "6", "7", "8"};
            createButton(hwnd, "Inserir Livro", 1, 100, 10);

            for (int i = 0; i < 7; i++) {
                create_Input_Label(hwnd, labels[i], atoi(ids[i]), 10, 50 + (i * 20)); }
            
            createButton(hwnd, "Adicionar", 13, 10, 220);
            createButton(hwnd, "Cancelar", 14, 200, 220);

            break;
        }
        case WM_COMMAND: {
            int wmId = LOWORD(wParam);
            switch (wmId) {
                case 13: // Código para o botão "Adicionar"
                    GetDlgItemText(hwnd, 2, char_cod, sizeof(char_cod));
                    GetDlgItemText(hwnd, 3, char_nome, sizeof(char_nome));
                    GetDlgItemText(hwnd, 4, char_num_paginas, sizeof(char_num_paginas));
                    GetDlgItemText(hwnd, 5, char_autor, sizeof(char_autor));
                    GetDlgItemText(hwnd, 6, char_editora, sizeof(char_editora));
                    GetDlgItemText(hwnd, 7, char_preco, sizeof(char_preco));
                    GetDlgItemText(hwnd, 8, char_funcionario_id, sizeof(char_funcionario_id));

                    if (myHashTable == NULL) {
                        myHashTable = loadHashTable(); // If the hash table is not initialized, initialize it from the file
                        if (myHashTable == NULL) { // If the file does not exist, create a new hash table 
                                myHashTable = createHashTable();
                            }
                    }

                    // Cria um livro com as informações do formulário
                    TLivro livro; // Cria um livro
                    livro.cod = atoi(char_cod); // Converte o código para inteiro
                    strcpy(livro.nome, char_nome); // Copia o nome para a struct
                    strcpy(livro.numero_paginas, char_num_paginas); // Copia o número de páginas para a struct
                    strcpy(livro.autor, char_autor); // Copia o autor para a struct
                    strcpy(livro.editora, char_editora); // Copia a editora para a struct
                    livro.preco = strtod(char_preco, NULL); // Converte o preço para double

                    TFunc func1 = {atoi(char_funcionario_id), "Adm", "11122233344", "01/01/1980", 3000.50};
                    livro.funcionario = &func1;

                    // Adiciona o livro à tabela hash
                    insert_hash(myHashTable, livro.cod, livro);

                    // Exibe uma mensagem indicando que o livro foi adicionado
                    MessageBox(hwnd, "Livro adicionado com sucesso!", "Sucesso", MB_OK | MB_ICONINFORMATION);
                    saveHashTable(myHashTable);
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
                case 13: {
                    GetDlgItemText(hwnd, 2, char_cod, sizeof(char_cod));
                    int_livro_cod = atoi(char_cod);
                    if (myHashTable == NULL) {
                        myHashTable = loadHashTable();
                    }


                    TLivro livroBuscado = search_hash(myHashTable, int_livro_cod);
                    if (livroBuscado.cod != -1) {

                        registro = (TLivro *)malloc(sizeof(TLivro));
                        registro->cod = livroBuscado.cod;
                        strcpy(registro->nome, livroBuscado.nome);
                        strcpy(registro->numero_paginas, livroBuscado.numero_paginas);
                        strcpy(registro->autor, livroBuscado.autor);
                        strcpy(registro->editora, livroBuscado.editora);
                        registro->preco = livroBuscado.preco;
                        strcpy(registro->data_emprestimo, "15/02/2023");


                        create_and_run_window(Window_Print_Hash, "Window_Print_Hash", "Livro Encontrado", WS_OVERLAPPEDWINDOW, 100, 100, SIZE_SUB_WINDOW_X, SIZE_SUB_WINDOW_Y);
                        
                    } else {
                        error_message("Livro nao encontrado.", "Erro");
                    }
                    break;
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
