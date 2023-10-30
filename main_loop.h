#ifndef MAIN_LOOP_H
#define MAIN_LOOP_H

#include "sequential_search.h"
#include <stdlib.h>


void init_main_loop();
void main_loop(FILE *funcionaryFile, FILE *booksFile, FILE *editorsFile);

#endif // MAIN_LOOP_H
