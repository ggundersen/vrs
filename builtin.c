#include "builtin.h"


/*
 * Vrs treats the filesystem as parts of the universe, e.g. people, places,
 * aliens. Vrs's builtin commands delegate to Unix's as necessary.
 */
struct cmd_struct commands[] = {
    { "enter", enter_cmd },
    { "look", look_cmd },
    { "open", open_cmd },
    { "make", make_cmd },
    { "start", start_cmd }
};

size_t commands_size = ARRAY_SIZE(commands);

struct cmd_struct* get_builtin(int argc, const char *s)
{
    int i;
    for (i = 0; i < ARRAY_SIZE(commands); i++) {
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
