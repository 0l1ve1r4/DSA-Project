#include "window_book_functions.h"

#define TAMANHO_LABEL_INSERT_Y 400

char codText[50]; int cod;
char nome[50];
char numero_paginas[11];
char autor[50];
char editora[50];
char data_emprestimo[11];
char precoText[50]; double preco;
char funcionario_id[50]; int funcionario_id_int;
char cliente_id[50]; int cliente_id_int;



TLivro *registro;
TFunc *registro_employee;

char codLivro_loan[10];
int cod_loan;


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
            sprintf(data_emprestimo_print, "Data Emprestimo: %s", registro->data_emprestimo);
            sprintf(funcionario_id, "Funcionario: %s | ID: %i", registro->funcionario->nome, registro->funcionario->cod);
            sprintf(cliente_id, "Cliente: %i", registro->cliente->nome);

            createButton(hwnd, "Livro encontrado!", 1, 10, 10);
            create_Static_Label(hwnd, cod_print, 10, 50, TAMANHO_LABEL_INSERT_Y*2, 20, 1);
            create_Static_Label(hwnd, nome_print, 10, 70, TAMANHO_LABEL_INSERT_Y*2, 20, 2);
            create_Static_Label(hwnd, paginas_print, 10, 90, TAMANHO_LABEL_INSERT_Y*2, 20, 3);
            create_Static_Label(hwnd, autor_print, 10, 110, TAMANHO_LABEL_INSERT_Y*2, 20, 4);
            create_Static_Label(hwnd, editora_print, 10, 130, TAMANHO_LABEL_INSERT_Y*2, 20, 5);
            create_Static_Label(hwnd, precoText, 10, 150, TAMANHO_LABEL_INSERT_Y*2, 20, 6);
            create_Static_Label(hwnd, data_emprestimo_print, 10, 170, TAMANHO_LABEL_INSERT_Y*2, 20, 7);
            create_Static_Label(hwnd, funcionario_id, 10, 190, TAMANHO_LABEL_INSERT_Y*2, 20, 8);


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
                    
                    GetDlgItemText(hwnd, 2, codText, sizeof(codText));
                    GetDlgItemText(hwnd, 3, nome, sizeof(nome));
                    GetDlgItemText(hwnd, 4, numero_paginas, sizeof(nome));
                    GetDlgItemText(hwnd, 5, autor, sizeof(nome));
                    GetDlgItemText(hwnd, 6, editora, sizeof(nome));
                    GetDlgItemText(hwnd, 7, precoText, sizeof(precoText));
                    GetDlgItemText(hwnd, 8, funcionario_id, sizeof(funcionario_id));
                    GetDlgItemText(hwnd, 9, cliente_id, sizeof(cliente_id));
                    
                    preco = strtod(precoText, NULL);
                    cod = atoi(codText);
                    funcionario_id_int = atoi(funcionario_id);
                    

                    if (preco == 0.0 && errno == ERANGE || cod == 0 && codText[0] != '0' || funcionario_id_int == 0 && funcionario_id[0] != '0') {
                        error_message("Verifique se preencheu corretamente", "Error");
                        break;
                    } 

                    FILE *bookFile, *employeeFile, *LogFileBinary;
                    employeeFile = fopen("src/bin/window_employee.dat", "rb");
                    LogFileBinary = fopen("src/bin/window_log.dat", "w");

                    int tamanho_base = tamanho_arquivo_de_funcionarios(employeeFile);
                    registro_employee = buscarFuncionario_binariamente(funcionario_id_int, employeeFile, tamanho_base , LogFileBinary);
                    
                    if (registro_employee == NULL) {
                        MessageBox(NULL, "Funcionario Nao Encontrado.", "Error", MB_ICONERROR | MB_OK);
                        break;
                    
                                 }
                   
                    bookFile = fopen("src/bin/window_books.dat", "ab+");
                    TLivro *temp = criar_livro(cod, nome, numero_paginas, autor, editora, "Disponivel", preco, registro_employee, NULL);
                    salvar_livro(temp, bookFile);
                    
                    insertionSort_livros(bookFile, tamanho_arquivo_de_livros(bookFile));
                    
                    fclose(bookFile); fclose(employeeFile); fclose(LogFileBinary);
                    free(temp); 
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

                    GetDlgItemText(hwnd, 2, codText, sizeof(codText));
                    cod = atoi(codText);

                    if (cod == 0 && codText[0] != '0') {
                        printf("Window Debug: Erro ao converter o texto do inteiro \n");
                        break; 
                    } 

                    

                    FILE *bookFile, *LogFileBinary;
                    bookFile = fopen("src/bin/window_books.dat", "rb");
                    LogFileBinary = fopen("src/bin/window_log.dat", "w");

                    #pragma GCC diagnostic push
                    #pragma GCC diagnostic ignored "-Wimplicit-function-declaration" // Nao faço a minima ideia pq ta dando essas warning com o header incluido,
                    #pragma GCC diagnostic ignored "-Wint-conversion"   // Apenas fingindo que nao ta acontecendo...

                    int tamanho_base = tamanho_arquivo_de_livros(bookFile);
                    registro = buscarLivro_binariamente(cod, bookFile, tamanho_base, LogFileBinary);
                    if (registro == NULL){ 
                        error_message("Livro nao encontrado", "Error");
                        break;
                    }

                    create_and_run_window(Window_Print_Book, "Window_Print_Book", "Livro Encontrado", WS_OVERLAPPEDWINDOW, 100, 100, SIZE_SUB_WINDOW_X, SIZE_SUB_WINDOW_Y);

                    #pragma GCC diagnostic pop 

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

                    GetDlgItemText(hwnd, 2, codLivro_loan, sizeof(codLivro_loan));
                    GetDlgItemText(hwnd, 3, funcionario_id, sizeof(funcionario_id));
                    GetDlgItemText(hwnd, 4, nome, sizeof(nome));
                    GetDlgItemText(hwnd, 5, cliente_id, sizeof(cliente_id));

                    cod_loan = atoi(codLivro_loan); funcionario_id_int = atoi(funcionario_id);

                    if (cod_loan == 0 && codLivro_loan[0] != '0' || funcionario_id_int == 0 && funcionario_id[0] != '0') {
                        error_message("Verifique se preencheu corretamente", "Error");
                        break; 
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
                        error_message("Erro ao abrir arquivo", "Erro");
                        break;
                    }

                    int tam_file_book = tamanho_arquivo_de_livros(bookFileBinary);  
                    livro = buscarLivro_binariamente(cod_loan, bookFileBinary, tam_file_book, LogFileBinary);
                    

                     if (livro != NULL) {
                        strcpy(livro->data_emprestimo, "Emprestado");
                        livro->funcionario->cod = funcionario_id_int;
                        strcpy(livro->cliente->nome, nome);
                        
                        fseek(bookFileBinary, -sizeof(TLivro), SEEK_CUR);
                        fwrite(livro, sizeof(TLivro), 1, bookFileBinary);

                        free(livro);
                    } else {

                        error_message("Livro nao encontrado", "Error");
                    }

                   
                    fclose(bookFileBinary);
                    fclose(LogFileBinary);


                    #pragma GCC diagnostic pop 


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
                        error_message("Erro ao abrir arquivo", "Erro");
                        break;
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
