#include "configGame.h"
#include "gameBreak.h"



// Cria a instancia do player
playerStruct createPlayer(){
    playerStruct player;
    player.x = (SCR_WID/2) - (PLR_WID/2) -1; // Meio da tela
    player.y = PLR_Y;
    player.color = video_WHITE;
    return player;
}

// Mover o player de acordo com o valor do X do acelerometro
void movePlayer(playerStruct *player, int x){

    int moduleX = (int) x / PLR_SENSITIVITY;


    if (moduleX > PLR_SPD){
        moduleX = PLR_SPD;
    } else if (moduleX < PLR_SPD * -1){
        moduleX = PLR_SPD * -1;
    }

    player->x += moduleX;


    // Se o valor de x for menor que 20, mover para a esquerda e verificar se o player não está na parede da esquerda
    if (player-> x <= WALL_SIZE){
        player->x = WALL_SIZE;
    // Se o valor de x for maior que 20, mover para a direita e verificar se o player não está na parede da direita
    } else if ((player->x + PLR_WID) >= (SCR_WID - WALL_SIZE)){
        player->x = SCR_WID - WALL_SIZE - PLR_WID;
    }
}

// Verificar se a bola colidiu com o player, se ele pingar na metade 
void checkPlayerCollision(ballStruct *ball, playerStruct *player){
    // Se a bola colidir com o player
    int centerSize = 6;
    if (ball->speedY > 0 &&checkBallCollision(ball, player->x, player->y, PLR_HEI, PLR_WID)){
        // Verificar se ela colidiu na metade do player e o angulo dele, para inverter a jogada
        if (ball->x2 >= player->x + PLR_WID/2 + centerSize && ball->speedX < 0 && ball->speedY > 0){
            ball->speedX = invertSpeedSignal(ball->speedX);
            ball->speedY = invertSpeedSignal(ball->speedY);
        }
        else if (ball->x1 <= player->x + PLR_WID/2 - centerSize && ball->speedX > 0 && ball->speedY > 0){
            ball->speedX = invertSpeedSignal(ball->speedX);
            ball->speedY = invertSpeedSignal(ball->speedY);
        }else if(ball->x1 >= player->x + PLR_WID/2 - centerSize && ball->x2 <= player->x + PLR_WID/2 + centerSize){
            ball->speedX = 0;
            ball->speedY = invertSpeedSignal(ball->speedY);
        }else if (ball->speedX == 0) {
            ball->speedY = invertSpeedSignal(ball->speedY);
            if(ball->x2 <= player->x + PLR_WID/2 - centerSize){
                ball->speedX = BALL_SPD * -1;
            }else {
                ball->speedX = BALL_SPD;
            }
        }
        // se cair do lado normal
        else{
            ball->speedY = invertSpeedSignal(ball->speedY);
        }
    }
}

// Mostra o player na tela
void showPlayer(playerStruct *player){
    video_box(
        player->x,
        player->y, 
        player->x + PLR_WID, 
        player->y + PLR_HEI, 
        player->color
    );
}