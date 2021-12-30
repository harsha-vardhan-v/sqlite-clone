#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "cli.h"
int main(int argc, char *argv[])
{
    InputBuffer *inputBuffer = new_input_buffer();
    
    while (true) {
        print_prompt();
        read_input(inputBuffer);

        if (strcmp(inputBuffer->buffer, ".exit") == 0)
            exit(EXIT_SUCCESS);
        else {
            printf(" Unrecognized command %s.\n", inputBuffer->buffer);
        }
    }
}