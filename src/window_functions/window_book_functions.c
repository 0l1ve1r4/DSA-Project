#include <windows.h>
#include <stdio.h>

#include "../livro.h"
#include "../buscas/buscas_binarias.h"

#define TAMANHO_LABEL_INSERT_Y 400

int cod;
char codText[50];
char nome[50];
char numero_paginas[11];
char autor[50];
char editora[50];
char data_emprestimo[11];
double preco;
char precoText[50];
TLivro *registro;

//___________________________________________________*___________________________________________________
//Windows para lidar com a impressão de livros que estarao armazenadas dinamicamente em uma estutura que pesquisou em um arquivo binario;
LRESULT CALLBACK Window_Print_Book(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CREATE: {

            if (registro != NULL){
            char cod_print[50];
            char nome_print[50];
            char paginas_print[50];
            char autor_print[50];
            char editora_print[50];
            char data_emprestimo_print[50];
            char preco_print[50];

            sprintf(cod_print, "Codigo: %i", registro->cod);
            sprintf(nome_print, "Nome: %s", registro->nome);
            sprintf(paginas_print, "Numero Paginas: %s", registro->numero_paginas);
            sprintf(autor_print, "Autor: %s", registro->autor);
            sprintf(editora_print, "Editora: %s", registro->editora);
            sprintf(precoText, "Preco: %.2lf", registro->preco);

            CreateWindow("STATIC", cod_print, WS_VISIBLE | WS_CHILD, 10, 50, TAMANHO_LABEL_INSERT_Y*2, 20, hwnd, NULL, NULL, NULL);
            CreateWindow("STATIC", nome_print, WS_VISIBLE | WS_CHILD, 10, 70, TAMANHO_LABEL_INSERT_Y*2, 20, hwnd, NULL, NULL, NULL);
            CreateWindow("STATIC", paginas_print, WS_VISIBLE | WS_CHILD, 10, 90, TAMANHO_LABEL_INSERT_Y*2, 20, hwnd, NULL, NULL, NULL);
            CreateWindow("STATIC", autor_print, WS_VISIBLE | WS_CHILD, 10, 110, TAMANHO_LABEL_INSERT_Y*2, 20, hwnd, NULL, NULL, NULL);
            CreateWindow("STATIC", editora_print, WS_VISIBLE | WS_CHILD, 10, 130, TAMANHO_LABEL_INSERT_Y*2, 20, hwnd, NULL, NULL, NULL);
            CreateWindow("STATIC", precoText, WS_VISIBLE | WS_CHILD, 10, 150, TAMANHO_LABEL_INSERT_Y*2, 20, hwnd, NULL, NULL, NULL);

            break;
            
            }

            else {
            MessageBox(NULL, "Livro nao encontrado.", "Error", MB_ICONERROR | MB_OK);
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


int print_Book() {
    WNDCLASS wc = {0};
    wc.lpfnWndProc = Window_Print_Book;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "Window_Print_Book_Class";
    RegisterClass(&wc);

    HWND hwnd = CreateWindow("Window_Print_Book_Class", "Buscar Livro no Banco de Dados", WS_OVERLAPPEDWINDOW, 100, 100, 400, 300, NULL, NULL, GetModuleHandle(NULL), NULL);
    ShowWindow(hwnd, SW_SHOWDEFAULT);
    MSG msg;

    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

//___________________________________________________*___________________________________________________
// Funções para lidar com a inserção de livros no arquivo binário
LRESULT CALLBACK Window_Insert_Book(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CREATE: {

            CreateWindow("BUTTON", "Inserir Livro", WS_VISIBLE | WS_CHILD, 10, 10, 150, 30, hwnd, (HMENU)1, NULL, NULL);

            CreateWindow("STATIC", "Codigo:", WS_VISIBLE | WS_CHILD, 10, 50, 100, 20, hwnd, NULL, NULL, NULL);
            CreateWindow("EDIT", "0", WS_VISIBLE | WS_CHILD | WS_BORDER, 110, 50, TAMANHO_LABEL_INSERT_Y, 20, hwnd, (HMENU)2, NULL, NULL);

            CreateWindow("STATIC", "Nome:", WS_VISIBLE | WS_CHILD, 10, 70, 100, 20, hwnd, NULL, NULL, NULL);
            CreateWindow("EDIT", "Livro", WS_VISIBLE | WS_CHILD | WS_BORDER, 110, 70, TAMANHO_LABEL_INSERT_Y, 20, hwnd, (HMENU)3, NULL, NULL);

            CreateWindow("STATIC", "Paginas:", WS_VISIBLE | WS_CHILD, 10, 90, 100, 20, hwnd, NULL, NULL, NULL);
            CreateWindow("EDIT", "0", WS_VISIBLE | WS_CHILD | WS_BORDER, 110, 90, TAMANHO_LABEL_INSERT_Y, 20, hwnd, (HMENU)4, NULL, NULL);

            CreateWindow("STATIC", "Autor:", WS_VISIBLE | WS_CHILD, 10, 110, 100, 20, hwnd, NULL, NULL, NULL);
            CreateWindow("EDIT", "Unknown", WS_VISIBLE | WS_CHILD | WS_BORDER, 110, 110, TAMANHO_LABEL_INSERT_Y, 20, hwnd, (HMENU)5, NULL, NULL);

            CreateWindow("STATIC", "Editora:", WS_VISIBLE | WS_CHILD, 10, 130, 100, 20, hwnd, NULL, NULL, NULL);
            CreateWindow("EDIT", "Unknown", WS_VISIBLE | WS_CHILD | WS_BORDER, 110, 130, TAMANHO_LABEL_INSERT_Y, 20, hwnd, (HMENU)6, NULL, NULL);

            CreateWindow("STATIC", "Preco:", WS_VISIBLE | WS_CHILD, 10, 150, 100, 20, hwnd, NULL, NULL, NULL);
            CreateWindow("EDIT", "0.0", WS_VISIBLE | WS_CHILD | WS_BORDER, 110, 150, TAMANHO_LABEL_INSERT_Y, 20, hwnd, (HMENU)7, NULL, NULL);


            CreateWindow("BUTTON", "Adicionar", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 10, 200, 100, 30, hwnd, (HMENU)13, NULL, NULL);
            break;
        }
        case WM_COMMAND: {
            int wmId = LOWORD(wParam);
            switch (wmId) {
                case 13: //CreateWindow("BUTTON", "Adicionar") (HMENU)13
                    
                    GetDlgItemText(hwnd, 2, codText, sizeof(codText));
                    GetDlgItemText(hwnd, 3, nome, sizeof(nome));
                    GetDlgItemText(hwnd, 4, numero_paginas, sizeof(nome));
                    GetDlgItemText(hwnd, 5, autor, sizeof(nome));
                    GetDlgItemText(hwnd, 6, editora, sizeof(nome));
                    GetDlgItemText(hwnd, 7, precoText, sizeof(precoText));
                    
                    preco = strtod(precoText, NULL);
                    cod = atoi(codText);

                    if (preco == 0.0 && errno == ERANGE || cod == 0 && codText[0] != '0') {
                        printf("Window Debug: Erro ao converter alguma variável\n");
                        break;
                    } 
                    
                    else {
                        printf("Window Debug: Codigo %i | Nome %s | Numero Paginas %s | Autor %s | Editora %s | Preco %f\n",
                         cod, nome, numero_paginas, autor, editora, preco);
                    }


                    FILE *bookFile;
                    bookFile = fopen("src/bin/window_books.dat", "ab+");
                    TLivro *temp = criar_livro(cod, nome, numero_paginas, autor, editora, "XXXXXX", preco);
                    salvar_livro(temp, bookFile);

                    fclose(bookFile);
                    free(temp);
                    DestroyWindow(hwnd); // Fechar a janela automaticamente após inserir o livro para evitar bugs
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
    WNDCLASS wc = {0};
    wc.lpfnWndProc = Window_Insert_Book;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "Window_Insert_Book_Class";
    RegisterClass(&wc);

    HWND hwnd = CreateWindow("Window_Insert_Book_Class", "Inserir Livro no Banco de Dados", WS_OVERLAPPEDWINDOW, 100, 100, 400, 300, NULL, NULL, GetModuleHandle(NULL), NULL);
    ShowWindow(hwnd, SW_SHOWDEFAULT);
    MSG msg;

    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

//___________________________________________________*___________________________________________________
//Funções para lidar com a pesquisa de Livros no arquivo binário
LRESULT CALLBACK Window_Search_Book(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CREATE: {

            CreateWindow("BUTTON", "Procurar Livro", WS_VISIBLE | WS_CHILD, 10, 10, 150, 30, hwnd, (HMENU)1, NULL, NULL);
            CreateWindow("STATIC", "Codigo:", WS_VISIBLE | WS_CHILD, 10, 50, 100, 20, hwnd, NULL, NULL, NULL);
            CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 110, 50, 100, 20, hwnd, (HMENU)2, NULL, NULL);

            CreateWindow("BUTTON", "Procurar", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 10, 200, 100, 30, hwnd, (HMENU)13, NULL, NULL);
            break;
        }

        case WM_COMMAND: {
            int wmId = LOWORD(wParam);
            switch (wmId) {
                case 13: 

                    GetDlgItemText(hwnd, 2, codText, sizeof(codText));
                    cod = atoi(codText);

                    if (cod == 0 && codText[0] != '0') {
                        printf("Window Debug: Erro ao converter o texto do inteiro \n");
                        break; 
                    } 
                    else {
                         printf("Window Debug: Sucesso ao converter o inteiro do codigo: %d\n", cod);
                    }
                    

                    FILE *bookFile, *LogFileBinary;
                    bookFile = fopen("src/bin/window_books.dat", "r");
                    LogFileBinary = fopen("src/bin/window_log.dat", "w");

                    #pragma GCC diagnostic push
                    #pragma GCC diagnostic ignored "-Wimplicit-function-declaration" // Nao faço a minima ideia pq ta dando essas warning com o header incluido,
                    #pragma GCC diagnostic ignored "-Wint-conversion"   // Apenas fingindo que nao ta acontecendo...

                    int tamanho_base = tamanho_arquivo_de_livros(bookFile);
                    registro = buscarLivro_binariamente(cod, bookFile, tamanho_base, LogFileBinary);
                    registro != NULL ? printf("\nWindow Debug: Livro encontrado com sucesso!"): printf("\nWindow Debug: Livro nao encontrado!");
                    print_Book();

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


int search_Book() {
    WNDCLASS wc = {0};
    wc.lpfnWndProc = Window_Search_Book;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "Window_Search_Book_Class";
    RegisterClass(&wc);


    HWND hwnd = CreateWindow("Window_Search_Book_Class", "Buscar Livro no Banco de Dados", WS_OVERLAPPEDWINDOW, 100, 100, 400, 300, NULL, NULL, GetModuleHandle(NULL), NULL);
    ShowWindow(hwnd, SW_SHOWDEFAULT);
    MSG msg;

    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

//___________________________________________________*___________________________________________________

