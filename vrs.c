/*
 * Vrs is a command-line worldbuilding game set in alternate universes.
 *
 * 2015-01-01 Gregory Gundersen
 */

/* 
 * Should vrs.c have a header file? What would be the benefit, since nothing
 * would reference it?
 */


#include <string.h>
#include "builtin.h"
#include "help.h"


int main(int argc, char *av[])
{
    const char **argv = (const char **) av;

    if (argc > 1) {
        struct cmd_struct *cmd = get_builtin(argc, argv[1]);
        if (cmd)
            handle_builtin(cmd, argc, argv);
        else
            pretty_print_cmdnames();
    } else {
        fmt_write_vrs("%s\n", strdup(VRS_USAGE));
    }
    return 0;
}
