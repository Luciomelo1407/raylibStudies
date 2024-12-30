#include <stdlib.h>

int main(){
    system("g++ -o saida.exe main.cpp -lraylib -lgdi32 -lwinmm");
    system("saida.exe");
    return 0;
}