#include "configGame.h"
#include "gameBreak.h"



ballStruct createBall(){
    ballStruct ball;
    ball.x1 = 161; // Meio da tela 161
    ball.y1 = 221; // Meio da tela 221
    ball.x2 = ball.x1 + BALL_SIZE; // Meio da tela
    ball.y2 = ball.y1 + BALL_SIZE; // Meio da tela
    ball.speedX = BALL_SPD; // Velocidade da bola no eixo x
    ball.speedY = -BALL_SPD; // Velocidade da bola no eixo y
    ball.color = video_WHITE;
    return ball;
}
// Mover a bola de acordo com o angulo
void moveBall(ballStruct *ball){
    // Calcula o valor de X e Y de acordo com o angulo
    ball->x1 += ball->speedX;
    ball->y1 += ball->speedY;
    ball->x2 = ball->x1 + BALL_SIZE;
    ball->y2 = ball->y1 + BALL_SIZE;
}

int checkBallCollision(ballStruct *ball, int x, int y, int height, int width){
    return ball->x1 <= x + width && ball->x2 >= x && ball->y1 <= y + height && ball->y2 >= y;
}

//Função que verica qual lado da bola colidiu com alguma estrutura dos lados ou em em cima e em baixo
void calculateBallCollision(ballStruct *ball, int x, int y, int height, int width){
    // Se a bola colidir verticalmente
    if (ball->y1 >= y && ball->y2 <= y + height){
        ball->speedX = invertSpeedSignal(ball->speedX);

    }
    // Se a bola colidir horizontalmente
    else if (ball->x1 >= x && ball->x2 <= x + width){
        ball->speedY = invertSpeedSignal(ball->speedY);
    }
    // Acho que dá pra juntar e virar um ELSE só (Esse caso ele verifica se tocou numa quina)
    else {
        ball->speedY = invertSpeedSignal(ball->speedY);
        ball->speedX = invertSpeedSignal(ball->speedX);
    }
}

// Mostra a bola redonda na tela
void showBall(ballStruct *ball){
    video_box(
        ball->x1,
        ball->y1, 
        ball->x2, 
        ball->y2, 
        ball->color
    );
}