/*Desafionível novato:

Movimentando as Peças do xadrez

    Este desafio foca na movimentação das peças de xadrez usando estruturas de repetição em C. Você 
    aplicará o que aprendeu sobre for, while e do-while para simular movimentos no tabuleiro.

O que você vai fazer

    Você deverá criar um único programa em C que simule o movimento de três peças: Torre, Bispo 
    e Rainha. Para cada peça, utilize uma estrutura de repetição diferente (for, while ou do-while) 
    para simular seu movimento. O programa deverá imprimir no console a direção do movimento a cada 
    casa percorrida pela peça.
    
    Torre: Move-se em linha reta horizontalmente ou verticalmente. Seu programa deverá simular 
    o movimento da Torre cinco casas para a direita.
    
    Bispo: Move-se na diagonal. Seu programa deverá simular o movimento do Bispo cinco casas na 
    diagonal para cima e à direita. Para representar a diagonal, você imprimirá a combinação de
    duas direções a cada casa (ex: "Cima, Direita").
    
    Rainha: Move-se em todas as direções. Seu programa deverá simular o movimento da Rainha oito 
    casas para a esquerda.

Requisitos funcionais

    Entrada de Dados: Os valores para o número de casas a serem movidas serão definidos diretamente
    no código através de variáveis ou constantes.
    
    Lógica de Movimentação: Cada programa deverá implementar a lógica de movimento específica de 
    cada peça (Torre, Bispo, Rainha).
    
    Saída de Dados: O programa deverá imprimir no console a direção do movimento a cada casa 
    percorrida pela peça. Para movimentos na diagonal (Bispo), imprimir a combinação de duas 
    direções. Utilize o comando printf para exibir as informações. As saídas devem seguir o padrão:
    printf("Cima\n");, printf("Baixo\n");, printf("Esquerda\n");, printf("Direita\n");
    printf("Cima Esquerda\n"); printf("Direita\n");*/

    #include <stdio.h>

    int main () {
    
        /*Entra das variaveis para o switch, estrutura de repetição e contador.*/
        int rainha, bispo = 0, torre = 0, jogo, pssw = 3;
    
        /* DO-WHILE para número de tentativas na escolha correta das peças mostradas.*/
        do {
        printf ("\n######Jogo do Xadrez######"
                "\n1. Rainha;\n"
                "2. Bispo;\n"
                "3. Torre.\n"
                "Escolha qual peça quer jogar: ");
                scanf ("%d", &jogo);
    
            switch (jogo){ /*switch para escolha das peças e assim mostrar quantas casas e direção irão andar.*/
                case 1:
                    for (rainha = 1; rainha <= 8; rainha++){
                        printf ("\nRainha (%d): Esquerda!", rainha);
                }
                break;
    
                case 2:
                    while (bispo < 5 ){
                        bispo ++;
                        printf ("\nBispo (%d): Cima, Direita!", bispo);
                    }
                break;
    
                case 3:
                    do {
                        torre ++;
                        printf ("\nTorre (%d): Direita!", torre);
                    } while (torre < 5);
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
        } while (pssw >= 0 && jogo > 3);
    
        return 0;
    }
