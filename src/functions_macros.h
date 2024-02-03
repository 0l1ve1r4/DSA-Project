#ifndef FUNCTIONS_MACROS_H
#define FUNCTIONS_MACROS_H

// Macro definitions
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

#define CREATE_LABEL_AND_PRINT(hwnd, format, value, y_position, id) \
    do { \
        char buffer[256]; \
        sprintf(buffer, format, value); \
        create_Static_Label(hwnd, buffer, 10, y_position, TAMANHO_LABEL_INSERT_Y*2, 20, id); \
    } while(0)

#endif // FUNCTIONS_MACROS_H