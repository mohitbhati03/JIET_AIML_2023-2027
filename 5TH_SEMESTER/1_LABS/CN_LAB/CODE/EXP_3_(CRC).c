#include <stdio.h>
#include <string.h>

void xor(char *r, const char *p, int len) {
    for (int i = 0; i < len; i++)
        r[i] = (r[i] == p[i]) ? '0' : '1';
}

void computeCRC(char *data, char *poly, char *crc) {
    int dLen = strlen(data), pLen = strlen(poly);
    char rem[200];
    strcpy(rem, data); strcat(rem, "0000000000000000");
    strncpy(crc, rem, pLen);
    for (int i = pLen; i <= dLen + pLen - 1; i++) {
        if (crc[0] == '1') xor(crc, poly, pLen);
        memmove(crc, crc + 1, pLen - 1);
        crc[pLen - 1] = rem[i];
    }
    crc[pLen - 1] = '\0';
}

int main() {
    char data[100], poly[20], crc[20], tx[120], rx[120], check[20];
    printf("Data: "); scanf("%s", data);
    printf("Poly: "); scanf("%s", poly);
    computeCRC(data, poly, crc);
    printf("CRC: %s\n", crc);
    strcpy(tx, data); strcat(tx, crc);
    printf("Tx: %s\n", tx);
    printf("Rx: "); scanf("%s", rx);
    computeCRC(rx, poly, check);
    printf("%s\n", strspn(check, "0") == strlen(poly) - 1 ?
        "No Error" : "Error Detected");
    return 0;
}
