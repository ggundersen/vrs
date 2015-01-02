#include "builtin.h"


struct cmd_struct {
    const char *name;
    /* Pass the user's command line arguments to each command. */
    void (*fn)(int, const char **);
};

/*
 * Vrs treats the filesystem as parts of the universe, e.g. people, places,
 * aliens. Vrs's builtin commands delegate to Unix's as necessary.
 */
struct cmd_struct commands[] = {
    { "look", look_cmd },
    { "enter", enter_cmd },
    { "open", open_cmd }
    // create a .vrs directory in the current directory.
    // { "init" }
};

struct cmd_struct* get_builtin(int argc, const char *s)
{
    int i;
    for (i = 0; i < argc; i++) {
        struct cmd_struct *p = commands + i;
        if (strcmp(p->name, s) == 0) {
            return p;
        }
    }
    return NULL;
}

void handle_builtin(struct cmd_struct* cmd, int argc, const char **argv)
{
    cmd->fn(argc, argv);
}
