/*
 * Shows the user everything visible in their environment.
 */


#ifndef LOOK_CMD_H
#define LOOK_CMD_H


#include <dirent.h>
#include <regex.h>
#include <stdlib.h>
#include <unistd.h>
#include "fmt_stdout.h"
#include "path.h"
#include "util.h"


void look_cmd(int argc, const char ** argv);
void read_file(char *filename);


#endif
