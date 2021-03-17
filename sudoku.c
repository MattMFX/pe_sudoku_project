#include <stdio.h>
#include <locale.h>
#include <stdbool.h>

int sudoku[4][4][5];
bool resolvido = false;

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
            printf("%i ", sudoku[i][j][0]);
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
        sudoku[x][0][0] = a;
        sudoku[x][1][0] = b;
        sudoku[x][2][0] = c;
        sudoku[x][3][0] = d;
        x++;
    }

    fclose(arquivo);
}
    
/*==================================================================================================================================
Função main
==================================================================================================================================*/
int main(){

    transforma_arquivo_para_matriz();
    imprime_sudoku();
    
    //resolve_sudoku();

    //imprime_sudoku();
}


    /*
    resolve_sudoku(){
        while(resolvido==false){
            valores_possiveis();
            atribui_valor();
        }
    }
    */

    /*
    void valores_possiveis(){
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){

                if(sudoku[i][j][0] !=0){
                    for(int k=0; k<4; k++){
                        sudoku[i][j][k]=0;
                    }
                }else{
                    ---------------
                }

            }
            
        }
    }
    */

        

    /*
    void atribui_valor(){
        for(){
            for(){

            }
        }
            
    }
    */
