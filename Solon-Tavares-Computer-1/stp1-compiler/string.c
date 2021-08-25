int strlen(char *s) {
    register int i = 0;
    while (s[i] != '\0') i++;
    return i;
}

char *strcat(char *dest, char *orig) {
    register int i = 0, len = strlen(dest);
    while (dest[i + len] = orig[i]) i++;
    return dest;
}

int strcmp(char *s1, char *s2) {
  register int i = 0;   
  while(s1[i] == s2[i] && s1[i] != '\0') i++;
  return((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char *tradeFormat(char *s) {
    register int len = strlen(s), n = 0;
    char format[5] = ".bin";
    for (register int i = len - 4; i <= len; i++) {
        s[i] = format[n];
        n++;
    }
    return s;
}