#include "util.h"


int is_dir(const char *path) {
   struct stat statbuf;
   stat(path, &statbuf);
   return S_ISDIR(statbuf.st_mode);
}
