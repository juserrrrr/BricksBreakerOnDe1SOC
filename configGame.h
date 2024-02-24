#ifndef CONFIG_H
#define CONFIG_H

//CORES
#define video_BLACK 0x1000
#define video_GREEN 0x07E0
#define video_WHITE 0xFFFF

// Seta o tamanho da tela
#define SCR_WID  320  // X
#define SCR_HEI  240   // Y

// Seta o tamanho da matriz de caracteres
#define CHAR_WID 80
#define CHAR_HEI 60

// Configuração da parede
#define WALL_SIZE 7 
//-> Parede Superior
#define START_TOP_WALL 30
//-> Parede Esquerda
#define START_LEFT_WALL 0
//-> Parede Direita
#define START_RIGHT_WALL 0

// Configuração do bloco
#define BLK_HEI 8 //Altura do bloco
#define BLK_WID 21 //Tamanho do bloco
#define BLK_SPACE 4 //Espaço a somar junto com o bloco
#define START_SPACE 0 //Espaço entre a parede e o bloco
#define BLK_PER_LINE 12 // 12
#define COLUMNS_BLK 5 //4 


// Configuração do player
#define PLR_WID 40  // Largura do player 26
#define PLR_HEI 3 // Altura
#define PLR_Y   230 // Em qual cordenada y o player deve estar fixo
#define PLR_SENSITIVITY 17  // Sensibilidade do acelerometro
#define PLR_SPD 5  // Velocidade (pixels por frame)

// Configuração da bola
#define BALL_SIZE 2 // Largura da bola
#define BALL_SPD 1// Velocidade (pixels por frame)

#endif

