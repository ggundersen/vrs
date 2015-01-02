#include "fmt_stdout.h"


struct color_struct {
    char *name;
    char *code;
};

struct color_struct colors[] = {
    { "BLK", "\x1B[0m"  },
    { "WHT", "\x1B[37m" },
    { "CYN", "\x1B[36m" },
    { "RED", "\x1B[31m" },
    { "GRN", "\x1B[32m" },
    { "YEL", "\x1B[33m" },
    { "BLU", "\x1B[34m" },
    { "MAG", "\x1B[35m" }
};

/* Is this global in C? */
int COLORS_SIZE = sizeof(colors) / sizeof(colors[0]);

char *get_color_code(char *color)
{
    int i;
    for (i = 0; i < COLORS_SIZE; i++) {
        struct color_struct *p = colors + i;
        if (p->name == color)
            return p->code;
    }
    /* Default to black if color argument is not found. */
    return colors[0].code;
}

void fmt_write(char *specifier, char *msg, char *color)
{
    char *code = get_color_code(color);

    /* +6 for color codes, +2 for spaces, +1 for null character. */
    char color_msg[strlen(msg) + 6 + 1];

    /* Is strcat() safe? See http://stackoverflow.com/a/308732/1830334. */    
    strcpy(color_msg, code);
    strcat(color_msg, msg);

    /* Reset the output to black. */
    strcat(color_msg, colors[0].code);
    strcat(color_msg, "\0");
    printf(specifier, color_msg);
}
