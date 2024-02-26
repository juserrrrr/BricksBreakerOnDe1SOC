# BricksBreakerOnDe1SOC

## Introdução

## Metodologia

Para a metodologia empregada na construção do projeto solicitado, adotamos uma abordagem que valoriza a modularização e flexibilidade. Utilizamos diversas ferramentas, realizando a leitura e análise dos datasheets correspondentes. A estrutura do projeto foi dividida em partes, com a incorporação de variáveis de configuração, permitindo ajustes conforme as preferências do usuário. Essa abordagem não apenas facilita a manutenção do código, mas também aprimora a legibilidade e assegura escalabilidade. A base do projeto contém instruções essenciais, estabelecendo uma estrutura adaptável para futuras adições de maneira eficiente.

As ferramentas utilizadas no desenvolvimento do projeto foram:

- Kit FPGA DE1-SoC.
- Visual Studio Code para escrita do código em C e Terminal Linux para conexão SSH com a DE1-SoC, compilação e execução do código.
- Lucidchart, para construção de fluxogramas.

Após o conhecimento e análise das ferramentas, o projeto foi dividido nas seguintes etapas, em ordem cronológica:

1. Funções existentes do sistema do Kit (lintelfpgaup)

   1. Leitura do manual em relação ao acesso aos seus dispositivos, como botões, acelerômetro, saída de vídeos e afins.
   2. Utilização das mesmas como forma de auxílio na construção do projeto.

2. Configuração dos dispositivos essenciais

   1. Utilização das funções para configurar o acelerômetro, os botões e também a saída de vídeo.
   2. Definição de onde as funções vão ser usadas no código.
   3. Decisão de quais botões seriam usados para as suas respectivas funções.

3. Construção do jogo

   1. Pesquisas básicas para entender a melhor forma de programar o jogo.
   2. Criação de funções específicas para controle do jogo.
   3. Testes de colisões entre a bola e os blocos através de debuggers.
   4. Constantes pré-configuradas para um ajuste completo do jogo.

4. Integração das funções das placas com as do jogo

   1. Decisão de como o jogo iria ser renderizado (Limpando elementos específicos, ou recriando os mesmos no buffer).
   2. Aplicação dos códigos de geração do píxel de vídeo dentro das funções de exibição do jogo.
   3. Transferindo os valores lidos do acelerômetro para a função de movimento do jogador (raquete).
   4. Aplicando as funções dos botões no fluxo do programa (Opção do menu, pausar, continuar, iniciar e sair).
   5. Telas já pré-moldadas do menu, tela de vitória e derrota, encaixando-as no fluxo do programa.

5. Ajustes finais

   1. Testar o jogo e, ao decorrer de situações inesperadas, ajustar o código final.
   2. Melhorias no fluxo do programa.
   3. Ajuste fino no jogo através das constantes de configurações.

## Descrição do Projeto:

### Acelerometro(G-Sensor)

A placa vem com um módulo de sensor de acelerômetro digital (ADXL345), comumente conhecido como G-sensor. Este G-sensor é um acelerômetro de 3 eixos pequeno, fino e de baixissimo consumo de energia, com medição de alta resolução. A saída digitalizada é formatada como 16 bits em complemento de dois e pode ser acessada por meio da interface I2C.

Conforme mencionado anteriormente, existem funções pré-configuradas para facilitar o uso do dispositivo. Inicialmente, foi necessário realizar a inicialização do sensor, seguida pela etapa de calibração e, por fim, a formatação dos dados recebidos. Após a conclusão desses procedimentos, uma função adicional foi disponibilizada para recuperar os valores nos três eixos (X, Y e Z). No contexto deste projeto específico, optou-se por utilizar o eixo "Z" para controlar o movimento do jogador (raquete).

## Resultados e conclusão

## Referências

## Autores

- José Gabriel de Almeida Pontes
- Pedro Mendes
- Thiago Pinto Pereira Sena
