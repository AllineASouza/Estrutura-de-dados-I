#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PARTICIPANTS 10

int main() {
    
	char participants[MAX_PARTICIPANTS][50]; // é uma matriz de caracteres que armazenará os nomes dos participantes do jogo.
    int numParticipants; 
    int partSort[MAX_PARTICIPANTS] = {0};  // Array para controlar os participantes já sorteados


    printf("Bem-vindo(a) ao Amigo Oculto!\n");
    printf("Quantos participantes irao brincar? (maximo de %d): ", MAX_PARTICIPANTS);
    scanf(" %d", &numParticipants);

    if (numParticipants < 2 || numParticipants > MAX_PARTICIPANTS) {
        printf("Numero invalido de participantes.\n");
        return 1;
    }

    // Obtém os nomes dos participantes
	for (int i = 0; i < numParticipants; i++) {
    printf("Digite o nome do participante %d: ", i + 1);
    scanf(" %[^\n]s", participants[i]);
}
    // Realiza o sorteio dos amigos ocultos
    srand(time(NULL));
 
    for (int i = 0; i < numParticipants; i++) {
    	int j;
       
	    // Encontra um amigo oculto que ainda não foi sorteado
        do {
            j = rand() % numParticipants;
        } while (i == j || participants[j][0] == '\0');

       // Mostra o resultado do sorteio
        printf("%s -> %s\n", participants[i], participants[j]);

        // Marca o amigo oculto como sorteado
        partSort[j] = 1;
        
    }

    return 0;
}

