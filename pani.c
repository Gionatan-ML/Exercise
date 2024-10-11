#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#define MAX 1

int *array;
int cont=MAX;
bool result=false;

void read_cont(FILE* stream){
    bool fine=false;
    stream=fopen("pane.txt", "r");
    array=malloc(sizeof(int)*MAX);
    if(array==NULL){
        exit(0);
    }
    int i=0;
    char ptr;
    while((ptr=getc(stream))!=EOF){
        if(isdigit(ptr)==0){
            continue;
        }
        ungetc(ptr, stream);
        if(fscanf(stream, "%d", &array[i])==1){
            printf("%d\n", array[i]);
            i++;
            if(i>=cont){
                cont++;
                int *temp=realloc(array, sizeof(int)*cont);
                if(temp==NULL){
                    printf("\nerror");
                    free(array);
                    exit(1);
                }
                array=temp;
            }
        }else{
            fine=true;
        }
    }
    fclose(stream);
   
}

void append(FILE* stream){
    stream=fopen("pane.txt", "a");
    if(stream==NULL){
        printf("An error occurred");
        exit(0);
    }
    for(int i=0; i<cont-1; i=i+2){
        int tmp=0;
        while((result==false) && ( (array[i]<=1000 && array[i+1]<=1000) || (array[i]>=1 && array[i+1]>=1) )){
            if(array[i]%2==0 && array[i+1]%2==0){
                array[i]=array[i]/2;
                array[i+1]=array[i+1]/2;
                printf("\nPari: %d, %d", array[i], array[i+1]);
            }
            else if(array[i]%2!=0 && array[i+1]%2!=0){
                array[i]=array[i]+(2*array[i])+1;
                array[i+1]=array[i+1]+(2*array[i+1])+1;
                printf("\nDispari: %d, %d", array[i], array[i+1]);
            }
                
            else{
                if(array[i]%2!=0){
                    array[i]=array[i]+3;
                    printf("\nDispari_uno: %d, %d", array[i], array[i+1]);
                }
                if(array[i+1]%2!=0){
                    array[i+1]=array[i+1]+3;
                    printf("\nDispari_due: %d, %d", array[i], array[i+1]);
                }
            }
            if((array[i]==array[i+1])&&(array[i]==1)){
                result=true;
            }
            tmp++;
        }
        printf("\n   Tentativi: %d; array1:%d; array2:%d\n",tmp, array[i], array[i+1]);
        fprintf(stream, "\nTentativi: %d", tmp);
    }
    fflush(stream);
    fclose(stream);
}
void write(int a, int b, FILE* stream){
    stream=fopen("pane.txt", "w");
    fprintf(stream, "%d,%d", a,b);
    fclose(stream);

}

int main(void){
    int a,b;
    printf("\n\n Inserisci 2 numeri: ");
    scanf("%d", &a);
    scanf("%d", &b);
    FILE* stream;
    write(a,b, stream);
    read_cont(stream);
    printf("Cont: %d\n", cont-1);
    append(stream);
    free(array);
}
