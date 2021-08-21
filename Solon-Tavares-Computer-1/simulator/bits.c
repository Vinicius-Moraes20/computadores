extern int pc, bus, programMemory[], iri, mai, acc;

#define PCO bus = pc
#define MAI mai = bus
#define PCI pc++
#define RMO bus = programMemory[mai];
#define IRI iri = bus
#define ACI acc = bus
#define RMI programMemory[mai] = bus
#define ACO bus = acc