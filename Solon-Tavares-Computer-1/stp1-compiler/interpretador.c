int chr_read(int ch) {
    if (ch >= '0' && ch <= '9') {
        return ch - 0x30;
    } else {
        switch(ch) {
	        case 'a':
	        case 'A': return 0x0A; break;
	        case 'b':
	        case 'B': return 0x0B; break;
	        case 'c':
	        case 'C': return 0x0C; break;
	        case 'd':
	        case 'D': return 0x0D; break;
	        case 'e':
	        case 'E': return 0x0E; break;
	        case 'f':
	        case 'F': return 0x0F; break;
	    }
    }
}

unsigned char interpreter(unsigned char *inst) {
    if     (!strcmp(inst,"NOP"))  return 0x00;
    else if(!strcmp(inst,"LDA"))  return 0x01;
    else if(!strcmp(inst,"LDI"))  return 0x02;
    else if(!strcmp(inst,"STA"))  return 0x03;
    else if(!strcmp(inst,"ADD"))  return 0x04;
    else if(!strcmp(inst,"SUB"))  return 0x05;
    else if(!strcmp(inst,"AND"))  return 0x06;
    else if(!strcmp(inst,"ORL"))  return 0x07;
    else if(!strcmp(inst,"XOR"))  return 0x08;
    else if(!strcmp(inst,"NOT"))  return 0x09;
    else if(!strcmp(inst,"JMP"))  return 0x0c;
    else if(!strcmp(inst,"INR"))  return 0x0d;
    else if(!strcmp(inst,"OUT"))  return 0x0e;
    else if(!strcmp(inst,"HLT"))  return 0x0f;
}