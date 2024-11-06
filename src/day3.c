#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../helper/file.h"

int is_valid_triangle(int a[]) {
    return (a[0] + a[1] > a[2]) && (a[0] + a[2] > a[1]) && (a[1] + a[2] > a[0]);
}

int part1(FILE *fptr, long max_line_length){
    char *line = malloc(sizeof(char)*(max_line_length+1));
    int count = 0;
    int index = 0;

    while (fgets(line, sizeof(char)*(max_line_length+1), fptr))
    {
        int a[3];
        int b[3];
        int c[3];

        if (sscanf(line, "%d %d %d", &a[index], &b[index], &c[index]) != 3)
        {
            printf("error in parsing\n");
        }

        index++;

        if (index == 3)
        {
            if (is_valid_triangle(a)) count++;
            if (is_valid_triangle(b)) count++;
            if (is_valid_triangle(c)) count++;
            index = 0;
        }
    }

    printf("tot possible triangles = %d\n", count);


    free(line);
    return 0;
}

int main() {
    FILE *fptr;

    fptr = fopen("data/day3.txt", "r");
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

