#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int criar_cha(char* cha, char* codigo){
FILE*file;
file= fopen("cha.txt","a");
fprintf(file, "codigo:%s Nome do cha:%s\n",codigo ,cha);
fclose (file);
return 0;
}
char* ler_cha(char* cha_requerido){
    char leitura_cha[31];
    char* cha_lido = malloc(23); 
    strcpy(cha_lido, "Chá não encontrado");
    char temp[23];
    char codigo[3];
    FILE *file;
    file = fopen("cha.txt", "r");
    while (fgets(leitura_cha,31,file))
    {
        
       if (sscanf(leitura_cha, "codigo:%2s Nome do cha:%23[^\n]", codigo, temp) != 2)
            continue;
        if(strcmp(codigo, cha_requerido) == 0){
            strcpy(cha_lido, temp);
            break;
        }
    }
    fclose(file);
    return cha_lido ;
}
int remover_cha(char* cha_requerido){
    char codigo[3];
    char cha_lido[10];
    char leitura_cha[31];
    int encontrada = 0;
    FILE *origem, *destino;
    origem = fopen("cha.txt", "r");
    destino = fopen("temp.txt", "w");
   
    while (fgets(leitura_cha, 31, origem))
    {
        if (sscanf(leitura_cha, "codigo:%2s Nome do cha:%10[^\n]", codigo, cha_lido) != 2)
            continue;
       
        if (strcmp(codigo, cha_requerido) == 0)
        {
            encontrada = 1;
            printf("\nExcluindo cha %s\n", leitura_cha);
        }
        else
        {
            fprintf(destino,"codigo:%s Nome do cha:%s\n", codigo, cha_lido);
        }
        }
    
    fclose(origem);
    fclose(destino);
    remove("cha.txt");
    rename("temp.txt", "cha.txt");
    if (!encontrada)
    {
        return 0;
    }
    return 1;


}

