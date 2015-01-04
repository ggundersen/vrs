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
    "           [--help]";

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
