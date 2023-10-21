#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(int argc, char* argv)
{
    No* n0 = no(2.0, NULL);
    No* n1 = no(3.23, NULL);
    No* n2 = no(0.5, NULL);

    lista_inserir_no(n0, n1);
    lista_inserir_no(n0, n2);

    lista_imprimir(n0);

    No* n0Copia = lista_copiar(n0);

    lista_concatenar(n0, n0Copia);

    lista_imprimir(n0);

    exit(0);
}