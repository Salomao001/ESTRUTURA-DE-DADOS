#include <stdio.h>
#include <stdlib.h>
#include "bubble_sort.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s nome_do_arquivo\n", argv[0]);
        return 1;
    }

    char *arquivo_entrada = argv[1];
    char *arquivo_saida = "arq_palavras_ordenado.txt";

    if (bubbleSortFile(arquivo_entrada, arquivo_saida) == 0) {
        printf("Palavras ordenadas com sucesso. Veja o arquivo %s.\n", arquivo_saida);
    } else {
        printf("Ocorreu um erro ao ordenar as palavras.\n");
    }

    return 0;
}
