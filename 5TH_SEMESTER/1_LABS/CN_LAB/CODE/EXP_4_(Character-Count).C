#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void frameData(char *data, char *framed_data) {
    sprintf(framed_data, "%d%s", (int)strlen(data), data);
}

void unframeData(char *framed_data, char *unframed_data) {
    char *ptr;
    int char_count = strtol(framed_data, &ptr, 10); 
    if (strlen(ptr) == char_count) {
        strcpy(unframed_data, ptr);
        printf("Data received correctly\n");
    } else {
        printf("Error in data transmission\n");
    }
}

int main() {
    char data[] = "Hello, World!";
    char framed_data[256], unframed_data[256];

    printf("Original Data: %s\n", data);

    frameData(data, framed_data);
    printf("Framed Data: %s\n", framed_data);

    unframeData(framed_data, unframed_data);
    printf("Unframed Data: %s\n", unframed_data);

    return 0;
}
