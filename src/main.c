#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "cli.h"
#include "meta.h"
int main(int argc, char *argv[])
{
    InputBuffer *inputBuffer = new_input_buffer();
    
    while (true) {
        print_prompt();
        read_input(inputBuffer);

        //To execute meta commands
        if (inputBuffer->buffer[0] == '.') {
            switch (do_meta_command(inputBuffer))
            {
            case (META_COMMAND_SUCCESS):
                continue;
            
            case (META_COMMAND_UNRECOGNIZED_COMMAND):
                printf(" Unrecognized command %s.\n", inputBuffer->buffer);
                continue;
            }
        }

        //To execute SQL Queries
        // Statement statement;
        // switch (prepare_statement(input_buffer, &statement))
        // {
        // case (PREPARE_SUCCESS):
        //     break;
        
        // case (PREPARE_UNRECOGNIZED_STATEMENT):
        //     printf(" Unrecognized keyword at the start of %s.\n", inputBuffer->buffer);
        //     continue;
        // }

        // execute_statement(&statement);
        // printf("Executed.\n");
    }
}