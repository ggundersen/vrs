#include "enter.h"


/*
 * Users can only enter hidden directories that end in .env and begin with the
 * characters "vrs".
 *
 * This function delegates to the Unix cd command. This simplifies the program
 * considerably, since we do not have to worry about changing any state
 * variables. The OS does that for us.
 */
void enter_cmd(int argc, const char **argv)
{
    /*
     * When a user enters a new place, Vrs should tell them about it. This data
     * should be stored in a metadata file.
     */

    const char *dir = argv[2];

    char cwd[255];
    if (getcwd(cwd, sizeof(cwd)) == NULL)
        return;

    /* +2 for extra forward slash and null character. */
    char new_cwd[sizeof(cwd) + sizeof(dir) + 2];
    strcpy(new_cwd, cwd);
    strcat(new_cwd, "/");
    strcat(new_cwd, dir);
    strcat(new_cwd, "\0");

    /* Open the directory, returning early on failure. */
    DIR* d = opendir(new_cwd);
    if (d == NULL) {
        fmt_write_vrs("%s\n", "There is nothing there.");
        return;
    }

    /* 
     * The directory exists but Vrs cannot  actually change the parent
     * process's working directory. Close DIR and change Vrs's interanl path.
     * See path.h to see how Vrs handles this.
     */
    closedir(d);
    write_cwd(new_cwd);
    fmt_write_vrs("You enter %s\n", strdup(dir));
}
