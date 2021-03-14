#include <stdio.h>
#include <locale.h>

int sudoku[4][4];

/*==================================================================================================================================
WIP
==================================================================================================================================*/
void imprime_sudoku(){
    
    int x=1;
    while(x<=2){
        printf("-------------\n");
        int y=1;
        while(y<=2){
            printf("| 0 0 | 0 0 |\n");    
            y++;
        }
        x++;
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
    setlocale(LC_ALL, "Portuguese_Brasil");

    imprime_sudoku();
    transforma_arquivo_para_matriz();

    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            printf("%i ", sudoku[i][j]);
        }
        printf("\n");
    }
}