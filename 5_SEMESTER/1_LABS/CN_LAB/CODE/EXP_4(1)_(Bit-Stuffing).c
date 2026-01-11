#include <stdio.h>
#include <string.h>

void stuff(const char* in, char* out) {
    int i=0,j=0,c=0;
    while(in[i]) {
        out[j++] = in[i];
        if(in[i]=='1' && ++c==5) { out[j++]='0'; c=0; }
        if(in[i]=='0') c=0; i++;
    } out[j]='\0';
}

void destuff(const char* in, char* out) {
    int i=0,j=0,c=0;
    while(in[i]) {
        out[j++] = in[i];
        if(in[i]=='1' && ++c==5) { if(in[i+1]=='0') i++; c=0; }
        if(in[i]=='0') c=0; i++;
    } out[j]='\0';
}

int main() {
    const char *bits="011111101111110"; char s[100], ds[100];
    stuff(bits,s); destuff(s,ds);
    printf("Original: %s\nStuffed: %s\nDestuffed: %s\n", bits,s,ds);
}
