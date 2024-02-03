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
                    printf("Debug: %d\n", int_livro_cod);

                    // Remove o livro da HashTable global
                    remove_hash(myHashTable, int_livro_cod);
                    printf("Livro removido da HashTable.\n");

                    // Agora você pode adicionar lógica adicional, se necessário

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

                    TLivro livroBuscado = search_hash(myHashTable, int_livro_cod);
                    if (livroBuscado.cod != -1) {
                        printf("Livro encontrado.\n");
                        printf("Codigo: %d\n", livroBuscado.cod);
                        printf("Nome: %s\n", livroBuscado.nome);
                        printf("Paginas: %s\n", livroBuscado.numero_paginas);
                        printf("Autor: %s\n", livroBuscado.autor);
                        printf("Editora: %s\n", livroBuscado.editora);
                        printf("Preco: %.2f\n", livroBuscado.preco);

                        
                    } else {
                        error_message("Livro nao encontrado.", "Erro");
                    }
                    break;
                }

                case 14:
                    printf("Fechar janela.\n");
                    DestroyWindow(hwnd);
                    break;
            }

            break;
        }

        case WM_DESTROY: {
            printf("Fechar aplicativo.\n");
            PostQuitMessage(0);
            break;
        }

        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }

    return 0;
}
