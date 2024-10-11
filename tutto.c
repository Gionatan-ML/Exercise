#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <pthread.h>

#ifndef SYSTEM
#define SYSTEM 0
#endif

typedef struct Union
{
    char *nome;
    char *cognome;
    int eta;
    struct Union* next;
}Union;

typedef enum Tipo{
    a,
    b,
    c,
    d
}Tipo;

Union* add(){
    Union* x=malloc(sizeof(Union));
    x->nome="Gionatan";
    return x;
}

void file(){
    FILE *f1;
    f1=fopen("file.txt", "a");
    char *c="ci siamo";
    fputs(c,f1);
    printf("\n");
    fprintf(stdout, "%s", c);
    fclose(f1);
    FILE *f2= fopen("file.txt", "r");
    char *x=malloc(sizeof(char)*4);
    fread(x, sizeof(char), 3, f2);
    x[4]='\0';
    printf("%s", x);
}

int main(void){
    file();
    
}