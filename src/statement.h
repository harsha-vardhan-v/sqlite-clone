#ifndef STATEMENT_H
#define STATEMENT_H

#include <stdio.h>
#include <string.h>

#include "cli.h"

typedef enum StatementType{
    STATEMENT_INSERT,
    STATEMENT_SELECT
} StatementType;

typedef enum PrepareResult{
    PREPARE_SUCCESS,
    PREPARE_UNRECOGNIZED_STATEMENT,
} PrepareResult;

typedef struct Statement{
    StatementType type;
} Statement;

PrepareResult prepare_statement(InputBuffer *inputBuffer, Statement *statement);
void execute_statement(Statement *statement);

#endif