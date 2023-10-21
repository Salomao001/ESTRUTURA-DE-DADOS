#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

No* no(float valor, No* proximo_no)
{
    No* no = malloc(sizeof(No));
    no->valor = valor;
    no->proximo_no = proximo_no;
    return no;
}

void lista_inserir_no(No* H, No* no)
{
    if (H != NULL)
    {
        if (H->proximo_no == NULL)
        {
            H->proximo_no = no;
        }
        else {
            lista_inserir_no(H->proximo_no, no);
        }
    }
}

void lista_imprimir(No* H)
{
    if(H != NULL){
        printf("%.2f ", H->valor);
        lista_imprimir(H->proximo_no);
    }
}

No* lista_copiar(No* H)
{
    if (H != NULL)
    {
        return no(H->valor, lista_copiar(H->proximo_no));
    }
    return NULL;
}

void lista_concatenar(No* H, No* Hc){
    lista_inserir_no(H, Hc);
}

void lista_liberar(No* H)
{
    if(H != NULL)
    {
        lista_liberar(H->proximo_no);
        free(H);
    }
}

int lista_tamanho(No* H)
{
    if(H != NULL)
    {
        return 1 + lista_tamanho(H);
    }
    return 0;
}