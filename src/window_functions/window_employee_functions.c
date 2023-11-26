#include "window_employee_functions.h"


int cod;
char codText_Employee[50];
char nome[50];
char cpf[15];
char data_nascimento[11];
double salario;
char salarioText[50];

TFunc *registro_employee;

#define TAMANHO_LABEL_INSERT_Y 400
#define DISTANCIA_BOTOES_Y 50

LRESULT CALLBACK Window_Print_Employee(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CREATE: {

            if (registro_employee != NULL){

            char cod_print[50];
            char nome_print[50];
            char cpf_print[50];
            char data_nascimento_print[50];
            char salario_print[50];

            sprintf(cod_print, "Codigo: %i", registro_employee->cod);
            sprintf(nome_print, "Nome: %s", registro_employee->nome);
            sprintf(cpf_print, "Cpf: %s", registro_employee->cpf);
            sprintf(data_nascimento_print, "Data Nascimento: %s", registro_employee->data_nascimento);
            sprintf(salario_print, "Salario: %d", registro_employee->salario);

            
            createButton(hwnd, "Funcionario Encontrado", 0, 10, 0);
            create_Static_Label(hwnd, cod_print, 10, DISTANCIA_BOTOES_Y, TAMANHO_LABEL_INSERT_Y, 20, 1);
            create_Static_Label(hwnd, nome_print, 10, DISTANCIA_BOTOES_Y+20, TAMANHO_LABEL_INSERT_Y, 20, 2);
            create_Static_Label(hwnd, cpf_print, 10, DISTANCIA_BOTOES_Y+40, TAMANHO_LABEL_INSERT_Y, 20, 3);
            create_Static_Label(hwnd, data_nascimento_print, 10, DISTANCIA_BOTOES_Y+60, TAMANHO_LABEL_INSERT_Y, 20, 4);
            create_Static_Label(hwnd, salario_print, 10, DISTANCIA_BOTOES_Y+80, TAMANHO_LABEL_INSERT_Y, 20, 5);


            break;
            
            }

        else {
            error_message("Funcionario nao encontrado", "Erro");
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

LRESULT CALLBACK Window_Insert_Employee(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CREATE: {
            
        createButton(hwnd, "Inserir Funcionario", 1, 10, 10);
        create_Input_Label(hwnd, "Codigo:", 2, 10, 50);
        create_Input_Label(hwnd, "Nome:", 4, 10, 70);
        create_Input_Label(hwnd, "CPF:", 6, 10, 90);
        create_Input_Label(hwnd, "Nascimento:", 8, 10, 110);
        create_Input_Label(hwnd, "Salario:", 10, 10, 130);
        createButton(hwnd, "Adicionar", 13, 10, 200);


            break;
        }
        case WM_COMMAND: {
            int wmId = LOWORD(wParam);
            switch (wmId) {
                case 13:

                    GetDlgItemText(hwnd, 2, codText_Employee, sizeof(codText_Employee));
                    GetDlgItemText(hwnd, 3, nome, sizeof(nome));
                    GetDlgItemText(hwnd, 4, cpf, sizeof(cpf));
                    GetDlgItemText(hwnd, 5, data_nascimento, sizeof(data_nascimento));
                    GetDlgItemText(hwnd, 6, salarioText, sizeof(salario));
                    salario = strtod(salarioText, NULL);
                    cod = atoi(codText_Employee);

                    if (salario == 0.0 && errno == ERANGE || cod == 0 && codText_Employee[0] != '0') {
                        printf("Window Debug: Erro ao converter o salario para double\n");
                        return 1;
                    } else { 
                        
                        printf("Window Debug: Codigo %i | Nome %s | CPF %s | Data Nascimento %s | Salario %f\n", cod, nome, cpf, data_nascimento, salario);
                        printf("Window Debug: Conversoes realizadas com sucesso\n");
                    }

                    FILE *employeeFile;
                    employeeFile = fopen("src/bin//window_employee.dat", "ab+");
                    TFunc *temp = criar_funcionario(cod, nome, cpf, data_nascimento, salario); 
                    salvar_funcionario(temp, employeeFile);
                    
                    insertionSort_funcionarios(employeeFile, tamanho_arquivo_de_funcionarios(employeeFile));
                    fclose(employeeFile);
                    free(temp);
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
            create_Input_Label(hwnd, "Codigo", 2, 0, 50);
            createButton(hwnd, "Procurar", 13, 10, 200);

            break;
        }

        case WM_COMMAND: {
            int wmId = LOWORD(wParam);
            switch (wmId) {
                case 13:

                    GetDlgItemText(hwnd, 2, codText_Employee, sizeof(codText_Employee));
                    cod = atoi(codText_Employee);

                    if (cod == 0 && codText_Employee[0] != '0') {
                        printf("Window Debug: Erro ao converter o texto do inteiro \n");
                        break; 
                    } 
                    
                    else { 
                        printf("Window Debug: Numero Convertido para double: %d\n", cod);
                    }
                    

                    FILE *employeeFileBinary, *LogFileBinary;
                    employeeFileBinary = fopen("src/bin//window_employee.dat", "r");
                    LogFileBinary = fopen("src/bin//window_log.dat", "w");

                    #pragma GCC diagnostic push
                    #pragma GCC diagnostic ignored "-Wimplicit-function-declaration" 
                    #pragma GCC diagnostic ignored "-Wint-conversion"  

                    int tamanho_base = tamanho_arquivo_de_funcionarios(employeeFileBinary);
                    registro_employee = buscarFuncionario_binariamente(cod, employeeFileBinary, tamanho_base, LogFileBinary);
                    registro_employee != NULL ? printf("Window Debug: Funcionario encontrado. \n"): printf("Window Debug: Funcionario nao encontrado. \n");

                    #pragma GCC diagnostic pop 

                    create_and_run_window(Window_Print_Employee, "Window_Print_Employee", "Funcionario Encontrado", WS_OVERLAPPEDWINDOW, 100, 100, SIZE_SUB_WINDOW_X, SIZE_SUB_WINDOW_Y);

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
