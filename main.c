#include "include/raylib.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int screenwidth = 600;
int screenheight = 600;

float entityWidth = 30;
float entityHeight = 30;




typedef enum{
  RIGHT = 0,
  LEFT = 1,
  DOWN = 2,
  UP = 3

} directions;

typedef struct Snake{
  Rectangle* head;
  Rectangle* body;
  int size; }Snake;

void moviment(Rectangle* rect,int atualMoviment, double* timeCeil){
  double totalTime = GetTime();
  
  // printf("\n%lf %lf",totalTime, *timeCeil);

  if(totalTime >= *timeCeil ){
    switch (atualMoviment) {
      case RIGHT:
        rect->x += rect->width;
        if(rect->x >= screenwidth){
          rect->x = 0;
        }
        break;
      case LEFT:
        rect->x -= rect->width;

        if(rect->x < 0){
          rect->x = screenwidth - rect->width;
        }
      break;
      case DOWN:
        rect->y += rect->width;
        if(rect->y >= screenheight){
          rect->y = 0;
        }
      break;
      case UP:
        rect->y -= rect->width;
        if(rect->y < 0){
          rect->y = screenheight - rect->height;
        }
      break;

      default:
        break;
    }
  *timeCeil = totalTime + 0.3;
  }
}

void ChangeMoviment(int* atualMoviment){
  int teclaPressionada = GetKeyPressed();
  if(teclaPressionada){
    switch (teclaPressionada) {
      case KEY_W :
        if(*atualMoviment != DOWN)
          *atualMoviment = UP;
        break;
        
      case KEY_S :
        if(*atualMoviment != UP)
          *atualMoviment = DOWN;
        break;

      case KEY_A :
        if(*atualMoviment != RIGHT)
          *atualMoviment = LEFT;
        break;

      case KEY_D:
        if(*atualMoviment != LEFT)
          *atualMoviment = RIGHT;
        break;
        

      default:

      break;
    }
  }
}


Rectangle* fruitFunctionality(Rectangle* fruit, Rectangle* cabeca){
  SetRandomSeed(time(NULL));
  int posX = GetRandomValue(0, screenwidth/entityWidth)*entityWidth;
  int posY = GetRandomValue(0, screenheight/entityHeight)*entityHeight;
  if(fruit == NULL){
   fruit= malloc(sizeof(Rectangle));
   fruit->x = posX;
   fruit->y = posY;
   fruit->width = entityWidth;
   fruit->height = entityHeight;
  } 
  
  if(cabeca->x == fruit->x && cabeca->y == fruit->y){
    free(fruit);
    fruit = NULL;
  }

  return fruit;
}


Snake* initSnake(){
  Snake* snake = (Snake*)malloc(sizeof(Snake));
  snake->body = (Rectangle*)malloc((screenheight/entityHeight) * (screenwidth/entityWidth) * sizeof(Rectangle));
  snake->size = 0;
  return snake;
}



int main(int argc, char *argv[])
{

  Snake* snake = initSnake();
  
  Rectangle* fruit = NULL;


  Rectangle cabeca = {
    300 - 30,
    300 - 30,
    30,
    30
  };

  int atualMoviment = RIGHT;
  
  double timeCeil = 0;
  InitWindow(600, 600, "telinha");
  SetTargetFPS(120);
  
  while(!WindowShouldClose()){

    ChangeMoviment(&atualMoviment);
    //TODO PENSAR MELHOR NESSE MOVIMENTO DA COBRA O CORPO NN SE MOVIMENTA JUNTO COM A COBRA
    moviment(&cabeca,atualMoviment,&timeCeil);
    for(int i =0; i<snake->size;i++){
      moviment(&cabeca,atualMoviment,&timeCeil);
    }
    

    fruit = fruitFunctionality(fruit,&cabeca);

    BeginDrawing();
    ClearBackground(LIGHTGRAY);

    if(fruit != NULL){
      DrawRectangleRec(*fruit,PINK);
    }

    DrawRectangleRec(cabeca, RED);

    for(int i = 0;i<screenwidth/30;i++){
      DrawLine(i*30, 0, i*30, screenheight, BLACK);
    }
    for(int i = 0;i<screenwidth/30;i++){
      DrawLine(0, i*30, screenwidth, i*30, BLACK);
    }
    EndDrawing();
  }
  return 0;
}
