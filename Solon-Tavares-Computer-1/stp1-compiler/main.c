#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "strings.c"

int chr_reader(int ch);

int main() {
    FILE *arq_asm, *arq_bin;
    int chr, comment = 0, LSB, MSB;
    char s[50];
    register int count = 0;

    puts("\t\t\tSolon Tavares Computer 1 - Compiler");
    printf("Informe o nome do arquivo (.asm): ");
    gets(s);

    if ((arq_asm = fopen(s, "r")) == NULL) {
        puts(":( Arquivo nao encontrado :(");
        exit(1);
    }

    puts("Compilando...");

    arq_bin = fopen(tradeFormat(s), "wb");

    while ((chr = fgetc(arq_asm)) != EOF) {
        if (chr == ';') comment = 1;

        if(comment) {
            if (chr == 0x0A) comment = 0;
        } else {
            if (chr != 0x20 && chr != 0x09 && chr != 0x0A) {
                switch(count) {
                    case 0: MSB = chr_read(chr); break;
                    case 1: LSB = chr_read(chr); break;
                }
                count++;

                if (count > 1 && chr == 'h') {
                    fputc(MSB << 4 | LSB, arq_bin);
                    count = 0;
                }
            }
        }
    }

    printf("Arquivo compilado com sucesso! :)");
    fclose(arq_asm);
    fclose(arq_bin);
}

int chr_read(int ch) {
    if (ch >= '0' && ch <= '9') {
        return ch - 0x30;
    } else {
        switch(ch) {
	        case 'a':
	        case 'A': return 0x0A; break;
	        case 'b':
	        case 'B': return 0x0B; break;
	        case 'c':
	        case 'C': return 0x0C; break;
	        case 'd':
	        case 'D': return 0x0D; break;
	        case 'e':
	        case 'E': return 0x0E; break;
	        case 'f':
	        case 'F': return 0x0F; break;
	    }
    }
}
