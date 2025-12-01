#include "filesystemcrud_functions.c"
#include <assert.h>
void main()
{
    assert(criar_cha("hibisco", "01")==0)  ;
    assert(criar_cha("comomila", "02")==0) ;
    FILE *file;
    file = fopen("cha.txt", "r");
    assert(file != NULL);
    char *leitura = ler_cha("01");
    leitura[strcspn(leitura, "\r\n")] = 0;
    assert(strcmp(leitura, "hibisco") == 0);
    free(leitura);
    assert(remover_cha("01")==1);
    leitura = ler_cha("01");
    assert(strcmp(leitura, "Chá não encontrado") == 0);
    free(leitura);
}
