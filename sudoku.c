#include <stdio.h>
#include <locale.h>
#include <stdbool.h>

void main();
void imprime_sudoku();
void transforma_arquivo_para_matriz();
bool sudoku_foi_resolvido();
void atribui_valores();
void resolve_sudoku();

int tamanho_sudoku=4;
int sudoku[4][4][5];

/*==================================================================================================================================
Função que imprime o sudoku
==================================================================================================================================*/
void imprime_sudoku(){

    printf("-------------\n");

    for(int i=0; i<tamanho_sudoku; i++){
        if(i==2){
            printf("|-----|-----|\n");
        }
        printf("| ");
        for(int j=0; j<tamanho_sudoku; j++){
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
Função que verifica se o sudoku foi resolvido, caso sim, retorna o valor true. Se não retorna o valor false  
==================================================================================================================================*/
bool sudoku_foi_resolvido(){
    for(int i=0; i<tamanho_sudoku; i++){
        for(int j=0; j<tamanho_sudoku; j++){
            if(sudoku[i][j][0]==0){
                return false;
            }
        }
    }
    return true;
}

/*==================================================================================================================================
Atribui valor para cada celula com apenas uma possibilidade
==================================================================================================================================*/
void atribui_valores(){

    int verificador, aux;
    bool fez_substituicao = false;

    for(int i=0; i<tamanho_sudoku; i++){
        for(int j=0; j<tamanho_sudoku; j++){
            verificador = 0;
            aux = 0;
            int k=1;
            while(sudoku[i][j][k]!=0){
                verificador++;
                aux=sudoku[i][j][k];
                k++;
            }    
                    
            if(verificador==1){
                sudoku[i][j][0] = aux;
                sudoku[i][j][1] = 0;
                fez_substituicao=true;
            }
        }
    }

    if(!fez_substituicao && !sudoku_foi_resolvido()){
        printf("Este sudoku é muito dificil, por favor insira outro\n");
        main();
    }
}

/*==================================================================================================================================
Função que faz as devidas chamadas para resolver o sudoku
==================================================================================================================================*/
void resolve_sudoku(){
        valores_possiveis();
        atribui_valores();
        if(!sudoku_foi_resolvido()){
            resolve_sudoku();
        }
}

/*==================================================================================================================================
Função main
==================================================================================================================================*/
void main(){

    transforma_arquivo_para_matriz();

    printf("Sudoku inserido antes de ser resolvido:\n");
    imprime_sudoku();

    resolve_sudoku();

    printf("Sudoku resolvido:\n");
    imprime_sudoku();
}

    /*
    void valores_possiveis(){
        for(int i=0; i<tamanho_sudoku; i++){
            for(int j=0; j<tamanho_sudoku; j++){

                if(sudoku[i][j][0] !=0){
                    for(int k=0; k<tamanho_sudoku; k++){
                        sudoku[i][j][k]=0;
                    }
                }else{
                    ---------------
                }

            }

        }
    }
    */

