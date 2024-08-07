#include "functions.h"
#include <ctype.h>
#include "string.h"
#include "stdio.h"
#include "stdlib.h"

int hexadecimal_para_decimal (char *num) {
    int num_decimal = strtol(num, NULL, 16);
    return num_decimal;
}

void gerador (char *inicial, char *final) {
    FILE *file = fopen(FILE_NAME, "w");
    if (file) {
        if (hexadecimal_para_decimal(inicial) < hexadecimal_para_decimal(final)) {
            for (int i = hexadecimal_para_decimal(inicial); i <= hexadecimal_para_decimal(final); i++) {
                char hexa[20];
                sprintf(hexa, "%X\n", i);
                fputs(hexa, file);
            }
        }
        else
            printf("Valor inicial é maior que final, por favor, insira um intervalo do menor para o maior.\n");
        fclose(file);
        printf("Arquivo com sequencia hexadecimal gerada com sucesso\nO arquivo encontra-se pelo nome SerialNumber.txt\n");
    }
    else
        printf("Falha na criação do arquivo.\n");
}

void menu() {
    char hexa_inicial[20], hexa_final[20];
    printf("Insira o valor inicial (menor): \n");
    fgets(hexa_inicial, 20, stdin);
    printf("Insira o valor final (maior): \n");
    fgets(hexa_final, 20, stdin);
    gerador(hexa_inicial, hexa_final);
    system("pause");
}

