#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#define PI 3.14159
#define MAX 50

int board[MAX][MAX*5];


void fill_board(int n){
    for(int z=0; z<n; z++){
        int distance =round((6*sin((double)z/10)));
        int half_board=MAX/2;
        int value=half_board+distance;
        board[value][z]='*';
    }
    for(int y=0; y<MAX; y++){
        for(int x=0; x<MAX*5; x++){
            if(board[y][x]!='*'){
                board[y][x]=' ';
            }
        }
    }
}
void print_board(){
    for(int i=0; i<10; i++){
        printf(" ");
    }
    for(int y=0; y<MAX; y++){
        for(int x=0; x<MAX*5; x++){
            printf("%c", board[y][x]);
        }
        printf("\n");
    }

}

int main() {
    int n, f;
    printf("\nInserisci un numero: ");
    scanf("%d", &n);
    fill_board(n);
    print_board();
    scanf("%d", &f);
    return 0;
 
    
   
}
