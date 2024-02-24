#include "configGame.h"
#include "gameBreak.h"

int invertSpeedSignal(int speed)
{
    return speed * -1;
}

// Mostra as paredes na tela
// 320x240, Verificar se precisa ser -1
void showProtectedWalls()
{
    video_box(0, START_TOP_WALL, SCR_WID - 1, WALL_SIZE + START_TOP_WALL, video_WHITE);          // Parede Superior
    video_box(0, START_TOP_WALL, WALL_SIZE, SCR_HEI - 1, video_WHITE);                           // Parede Esquerda
    video_box((SCR_WID - 2) - WALL_SIZE, START_TOP_WALL, SCR_WID - 1, SCR_HEI - 1, video_WHITE); // Parede Direita
}

// Verificar se a bola colidiu com a parede
void checkWallCollision(ballStruct *ball, int *finishGame)
{
    // Se a bola colidir com a parede superior
    if (ball->y1 <= START_TOP_WALL + WALL_SIZE)
    {
        ball->speedY = invertSpeedSignal(ball->speedY);
        printf("colidiu com a parede superior\n");
    }
    // Se a bola colidir com a parede esquerda
    if (ball->x1 <= WALL_SIZE)
    {
        ball->speedX = invertSpeedSignal(ball->speedX);
        printf("colidiu com a parede esquerda\n");
    }
    // Se a bola colidir com a parede direita
    if (ball->x2 >= (SCR_WID - 1) - WALL_SIZE)
    {
        ball->speedX = invertSpeedSignal(ball->speedX);
        printf("colidiu com a parede direita\n");
    }
    // Se a bola colidir com a parede inferior(death)
    if (ball->y2 >= (SCR_HEI - 1))
    {
        *finishGame = 1;
        printf("colidiu com a parede inferior\n");
    }
}

int verifyWin(blockStruct blocks[])
{
    int numberOfBlocks = BLK_PER_LINE * COLUMNS_BLK;
    int numberOfBlocksBreaked = 0;
    for (int i = 0; i < numberOfBlocks; i++)
    {
        if (blocks[i].isBroken)
        {
            numberOfBlocksBreaked += 1;
        }
    }
    return numberOfBlocks == numberOfBlocksBreaked;
}

// Função para ler o acelerometro
int accelRead(int *x, int *y, int *z)
{
    int ready, tap, dtap, mg_per_lsb;
    if (accel_read(&ready, &tap, &dtap, x, y, z, &mg_per_lsb) == 0)
    {
        printf("Erro ao ler o acelerometro\n");
        return 0;
    }
    return 1;
}

// Função para configurar o acelerometro
int accelConfigure()
{
    if (accel_open() == 0)
    {
        printf("Erro ao abrir o acelerometro\n");
        return 0;
    }
    accel_init();
    accel_calibrate();
    accel_format(1, 16);
}

// Executar video_read antes e pegar o tcols e trows
void showScoreName(int *pontosAcumulados, char *nome, int char_x, int char_y)
{

    char msgScore[100] = "Score: ";
    char score[10] = "";
    char msgNome[100] = "Nome: ";

    sprintf(score, "%d", *pontosAcumulados);

    // Concatenando as duas strings
    strcat(msgScore, score);
    strcat(msgNome, nome);

    // printf("%s\n", msgScore);
    // printf("%s\n", msgNome);

    video_erase();
    video_text(1, 1, msgScore);                       // Na posição (1,1) O Score
    video_text(char_x - strlen(msgNome), 1, msgNome); // Na posição (tamaho de colunas de chars - tamanho da Sting, 1) o Nome
}

void menu()
{

    char escolhaEsquerda[] = "->";
    char escolhaDireita[] = "<-";
    char start[] = "Play Game";
    char quit[] = "Quit Game";
    int data;
    int startGame = 0;
    int posYescolha = CHAR_HEI / 2;

    video_erase();
    video_clear();
    video_show();
    while (!startGame)
    {
        video_text((CHAR_WID / 2 - 1) - strlen(start) - strlen(escolhaEsquerda) + 3, posYescolha, escolhaEsquerda);
        video_text((CHAR_WID / 2 - 1) + strlen(start) - strlen(escolhaEsquerda) - 2, posYescolha, escolhaDireita);
        video_text(CHAR_WID / 2 - strlen(start) + 3, CHAR_HEI / 2, start);
        video_text(CHAR_WID / 2 - strlen(quit) + 3, CHAR_HEI / 2 + 6, quit);
        KEY_read(&data);

        if (data == 0b1000)
        {
            if (posYescolha == CHAR_HEI / 2)
            {
                posYescolha += 6;
                video_erase();
            }
            else
            {
                posYescolha -= 6;
                video_erase();
            }
        }

        if (data == 0b0100)
        {
            if (posYescolha == CHAR_HEI / 2)
            {
                startGame = 1;
                video_erase();
            }
            else
            {
                video_erase();
                exit(1);
            }
        }
    }
}

void showFinishGame(char text[])
{
    int sizeX = (CHAR_WID / 2 - 1) - strlen(text) / 2;
    int sizeY = (CHAR_HEI / 2 - 1) - 8 / 2;
    video_text(sizeX, sizeY, text);
}
