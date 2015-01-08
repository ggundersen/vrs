#ifndef UTIL_H
#define UTIL_H


#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))


int is_dir(const char *path);


#endif
