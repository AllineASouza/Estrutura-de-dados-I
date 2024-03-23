#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

/* 10. Um determinado material radioativo perde metade de sua massa a cada 50 segundos. Dada a massa inicial, em
gramas, fazer um programa em C que calcule o tempo necessário para que essa massa se torne menor que 0,5
grama. O programa em C deve escrever a massa inicial, a massa final e o tempo calculado em horas, minutos e
segundos. */


int main() {
    double massa_inicial, massa_final = 0.5;
    int horas = 0, minutos = 0, segundos = 0;
    int tempo_total_segundos = 0;

    printf("Digite a massa inicial em gramas: ");
    scanf(" %lf", &massa_inicial);

    // Calcula o tempo necessário em segundos
    while (massa_inicial > massa_final) {
        massa_inicial /= 2;
        tempo_total_segundos += 50;
    }

    // Converte o tempo total em horas, minutos e segundos
    horas = tempo_total_segundos / 3600;
    minutos = (tempo_total_segundos % 3600) / 60;
    segundos = tempo_total_segundos % 60;

    // Imprime os resultados
    printf("Massa inicial: %.2lf gramas\n", massa_inicial * 2);
    printf("Massa final: %.2lf gramas\n", massa_inicial);
    printf("Tempo necessário: %d horas, %d minutos e %d segundos\n", horas, minutos, segundos);

    return 0;
}


