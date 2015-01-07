#include "help.h"


/* 
 * While help.h includes builtin.h, builtin.h is not exposing commands[]. This
 * means that while help.o will have that symbol accessible, the compiler does
 * not know it yet. This is what the extern keyword is for. See:
 * http://stackoverflow.com/a/499330/1830334
 */
extern struct cmd_struct commands[];

/* TODO: Implement these commands. */
const char *VRS_USAGE = 
    "usage: vrs [--version]\n"
    "           [--help]\n"
    "\n"
    /* This should be automated! Each cmd_struct should have a descriptor. */
    "Some common Vrs commands are:\n"
    "\tlook\n"
    "\tenter";

const char *VRS_VERSION = "1.0";

void *pretty_print_cmdnames()
{
    fmt_write_vrs("%s\n", "Did you mean one of these?");
    int i;
    for (i = 0; i < commands_size; i++) {
        struct cmd_struct *p = commands + i;
        fmt_write_vrs("\t%s\n", strdup(p->name));
    }
    return 0;
}

/* Based on its current architecture, Vrs can only run in a root directory with
 * a .vrs subdirectory. This function just checks that there is a .vrs
 * subdirectory.
 */
void is_vrs_directory()
{
    DIR* d = opendir(".vrs");
    if (d == NULL) {
        fmt_write_vrs("%s\n", "This is not a valid Vrs directory.");
        exit(0);
    }
    /* Otherwise, do nothing. Program control returns to main(). */
}

void print_usage()
{
    fmt_write_vrs("%s\n", strdup(VRS_USAGE));
}
