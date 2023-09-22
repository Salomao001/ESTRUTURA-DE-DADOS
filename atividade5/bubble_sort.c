#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bubble_sort.h"

void bubbleSort(char **arr, int n) {
    int swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                char *temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0) {
            break;
        }
    }
}

int bubbleSortFile(const char *inputFileName, const char *outputFileName) {
    FILE *arquivo_entrada = fopen(inputFileName, "r");
    if (arquivo_entrada == NULL) {
        perror("Erro ao abrir o arquivo de entrada");
        return 1;
    }

    int tamanho_maximo = 100; // Tamanho máximo de cada palavra
    int tamanho = 0;
    char **palavras = malloc(sizeof(char *) * tamanho_maximo);

    char palavra[tamanho_maximo];
    while (fscanf(arquivo_entrada, "%s", palavra) != EOF) {
        palavras[tamanho] = strdup(palavra);
        tamanho++;
        if (tamanho >= tamanho_maximo) {
            tamanho_maximo *= 2;
            palavras = realloc(palavras, sizeof(char *) * tamanho_maximo);
        }
    }

    fclose(arquivo_entrada);

    bubbleSort(palavras, tamanho);

    FILE *arquivo_saida = fopen(outputFileName, "w");
    if (arquivo_saida == NULL) {
        perror("Erro ao criar o arquivo de saída");
        return 1;
    }

    for (int i = 0; i < tamanho; i++) {
        fprintf(arquivo_saida, "%s\n", palavras[i]);
        free(palavras[i]);
    }

    fclose(arquivo_saida);

    free(palavras);

    return 0;
}
