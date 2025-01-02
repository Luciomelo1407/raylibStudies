#include <stdlib.h>

int main(){
    system("gcc -o saida.exe main.c -lraylib -lgdi32 -lwinmm");
    system("saida.exe");
    return 0;
}
