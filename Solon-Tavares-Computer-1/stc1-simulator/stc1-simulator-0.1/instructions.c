#include "bits.c"
extern int pc, bus;


int mai = 0x00, tm = 0x00, iri = 0x00, acc = 0x00, brg = 0x00, out = 0x00, ir = 0x00;


void fetchExecution() {
    PCO; MAI;               tm++;
    PCI; RMO; IRI;          tm++;
}

void NOP() {
    fetchExecution();
                            tm++;
                            tm++;
                            tm++;
                            tm++;
                            tm = 0;
}

void LDA() {
    fetchExecution();
    PCO; MAI;               tm++;   
    PCI; RMO; MAI;          tm++;   
    RMO; ACI;               tm++;   
                            tm++;   
                            tm = 0;
}

void LDI() {
    fetchExecution();
    PCO; MAI;               tm++;
    PCI; RMO; ACI;          tm++;
                            tm++;
                            tm++;
                            tm = 0;
}   

void STA() {
    fetchExecution();
    PCO; MAI;               tm++;
    PCI, RMO; MAI;          tm++;
    ACO, RMI;               tm++;
                            tm++;
                            tm = 0;
}

void ADD() {
    fetchExecution();
    PCO; MAI;               tm++;
    PCI; RMO; MAI;          tm++;
    RMO; BRI;               tm++;
    ALU; ACI;               tm++;
                            tm = 0;
}

void SUB() {
    fetchExecution();
    PCO; MAI;               tm++;
    PCI; RMO; MAI;          tm++;
    RMO; BRI;               tm++;
    SUM; ALU; ACI;          tm++;
                            tm = 0;
}

void AND() {
    fetchExecution();    
    PCO; MAI;               tm++;
    PCI; RMO; MAI;          tm++;
    RMO; BRI;               tm++;
    AL0; ALU; ACI;          tm++;
                            tm = 0;
}

void OR() {
    fetchExecution();
    PCO; MAI;               tm++;
    PCI; RMO; MAI;          tm++;
    RMO; BRI;               tm++;
    AL1; ALU; ACI;          tm++;
                            tm = 0;
}

void XOR() {
    fetchExecution();
    PCO; MAI;               tm++;
    PCI; RMO; MAI;          tm++;
    RMO; BRI;               tm++;
    AL1; AL0; ALU; ACI;     tm++;
                            tm = 0;
}

void NOT() {
    fetchExecution();
    AL0; AL1; NOT_B; ALU; ACI;  tm++;
                            tm++;
                            tm++;
                            tm++;
                            tm = 0;
}

void IN() {
    fetchExecution();
    ITI; ACI;               tm++;
                            tm++;
                            tm++;
                            tm++;
                            tm = 0;
}

void OUT() {
    fetchExecution();       
    ACO; ORI;               tm++;
                            tm++;
                            tm++;
                            tm++;
                            tm = 0;
    printf("\n\t\t\t  >> 0x%.2x\n", out);
}

void JMP() {
    fetchExecution();
    PCO; MAI;               tm++;
    RMO; JMP_B;             tm++;
                            tm++;
                            tm++;
                            tm = 0;
    system("pause");
}

void HLT() {
    fetchExecution();
    puts("Fim da execucao."); getch();
    exit(1);
}
