/*
    main: Solon Tavares Computer 1 - Maquina Virtual

    Arquivo onde é declarado todos os registradores do computador STC1

    Autor: Tec. Vinicius Moraes  
    Versão: 1.0
    Data: 08/2021
*/

int B_REG = 0x00,       // Registrador B
    IN_REG = 0x00,      // Registrador de instrução
    SP_REG = 0x00,      // Registrador de ponto na pilha
    ACC_REG = 0x00,     // Acumulador
    OUT_REG = 0x00,     // Registrador de saida
    INS_REG = 0x00,     // Registrador de instrução
    ARG_REG = 0x00,     // Registrador de argumento
    FLAG_REG = 0x00;    // Registrador de status
    
int UR[16] = {0x00};    // Registrador de usuario