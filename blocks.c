#include "configGame.h"
#include "gameBreak.h"



// Cria a instancia do bloco
blockStruct createBreakableBlock(int x1, int y1, int x2, int y2){
    blockStruct block;
    block.x1 = x1;
    block.y1 = y1;
    block.x2 = x2;
    block.y2 = y2;
    block.isBroken  = 0;
    block.color = video_WHITE;
    return block;
}

// gerar todos os blocos do jogo
void generateBlocks(blockStruct blocks[]){
    int startX = WALL_SIZE + START_SPACE; // Valor inicial de X
    int startY = START_TOP_WALL + (WALL_SIZE + START_SPACE); // Valor inicial de Y
    int blockMoreSpace = BLK_WID + BLK_SPACE; // Soma do espaço com a largura do bloco

    for (int i = 0; i < COLUMNS_BLK; i++){
        for (int j = 0; j < BLK_PER_LINE; j++){
            // Calcula o index do bloco
            int index = i * BLK_PER_LINE + j;
            blocks[index] = createBreakableBlock(
                startX + BLK_SPACE, // Primeira coluna
                startY + BLK_SPACE, // Primeira linha
                startX + blockMoreSpace, // Segunda coluna
                startY + BLK_HEI + BLK_SPACE // Segunda linha
            );
            // Aumentar o valor de startX para os proximos blocos
            startX += blockMoreSpace;
        }
        // Resetar o valor de startX e aumentar o valor de startY
        startX = WALL_SIZE + START_SPACE;
        startY += BLK_HEI + BLK_SPACE;
    }
}

// Verificar se a bola colidiu com um bloco quebravel
//TRABALHAR MELHOR NESSA FUNÇÃO
void checkBlockCollision(ballStruct *ball, blockStruct blocks[], int * score){
    int numberOfBlocks = BLK_PER_LINE*COLUMNS_BLK;
    int isBrokeBlock = 0;
    for (int i = 0; i < numberOfBlocks; i++){
        // Verificar se o bloco está quebrado, se não estiver, verificar a colisão
        if (!blocks[i].isBroken){
            // Verificar colisão entre a bola e o bloco
            if (checkBallCollision(ball, blocks[i].x1, blocks[i].y1, BLK_HEI, BLK_WID)){
                // Quebrar o bloco e inverter o ângulo da bola
                if(!isBrokeBlock){
                    calculateBallCollision(ball, blocks[i].x1, blocks[i].y1, BLK_HEI, BLK_WID);
                    isBrokeBlock = 1;
                    ball->color = blocks[i].color;
                }
                *score += 100;
                blocks[i].isBroken = 1;
                
                printf("Colidindo com o bloco %d\n", i); 
            }
        }
    }
}

// Mostra os blocos na tela
void showBlocks(blockStruct blocks[]){
    int numberOfBlocks = BLK_PER_LINE*COLUMNS_BLK;
    int startColor = 0x7B68EE;
    int valueToSum = 0x2323; // 2323
    int count = 0;
    for (int i = 0; i < numberOfBlocks; i++){
        count+=1;
        //Verificar se o bloco está quebrado, se não estiver, desenhar
        if (blocks[i].isBroken == 0){
            blocks[i].color = startColor;
            video_box(blocks[i].x1, blocks[i].y1, blocks[i].x2, blocks[i].y2, startColor);
        }
        if(count == BLK_PER_LINE){
            startColor += valueToSum;
            count=0;
        }
    }
}