#ifndef GAMEBREAK_H
#define GAMEBREAK_H
#include <intelfpgaup/KEY.h>
#include <intelfpgaup/video.h>
#include <intelfpgaup/accel.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
  
  typedef struct{
      int x, y; // Valor inicial de X e Y do player
      int color;
  } playerStruct;
  
  typedef struct{
      int x1, y1;
      int x2, y2;
      int isBroken ; // 1 = broken, 0 = not broken
      int color;
  } blockStruct;
  
  typedef struct{
      int x1, y1; // Valor inicial de X e Y da bola
      int x2, y2; // Valor final de X e Y da bola
      int speedX; // Velocidade da bola no eixo X
      int speedY; // Velocidade da bola no eixo Y
      int color; // Cor da bola
  } ballStruct;
  
  // Funções relaciona aos blocos
  blockStruct createBreakableBlock(int x1, int y1, int x2, int y2);
  void generateBlocks(blockStruct blocks[]);
  void checkBlockCollision(ballStruct *ball, blockStruct blocks[], int * score);
  void showBlocks(blockStruct blocks[]);
  
  // Funções relacionadas ao player
  playerStruct createPlayer();
  void movePlayer(playerStruct *player, int x);
  void checkPlayerCollision(ballStruct *ball, playerStruct *player);
  void showPlayer(playerStruct *player);
  
  // Funções relacionadas a parede
  
  void showProtectedWalls();
  void checkWallCollision(ballStruct *ball, int *finishGame);
  
  // Funções relacionadas a bola
  ballStruct createBall();
  void moveBall(ballStruct *ball);
  int checkBallCollision(ballStruct *ball, int x, int y, int height, int width);
  void calculateBallCollision(ballStruct *ball, int x, int y, int height,int width);
  void showBall(ballStruct *ball);
  
  // utils
  int invertSpeedSignal(int speed);
  int accelConfigure();
  int accelRead(int *x, int *y, int *z);    
  void showFinishGame(char text[]);
  int verifyWin(blockStruct blocks[]);
  void menu();
  void showScoreName(int * pontosAcumulados, char *nome, int char_x, int char_y);

  
  #endif