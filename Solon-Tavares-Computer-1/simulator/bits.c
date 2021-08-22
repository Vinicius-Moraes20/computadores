extern int pc, bus, programMemory[], iri, mai, acc, brg, instruction, out;

#define PCO bus = pc
#define MAI mai = bus
#define PCI pc++
#define RMO bus = programMemory[mai];
#define IRI iri = bus
#define ACI acc = bus
#define RMI programMemory[mai] = bus
#define ACO bus = acc
#define BRI brg = bus
#define ORI out = bus
#define SUM 

#define ALU switch (instruction) {                 \
                case 0x04: bus = acc + brg; break; \
                case 0x05: bus = acc - brg; break; \
            }