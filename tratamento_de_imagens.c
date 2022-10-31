#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Por: Bruno Gomes Pereira e Eduardo Fidelis de Medeiros

int escalacinza(char nome_origem[50]){
    //Lê a imagem origem
    FILE *origem = fopen(nome_origem, "r");
    int i, j, k, coluna, linha, vmax, media;
    char buffer[250];
    fgets(buffer, 250, origem);
    fgets(buffer, 250, origem);
    fscanf(origem, "%d %d", &coluna, &linha);
    int matriz[linha][coluna][3];
    fscanf(origem, "%d", &vmax);
    for(i = 0; i < linha; i++){
        for(j = 0; j < coluna; j++){
            for(k = 0; k < 3; k++){
                fscanf(origem, "%d", &matriz[i][j][k]);
            }
        }
    }

    //Escala de cinza
    FILE *escalacinza = fopen("escala_cinza.ppm", "w");
    fprintf(escalacinza, "P3\n");
    fprintf(escalacinza, "# By Bruno Gomes e Eduardo Fidelis\n");
    fprintf(escalacinza, "%d %d\n", coluna, linha);
    fprintf(escalacinza, "%d\n", vmax);
    for(i = 0; i < linha; i++){
        for(j = 0; j < coluna; j++){
            media = (matriz[i][j][0] + matriz[i][j][1] + matriz[i][j][2])/3;
            fprintf(escalacinza, "%d ", media);
            fprintf(escalacinza, "%d ", media);
            fprintf(escalacinza, "%d ", media);
        }
    }
    printf("\nFeito! Nome do arquivo: escala_cinza.ppm\n");
    fclose(escalacinza);
    fclose(origem);
}


int horizontal(char nome_origem[50]){
    //Lê a imagem origem
    FILE *origem = fopen(nome_origem, "r");
    int i, j, k, coluna, linha, vmax, media;
    char buffer[250];
    fgets(buffer, 250, origem);
    fgets(buffer, 250, origem);
    fscanf(origem, "%d %d", &coluna, &linha);
    int matriz[linha][coluna][3];
    fscanf(origem, "%d", &vmax);
    for(i = 0; i < linha; i++){
        for(j = 0; j < coluna; j++){
            for(k = 0; k < 3; k++){
                fscanf(origem, "%d", &matriz[i][j][k]);
            }
        }
    }

    //Inverte Horizontalmente
    FILE *horizontal = fopen("horizontal.ppm", "w");
    fprintf(horizontal, "P3\n");
    fprintf(horizontal, "# By Bruno Gomes e Eduardo Fidelis\n");
    fprintf(horizontal, "%d %d\n", coluna, linha);
    fprintf(horizontal, "%d\n", vmax);
    for(i = 0; i < linha; i++){
        for(j = coluna - 1; j >= 0; j--){
            for(k = 0; k < 3; k++){
                fprintf(horizontal, "%d\n", matriz[i][j][k]);
            }
        }
    }
    printf("\nFeito! Nome do arquivo: horizontal.ppm\n");
    fclose(horizontal);
    fclose(origem);
}


int vertical(char nome_origem[50]){
    //Lê a imagem origem
    FILE *origem = fopen(nome_origem, "r");
    int i, j, k, coluna, linha, vmax, media;
    char buffer[250];
    fgets(buffer, 250, origem);
    fgets(buffer, 250, origem);
    fscanf(origem, "%d %d", &coluna, &linha);
    int matriz[linha][coluna][3];
    fscanf(origem, "%d", &vmax);
    for(i = 0; i < linha; i++){
        for(j = 0; j < coluna; j++){
            for(k = 0; k < 3; k++){
                fscanf(origem, "%d", &matriz[i][j][k]);
            }
        }
    }

    //Inverte Verticalmente
    FILE *vertical = fopen("vertical.ppm", "w");
    fprintf(vertical, "P3\n");
    fprintf(vertical, "# By Bruno Gomes e Eduardo Fidelis\n");
    fprintf(vertical, "%d %d\n", coluna, linha);
    fprintf(vertical, "%d\n", vmax);
    for(i = linha - 1; i >= 0; i--){
        for(j = 0; j < coluna; j++){
            for(k = 0; k < 3; k++){
                fprintf(vertical, "%d\n", matriz[i][j][k]);
            }
        }
    }
    printf("\nFeito! Nome do arquivo: vertical.ppm\n");
    fclose(vertical);
    fclose(origem);
}


int divisao_vertical(char nome_origem[50]){
    //Lê a imagem origem
    FILE *origem = fopen(nome_origem, "r");
    int i, j, k, coluna, linha, vmax, media;
    char buffer[250];
    fgets(buffer, 250, origem);
    fgets(buffer, 250, origem);
    fscanf(origem, "%d %d", &coluna, &linha);
    int matriz[linha][coluna][3];
    fscanf(origem, "%d", &vmax);
    for(i = 0; i < linha; i++){
        for(j = 0; j < coluna; j++){
            for(k = 0; k < 3; k++){
                fscanf(origem, "%d", &matriz[i][j][k]);
            }
        }
    }

    //Parte esquerda da imagem
    int a,b,c;
    a = linha/2;
    b = coluna/2;
    FILE *esquerda = fopen("esquerda.ppm", "w");
    fprintf(esquerda, "P3\n");
    fprintf(esquerda, "# By Bruno Gomes e Eduardo Fidelis\n");
    fprintf(esquerda, "%d %d\n", coluna/2, linha);
    fprintf(esquerda, "%d\n", vmax);
    for(i = 0; i < linha; i++){
        for(j = 0; j < coluna/2; j++){
            for(k = 0; k < 3; k++){
                fprintf(esquerda, "%d\n", (matriz[i][j][k]));
            }
        }
    }
    
    //Parte direita da imagem
    FILE *direita = fopen("direita.ppm", "w");
    fprintf(direita, "P3\n");
    fprintf(direita, "# By Bruno Gomes e Eduardo Fidelis\n");
    fprintf(direita, "%d %d\n", coluna/2, linha);
    fprintf(direita, "%d\n", vmax);
    for(i = 0; i < linha; i++){
        for(j = coluna/2; j < coluna; j++){
            for(k = 0; k < 3; k++){
                fprintf(direita, "%d\n", (matriz[i][j][k]));
            }
        }
    }
    
    printf("\nFeito! Nome dos arquivos: esquerda.ppm e direita.ppm\n");
    fclose(esquerda);
    fclose(direita);
    fclose(origem);
}


int divisao_horizontal(char nome_origem[50]){
    //Lê a imagem origem
    FILE *origem = fopen(nome_origem, "r");
    int i, j, k, coluna, linha, vmax, media;
    char buffer[250];
    fgets(buffer, 250, origem);
    fgets(buffer, 250, origem);
    fscanf(origem, "%d %d", &coluna, &linha);
    int matriz[linha][coluna][3];
    fscanf(origem, "%d", &vmax);
    for(i = 0; i < linha; i++){
        for(j = 0; j < coluna; j++){
            for(k = 0; k < 3; k++){
                fscanf(origem, "%d", &matriz[i][j][k]);
            }
        }
    }

    //Parte Superior
    int a,b,c;
    a = linha/2;
    b = coluna/2;
    FILE *superior = fopen("superior.ppm", "w");
    fprintf(superior, "P3\n");
    fprintf(superior, "# Eduardo Fidelis\n");
    fprintf(superior, "%d %d\n", coluna, linha/2);
    fprintf(superior, "%d\n", vmax);
    for(i = 0; i < linha/2; i++){
        for(j = 0; j < coluna; j++){
            for(k = 0; k < 3; k++){
                fprintf(superior, "%d\n", (matriz[i][j][k]));
            }
        }
    }
    
    //Parte Inferior
    FILE *inferior = fopen("inferior.ppm", "w");
    fprintf(inferior, "P3\n");
    fprintf(inferior, "# Eduardo Fidelis\n");
    fprintf(inferior, "%d %d\n", coluna, linha/2);
    fprintf(inferior, "%d\n", vmax);
    for(i = linha/2; i < linha; i++){
        for(j = 0; j < coluna; j++){
            for(k = 0; k < 3; k++){
                fprintf(inferior, "%d\n", (matriz[i][j][k]));
            }
        }
    }

    printf("\nFeito! Nome dos arquivos: superior.ppm e inferior.ppm\n");
    fclose(superior);
    fclose(inferior);
    fclose(origem);
}






int main(void){
    //Pega o nome do arquivo original
    char nome_origem[50];
    printf("Digite o nome do arquivo original: ");
    gets(nome_origem);

    int contador = 1, escolha;
    while(contador > 0){
        //Menu
        printf("\n\nSistema de tratamento de imagens");
        printf("\n1 - Converter uma imagem colorida para escala de cinza");
        printf("\n2 - Espelhar uma imagem horizontalmente");
        printf("\n3 - Espelhar uma imagem verticalmente");
        printf("\n4 - Dividir uma imagem em dois arquivos (metade esquerda e metade direita)");
        printf("\n5 - Dividir uma imagem em dois arquivos (metade superior e metade inferior)");
        printf("\n11 - Sair");
        printf("\nEscolha: ");
        scanf("%d", &escolha);

        switch(escolha){
            case 1:
                escalacinza(nome_origem);
                break;

            case 2:
                horizontal(nome_origem);
                break;

            case 3:
                vertical(nome_origem);
                break;

            case 4:
                divisao_vertical(nome_origem);
                break;

            case 5:
                divisao_horizontal(nome_origem);
                break;

            case 6:
                break;

            case 7:
                break;

            case 8:
                break;

            case 9:
                break;

            case 10:
                break;

            case 11:
            contador--;
                break;

            default:
                printf("\n\nOpção Inválida!");
        }
    }
    return 0;
}