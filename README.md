# BricksBreakerOnDe1SOC

## Introdução
 
Os jogos desempenham um papel fundamental tanto no desenvolvimento cognitivo quanto no social. Eles promovem o raciocínio lógico, a criatividade e a resolução de problemas, ao mesmo tempo em que proporcionam oportunidades valiosas para interação, colaboração e construção de relacionamentos (BARANITA, 2012).

Além disso, os jogos não apenas exercitam o corpo, melhorando a coordenação, agilidade e aptidão física, mas também têm um impacto positivo no bem-estar emocional. Ao oferecer momentos de diversão, relaxamento e alívio do estresse, os jogos se tornam uma fonte valiosa de equilíbrio e saúde mental para indivíduos de todas as idades (BARANITA, 2012).

Dada a importância dos jogos para o desenvolvimento humano, nosso grupo foi encarregado de desenvolver um jogo inspirado no clássico Breakout da ATARI. A interação física do jogador com o jogo se dá por meio do acelerômetro disponível no Kit de Desenvolvimento DE1-SoC. Para controlar o jogo, o usuário pode utilizar os botões fornecidos na placa. Além disso, o jogo será visualizado em um monitor CRT utilizando a interface VGA.

## Metodologia

## Descrição do Projeto

### Visão geral da placa
Como foi dito nas seções anteriores, o projeto utilizou do kit de desenvolvimento DE1-SOC. Este kit possui o processador ARM Cortex-A9 dual-core que é utilizado para executar o sistema operacional Linux e outras aplicações de software. Há também a FPGA da família Intel Cyclone V com alguns periféricos que foram utilizados: a interface VGA, botões e acelerômetro. 

Quando compilamos e executamos um programa escrito em C, estamos fazendo isso no processador ARM. Para termos acesso aos periféricos presentes na FPGA, o processador precisa se comunicar a todo momento com a FPGA. Esta comunicação geralmente ocorre por meio de interfaces específicas, que são bridges HPS-to-FPGA, Lightweight HPS-to-FPGA Bridge, Compartilhamento de Periféricos e Interrupções.

Os bridges HPS-to-FPGA (Hard Processor System to FPGA) são interfaces dedicadas que facilitam a comunicação entre o processador ARM (parte do HPS) e a lógica programável da FPGA. Eles são usados para transferir dados, sinais de controle e até mesmo para configurar a lógica da FPGA a partir do processador. Eles mapeiam regiões de memória específicas na FPGA para endereços de memória acessíveis pelo processador ARM. Quando o processador ARM deseja interagir com um periférico na FPGA, ele envia comandos e dados para os endereços de memória correspondentes à região mapeada pela bridge.

Além disso, existe o Lightweight HPS-to-FPGA Bridge, uma versão simplificada da HPS-to-FPGA Bridge e é frequentemente usada para comunicações mais simples e de baixa largura de banda entre o processador ARM e a FPGA.

### Pushbutton Key

Há 4 botões conectados a FPGA da placa. Quando um ou mais é pressionado, ele(s) fecha(m) um circuito elétrico, provocando uma mudança no estado do(s) pino(s) de entrada correspondente(s) na FPGA. A FPGA, por sua vez, monitora continuamente o estado dos pinos de entrada conectados aos botões e detecta a alteração quando um botão é pressionado. Em seguida, a FPGA pode gerar um sinal de interrupção ou outro tipo de sinal para notificar o processador ARM sobre o evento, utilizando uma interface de comunicação como os bridges HPS-to-FPGA. Assim que o processador ARM recebe a notificação da FPGA, ele executa um tratamento de interrupção para lidar com o evento.

Há um Header em C que pode ser incluído ao projeto:

![Header PushButtons](public/buttons.png)

Esse header nos mostra a assinatura de 3 métodos que são utilizados no projeto. O primeiro é o KEY_open() que possibilita a abertura da comunicação do processador ARM com os botões da FPGA. O KEY_close() já realiza o contrário, encerrando a comunicação. O que é utilizado para leitura dos dados dos botões é o KEY_read(). Este método recebe um ponteiro de um inteiro que guarda os valores dos botões (0-Não pressionado e 1-Pressionado). Se todos os botões não estão pressionados, o retorno é 0b0000. Caso todos estejam pressionados, o retorno é 0b1111.

### Fluxo do Jogo

Com o estudo feito de cada periférico a ser utilizado, partimos para o estabelecimento da lógica de controle do jogo:

![Fluxo do Jogo](public/gameControl.png)

Inicialmente há um Menu. Por meio do controle dos botões, o jogador pode escolher sair do jogo ou jogar. Só são utilizados nessa tela dois botões. O primeiro alterna entre as duas escolhas e o segundo dá enter. Selecionado enter para jogar, o sistema entra no loop do jogo até que o jogador vença ou perca. Nesta etapa, o controle do player é dado pelo acelerômetro do kit, sendo possível pausar o jogo por meio do botão. Com a finalização do jogo, o usuário retorna para o Menu.

## Resultados 

## Conclusão

## Referências

- MARIA DA COSTA BARANITA, I.; SUPERIOR DE EDUCAÇÃO, E.; GARRETT, A. A Importância do Jogo no Desenvolvimento da criança 1. Isabel baranita -2012 A importância do Jogo no desenvolvimento da Criança. [s.l: s.n.]. Disponível em: [https://recil.ensinolusofona.pt/bitstream/10437/3254/1/Dissertacao.pdf].
- FPGAcademy.org. (Mar 2022). Linux with ARM A9. Recuperado de [https://pt.scribd.com/document/695343767/Linux-with-ARM-A9]
- Terasic Technologies. (2015). Manual do Usuário DE1-SoC (Versão 1.2.2). Recuperado de [http://www.terasic.com]

## Autores

- José Gabriel de Almeida Pontes
- Pedro Mendes
- Thiago Pinto Pereira Sena
