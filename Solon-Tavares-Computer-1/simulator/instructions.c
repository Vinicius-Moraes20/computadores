#include "bits.c"
extern int pc, bus;


int mai = 0x00, tm = 0x00, iri = 0x00, acc = 0x00, brg = 0x00, out = 0x00;


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
    PCI; RMO; MAI;
    RMO; BRI;
    printf("b: 0x%.2x        acc: 0x%.2x\n", brg, acc);
    ALU; ACI; 
}

void OUT() {
    fetchExecution();
    ACO; ORI;
    printf(">> 0x%.2x\n", out);
}

void HLT() {
    fetchExecution();
    system("pause");
    exit(1);
}
