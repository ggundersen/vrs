#ifndef BUILTIN_H
#define BUILTIN_H


#include <stdio.h>
#include <string.h>
#include "enter.h"
#include "fmt_stdout.h"
#include "look.h"
#include "open.h"
#include "util.h"


struct cmd_struct {
    const char *name;
    /* Pass the user's command line arguments to each command. */
    void (*fn)(int, const char **);
};

size_t commands_size;

struct cmd_struct *get_builtin(int argc, const char *s);

void handle_builtin(struct cmd_struct* cmd, int argc, const char **argv);


#endif
