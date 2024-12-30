#include <iostream>
#include "raylib.h"
#include <vector>
using namespace std;

class entidade
{
private:
    /* data */
public:
    entidade(/* args */);
    ~entidade();
};

entidade::entidade(/* args */)
{
}

entidade::~entidade()
{
}

class carro : public entidade
{
private:
    /* data */
public:
    carro(/* args */);
    ~carro();
};

carro::carro(/* args */)
{
    
}

carro::~carro()
{
}


class Game
{
private:
    int screenWidth = 0;
    int screenHeight = 0;
    int currentMonitor = 0;
    vector<entidade> entidades;
    int *counter ;



public:
    Game(/* args */);
    void mainLoop(){

    };
    void rendering(){
        ClearBackground(RED);
    };
    ~Game();
};


Game::Game(/* args */)
{
    InitWindow(600,600,"Abrindo");
    currentMonitor = GetCurrentMonitor();
    screenHeight = GetMonitorHeight(currentMonitor);
    screenWidth = GetMonitorWidth(currentMonitor);
    SetWindowSize(screenWidth/2,screenHeight/2);

    while(!WindowShouldClose()){
        mainLoop();
        BeginDrawing();
        rendering();
        EndDrawing();
    }


}



Game::~Game()
{

}



int main(int argc, char const *argv[])
{
    // Game* jogo = new Game(); 
    entidade* teste = new entidade();
    carro* teste2 = new carro();
    int* enderecos[100];
    enderecos[0] = (int*)teste;
    enderecos[1] = (int*)teste2;
    entidade* jogo = (entidade*)enderecos[0];

    cout<< teste2;
    return 0;
}
