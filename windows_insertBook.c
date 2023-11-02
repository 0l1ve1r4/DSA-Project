#include <windows.h>
#include <stdio.h>
#include "livro.h"

// Declaração de variáveis globais
int cod;
char codText[50];
char nome[50];
char numero_paginas[11];
char autor[50];
char editora[50];
char data_emprestimo[11];
double preco;
char precoText[50];

// Função para criar a janela inicial
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CREATE: {
            // Criar os botões e caixas de texto
            CreateWindow("BUTTON", "Inserir Livro", WS_VISIBLE | WS_CHILD, 10, 10, 150, 30, hwnd, (HMENU)1, NULL, NULL);
            CreateWindow("STATIC", "Codigo:", WS_VISIBLE | WS_CHILD, 10, 50, 100, 20, hwnd, NULL, NULL, NULL);
            CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 110, 50, 100, 20, hwnd, (HMENU)2, NULL, NULL);

            CreateWindow("STATIC", "Nome:", WS_VISIBLE | WS_CHILD, 10, 70, 100, 20, hwnd, NULL, NULL, NULL);
            CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 110, 70, 100, 20, hwnd, (HMENU)3, NULL, NULL);

            CreateWindow("STATIC", "Paginas:", WS_VISIBLE | WS_CHILD, 10, 90, 100, 20, hwnd, NULL, NULL, NULL);
            CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 110, 90, 100, 20, hwnd, (HMENU)4, NULL, NULL);

            CreateWindow("STATIC", "Autor:", WS_VISIBLE | WS_CHILD, 10, 110, 100, 20, hwnd, NULL, NULL, NULL);
            CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 110, 110, 100, 20, hwnd, (HMENU)5, NULL, NULL);

            CreateWindow("STATIC", "Editora:", WS_VISIBLE | WS_CHILD, 10, 130, 100, 20, hwnd, NULL, NULL, NULL);
            CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 110, 130, 100, 20, hwnd, (HMENU)6, NULL, NULL);

            CreateWindow("STATIC", "Preco:", WS_VISIBLE | WS_CHILD, 10, 150, 100, 20, hwnd, NULL, NULL, NULL);
            CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 110, 150, 100, 20, hwnd, (HMENU)7, NULL, NULL);
            // Adicione os outros controles aqui...

            CreateWindow("BUTTON", "Adicionar", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 10, 200, 100, 30, hwnd, (HMENU)13, NULL, NULL);
            CreateWindow("BUTTON", "Cancelar", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 120, 200, 100, 30, hwnd, (HMENU)14, NULL, NULL);
            break;
        }
        case WM_COMMAND: {
            int wmId = LOWORD(wParam);
            switch (wmId) {
                case 13: // Botão "Adicionar" pressionado
                    // Obter os valores das caixas de texto
                    GetDlgItemText(hwnd, 2, codText, sizeof(codText));
                    GetDlgItemText(hwnd, 3, nome, sizeof(nome));
                    GetDlgItemText(hwnd, 4, numero_paginas, sizeof(nome));
                    GetDlgItemText(hwnd, 5, autor, sizeof(nome));
                    GetDlgItemText(hwnd, 6, editora, sizeof(nome));
                    GetDlgItemText(hwnd, 7, precoText, sizeof(precoText));
                    
                    preco = strtod(precoText, NULL);
                    cod = atoi(codText);

                    // Check for conversion errors, if necessary
                    if (preco == 0.0 && errno == ERANGE || cod == 0 && codText[0] != '0') {

                        printf("Error converting to some variable \n");
                        break;
                    } else {
                        printf("Preço: %lf\n", preco);
}

                    // Obtenha os outros valores das outras caixas de texto...

                    // Imprimir os valores
                    printf("Código: %d\n", cod);
                    printf("Nome: %s\n", nome);
                    printf("Número de Páginas: %s\n", numero_paginas);
                    printf("Autor: %s\n", autor);
                    printf("Editora: %s\n", editora);
                    printf("Preço: %lf\n", preco);
                    // Imprima os outros valores...

                    FILE *bookFile;
                    bookFile = fopen("bin//books.dat", "ab+");
                    TLivro *temp = criar_livro(cod, nome, numero_paginas, autor, editora, "XXXXXX", preco);
                    salvar_livro(temp, bookFile);
                    free(temp);

                    break;
                case 14: // Botão "Cancelar" pressionado
                    // Fechar a janela
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

int insert_Book() {
    // Registrar a classe da janela
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "MyWindowClass_InsertBook";
    RegisterClass(&wc);

    // Criar a janela
    HWND hwnd = CreateWindow("MyWindowClass_InsertBook", "Inserir Livro no Banco de Dados", WS_OVERLAPPEDWINDOW, 100, 100, 400, 300, NULL, NULL, GetModuleHandle(NULL), NULL);

    ShowWindow(hwnd, SW_SHOWDEFAULT);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
