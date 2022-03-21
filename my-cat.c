#include <stdio.h>
#include <stdlib.h>

int readFile(char* filename) {
    FILE* f = NULL;
    char buf[100];
    int length = 100;
    if ((f = fopen(filename, "r")) == NULL) {
        fprintf(stderr, "my-cat: cannot open file\n");
        exit(1);
    }
    while (fgets(buf, length, f) != NULL){
        printf("%s", buf);
    }
    puts("\n");
    fclose(f);
    return(0);
}

int main(int argc, char** argv) {
    switch (argc) {
    case 1:
        exit(0);
        break;
    default:
        for (int i = 1; i < argc; i++) {
            readFile(argv[i]);
        }
        break;
    }
    return(0);
}