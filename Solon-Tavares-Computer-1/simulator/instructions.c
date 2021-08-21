#include "bits.c"
extern int pc, bus;


int mai = 0x00, tm = 0x00, iri = 0x00, acc = 0x00;


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

void HLT() {
    fetchExecution();
    system("pause");
    exit(1);
}

void STA() {
    fetchExecution();
    PCO; MAI;               tm++;
    PCI, RMO; MAI;          tm++;
    ACO, RMI;               tm++;
                            tm++;
                            tm = 0;
}
