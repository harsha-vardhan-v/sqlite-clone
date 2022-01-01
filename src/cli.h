#ifndef CLI_H
#define CLI_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <malloc.h>
#include <sys/types.h>

typedef struct InputBuffer{
    char *buffer;
    size_t bufferLength;
    ssize_t inputLength;
} InputBuffer;

InputBuffer* new_input_buffer();
void close_input_buffer(InputBuffer* inputBuffer);

void print_prompt();
void read_input(InputBuffer *inputBuffer);

#endif