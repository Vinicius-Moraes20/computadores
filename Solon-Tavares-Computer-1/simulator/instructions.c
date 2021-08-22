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
    PCI; RMO; MAI;          tm++;
    RMO; BRI;               tm++;
    ALU; ACI;               tm++;
                            tm = 0;
}

void SUB() {
    fetchExecution();
    PCO; MAI;
    PCI; RMO; MAI;
    RMO; BRI;
    SUM; ALU; ACI;
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

void HLT() {
    fetchExecution();
    system("pause");
    exit(1);
}
