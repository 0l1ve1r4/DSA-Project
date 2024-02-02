#include "estruturas.h"

NEW_WINDOW WindowProc_Main(WINDOW_PARAMS) {
    switch (uMsg) {
        case WM_CREATE: {

            CREATE_BOOK_BUTTON(hwnd);
            SEARCH_BOOK_BUTTON(hwnd);
            LOAN_BOOK_BUTTON(hwnd);
            RETURN_BOOK_BUTTON(hwnd);
            ADD_EMPLOYEE_BUTTON(hwnd);
            SEARCH_EMPLOYEE_BUTTON(hwnd);
            RESET_DB_BUTTON(hwnd);
            CREATE_SORTED_DB_BUTTON(hwnd);
            CREATE_UNSORTED_DB_BUTTON(hwnd);
            INSERTION_SORT_BUTTON(hwnd);
            INTERNAL_CLASSIFICATION_BUTTON(hwnd);
            BASIC_INTERCALATION_BUTTON(hwnd);
            ADD_IN_HASH_TABLE_BUTTON(hwnd);
            SEARCH_IN_HASH_TABLE_BUTTON(hwnd);
            REMOVE_IN_HASH_TABLE_BUTTON(hwnd);
            
            CREDITS_LABEL(hwnd);


            break;
        }

        case WM_COMMAND: {
            int wmId = LOWORD(wParam);
            switch (wmId) {
                case ID_ADD_BOOK:
                    create_and_run_window(Window_Insert_Book, "Window_Insert_Book", "Inserir Livro",
                    WS_OVERLAPPEDWINDOW, 100, 100, SIZE_SUB_WINDOW_X, SIZE_SUB_WINDOW_Y);
                    break;

                case ID_SEARCH_BOOK:
                    create_and_run_window(Window_Search_Book, "Window_Search_Book", "Buscar Livro",
                    WS_OVERLAPPEDWINDOW, 100, 100, SIZE_SUB_WINDOW_X, SIZE_SUB_WINDOW_Y);
                    break;

                case ID_LOAN_BOOK:
                    create_and_run_window(Windwow_Loan_book, "Windwow_Loan_book", "Emprestimo de Livros",
                    WS_OVERLAPPEDWINDOW, 100, 100, SIZE_SUB_WINDOW_X, SIZE_SUB_WINDOW_Y);
                    break;

                case ID_RETURN_BOOK:
                    create_and_run_window(Window_return_book, "Window_return_book", "Devolucao de Livros",
                    WS_OVERLAPPEDWINDOW, 100, 100, SIZE_SUB_WINDOW_X, SIZE_SUB_WINDOW_Y);
                    break;

                case ID_ADD_EMPLOYEE:
                    create_and_run_window(Window_Insert_Employee, "Window_Insert_Employee", "Inserir Funcionario",
                    WS_OVERLAPPEDWINDOW, 100, 100, SIZE_SUB_WINDOW_X, SIZE_SUB_WINDOW_Y);
                    break;

                case ID_SEARCH_EMPLOYEE:
                    create_and_run_window(Window_Search_Employee, "Window_Search_Employee", "Buscar Funcionario",
                    WS_OVERLAPPEDWINDOW, 100, 100, SIZE_SUB_WINDOW_X, SIZE_SUB_WINDOW_Y);
                    break;

                case ID_RESET_DB:
                    rmvBin();
                    break;

                case ID_CREATE_SORTED_DB:
                    create_and_run_window(Window_Sorted_DataBase_Search, "Window_Sorted_DataBase_Search", "Criar Base Ordenada",
                    WS_OVERLAPPEDWINDOW, 100, 100, SIZE_SUB_WINDOW_X, SIZE_SUB_WINDOW_Y);
                    break;

                case ID_CREATE_UNSORTED_DB:
                    create_and_run_window(Window_Unsorted_DataBase_Search, "Window_Unsorted_DataBase_Search", "Criar Base Desordenada",
                    WS_OVERLAPPEDWINDOW, 100, 100, SIZE_SUB_WINDOW_X, SIZE_SUB_WINDOW_Y);
                    break;

                case ID_INSERTION_SORT:
                    quicksort_both();
                    break;

                case ID_INTERNAL_CLASSIFICATION:
                    classificacoes(PARTITIONS_PER_STRUCTS);
                    break;

                case ID_BASIC_INTERCALATION:
                    intercalacoes_otimas();
                    break;

                case ID_ADD_IN_HASH_TABLE:
                     create_and_run_window(Window_Insert_Hash, "Window_Insert_Hashs", "Inserir Livro na Hash Table",
                     WS_OVERLAPPEDWINDOW, 100, 100, SIZE_SUB_WINDOW_X, SIZE_SUB_WINDOW_Y);
                     break;

                case ID_SEARCH_IN_HASH_TABLE:
                    create_and_run_window(Window_Search_Hash, "Window_Search_Hash", "Buscar Livro na Hash Table",
                    WS_OVERLAPPEDWINDOW, 100, 100, SIZE_SUB_WINDOW_X, SIZE_SUB_WINDOW_Y);
                    break;

                case ID_REMOVE_IN_HASH_TABLE:
                    break;

                default:
                    error_message("Funcao nao implementada", "Erro 404");
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

void TerminalProc_Main(){

    printf("\nDebug: hello world\n");
}


