#include <stdlib.h>
#include <stdio.h>

#include "instructions.c"
#include "bits.c"

#define sizeProgramMemory 512

void loadProgram();
void run();

int pc = 0, bus = 0x00;
int programMemory[sizeProgramMemory] = {0x00};

int main() {
    puts("\t\tSolon Tavares Processor 1        V0.1");
    loadProgram();
    run();

}

void loadProgram() {
    FILE *arq;
    register int i = 0;
    arq = fopen("arch.bin", "rb");

    if (arq == NULL) {
        puts("Arquivo inexistente ou corrompido!");
        exit(0);
    }

    while (!feof(arq)) {
        programMemory[i] = fgetc(arq);
        printf("0x%.2x ", programMemory[i]);
        i++;
        
    }
    system("pause");
    putchar ('\n');
    fclose(arq);
}

void run() {
    while (1) {
        printf("Local da memoria %x\t Instrucao: ", pc);
        switch(programMemory[pc]) {
            case 0x00:
                printf("NOP\n");
                NOP();
                break;

            case 0x01:
                printf("LDA\n");
                LDA();
                printf("ACC: 0x%.2x\n", acc);
                break;

            case 0x02:
                printf("LDI\n");
                LDI();
                printf("ACC: 0x%.2x\n", acc);
                break;
            
            case 0x03:
                printf("STA\n");
                STA();
                break;
                
            case 0x0f:
                printf("HLT\n");
                HLT();
                break;
            
            default:
                printf("NAO RECONHECIDA!\n");
                exit(1);
                break;
        }
    }
}