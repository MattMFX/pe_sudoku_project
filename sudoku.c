#include <stdio.h>
#include <locale.h>
#include <stdbool.h>

void main();
void imprime_sudoku();
void transforma_arquivo_para_matriz();
bool sudoku_foi_resolvido();
void atribui_valores();
void resolve_sudoku();
void valores_possiveis();
void zera_valores_possiveis();

int tamanho_sudoku=9;
int sudoku[9][9][10];
bool consegue_resolver =true;

/*==================================================================================================================================
Função que imprime o sudoku
==================================================================================================================================*/
void imprime_sudoku(){

    printf("-------------------------\n");

    for(int i=0; i<tamanho_sudoku; i++){
        if(i==3 || i==6){
            printf("|-------|-------|-------|\n");
        }
        printf("| ");
        for(int j=0; j<tamanho_sudoku; j++){
            printf("%i ", sudoku[i][j][0]);
            if(j==2 || j==5){
                printf("| ");
            }
        }
        printf("|\n");
    }

    printf("-------------------------\n");
}

/*==================================================================================================================================
Função lê um array de char (string), com o nome do arquivo csv a ser lido e insere as informações em uma matriz (variável
global 'int sudoku[][]') que será o sudoku.
==================================================================================================================================*/
void transforma_arquivo_para_matriz(){
    FILE *arquivo;

    char nome_arquivo[50];
    printf("\nDigite o nome do arquivo que sera lido.");
    gets(nome_arquivo);

    if ((arquivo = fopen(nome_arquivo, "r")) == NULL) {
        printf("\nNao existe tal arquivo, por favor digite outro.");
        transforma_arquivo_para_matriz();
    }

    int x=0;
    int a,b,c,d,e,f,g,h,i;
    while(fscanf(arquivo, "%i,%i,%i,%i,%i,%i,%i,%i,%i", &a, &b, &c, &d, &e, &f, &g, &h, &i)!=EOF){
        sudoku[x][0][0] = a;
        sudoku[x][1][0] = b;
        sudoku[x][2][0] = c;
        sudoku[x][3][0] = d;
        sudoku[x][4][0] = e;
        sudoku[x][5][0] = f;
        sudoku[x][6][0] = g;
        sudoku[x][7][0] = h;
        sudoku[x][8][0] = i;
        x++;
    }

    fclose(arquivo);
}

/*==================================================================================================================================
Função que faz as devidas chamadas para resolver o sudoku
==================================================================================================================================*/
void resolve_sudoku(){
    zera_valores_possiveis();
    valores_possiveis();
    atribui_valores();
    if(!sudoku_foi_resolvido() && consegue_resolver){
        resolve_sudoku();
    }
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
        consegue_resolver=false;
        printf("Muito dificil!! Esse foi o mais longe que cheguei:\n");
        imprime_sudoku();
    }
}

/*==================================================================================================================================
Função que zera os valores possiveis na matriz
==================================================================================================================================*/
void zera_valores_possiveis(){
    for(int i =0; i<tamanho_sudoku;i++){
        for(int j =0; j<tamanho_sudoku;j++){
            for(int k = 1;k<5;k++){
                sudoku[i][j][k]=0;
                
            }
        }
    }
}

/*==================================================================================================================================
Função que atribui todos valores possiveis para cada posição do sudoku
==================================================================================================================================*/
void valores_possiveis(){
    int valor=1;
    int k=1;
    int indicador=0;
    for(int i =0; i<9;i++){
        for(int j =0; j<9;j++){
            if(sudoku[i][j][0]==0){
                    /*Percorre primeiro quadrado*/
                if(i<=2 && j<=2){
                    while(valor<10){
                        indicador=0;
                        for(int linha=0; linha<3;linha++){
                            for(int coluna=0;coluna<3;coluna++){
                                if(sudoku[linha][coluna][0]== valor){
                                    indicador=1;
                                }
                            }
                        }

                        /*Percorre Linha*/
                        for(int aux=0; aux<9;aux++){
                            if(sudoku[aux][j][0]== valor){
                                indicador = 1;
                            }
                        }
                        /*Percorre Coluna*/
                        for(int contador=0; contador<9;contador++){
                            if(sudoku[i][contador][0]== valor){
                                indicador = 1;
                            }
                        }
                        if(indicador!=1){
                            sudoku[i][j][k]=valor;
                            k++;
                        }
                        valor++;
                    }
                }

                    /* Percorre segundo quadrado*/

                else if(i<=2 && (j<6 && j>2)){

                        /*Percorre quadrado*/

                    while(valor<10){
                        indicador =0;
                        for(int linha=0; linha<3;linha++){
                            for(int coluna=3;coluna<6;coluna++){
                                if(sudoku[linha][coluna][0]== valor){
                                    indicador=1;
                                }
                            }
                        }

                        /*Percorre Linha*/

                        for(int aux=0; aux<9;aux++){
                            if(sudoku[aux][j][0]== valor){
                                indicador = 1;
                            }
                        }
                        /*Percorre Coluna*/

                        for(int contador=0; contador<9;contador++){
                            if(sudoku[i][contador][0]== valor){
                                indicador = 1;
                            }
                        }
                        if(indicador!=1){
                            sudoku[i][j][k]=valor;
                            k++;
                        }
                        valor++;
                    }
                }

                    /*Percorrer terceiro quadrado*/

                else if((i<=2) && (j>5 && j<9)){
                    
                    while(valor<10){
                        indicador =0;
                        for(int linha=0; linha<3;linha++){
                            for(int coluna=6;coluna<9;coluna++){
                                if(sudoku[linha][coluna][0]== valor){
                                    indicador=1;
                                }
                            }
                        }

                        /*Percorre Linha*/
                        for(int aux=0; aux<9;aux++){
                            if(sudoku[aux][j][0]== valor){
                                indicador = 1;
                            }
                        }

                        /*Percorre Coluna*/

                        for(int contador=0; contador<9;contador++){
                            if(sudoku[i][contador][0]== valor){
                                indicador = 1;
                            }
                        }
                        if(indicador!=1){
                            sudoku[i][j][k]=valor;
                            k++;
                        }
                        valor++;
                    }
                }

                    /*Percorre quarto quadrado*/

                else if((i>2 && i<6) && (j>=0 && j<3)){
                    
                    while(valor<10){
                        indicador =0;
                        for(int linha=3; linha<6;linha++){
                            for(int coluna=0;coluna<3;coluna++){
                                if(sudoku[linha][coluna][0]== valor){
                                    indicador=1;
                                }
                            }
                        }

                        /*Percorre Linha*/

                        for(int aux=0; aux<9;aux++){
                            if(sudoku[aux][j][0]== valor){
                                indicador = 1;
                            }
                        }

                        /*Percorre Coluna*/

                        for(int contador=0; contador<9;contador++){
                            if(sudoku[i][contador][0]== valor){
                                indicador = 1;
                            }
                        }
                        if(indicador!=1){
                            sudoku[i][j][k]=valor;
                            k++;
                        }
                        valor++;
                    }
                }

                    /*Percorre quinto quadrado*/

                else if((i>2 && i<6) && (j>=3 && j<6)){
                    
                    while(valor<10){
                        indicador =0;
                        for(int linha=3; linha<6;linha++){
                            for(int coluna=3;coluna<6;coluna++){
                                if(sudoku[linha][coluna][0]== valor){
                                    indicador=1;
                                }
                            }
                        }

                        /*Percorre Linha*/

                        for(int aux=0; aux<9;aux++){
                            if(sudoku[aux][j][0]== valor){
                                indicador = 1;
                            }
                        }

                        /*Percorre Coluna*/

                        for(int contador=0; contador<9;contador++){
                            if(sudoku[i][contador][0]== valor){
                                indicador = 1;
                            }
                        }
                        if(indicador!=1){
                            sudoku[i][j][k]=valor;
                            k++;
                        }
                        valor++;
                    }
                }

                    /*Percorre sexto quadrado*/

                else if((i>2 && i<6) && (j>=6 && j<9)){
                    
                    while(valor<10){
                        indicador =0;
                        for(int linha=3; linha<6;linha++){
                            for(int coluna=6;coluna<9;coluna++){
                                if(sudoku[linha][coluna][0]== valor){
                                    indicador=1;
                                }
                            }
                        }

                        /*Percorre Linha*/

                        for(int aux=0; aux<9;aux++){
                            if(sudoku[aux][j][0]== valor){
                                indicador = 1;
                            }
                        }

                        /*Percorre Coluna*/

                        for(int contador=0; contador<9;contador++){
                            if(sudoku[i][contador][0]== valor){
                                indicador = 1;
                            }
                        }
                        if(indicador!=1){
                            sudoku[i][j][k]=valor;
                            k++;
                        }
                        valor++;
                    }
                }

                    /*Percorre setimo quadrado*/

                else if((i>5 && i<9) && (j>=0 && j<3)){
                    
                    while(valor<10){
                        indicador =0;
                        for(int linha=6; linha<9;linha++){
                            for(int coluna=0;coluna<3;coluna++){
                                if(sudoku[linha][coluna][0]== valor){
                                    indicador=1;
                                }
                            }
                        }

                        /*Percorre Linha*/

                        for(int aux=0; aux<9;aux++){
                            if(sudoku[aux][j][0]== valor){
                                indicador = 1;
                            }
                        }

                        /*Percorre Coluna*/

                        for(int contador=0; contador<9;contador++){
                            if(sudoku[i][contador][0]== valor){
                                indicador = 1;
                            }
                        }
                        if(indicador!=1){
                            sudoku[i][j][k]=valor;
                            k++;
                        }
                        valor++;
                    }
                }
                   
                    /*Percorre oitavo quadrado*/

                else if((i>5 && i<9) && (j>=3 && j<6)){
                    
                    while(valor<10){
                        indicador =0;
                        for(int linha=6; linha<9;linha++){
                            for(int coluna=3;coluna<6;coluna++){
                                if(sudoku[linha][coluna][0]== valor){
                                    indicador=1;
                                }
                            }
                        }

                        /*Percorre Linha*/

                        for(int aux=0; aux<9;aux++){
                            if(sudoku[aux][j][0]== valor){
                                indicador = 1;
                            }
                        }

                        /*Percorre Coluna*/

                        for(int contador=0; contador<9;contador++){
                            if(sudoku[i][contador][0]== valor){
                                indicador = 1;
                            }
                        }
                        if(indicador!=1){
                            sudoku[i][j][k]=valor;
                            k++;
                        }
                        valor++;
                    }
                }

                    /*Percorre nono quadrado*/

                else if((i>5 && i<9) && (j>=6 && j<9)){
                    
                    while(valor<10){
                        indicador =0;
                        for(int linha=6; linha<9;linha++){
                            for(int coluna=6;coluna<9;coluna++){
                                if(sudoku[linha][coluna][0]== valor){
                                    indicador=1;
                                }
                            }
                        }

                        /*Percorre Linha*/

                        for(int aux=0; aux<9;aux++){
                            if(sudoku[aux][j][0]== valor){
                                indicador = 1;
                            }
                        }

                        /*Percorre Coluna*/

                        for(int contador=0; contador<9;contador++){
                            if(sudoku[i][contador][0]== valor){
                                indicador = 1;
                            }
                        }
                        if(indicador!=1){
                            sudoku[i][j][k]=valor;
                            k++;
                        }
                        valor++;
                    }
                }


            k=1;
            valor=1;
            }

        }
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

    if(consegue_resolver){
        printf("\nSudoku resolvido:\n");
        imprime_sudoku();
    }
}
