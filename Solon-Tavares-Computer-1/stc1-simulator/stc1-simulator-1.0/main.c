/*
    main: Solon Tavares Computer 1 - Maquina Virtual

    Maquina virtual para simular a arquitetura do computador: Solon Tavares Computer 1

    Autor: Tec. Vinicius Moraes 
    Versão: 1.0
    Data: 08/2021
*/

//------------------------------------ Inclusão de bibliotecas
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

//------------------------------------ Inclusão de arquivos externos
#include "registradores.c"                  // Arquivo onde é declarado todos os registradores do computador
#include "instrucoes.c"                     // Arquivo de declaração de todas instruções do computador
#include "bits.c"                           // Arquivo que contém as marcros dos fios e bits do computador

//------------------------------------ Definição de constantes
#define sizeProgramMemory 512               // Constante que define o tamanho da memoria de programa

//------------------------------------ Definição de Variaveis
int programMemory[sizeProgramMemory];       // Vetor que vai ser carregado o programa (memoria de programa)

//------------------------------------ Protótipo de funções internas
void loadProgram();                         // Função responsavel por carregar o programa do arquivo indicado .bin
void header();                              // Função responsavel por escrever o cabeçalho das telas
void fimExecucao();                         // Função para finalizar o programa, para ter compatibilidade em qualquer sistema operacional
void run();                                 // Função responsavel por rodar o programa carregado na memoria de programa

//------------------------------------ Função principal
int main() {
    header();
    loadProgram();
    run();
    
    fimExecucao();
}

void header() {
    puts("\t----------------------------------------------------");
    puts("\t          Solon Tavares Computer 1    V1.0");
    puts("\t----------------------------------------------------");
}

void loadProgram() {
    char arq_bin[30];                       // Variavel que irá armazenar o nome do programa carregado
    register int i = 0,                     // Variavel de interações  
                 j = 1;                     // Variavel de interações 
    FILE *arq;                              // Ponteiro para o arquivo do programa a ser carregado

    printf("Digite o nome do programa (.bin): ");
    gets(arq_bin);
    arq = fopen(arq_bin, "rb");

    if(arq == NULL) {
        puts("\nArquivo inexistente ou corrompido :(");
        fimExecucao();
    }

    fseek(arq, 0, SEEK_END);
    if ((ftell(arq)) > sizeProgramMemory - 1) {
        puts("O Tamanho do programa excede a quantidade de bytes suportados pelo computador!");
        fimExecucao();
    }
    rewind(arq);
    printf("\n\t----------------------------------------------------\n\n\t\t  ");

    while (!feof(arq)) {
        programMemory[i] = fgetc(arq);
        if (programMemory[i] != 0xffffffff) printf(" %.2x", programMemory[i]);
        i++;
        if (i / 10 == j) {
            printf("\n\t\t  ");
            j++;
        }
    }    

    puts("\n\nPrograma carregado com sucesso!");
    printf("Tamanho do software: %d bytes", i);
}

void fimExecucao() {
    printf("\nPressione qualquer tecla para continuar... ");
    while (1) if (kbhit()) exit(1);
}

void run() {
    
}