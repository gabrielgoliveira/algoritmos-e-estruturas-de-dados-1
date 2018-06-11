#include <stdio.h>
#include <stdlib.h>
/*
    - Dificuldade: Quantidade de tempo que leva pra resolver um exercicio
    - Pontuação de cada problema: tempo inicio concurso -> resolução
    - Saida: Vencedor, Numero de Problemas Resolvidos, Pontuação
    - Quadro Geral: Soma das Pontuações
    - Vencedor: Quem resolveu mais problemas e com a Menor pontuação;
*/
char nome[3][33] = {"Joao", "Jose", "Joaquim"};
int pontuacao_geral[3] = {0};
int exercicios_total[3] = {0};
int matrizEmpate[3][3] = {0};

int* createVector(int x){
    int *list = (int*) malloc(x*sizeof(int));
    return list;
}

void ordernarCrescente( int *vetor, const int SIZE ){
    int i, j, aux;
    for( i = 0; i < SIZE; i++){
        for( j = 0; j < SIZE-1; j++){
            if(vetor[j] > vetor[j+1]){
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }
        }
    }
}

void ordernarDecrescente( int *vetor, const int SIZE ){
    int i, j, aux;
    for( i = 0; i < SIZE; i++){
        for( j = 0; j < SIZE-1; j++){
            if(vetor[j] < vetor[j+1]){
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }
        }
    }

}

int joao( int *dificuldade, int maxTempo, int SIZE ) {
    int i, j, somatoria = 0, cont = 0;
    /*
    printf("Ordem Joao: ");
    for( i = 0; i<SIZE; i++ ){
        printf("%d ", dificuldade[i]);
    }
    printf("\n");
    */
    for( i = 0; i<SIZE; i++){
        if(somatoria + dificuldade[i] <= maxTempo){
            somatoria+=dificuldade[i];
        } else {
            break;
        }
    }
    exercicios_total[0] = i;
    somatoria = 0;
    //printf("Joao fez %d Exercicios\n", exercicios_total[0]);
    for( i = 0; i < exercicios_total[0]; i++ ){
        cont++;
        for( j = 0; j<cont; j++){
            somatoria += dificuldade[j];
        }
    }
    pontuacao_geral[0] = somatoria;
    //printf("Sua Pontuacao Geral foi: %d\n", pontuacao_geral[0]);
}

int jose( int *dificuldade, int maxTempo, int SIZE ) {
    //resolve na ordem crescente de dificuldade
    int i, j, somatoria = 0, cont = 0;
    ordernarCrescente( dificuldade, SIZE );
  /*  
    printf("Ordem Jose: ");
    for( i = 0; i<SIZE; i++ ){
        printf("%d ", dificuldade[i]);
    }
    printf("\n");
 */
    for( i = 0; i<SIZE; i++){
        if(somatoria + dificuldade[i] <= maxTempo){
            somatoria+=dificuldade[i];
        } else {
            break;
        }
    }
    exercicios_total[1] = i;
    somatoria = 0;
    //printf("Jose fez %d Exercicios\n", exercicios_total[1]);
    for( i = 0; i < exercicios_total[1]; i++ ){
        cont++;
        for( j = 0; j<cont; j++){
            somatoria += dificuldade[j];
        }
    }
    pontuacao_geral[1] = somatoria;
    //printf("Sua Pontuacao Geral foi: %d\n", pontuacao_geral[0]);
}

int joaquim( int *dificuldade, int maxTempo, int SIZE ) {
    //resolve na ordem crescente de dificuldade
    int i, j, somatoria = 0, cont = 0;
    ordernarDecrescente( dificuldade, SIZE );
    /*    
    printf("Ordem Joaquim: ");
    for( i = 0; i<SIZE; i++ ){
        printf("%d ", dificuldade[i]);
    }
    printf("\n");
    */
    for( i = 0; i<SIZE; i++){
        if(somatoria + dificuldade[i] <= maxTempo){
            somatoria+=dificuldade[i];
        } else {
            break;
        }
    }
    exercicios_total[2] = i;
    somatoria = 0;
    //printf("Jose fez %d Exercicios\n", exercicios_total[1]);
    for( i = 0; i < exercicios_total[2]; i++ ){
        cont++;
        for( j = 0; j<cont; j++){
            somatoria += dificuldade[j];
        }
    }
    pontuacao_geral[2] = somatoria;
    //printf("Sua Pontuacao Geral foi: %d\n", pontuacao_geral[0]);
}
int empateX(){
    int i, j, menorPontuacao = 999999999, auxMenor, indiceSaida = 0;
    int aux = pontuacao_geral[0], contadorEmpate = 0;
    /*preenchendo uma matriz onde suas posições são elemento i que empatou com elemento j 
    em relação a exercicios totais realizados*/
    for( i = 1; i<3; i++){
        //verificando se existe empate na pontuacao
        if(aux == pontuacao_geral[i]){
            contadorEmpate++;
        }
    }
    //printf("Contador Empate = %d\n", contadorEmpate);
    if(contadorEmpate == 2){
        //printf("Condicao Empate por Pontuacao\n");
        printf("%s ganha, com %d problemas resolvidos e pontuacao de %d.\n", nome[1], exercicios_total[1], pontuacao_geral[1]);
        return 1;
    }

    //se caso a pontuacao geral nao tiver em empate
    for( i=0; i<3; i++){
        for( j=0; j<3; j++){
            if(i != j && exercicios_total[i] == exercicios_total[j]){
                matrizEmpate[i][j] = 1;
            }
        }
    }
    /*
    printf("MATRIZ DE ADJACENCIA\n");
    for( i=0; i<3; i++){
        for( j=0; j<3; j++){
            printf("%d ", matrizEmpate[i][j]);
        }
        printf("\n");
    }
    */  
    /*Comparando a matriz de adjacencia e obtendo o menor valor da pontuação geral e o indice*/
    for( i=0; i<3; i++){
        for( j=0; j<3; j++){
            if(matrizEmpate[i][j] == 1){
                //comparando os dois carinhas
                //printf("Ocorreu empate entra %s e %s\n", nome[i], nome[j]);
                //printf("Pontuacao %s = %d e menor que Pontuacao de %s = %d ?\n", nome[i], pontuacao_geral[i], nome[j], pontuacao_geral[j]);
                if(pontuacao_geral[i] < pontuacao_geral[j] ) {
                    //printf("SIM\n");
                    //pontuação i é menor que j
                    auxMenor = pontuacao_geral[i];
                    if(menorPontuacao > auxMenor ){
                        menorPontuacao = auxMenor;
                        indiceSaida = i;
                    }
                } 
            }
        }
    }
    printf("%s ganha, com %d problemas resolvidos e pontuacao de %d.\n", nome[indiceSaida], exercicios_total[indiceSaida], pontuacao_geral[indiceSaida]);

    //printf("Menor Pontuacao: %d, indice Saida: %d\n", menorPontuacao, indiceSaida);
}

void ganhador() {
    int i;
    int maior = 0, indiceGanhador = -1;
    for( i = 0; i < 3; i++){
        if(exercicios_total[i] > maior){
            maior  = exercicios_total[i];
            indiceGanhador = i;
        } else if(maior == exercicios_total[i]){
            empateX();
            return ;
        }
    }
    printf("%s ganha, com %d problemas resolvidos e pontuacao de %d.\n", nome[indiceGanhador], exercicios_total[indiceGanhador], pontuacao_geral[indiceGanhador]);
}


int main(){
    int caseTest, tempoCompeticao, numProblemas, contCasos = 1;
    int *dificuldade = NULL;
    int i, j;
    scanf("%d", &caseTest);
    while(caseTest--){  
        scanf("%d %d", &tempoCompeticao, &numProblemas);
        dificuldade = createVector(numProblemas);
        for( i=0; dificuldade != NULL && i<numProblemas; i++){
            scanf("%d", &dificuldade[i]);
        }
        joao(dificuldade, tempoCompeticao, numProblemas );
        jose(dificuldade, tempoCompeticao, numProblemas );
        joaquim(dificuldade, tempoCompeticao, numProblemas );
        printf("Cenario #%d:\n", contCasos);
        /*
        for(i=0;i<3;i++){
            printf("Nome: %s, Quantidade de Exe: %d, Pontuacao: %d\n", nome[i], exercicios_total[i], pontuacao_geral[i]);
        }
        */
        ganhador();
        //inicializando as variaveis
        for(i = 0; i < 3 ; i++){
            for(j = 0; j < 3; j++){
                matrizEmpate[i][j] = 0;
            }
            pontuacao_geral[i] = 0;
            exercicios_total[i] = 0;
        }
        contCasos++;  
    }
    return 0;
}
