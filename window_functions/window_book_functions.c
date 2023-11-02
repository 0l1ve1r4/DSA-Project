#include <windows.h>
#include <stdio.h>

#include "../livro.h"

#define TAMANHO_LABEL_INSERT_Y 200

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


LRESULT CALLBACK Window_Print_Book(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CREATE: {

            if (registro != NULL){

            char cod_print[11];
            char nome_print[50];
            char paginas_print[11];
            char autor_print[50];
            char editora_print[50];
            char data_emprestimo_print[11];
            char preco_print[11];

            sprintf(cod_print, "Codigo: %i", registro->cod);
            sprintf(nome_print, "Nome: %s", registro->nome);
            sprintf(paginas_print, "Numero Paginas: %s", registro->numero_paginas);
            sprintf(autor_print, "Autor: %s", registro->autor);
            sprintf(editora_print, "Editora: %s", registro->editora);
            sprintf(precoText, "Preco: %.2lf", preco);


            CreateWindow("STATIC", codText, WS_VISIBLE | WS_CHILD, 10, 50, TAMANHO_LABEL_INSERT_Y*2, 20, hwnd, NULL, NULL, NULL);
            CreateWindow("STATIC", nome_print, WS_VISIBLE | WS_CHILD, 10, 70, TAMANHO_LABEL_INSERT_Y*2, 20, hwnd, NULL, NULL, NULL);
            CreateWindow("STATIC", paginas_print, WS_VISIBLE | WS_CHILD, 10, 90, TAMANHO_LABEL_INSERT_Y*2, 20, hwnd, NULL, NULL, NULL);
            CreateWindow("STATIC", autor_print, WS_VISIBLE | WS_CHILD, 10, 110, TAMANHO_LABEL_INSERT_Y*2, 20, hwnd, NULL, NULL, NULL);
            CreateWindow("STATIC", editora_print, WS_VISIBLE | WS_CHILD, 10, 130, TAMANHO_LABEL_INSERT_Y*2, 20, hwnd, NULL, NULL, NULL);
            CreateWindow("STATIC", precoText, WS_VISIBLE | WS_CHILD, 10, 150, TAMANHO_LABEL_INSERT_Y*2, 20, hwnd, NULL, NULL, NULL);

            break;}

        else{

            CreateWindow("STATIC", "Livro nao encontrado", WS_VISIBLE | WS_CHILD, 10, 50, TAMANHO_LABEL_INSERT_Y*2, 20, hwnd, NULL, NULL, NULL);
            break;}


        
        }
        case WM_COMMAND: {
            int wmId = LOWORD(wParam);
            switch (wmId) {
                // Handle button clicks or other actions here...
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
int print_Book() {
    // Registrar a classe da janela
    WNDCLASS wc = {0};
    wc.lpfnWndProc = Window_Print_Book;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "Window_Print_Book_Class";
    RegisterClass(&wc);

    // Criar a janela
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

// Função para criar a janela inicial
LRESULT CALLBACK Window_Insert_Book(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CREATE: {
            // Criar os botões e caixas de texto
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
            // Adicione os outros controles aqui...

            CreateWindow("BUTTON", "Adicionar", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 10, 200, 100, 30, hwnd, (HMENU)13, NULL, NULL);
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


                    fclose(bookFile);
                    free(temp);
                    DestroyWindow(hwnd); // Fechar a janela automaticamente após inserir o livro
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
    wc.lpfnWndProc = Window_Insert_Book;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "Window_Insert_Book_Class";
    RegisterClass(&wc);

    // Criar a janela
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


LRESULT CALLBACK Window_Search_Book(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CREATE: {
            // Criar os botões e caixas de texto
            CreateWindow("BUTTON", "Procurar Livro", WS_VISIBLE | WS_CHILD, 10, 10, 150, 30, hwnd, (HMENU)1, NULL, NULL);
            CreateWindow("STATIC", "Codigo:", WS_VISIBLE | WS_CHILD, 10, 50, 100, 20, hwnd, NULL, NULL, NULL);
            CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 110, 50, 100, 20, hwnd, (HMENU)2, NULL, NULL);

            CreateWindow("BUTTON", "Procurar", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 10, 200, 100, 30, hwnd, (HMENU)13, NULL, NULL);
            break;
        }
        case WM_COMMAND: {
            int wmId = LOWORD(wParam);
            switch (wmId) {
                case 13: // Botão "Procurar" pressionado
                    // Obter os valores das caixas de texto

                    GetDlgItemText(hwnd, 2, codText, sizeof(codText));
                    cod = atoi(codText);

                    if (cod == 0 && codText[0] != '0') {
                        printf("Erro ao converter o texto do inteiro \n");
                        break; } else
                        { printf("Codigo: %d\n", cod);}
                    

                    FILE *bookFile, *LogFileBinary;
                    
                    bookFile = fopen("bin//books.dat", "r");
                    LogFileBinary = fopen("bin//logBinary.dat", "w");

                    #pragma GCC diagnostic push
                    #pragma GCC diagnostic ignored "-Wimplicit-function-declaration" // Nao faço a minima ideia pq ta dando essas warning com o header incluido,
                    #pragma GCC diagnostic ignored "-Wint-conversion"   // Apenas fingindo que nao ta acontecendo...

                    registro = buscarLivro_binariamente(cod, bookFile, 10000, LogFileBinary);
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
    // Registrar a classe da janela
    WNDCLASS wc = {0};
    wc.lpfnWndProc = Window_Search_Book;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "Window_Search_Book_Class";
    RegisterClass(&wc);

    // Criar a janela
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

