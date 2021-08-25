SET DE INSTRUÇÕES:
> NOP: não faz nada
> LDA: carregada no acumulador, valor presente no endereço de memoria indicado
> LDI: carrega no acumulador, o valor indicado
> STA: armazena o conteúdo do acumulador no endereço definido no operando da instrução.
> ADD: Soma o conteúdo do acumulador com o conteúdo da posição de memoria apontada pelo operando da instrução. 							ACC = ACC + B_REG(oper)
> SUB: Subtrai o conteúdo do acumulador com o conteúdo da posição de memoria apontada pelo operando da instrução. 							ACC = ACC - B_REG(oper)
> AND: Executa a operação logica AND, entre o conteúdo do acumulador e o conteúdo da posição de memoria apontada pelo operando da instrução. 	ACC = ACC | B_REG(oper)
> ORL: Executa a operação logica OR, entre o conteúdo do acumulador e o conteúdo da posição de memoria apontada pelo operando da instrução. 		ACC = ACC & B_REG(oper)
> XOR: Executa a operação lógica XOR, entre o conteúdo do acumulador e o conteúdo da posição da memora apontada pelo operando da instrução.		ACC = ACC ^ B_REG(oper)
> NOT: Executa a operação logica NOT, sobre o conteúdo do acumulador. 																ACC = ~ACC
> OUT: Guarda o conteúdo do acumulador no registrador de saida.
> INR: Envia o conteúdo do registrador de entrada para o acumulador;
> HLT: Para o processamento.


REGISTRADORES ESPECIAIS
> Registrador de saida: Poderá ser usado para armazenar um byte de saida do computador
> Registrador de entrada:  Poderá ser usado para armazenar um byte de entrada para o computador
> Acumulador: Poderá conter valores de 00h a FFh, pois é um registrador de 8 bits. Pode ser lido e escrito pelo usuario.
> Registrador B: Poderá conter valores de 00h a FFh, pois é um registrador de 8 bits. É apenas escrito automaticamente quando utilizamos instruções lógicas e aritméticas. Serve para guardar o dado correspondente ao endereço de memoria indicado no operando das instruções da ALU.
> Registrador de instrução: é nele que opcode de 8 bits referente a cada instrução fica salvo para ser processado pelo decodificador de instruções.

