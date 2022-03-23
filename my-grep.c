#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/* sources:
    1: https://www.delftstack.com/howto/c/string-contains-in-c/
*/
void readStream(char* searchTerm) {
    size_t length = 0;
    char* buf = NULL;
    while (getline(&buf, &length, stdin) != -1) {
        if (strstr(buf, searchTerm) != NULL) { //sources used: 1
            printf("%s", buf);
        }
    }
    puts("\0");
    free(buf);
}

void readFile(char* searchTerm, FILE* file) {
    size_t length = 0;
    char* buf = NULL;
    while (getline(&buf, &length, file) != -1) {
        if (strstr(buf, searchTerm) != NULL) { //sources used: 1
            printf("%s", buf);
        }
    }
    puts("\0");
    fclose(file);
    free(buf);
}

FILE* openFile(char* filename) {
    FILE* f = NULL;
    if ((f = fopen(filename, "r")) == NULL) {
        fprintf(stderr, "my-grep: cannot open file\n");
        exit(1);
    }
    return f;
}

int main(int argc, char** argv) {
    if (argc == 1)
        printf("my-grep: searchterm [file ...]\n");
    else if (argc == 2) {
        readStream(argv[1]);
    } else {
        for (int i = 2; i < argc; i++) {
            FILE* f = NULL;
            f = openFile(argv[i]);
            readFile(argv[1], f);
        }
    }
    return 0;
}