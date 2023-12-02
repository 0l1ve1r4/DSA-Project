#include "window_employee_functions.h"

int int_func_cod;
double double_func_salario;
char char_func_cod[10];
char char_func_nome[50];
char char_func_cpf[15];
char char_func_data_nascimento[11];
char char_func_salario[50];

TFunc *registro_employee;
FILE *employeeFile;
FILE *LogFileBinary;

LRESULT CALLBACK Window_Print_Employee(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CREATE: {

            if (registro_employee != NULL){
            createButton(hwnd, "Funcionario Encontrado", 0, 10, 0);

            sprintf(char_func_cod, "Codigo: %i", registro_employee->cod);
            sprintf(char_func_nome, "Nome: %s", registro_employee->nome);
            sprintf(char_func_cpf, "Cpf: %s", registro_employee->cpf);
            sprintf(char_func_data_nascimento, "Nascimento: %s", registro_employee->data_nascimento);
            sprintf(char_func_salario, "Salario: %f", registro_employee->salario);

            create_Static_Label(hwnd, char_func_cod, 10, DISTANCE_BUTTONS_Y, TAMANHO_LABEL_INSERT_Y, 20, 1);
            create_Static_Label(hwnd, char_func_nome, 10, DISTANCE_BUTTONS_Y+20, TAMANHO_LABEL_INSERT_Y, 20, 2);
            create_Static_Label(hwnd, char_func_cpf, 10, DISTANCE_BUTTONS_Y+40, TAMANHO_LABEL_INSERT_Y, 20, 3);
            create_Static_Label(hwnd, char_func_data_nascimento, 10, DISTANCE_BUTTONS_Y+60, TAMANHO_LABEL_INSERT_Y, 20, 4);
            create_Static_Label(hwnd, char_func_salario, 10, DISTANCE_BUTTONS_Y+80, TAMANHO_LABEL_INSERT_Y, 20, 5);

            break;
            
            }

        else {
            error_message("Funcionario nao encontrado", "Erro");
            DestroyWindow(hwnd);
            break;
            
            }

        
            free(registro_employee);
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

LRESULT CALLBACK Window_Insert_Employee(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CREATE: {
            
        createButton(hwnd, "Inserir Funcionario", 1, 100, 10);
        create_Input_Label(hwnd, "Codigo:", 2, 10, 50);
        create_Input_Label(hwnd, "Nome:", 3, 10, 70);
        create_Input_Label(hwnd, "CPF:", 4, 10, 90);
        create_Input_Label(hwnd, "Nascimento:", 5, 10, 110);
        create_Input_Label(hwnd, "Salario:", 6, 10, 130);
        createButton(hwnd, "Adicionar", 13, 10, 220);
        createButton(hwnd, "Cancelar", 14, 200, 220);


            break;
        }
        case WM_COMMAND: {
            int wmId = LOWORD(wParam);
            switch (wmId) {
                case 13:

                    GetDlgItemText(hwnd, 2, char_func_cod, sizeof(char_func_cod));
                    GetDlgItemText(hwnd, 3, char_func_nome, sizeof(char_func_nome));
                    GetDlgItemText(hwnd, 4, char_func_cpf, sizeof(char_func_cpf));
                    GetDlgItemText(hwnd, 5, char_func_data_nascimento, sizeof(char_func_data_nascimento));
                    GetDlgItemText(hwnd, 6, char_func_salario, sizeof(char_func_salario));
                    
                    double_func_salario = strtod(char_func_salario, NULL);
                    int_func_cod = atoi(char_func_cod);

                    employeeFile = fopen(EMPLOYEE_FILE_PATH, "ab+");
                    registro_employee = criar_funcionario(int_func_cod, char_func_nome, char_func_cpf, char_func_data_nascimento, double_func_salario); 
                    
                    salvar_funcionario(registro_employee, employeeFile);
                    insertionSort_funcionarios(employeeFile, tamanho_arquivo_de_funcionarios(employeeFile));
                    fclose(employeeFile); free(registro_employee); DestroyWindow(hwnd);
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

LRESULT CALLBACK Window_Search_Employee(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CREATE: {
            createButton(hwnd, "Procurar Funcionario", 1, 10, 10);
            create_Input_Label(hwnd, "Codigo", 2, 10, 50);
            createButton(hwnd, "Procurar", 13, 10, 220);
            createButton(hwnd, "Cancelar", 14, 200, 220);

            break;
        }

        case WM_COMMAND: {
            int wmId = LOWORD(wParam);
            switch (wmId) {
                case 13:

                    GetDlgItemText(hwnd, 2, char_func_cod, sizeof(char_func_cod));
                    int_func_cod = atoi(char_func_cod);
    
                    
                    employeeFile = fopen("src/bin//window_employee.dat", "r");
                    LogFileBinary = fopen("src/bin//window_log.dat", "w");

                    #pragma GCC diagnostic push
                    #pragma GCC diagnostic ignored "-Wimplicit-function-declaration" 
                    #pragma GCC diagnostic ignored "-Wint-conversion"  

                    int tamanho_base = tamanho_arquivo_de_funcionarios(employeeFile);
                    registro_employee = buscarFuncionario_binariamente(int_func_cod, employeeFile, tamanho_base, LogFileBinary);

                    #pragma GCC diagnostic pop 


                    create_and_run_window(Window_Print_Employee, "Window_Print_Employee", "Funcionario Encontrado", WS_OVERLAPPEDWINDOW, 100, 100, SIZE_SUB_WINDOW_X, SIZE_SUB_WINDOW_Y);
                    fclose(employeeFile); fclose(LogFileBinary);

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
