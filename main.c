#include "gameBreak.h"
#include "configGame.h"

volatile sig_atomic_t stop;
void catchSIGINT(int signum)
{
    stop = 1;
}

int screen_x, screen_y;
int char_x, char_y;

void initializeGame(playerStruct *player, ballStruct *ball, blockStruct blocks[], int *isLoser, int *score)
{
    *score = 0;
    *isLoser = 0;
    *player = createPlayer();
    *ball = createBall();
    generateBlocks(blocks);
}

void renderGameElements(playerStruct *player, ballStruct *ball, blockStruct blocks[])
{
    showProtectedWalls();
    showBlocks(blocks);
    showPlayer(player);
    showBall(ball);
    video_show();
}

void updateGameState(playerStruct *player, ballStruct *ball, blockStruct blocks[], int x, int *isLoser, int *score)
{
    video_clear();
    moveBall(ball);
    movePlayer(player, x);
    checkWallCollision(ball, isLoser);
    checkBlockCollision(ball, blocks, score);
    checkPlayerCollision(ball, player);
}

int main()
{
    signal(SIGINT, catchSIGINT);
    KEY_close();
    if (!KEY_open() || !video_open())
        return -1;

    video_read(&screen_x, &screen_y, &char_x, &char_y);

    // Configura o acelerometro
    accelConfigure();
    // Inicializa as estruturas do jogo
    char msgPaused[10] = "Paused";
    int x, y, z;
    int isLoser = 0;
    int isWinner = 0;
    int isPaused = 0;
    int score = 0;
    int lastScore = 0;
    char nome[] = "Dengoso";
    int btn;
    playerStruct player;
    ballStruct ball;
    int totalBlocks = BLK_PER_LINE*COLUMNS_BLK;
    blockStruct blocks[totalBlocks];

    KEY_read(&btn);
    while (1)
    { // Responsável pelo Menu

        showScoreName(&score, nome, char_x, char_y);
        menu();
        // Resentando variaveis do jogo
        video_erase(); // Tira todo o texto da tela.
        initializeGame(&player, &ball, blocks, &isLoser, &score);
        showScoreName(&score, nome, char_x, char_y);
        while (isLoser < 1 && !isWinner)
        { // Responsável pelo jogo
            KEY_read(&btn);
            if (btn == 8)
            {
                video_erase();
                showScoreName(&score, nome, char_x, char_y);
                isPaused = !isPaused;
            }
            if (!isPaused)
            {
                if (score != lastScore)
                {
                    showScoreName(&score, nome, char_x, char_y);
                    lastScore = score;
                }
                accelRead(&x, &y, &z);
                updateGameState(&player, &ball, blocks, x, &isLoser, &score);
                renderGameElements(&player, &ball, blocks);
                isWinner = verifyWin(blocks);
            }
            else
            {
                video_text(37, 36, msgPaused); // Na posição (tamaho de colunas de chars - tamanho da Sting, 1) o Nome
            }
        }
        video_clear();
        video_show();
        if (isWinner)
        {
            showFinishGame("Game Winner");
        }
        else
        {
            showFinishGame("Game Over");
        }
        sleep(3);
    }
    return 0;
}