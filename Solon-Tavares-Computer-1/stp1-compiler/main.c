#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "interpretador.c"
#include "string.c"


int main() {
    FILE *arq_asm, *arq_bin;
    int chr, LSB, MSB;
    
    char s[50];
    register int count = 0;

    char inst[4];
    int ins1, ins2, ins3;
    int comment = 0;

    int countByte = 0;

    puts("\t\t\tSolon Tavares Computer 1 - Compiler");
    printf("Informe o nome do arquivo (.asm): ");
    gets(s);

    if ((arq_asm = fopen(s, "r")) == NULL) {
        puts(":( Arquivo nao encontrado :(");
        printf("Pressiona qualquer tecla para sair...");
        getch();
        exit(1);
    }

    puts("Compilando...");

    arq_bin = fopen(tradeFormat(s), "wb");

    while ((chr = fgetc(arq_asm)) != EOF) {
        if (chr == ';') comment = 1;

        if (comment) {
            if (chr == 0x0A) comment = 0;
        } else {
            if (chr != 0x20 && chr != 0x09 && chr != 0x0A) {
                switch (count) {
                    case 0:
                        MSB = chr_read(chr);
                        inst[0] = chr;
                        break;
                    case 1:
                        LSB = chr_read(chr);
                        inst[1] = chr;
                        break;
                    case 2:
                        inst[2] = chr;
                        inst[3] = '\0';
                        break;
                }
                count++;

                if (count > 1 && chr == 'h') {
                    fputc(MSB << 4 | LSB, arq_bin);
                    countByte++;
                    count = 0;
                }
                if (count > 2) {
                    printf("%s\n", inst);
                    fputc(interpreter(inst), arq_bin);
                    countByte++;
                    count = 0;
                }
            }
        }
    }
    
    puts(" :) Programa compilado com sucesso :)");
    printf("Arquivo gerado: %s\tTamanho: %dbytes\n", tradeFormat(s), countByte);
    printf("Pressiona qualquer tecla para sair...");
    getch();
    fclose(arq_asm);
    fclose(arq_bin);
}