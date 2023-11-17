#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../livro.h"
#include "../buscas/buscas_binarias.h"

char codLivro_loan[10];
int cod_loan;

LRESULT CALLBACK Windwow_Loan_book(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CREATE: {

            CreateWindow("BUTTON", "Emprestar Livro", WS_VISIBLE | WS_CHILD, 10, 10, 150, 30, hwnd, (HMENU)1, NULL, NULL);
            CreateWindow("STATIC", "Codigo:", WS_VISIBLE | WS_CHILD, 10, 50, 100, 20, hwnd, NULL, NULL, NULL);
            CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 110, 50, 100, 20, hwnd, (HMENU)2, NULL, NULL);
            CreateWindow("BUTTON", "Emprestar", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 10, 200, 100, 30, hwnd, (HMENU)13, NULL, NULL);
            break;
        }

        case WM_COMMAND: {
            int wmId = LOWORD(wParam);
            switch (wmId) {
                case 13:

                    

                    GetDlgItemText(hwnd, 2, codLivro_loan, sizeof(codLivro_loan));
                    cod_loan = atoi(codLivro_loan);

                    if (cod_loan == 0 && codLivro_loan[0] != '0') {
                        printf("Window Debug: Erro ao converter o texto do inteiro \n");
                        break; 
                    } 
                    
                    else { 
                        printf("Window Debug: Numero Convertido para double: %d\n", cod_loan);
                    }

                    
                    #pragma GCC diagnostic push
                    #pragma GCC diagnostic ignored "-Wimplicit-function-declaration" 
                    #pragma GCC diagnostic ignored "-Wint-conversion"  
                    #pragma GCC diagnostic ignored "-Woverflow"  
    

                    TLivro *livro;
                    FILE *bookFileBinary, *LogFileBinary;

                    bookFileBinary = fopen("./src/bin/window_books.dat", "rb+");
                    LogFileBinary = fopen("./src/bin/window_log.dat", "rb+");

                    if (bookFileBinary == NULL || LogFileBinary == NULL) {
                        perror("Erro ao abrir arquivo");
                        exit(EXIT_FAILURE);
                    }

                    int tam_file_book = tamanho_arquivo_de_livros(bookFileBinary);  
                    livro = buscarLivro_binariamente(cod_loan, bookFileBinary, tam_file_book, LogFileBinary);
                    

                     if (livro != NULL) {
                        strcpy(livro->data_emprestimo, "Emprestado");

                        // Salva as alterações no arquivo
                        fseek(bookFileBinary, -sizeof(TLivro), SEEK_CUR);
                        fwrite(livro, sizeof(TLivro), 1, bookFileBinary);

                        free(livro);
                    } else {

                        printf("Livro não encontrado\n");
                    }

                    // Fecha os arquivos
                    fclose(bookFileBinary);
                    fclose(LogFileBinary);


                    #pragma GCC diagnostic pop 


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

int loan_book() {
    WNDCLASS wc = {0};
    wc.lpfnWndProc = Windwow_Loan_book;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "Windwow_Loan_book";
    RegisterClass(&wc);


    HWND hwnd = CreateWindow("Windwow_Loan_book", "Emprestimo de Livros", WS_OVERLAPPEDWINDOW, 100, 100, 400, 300, NULL, NULL, GetModuleHandle(NULL), NULL);
    ShowWindow(hwnd, SW_SHOWDEFAULT);
    MSG msg;

    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

//_______________________________________________________________________________________________________________________________________________________________________________________

LRESULT CALLBACK Window_return_book(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CREATE: {

            CreateWindow("BUTTON", "Devolver Livro", WS_VISIBLE | WS_CHILD, 10, 10, 150, 30, hwnd, (HMENU)1, NULL, NULL);
            CreateWindow("STATIC", "Codigo:", WS_VISIBLE | WS_CHILD, 10, 50, 100, 20, hwnd, NULL, NULL, NULL);
            CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 110, 50, 100, 20, hwnd, (HMENU)2, NULL, NULL);
            CreateWindow("BUTTON", "Devolber", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 10, 200, 100, 30, hwnd, (HMENU)13, NULL, NULL);
            break;
        }

        case WM_COMMAND: {
            int wmId = LOWORD(wParam);
            switch (wmId) {
                case 13:

                    

                    GetDlgItemText(hwnd, 2, codLivro_loan, sizeof(codLivro_loan));
                    cod_loan = atoi(codLivro_loan);

                    if (cod_loan == 0 && codLivro_loan[0] != '0') {
                        printf("Window Debug: Erro ao converter o texto do inteiro \n");
                        break; 
                    } 
                    
                    else { 
                        printf("Window Debug: Numero Convertido para double: %d\n", cod_loan);
                    }

                    
                    #pragma GCC diagnostic push
                    #pragma GCC diagnostic ignored "-Wimplicit-function-declaration" 
                    #pragma GCC diagnostic ignored "-Wint-conversion"  
                    #pragma GCC diagnostic ignored "-Woverflow"  
                    //Nessa função, eu procuro uma estrutura de um livto dentro de um arquivo, como faço para alterar o valor do campo livro->data_emprestimo  no arquivo e salvar?

                    TLivro *livro;
                    FILE *bookFileBinary, *LogFileBinary;

                    // Abre os arquivos para leitura e escrita binária
                    bookFileBinary = fopen("./src/bin/window_books.dat", "rb+");
                    LogFileBinary = fopen("./src/bin/window_log.dat", "rb+");

                    if (bookFileBinary == NULL || LogFileBinary == NULL) {
                        perror("Erro ao abrir arquivo");
                        exit(EXIT_FAILURE);
                    }

                    int tam_file_book = tamanho_arquivo_de_livros(bookFileBinary);  
                    livro = buscarLivro_binariamente(cod_loan, bookFileBinary, tam_file_book, LogFileBinary);
                    

                     if (livro != NULL) {
                        // Modifica o campo data_emprestimo
                        strcpy(livro->data_emprestimo, "NULL");

                        // Salva as alterações no arquivo
                        fseek(bookFileBinary, -sizeof(TLivro), SEEK_CUR);
                        fwrite(livro, sizeof(TLivro), 1, bookFileBinary);

                        free(livro);
                    } else {
                        // Lida com o caso em que o livro não foi encontrado
                        printf("Livro não encontrado\n");
                    }

                    // Fecha os arquivos
                    fclose(bookFileBinary);
                    fclose(LogFileBinary);


                    #pragma GCC diagnostic pop 


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

int return_book() {
    WNDCLASS wc = {0};
    wc.lpfnWndProc = Window_return_book;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "Window_return_book";
    RegisterClass(&wc);


    HWND hwnd = CreateWindow("Window_return_book", "Devolucao de Livros", WS_OVERLAPPEDWINDOW, 100, 100, 400, 300, NULL, NULL, GetModuleHandle(NULL), NULL);
    ShowWindow(hwnd, SW_SHOWDEFAULT);
    MSG msg;

    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}