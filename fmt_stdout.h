/*
 * Handles stdout with colors and formatting.
 */


#ifndef STDOUT_CMD_H
#define STDOUT_CMD_H
#include <stdio.h>
#include <string.h>


struct color_struct;
char *get_color_code(char *color);
void fmt_write(char *specifier, char *msg, char *color);


#endif
