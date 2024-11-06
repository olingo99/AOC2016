#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../helper/file.h"


typedef enum direction{
    NORTH,
    EAST,
    SOUTH,
    WEST,
}direction_t;

typedef struct {
    int x,y;
}Coordinates;

int part1(FILE *fptr, long max_line_length){
    char *line = malloc(sizeof(char)*(max_line_length+1));

    int dir = NORTH;
    int count[2] = {0,0};

    while (fgets(line, sizeof(char)*(max_line_length+1), fptr)) {
        char *pt = strtok(line, ", ");
        while (pt != NULL){
            char ndir;
            int steps;

            sscanf(pt, "%c%d", &ndir, &steps);

            ndir=='L' ? dir--:dir++;
            if (dir > WEST){
                dir = NORTH;
            }
            else if (dir < NORTH){
                dir = WEST;
            }


            count[dir%2] += dir>=2?-steps:steps;

            pt = strtok(NULL, ", ");
        }
    }

    printf("vert : %d ; hori: %d\n", count[0], count[1]);

    printf("tot %d\n", abs(count[0]) + abs(count[1]));

    free(line);
    return 0;
}


int part2(FILE *fptr, long max_line_length){
    char *line = malloc(sizeof(char)*(max_line_length+1));

    int dir = NORTH;
    int count[2] = {0,0};

    int history_size = 100;
    int history_count = 0;
    Coordinates *history = malloc(history_size * sizeof(Coordinates));

    while (fgets(line, sizeof(char)*(max_line_length+1), fptr)) {
        char *pt = strtok(line, ", ");
        while (pt != NULL){
            char ndir;
            int steps;

            sscanf(pt, "%c%d", &ndir, &steps);

            ndir=='L' ? dir--:dir++;
            if (dir > WEST){
                dir = NORTH;
            }
            else if (dir < NORTH){
                dir = WEST;
            }

            for (int i = 0; i <steps; i++){
                count[dir%2] += dir>=2?-1:1;

                for (int j = 0; j < history_count; j++){
                    if (history[j].y == count[0] && history[j].x == count[1]){
                        printf("tot %d\n", abs(count[0]) + abs(count[1]));
                        free(line);
                        free(history);
                        return 0;
                    }
                }

                if (history_count>= history_size){
                    history_size *=2;
                    history = realloc(history, history_size*sizeof(Coordinates));
                    if (history == NULL){
                        printf("memory alloc failed");
                        free(line);
                        return -1;
                    }
                }

                history[history_count].y = count[0];
                history[history_count].x = count[1];
                history_count++;
            }

            

            pt = strtok(NULL, ", ");
        }
    }

    printf("vert : %d ; hori: %d\n", count[0], count[1]);

    printf("tot %d\n", abs(count[0]) + abs(count[1]));

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

    part2(fptr, get_max_line_length(fptr));

    fclose(fptr);

    return 0;

}

