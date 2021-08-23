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
#define AL0
#define AL1
#define NOT_B 

#define ALU switch (instruction) {                   \
                case 0x04: bus = acc + brg;   break; \
                case 0x05: bus = acc - brg;   break; \
                case 0x06: bus = acc & brg;   break; \
                case 0x07: bus = acc | brg;   break; \
                case 0x08: bus = acc ^ brg;   break; \
                case 0x09: bus = ~acc & 0xff; break; \
            }