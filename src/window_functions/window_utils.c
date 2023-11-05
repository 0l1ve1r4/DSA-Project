#include <windows.h>

void removeExpandButton(HWND hwnd){


    LONG_PTR style = GetWindowLongPtr(hwnd, GWL_STYLE);
    style = style & ~WS_MAXIMIZEBOX; 
    SetWindowLongPtr(hwnd, GWL_STYLE, style);
    SetWindowPos(hwnd, NULL, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE | SWP_NOZORDER | SWP_FRAMECHANGED);


}

void set_icon(HWND hwnd, char* path){

    HICON hIcon = (HICON)LoadImage(NULL, path, IMAGE_ICON, 0, 0, LR_LOADFROMFILE);

    if (hIcon != NULL)
                SendMessage(hwnd, WM_SETICON, ICON_BIG, (LPARAM)hIcon); 
                
    else
                printf("Window Debug: Icone nao encontrado\n");



}


void rmvBin() {
    int result = MessageBox(NULL, "Isso vai apagar TUDO, deseja continuar?", "Confirmacao", MB_ICONQUESTION | MB_YESNO);

    if (result == IDYES) {
        int deleteResult = system("del src\\bin\\*.dat");
        if (deleteResult == 0) {
            MessageBox(NULL, "Arquivos apagados. (Verifique Manualmente)", "Aviso", MB_ICONINFORMATION | MB_OK);
        } 

}
}


