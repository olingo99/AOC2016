#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../helper/file.h"

typedef struct{
    int x,y;
} Coordinate;

int part1(FILE *fptr, long max_line_length){
    char *line = malloc(sizeof(char)*(max_line_length+1));

    Coordinate coord = {1,1};

    char code[100];
    int counter = 0;


    while (fgets(line, sizeof(char)*(max_line_length+1), fptr))
    {
        // printf("Running for 2\n");

        for (int i = 0; line[i]!='\0'; i++)
        {
            switch (line[i])
            {
            case 'U':
                if (coord.y>0) coord.y--;
                break;
            case 'D':
                if (coord.y<2) coord.y++;
                break;
            case 'L':
                if (coord.x>0) coord.x--;
                break;
            case 'R':
                if (coord.x<2) coord.x++;
                break;
            
            default:
                break;
            }
        }
        // printf("adding to code\n");
        printf("coord %d,%d\n", coord.x, coord.y);
        printf("index = %d\n",coord.x+(3*coord.y)+1); 
        code[counter++] = coord.x+(3*coord.y)+1 + '0';
    }
    code[counter++] = '\0';
    printf("printing\n");


    printf("%s\n", code);


    free(line);
    return 0;
}


int part2(FILE *fptr, long max_line_length){
    const char keypad[25] = "0010002340567890ABC000D00";
    const int length = 5;
    char *line = malloc(sizeof(char)*(max_line_length+1));

    Coordinate coord = {0,2};

    char code[100];
    int counter = 0;


    while (fgets(line, sizeof(char)*(max_line_length+1), fptr))
    {
        for (int i = 0; line[i]!='\0'; i++)
        {
            switch (line[i])
            {
            case 'U':
                if (coord.y>0 &&keypad[coord.x+((coord.y-1)*length)]!='0') coord.y--;
                break;
            case 'D':
                if (coord.y<4 && keypad[coord.x+((coord.y+1)*length)]!='0') coord.y++;
                break;
            case 'L':
                if (coord.x>0 && keypad[(coord.x-1)+(coord.y*length)]!='0') coord.x--;
                break;
            case 'R':
                if (coord.x<4 && keypad[(coord.x+1)+(coord.y*length)]!='0') coord.x++;
                break;
            
            default:
                break;
            }
        }
        // printf("adding to code\n");
        printf("coord %d,%d\n", coord.x, coord.y);
        printf("index = %d\n",coord.x+(length*coord.y)); 
        code[counter++] = keypad[coord.x+(length*coord.y)];
    }
    code[counter++] = '\0';
    printf("printing\n");


    printf("%s\n", code);


    free(line);
    return 0;
}

int main() {
    FILE *fptr;

    fptr = fopen("data/day2.txt", "r");
    if(fptr == NULL) 
    {
        printf("Not able to open the file.");
        return -1;
    }

    printf("Running Day 2\n");

    part2(fptr, get_max_line_length(fptr));

    fclose(fptr);

    return 0;

}

