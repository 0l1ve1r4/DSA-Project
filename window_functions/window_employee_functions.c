#include <windows.h>
#include <stdio.h>

#include "../funcionario.h"
#include "../buscas_binarias.h"

int cod;
char codText_Employee[50];
char nome[50];
char cpf[15];
char data_nascimento[11];
double salario;
char salarioText[50];

TFunc *registro_employee;

#define TAMANHO_LABEL_INSERT_Y 200
#define DISTANCIA_BOTOES_Y 50


LRESULT CALLBACK Window_Print_Employee(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CREATE: {

            if (registro_employee != NULL){

            char cod_print[11];
            char nome_print[50];
            char cpf_print[30];
            char data_nascimento_print[50];
            char salario_print[40];

            sprintf(cod_print, "Codigo: %i", registro_employee->cod);
            sprintf(nome_print, "Nome: %s", registro_employee->nome);
            sprintf(cpf, "Cpf: %s", registro_employee->cpf);
            sprintf(data_nascimento, "Data Nascimento: %s", registro_employee->data_nascimento);
            sprintf(salario_print, "Salario: %s", registro_employee->salario);

            //CreateWindow("BUTTON", "Registrar Funcionario", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 10, DISTANCIA_BOTOES_Y*2, TAMANHO_BOTOES_Y, 30, hwnd, (HMENU)3, NULL, NULL);
            CreateWindow("STATIC", cod_print, WS_VISIBLE | WS_CHILD, 10, 0, TAMANHO_LABEL_INSERT_Y, 20, hwnd, NULL, NULL, NULL);
            CreateWindow("STATIC", nome_print, WS_VISIBLE | WS_CHILD, 10, DISTANCIA_BOTOES_Y, TAMANHO_LABEL_INSERT_Y, 20, hwnd, NULL, NULL, NULL);
            CreateWindow("STATIC", cpf_print, WS_VISIBLE | WS_CHILD, 10, DISTANCIA_BOTOES_Y*2, TAMANHO_LABEL_INSERT_Y, 20, hwnd, NULL, NULL, NULL);
            CreateWindow("STATIC", data_nascimento_print, WS_VISIBLE | WS_CHILD, 10, DISTANCIA_BOTOES_Y*3, TAMANHO_LABEL_INSERT_Y, 20, hwnd, NULL, NULL, NULL);
            CreateWindow("STATIC", salario_print, WS_VISIBLE | WS_CHILD, 10, DISTANCIA_BOTOES_Y*4, TAMANHO_LABEL_INSERT_Y, 20, hwnd, NULL, NULL, NULL);

            break;}

        else{

            CreateWindow("STATIC", "Funcionario nao encontrado", WS_VISIBLE | WS_CHILD, 10, 50, TAMANHO_LABEL_INSERT_Y*2, 20, hwnd, NULL, NULL, NULL);
            break;}


        
        }
        case WM_COMMAND: {
            int wmId = LOWORD(wParam);
            switch (wmId) {
                // ----
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


int print_Employee() {
    // Registrar a classe da janela
    WNDCLASS wc = {0};
    wc.lpfnWndProc = Window_Print_Employee;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "Window_Print_Employee_Class";
    RegisterClass(&wc);

    // Criar a janela
    HWND hwnd = CreateWindow("Window_Print_Employee_Class", "Buscar Funcionario", WS_OVERLAPPEDWINDOW, 100, 100, 400, 300, NULL, NULL, GetModuleHandle(NULL), NULL);

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
LRESULT CALLBACK Window_Insert_Employee(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CREATE: {
            // Criar os botões e caixas de texto
            CreateWindow("BUTTON", "Inserir Funcionario", WS_VISIBLE | WS_CHILD, 10, 10, 150, 30, hwnd, (HMENU)1, NULL, NULL);
            CreateWindow("STATIC", "Codigo:", WS_VISIBLE | WS_CHILD, 10, 50, 100, 20, hwnd, NULL, NULL, NULL);
            CreateWindow("EDIT", "0", WS_VISIBLE | WS_CHILD | WS_BORDER, 110, 50, TAMANHO_LABEL_INSERT_Y, 20, hwnd, (HMENU)2, NULL, NULL);

            CreateWindow("STATIC", "Nome:", WS_VISIBLE | WS_CHILD, 10, 70, 100, 20, hwnd, NULL, NULL, NULL);
            CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 110, 70, TAMANHO_LABEL_INSERT_Y, 20, hwnd, (HMENU)3, NULL, NULL);

            CreateWindow("STATIC", "CPF:", WS_VISIBLE | WS_CHILD, 10, 90, 100, 20, hwnd, NULL, NULL, NULL);
            CreateWindow("EDIT", "000.000.000-XX", WS_VISIBLE | WS_CHILD | WS_BORDER, 110, 90, TAMANHO_LABEL_INSERT_Y, 20, hwnd, (HMENU)4, NULL, NULL);

            CreateWindow("STATIC", "Nascimento:", WS_VISIBLE | WS_CHILD, 10, 110, 100, 20, hwnd, NULL, NULL, NULL);
            CreateWindow("EDIT", "02/11/1980", WS_VISIBLE | WS_CHILD | WS_BORDER, 110, 110, TAMANHO_LABEL_INSERT_Y, 20, hwnd, (HMENU)5, NULL, NULL);

            CreateWindow("STATIC", "Salario:", WS_VISIBLE | WS_CHILD, 10, 130, 100, 20, hwnd, NULL, NULL, NULL);
            CreateWindow("EDIT", "0.0", WS_VISIBLE | WS_CHILD | WS_BORDER, 110, 130, TAMANHO_LABEL_INSERT_Y, 20, hwnd, (HMENU)6, NULL, NULL);

            CreateWindow("BUTTON", "Adicionar", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 10, 200, 100, 30, hwnd, (HMENU)13, NULL, NULL);
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

                    // Check for conversion errors, if necessary
                    if (salario == 0.0 && errno == ERANGE || cod == 0 && codText_Employee[0] != '0') {
                        printf("Error converting to some variable \n");
                        return 1;
                    } else { printf("Salario: %lf\n", salario); }

                    FILE *employeeFile;
                    employeeFile = fopen("bin//employeeFileBinary.dat", "ab+");
                    TFunc *temp = criar_funcionario(cod, nome, cpf, data_nascimento, salario); 
                    salvar_funcionario(temp, employeeFile);


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

int insert_employee() {
    // Registrar a classe da janela
    WNDCLASS wc = {0};
    wc.lpfnWndProc = Window_Insert_Employee;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "Window_Insert_Employee_Class";
    RegisterClass(&wc);

    // Criar a janela
    HWND hwnd = CreateWindow("Window_Insert_Employee_Class", "Registrar Funcionario", WS_OVERLAPPEDWINDOW, 100, 100, 400, 300, NULL, NULL, GetModuleHandle(NULL), NULL);

    ShowWindow(hwnd, SW_SHOWDEFAULT);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

//___________________________________________________*___________________________________________________

LRESULT CALLBACK Window_Search_Employee(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CREATE: {
            // Criar os botões e caixas de texto
            CreateWindow("BUTTON", "Procurar Funcionario", WS_VISIBLE | WS_CHILD, 10, 10, 150, 30, hwnd, (HMENU)1, NULL, NULL);
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
                        break; } else
                        { printf("Window Debug: Codigo: %d\n", cod);}
                    

                    FILE *employeeFileBinary, *LogFileBinary;
                    
                    employeeFileBinary = fopen("bin//employeeFileBinary.dat", "r");
                    LogFileBinary = fopen("bin//logBinary.dat", "w");

                    #pragma GCC diagnostic push
                    #pragma GCC diagnostic ignored "-Wimplicit-function-declaration" // Nao faço a minima ideia pq ta dando essas warning com o header incluido,
                    #pragma GCC diagnostic ignored "-Wint-conversion"   // Apenas fingindo que nao ta acontecendo...

                    registro_employee = buscarFuncionario_binariamente(cod, employeeFileBinary, 10000, LogFileBinary);
                    registro_employee != NULL ? printf("\nWindow Debug: Funcionario encontrado com sucesso!"): printf("\nWindow Debug: Funcionario nao encontrado!");

                    #pragma GCC diagnostic pop // Volta a mostrar os warnings

                    print_Employee();

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

int search_employee() {
    // Registrar a classe da janela
    WNDCLASS wc = {0};
    wc.lpfnWndProc = Window_Search_Employee;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "Window_Search_Employee_Class";
    RegisterClass(&wc);

    // Criar a janela
    HWND hwnd = CreateWindow("Window_Search_Employee_Class", "Buscar Livro no Banco de Dados", WS_OVERLAPPEDWINDOW, 100, 100, 400, 300, NULL, NULL, GetModuleHandle(NULL), NULL);

    ShowWindow(hwnd, SW_SHOWDEFAULT);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}