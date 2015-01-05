#include "look.h"


void look_cmd(int argc, const char **argv)
{
    /*
     * Get the user's current working directory.
     * How big should the buffer be and how do I handle overflow?
     */
    
    char cwd[255];
    read_cwd(cwd);

    int n = strlen(cwd);
    if(n > 0 && cwd[n - 1] == '\n')
        cwd[n - 1] = '\0';

    /* Open the directory, returning early on failure. */
    DIR *d = opendir(cwd);
    if (d == NULL) {
        printf("%s\n", "error reading cwd");
        return;
    }

    /* Search for all relevant *.vrs files, excluding hidden files. */
    int found = 0;
    regex_t regex;
    int reti;
    reti = regcomp(&regex, "[^.].vrs", 0);
    for (struct dirent *de = NULL; (de = readdir(d)) != NULL;) {
        reti = regexec(&regex, de->d_name, 0, NULL, 0);
        if (!reti) {
            if (found != 1) {
                found = 1;
                fmt_write_vrs("%s\n", "You see");
            }
            read_file(de->d_name);
        }
    }
    if (found == 0)
        fmt_write_vrs("%s\n", "There is nothing here.");

    closedir(d);
}

void read_file(char *filename)
{
    FILE *f = fopen(filename, "r");
    if (!f)
        return;

    char contents[BUFSIZ];
    /* This should not be hard coded. It should be VRS_COLOR. */
        while (fgets(contents, BUFSIZ, f) != NULL)
        fmt_write("\t%s", contents, "YEL");

    fclose(f);
}
