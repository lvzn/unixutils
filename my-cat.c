#include <stdio.h>
#include <stdlib.h>


//Reading file given in args
int readFile(char* filename) {
    FILE* f = NULL;
    char buf[100];
    int length = 100;
    //Handling error in case when file cannot be opened
    if ((f = fopen(filename, "r")) == NULL) {
        fprintf(stderr, "my-cat: cannot open file\n");
        exit(1);
    }
    while (fgets(buf, length, f) != NULL){ //reading file line-by-line until fgets points to null
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
        //Initiating reading function to multiple files
        for (int i = 1; i < argc; i++) {
            readFile(argv[i]);
        }
        break;
    }
    return(0);
}