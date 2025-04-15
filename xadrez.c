/*
Desafio: nível mestre
Criando Movimentos Complexos

Neste desafio final, você aprimorará o programa de xadrez que vem desenvolvendo, explorando 
técnicas avançadas de programação para simular os movimentos das peças. Prepare-se para 
usar recursividade e loops complexos!

O que você vai fazer

Você deverá modificar o programa em C, que já contém a movimentação da Torre, Bispo, Rainha 
e Cavalo, realizando as seguintes alterações:

 

Recursividade: Substitua os loops simples que controlam os movimentos da Torre, Bispo e Rainha 
por funções recursivas. Cada função recursiva deverá simular o movimento da respectiva peça, 
imprimindo a direção correta a cada casa.
 
Loops Complexos para o Cavalo: Aprimore a movimentação do Cavalo, utilizando loops aninhados com 
múltiplas variáveis e/ou condições. Você pode usar continue e break para controlar o fluxo do 
loop de forma mais precisa. O movimento do Cavalo agora será para cima e para a direita, em "L" 
(duas casas para cima e uma para a direita).
 
Bispo com Loops Aninhados: O Bispo deve ser implementado com recursividade, e também com loops 
aninhados, utilizando o loop mais externo para o movimento vertical, e o mais interno para o 
movimento horizontal.

Requisitos funcionais

Entrada de Dados: Os valores para o número de casas a serem movidas (para recursão) e as condições 
dos loops (para o Cavalo) devem ser definidos diretamente no código, como variáveis ou constantes.
 
Recursividade (Torre, Bispo e Rainha): Implemente funções recursivas para simular o movimento de 
cada peça, substituindo os loops originais.
 
Loops Complexos (Cavalo): Utilize loops aninhados com múltiplas variáveis e/ou condições para simular 
o movimento do Cavalo em "L" (duas casas para cima e uma para a direita).
 
Loops Aninhados (Bispo): Utilize loops aninhados para o bispo, sendo o loop mais externo o vertical, e 
o mais interno o horizontal.
 
Saída de Dados: O programa deverá imprimir no console, de forma clara e organizada, a direção do 
movimento a cada casa percorrida por cada peça. Utilize o comando printf para exibir as informações. As 
saídas devem seguir o padrão: printf("Cima\n");, printf("Baixo\n");, printf("Esquerda\n");, printf("Direita\n");. 
Utilize linhas em branco para separar a saída de cada peça.
*/

#include <stdio.h>

/* -----------Função da Peça da Rainha-----------*/
void movRainha(int r){

    if (r <= 8){ // caso-base (9, 8)
        printf ("Rainha: Esquerda!\n"); // printf que irá ser executado 8x
        movRainha (r + 1); //Função Chamando-se e somando +1 para encerrar loop
    }
}

/* -----------Função da Peça do Bispo-----------*/
void movBispoInt(int b_hor, int b_vert){ /* Função Segundaria: criada primeiro para poder usar na função Bispo principal Externa
essa função é a interna e fica dentro da externa*/
    if (b_hor < b_vert){ // caso-base (1, 1)
        printf ("Bispo: Direita!\n"); //irá imprimir somente 1x
        movBispoInt(b_hor + 1, b_vert); // Função chamando-se b_hor +1 para encerrar e b_vert mantém valor
    }
}

void movBispoExt(int b_vert){ // Função Principal: Externa, Criada para ser chamada dentro do INT MAIN

    if (b_vert <= 1){ // caso-base (2,1)
        b_vert++; // soma +1 para chegar mais perto do caso-base
        printf ("Bispo: Cima!\n"); // executado 1x
        movBispoInt(0, b_vert); // chama a função criada com valor 0 e matém o valor dessa (b_vert = 1)
    }
}

/* -----------Função da Peça do Cavalo-----------*/
void movCavalo(int cav){ /* Função de Procedimento
O FOR foi usado com 'continue' para pular uma repetição, não tendo 3x CIMA e 'multipla variável e condição' para executar a segunda saída do print*/
    for (int a = 1, b = 3; a <= 3 && b > 0; a++, b--){
        if (a == 2) continue;
        printf ("Cavalo: Cima!\n");
        if (b == 1){
            printf("Cavalo: Direita!\n");
        }
    }
}

/* -----------Função da Peça da Torre-----------*/
void movTorre(int torr){
    if (torr < 5){

        printf ("Torre: Direita!\n");
        movTorre(torr + 1);
    }
}

int main () {

    /*Entra das variaveis para o switch, estrutura de repetição e contador.*/
    int rainha, bispo = 0, torre = 0, cavalo_x, cavalo_y, jogo, pssw = 3;

    /* DO-WHILE para número de tentativas na escolha correta das peças mostradas.*/
    do {
    printf ("\n######Jogo do Xadrez######"
            "\n1. Rainha;\n"
            "2. Bispo;\n"
            "3. Torre;\n"
            "4. Cavalo.\n"
            "Escolha qual peça quer jogar: ");
            scanf ("%d", &jogo);

        switch (jogo){ /*switch para escolha das peças e assim mostrar quantas casas e direção irão andar.*/
        
        /*Projeto em desenvolvimento, ainda quero fazer com que o usuário escolha a
        direção e quantidade de casas que gostaria de andar em acordo com as 
        regras do jogo, mas por agora estou entregando o que pediram*/

            case 1:
                movRainha (0);
            break;

            case 2:
                movBispoExt(0);
            break;

            case 3:
                movTorre(0);
            break;

            case 4:
                movCavalo(0);
            break;

            default: /*aqui faz com que a estrututa de repetição continua.*/
                if (pssw > 0){
                    printf ("\nOpção inválida, você tem (%d) tentativas para escolher a peça correta.\n", pssw);
                    pssw--;
                } 
                else {
                    printf ("\nOpção inválida e suas tentativas acabaram, infelizmente o programa vai ser encerrado.");
                    pssw--;
                    return 0;
                }
            break;
        }       
    } while (pssw >= 0 && jogo > 4);

    return 0;
}