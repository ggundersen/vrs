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
            printf("%s\n", "Unknown command");
    }
    return 0;
}
