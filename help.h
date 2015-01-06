/*
 * Contains Vrs version and usage information.
 */


#ifndef HELP_H
#define HELP_H


#include <stdio.h>
#include "builtin.h"
#include "util.h"


const char *VRS_USAGE;
const char *VRS_VERSION;
void *pretty_print_cmdnames();
void is_vrs_directory();


#endif
