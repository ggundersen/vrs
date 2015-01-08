#include "make.h"


void make_cmd(int argc, const char **argv)
{
    const char *new_file = argv[2];

    /* Add .vrs to string */
    /*char full_name[sizeof(new_file) + 4];
    strcpy(full_name, new_file);
    strcat(full_name, ".vrs");*/

    FILE *f = fopen("qux.vrs", "ab+");
    if (f)
        fprintf(f, "%s\n", argv[2]);
        fmt_write_vrs("You created %s.\n", strdup(new_file));
}
