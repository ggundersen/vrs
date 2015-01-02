/*
 * Vrs is a command-line worldbuilding game set in alternate universes.
 *
 * 2015-01-01 Gregory Gundersen
 * -------------------------------------------------------------------------- */


#include "builtin.h"


int main(int argc, char *av[])
{
    const char **argv = (const char **) av;

    if (argc > 1) {
        struct cmd_struct *cmd = get_builtin(argc, argv[1]);
        if (cmd)
            handle_builtin(cmd, argc, argv);
        else
            fmt_write("%s\n", "Unknown command", "RED");
    } else {
        /* This should show the user the valid commands. */
        fmt_write("%s\n", "Please enter a command", "RED");
    }
    return 0;
}
