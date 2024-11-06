#include <stdio.h>
#include <string.h>

long get_max_line_length(FILE *fptr) {
    long max_line_length = 0;
    long current_line_length = 0;
    int ch;

    while ((ch = fgetc(fptr)) != EOF) {
        current_line_length++;
        if (ch == '\n') {
            if (current_line_length > max_line_length) {
                max_line_length = current_line_length;
            }
            current_line_length = 0;
        }
    }

    if (current_line_length > max_line_length) {
        max_line_length = current_line_length;
    }

    fseek(fptr, 0, SEEK_SET);

    return max_line_length;
}