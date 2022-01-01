#ifndef META_H
#define META_H

#include <stdlib.h>
#include <string.h>
#include "cli.h"

typedef enum MetaCommandResult{
    META_COMMAND_SUCCESS,
    META_COMMAND_UNRECOGNIZED_COMMAND,
} MetaCommandResult;

MetaCommandResult do_meta_command(InputBuffer *inputBuffer);

#endif