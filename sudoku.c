#include <stdio.h>
#include <locale.h>

int sudoku[4][4];

/*==================================================================================================================================
Função que imprime o sudoku
==================================================================================================================================*/
void imprime_sudoku(){
    
    printf("-------------\n");

    for(int i=0; i<4; i++){
        if(i==2){
            printf("|-----|-----|\n");
        }
        printf("| ");
        for(int j=0; j<4; j++){
            printf("%i ", sudoku[i][j]);
            if(j==1){
                printf("| ");
            }
        }
        printf("|\n");
    }

    printf("-------------\n");
}

/*==================================================================================================================================
Função lê um array de char (string), com o nome do arquivo csv a ser lido e insere as informações em uma matriz (variável 
global 'int sudoku[][]') que será o sudoku.
==================================================================================================================================*/
void transforma_arquivo_para_matriz(){
    FILE *arquivo;

    char nome_arquivo[50];
    printf("\nDigite o nome do arquivo que será lido.");
    gets(nome_arquivo);

    if ((arquivo = fopen(nome_arquivo, "r")) == NULL) {
        printf("\nNão existe tal arquivo, por favor digite outro.");
        transforma_arquivo_para_matriz();
    }

    int x=0;
    int a,b,c,d;
    while(fscanf(arquivo, "%i,%i,%i,%i", &a, &b, &c, &d)!=EOF){
        sudoku[x][0] = a;
        sudoku[x][1] = b;
        sudoku[x][2] = c;
        sudoku[x][3] = d;
        x++;
    }

    fclose(arquivo);
}
    
/*==================================================================================================================================
Função main
==================================================================================================================================*/
int main(){

<<<<<<< HEAD
    transforma_arquivo_para_matriz();
    imprime_sudoku();

=======
>>>>>>> master
}