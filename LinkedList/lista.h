typedef struct No
{
    float valor;
    struct No* proximo_no;
} No;

No* no(float valor, No* proximo_no);
void lista_inserir_no(No* H, No* no);
void lista_imprimir(No* H);
No* lista_copiar(No* H);
void lista_concatenar(No* H, No* Hc);
void lista_liberar(No* H);
int lista_tamanho(No* H);