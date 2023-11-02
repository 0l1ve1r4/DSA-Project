#include <windows.h>
#include <stdio.h>

#include "../funcionario.h"

int cod;
char codText_Employee[50];
char nome[50];
char cpf[15];
char data_nascimento[11];
double salario;
char salarioText[50];


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
                    employeeFile = fopen("bin//employeeFileBinary", "ab+");
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