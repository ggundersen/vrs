#include "help.h"


/* 
 * While help.h includes builtin.h, builtin.h is not exposing commands[]. This
 * means that while help.o will have that symbol accessible, the compiler does
 * not know it yet. This is what the extern keyword is for. See:
 * http://stackoverflow.com/a/499330/1830334
 */
extern struct cmd_struct commands[];

/* This appears only when the user creates a new Vrs? */
const char *VRS_INTRO =
    "oooooo   .  oooo ooooooooo.    .oooooo..o\n" 
    " `888.  .  .8'  `888  .`Y88. d8P'  . `Y8 \n"
    ". `888.   .8'  . 888   .d88' Y88bo.     .\n"
    "   `888. .8'     888ooo88P' . `\"Y8888o.  \n"
    " .  `888.8'  .   888`88b.     .   `\"Y88b \n"
    "     `888'    .  888  `88b.  oo  .  .d8P \n"
    ".     `8'  .    o888o  o888o 8\"\"88888P' .\n"
    "=========================================";

const char *VRS_USAGE = 
    "usage: [--version]\n"
    "       [--help]";

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
        fmt_write_vrs("%s\n", "You are not in a Vrs.");
        exit(0);
    }
    /* Otherwise, do nothing. Program control returns to main(). */
}

void print_usage()
{
    fmt_write_vrs("%s\n", strdup(VRS_USAGE));
}

void print_intro()
{
    fmt_write_vrs("%s\n", strdup(VRS_INTRO));
}
