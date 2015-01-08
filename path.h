/*
 * Since Vrs--and other programs--cannot change the working directory of its
 * parent process, it reads and writes to a persistent .vrspath config file.
 *
 * See http://stackoverflow.com/q/27770918/1830334.
 */


#ifndef VRS_PATH_H
#define VRS_PATH_H


#include <stdio.h>
#include <string.h>
#include <unistd.h>


void write_cwd(char *new_cwd);
char *read_cwd(char *cwd_buff);
void reset_cwd();


#endif
