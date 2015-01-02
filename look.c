#include "look.h"


void look_cmd(int argc, const char ** argv)
{
    /* Get the user's current working directory. */
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) == NULL)
        return;

    /* Open the directory, returning early on failure. */
    DIR* d = opendir(cwd);
    if (d == NULL)
        return;

    /* Search for all relevant *.vrs files, excluding hidden files. */
    int found = 0;
    regex_t regex;
    int reti;
    reti = regcomp(&regex, "[^.].vrs", 0);
    for (struct dirent *de = NULL; (de = readdir(d)) != NULL;) {
        reti = regexec(&regex, de->d_name, 0, NULL, 0);
        if (!reti) {
            found = 1;
            read_file(de->d_name);
        }
    }
    if (found == 0)
        fmt_write("%s\n", "There is nothing here.", "RED");

    closedir(d);
}

void read_file(char *filename)
{
    FILE *f = fopen(filename, "r");
    if (!f)
        return;

    char contents[BUFSIZ];
    while (fgets(contents, BUFSIZ, f) != NULL)
        fmt_write("%s", contents, "YEL");

    fclose(f);
}
