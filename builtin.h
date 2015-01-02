#ifndef BUILTIN_H
#define BUILTIN_H


#include <stdio.h>
#include <string.h>
#include "look.h"
#include "enter.h"
#include "open.h"


struct cmd_struct;
struct cmd_struct *get_builtin(int argc, const char *s);
void handle_builtin(struct cmd_struct* cmd, int argc, const char **argv);


#endif
