#include "../estruturas.h"

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
            
            sprintf(char_cod, "Codigo: %i", registro->cod);
            sprintf(char_nome, "Nome: %s", registro->nome);
            sprintf(char_num_paginas, "Numero Paginas: %s", registro->numero_paginas);
            sprintf(char_autor, "Autor: %s", registro->autor);
            sprintf(char_editora, "Editora: %s", registro->editora);
            sprintf(char_preco, "Preco: %.2lf", registro->preco);
            sprintf(char_data_emprestimo, "Data Emprestimo: %s", registro->data_emprestimo);

            create_Static_Label(hwnd, char_cod, 10, 50, TAMANHO_LABEL_INSERT_Y*2, 20, 1);
            create_Static_Label(hwnd, char_nome, 10, 70, TAMANHO_LABEL_INSERT_Y*2, 20, 2);
            create_Static_Label(hwnd, char_num_paginas, 10, 90, TAMANHO_LABEL_INSERT_Y*2, 20, 3);
            create_Static_Label(hwnd, char_autor, 10, 110, TAMANHO_LABEL_INSERT_Y*2, 20, 4);
            create_Static_Label(hwnd, char_editora, 10, 130, TAMANHO_LABEL_INSERT_Y*2, 20, 5);
            create_Static_Label(hwnd, char_preco, 10, 150, TAMANHO_LABEL_INSERT_Y*2, 20, 6);
            create_Static_Label(hwnd, char_data_emprestimo, 10, 170, TAMANHO_LABEL_INSERT_Y*2, 20, 7);
            free(registro);
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
                    int_livro_cod = atoi(char_cod);
                    printf("[+] Debug: Codigo a ser removido: [%d]\n", int_livro_cod);

                    // Remove o livro da HashTable global
                    remove_hash(myHashTable, int_livro_cod);
                    printf("[+] Debug: Livro removido da HashTable.\n");

                    // Agora você pode adicionar lógica adicional, se necessário
                    saveHashTable(myHashTable);
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
                case 13: // Código para o botão "Adicionar"
                    GetDlgItemText(hwnd, 2, char_cod, sizeof(char_cod));
                    GetDlgItemText(hwnd, 3, char_nome, sizeof(char_nome));
                    GetDlgItemText(hwnd, 4, char_num_paginas, sizeof(char_num_paginas));
                    GetDlgItemText(hwnd, 5, char_autor, sizeof(char_autor));
                    GetDlgItemText(hwnd, 6, char_editora, sizeof(char_editora));
                    GetDlgItemText(hwnd, 7, char_preco, sizeof(char_preco));
                    GetDlgItemText(hwnd, 8, char_funcionario_id, sizeof(char_funcionario_id));

                    // Converte os valores do formulário para os tipos apropriados
                    int int_livro_cod = atoi(char_cod);
                    double double_preco = strtod(char_preco, NULL);
                    int int_funcionario_id = atoi(char_funcionario_id);

                        if (myHashTable == NULL) {
                        // Se falhou, criar uma nova tabela hash
                        myHashTable = (HashTable *)malloc(sizeof(HashTable));
                        for (int i = 0; i < TABLE_SIZE; i++) {
                            myHashTable->table[i] = NULL;
                        }
                    }

                    // Cria um livro com as informações do formulário
                    TLivro livro;
                    livro.cod = int_livro_cod;
                    strcpy(livro.nome, char_nome);
                    strcpy(livro.numero_paginas, char_num_paginas);
                    strcpy(livro.autor, char_autor);
                    strcpy(livro.editora, char_editora);
                    livro.preco = double_preco;

                    // Cria um funcionário (assumindo que a variável func1 seja definida)
                    TFunc func1 = {int_funcionario_id, "Funcionario1", "11122233344", "01/01/1980", 3000.50};
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
                        printf("[+] Debug: Livro encontrado.\n");
                        printf("[+] Debug: HashTable[%d] = %s\n", int_livro_cod, livroBuscado.nome);

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
