#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * strcat_start(const char*, char*);

int main(){
    FILE *fp, *fpout;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    char delims[] = " ";
    char *result = NULL;
    int caseno = -1;

    fp = fopen("B-large-0.in", "r");
    fpout = fopen("B-large-0.out", "w");

    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fp)) != -1) {
        caseno++;
        if(caseno == 0){
            continue;
        }
        char output[400];
        strcpy(output, "");
        int length = 0;
        length = strlen(line);
        if(line[length-1] == '\n' )
            line[length-1] = '\0';
        result = (char *)strtok(line, delims );
        while(result != NULL ) {
            strcat_start(result, output);
            result = (char*)strtok( NULL, delims );
        }
        fprintf(fpout, "Case #%d: %s\n", caseno, output);
    }

    exit(EXIT_SUCCESS);

    fclose(fp);
    fclose(fpout);
    return 0;
}

char *strcat_start(const char* source, char* dest){
    char *pos;
    char *temp = NULL;
    int length = 0;
    length = strlen(source) + strlen(dest) +2;
    temp = (char*)malloc(length);
    strcpy(temp, "");
    temp = strcat(temp, source);
    temp = strcat(temp, " ");
    temp = strcat(temp, dest);
    temp = strcat(temp, "\0");
    strcpy(dest, temp);
}

