#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../helper/file.h"


int part1(FILE *fptr, long max_line_length){
    char *line = malloc(sizeof(char)*(max_line_length+1));

    while (fgets(line, sizeof(char)*(max_line_length+1), fptr)) 
    {
        
    }


    free(line);
    return 0;
}

int main() {
    FILE *fptr;

    fptr = fopen("data/day1.txt", "r");
    if(fptr == NULL) 
    {
        printf("Not able to open the file.");
        return -1;
    }

    printf("Running Day 1\n");

    part1(fptr, get_max_line_length(fptr));

    fclose(fptr);

    return 0;

}

