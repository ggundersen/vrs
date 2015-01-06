#include "path.h"


/* We do not have to check for the current working directory, because Vrs's
 * execution path never changes. Vrs only *simulates* the directory changing.
 *
 * What happens if the user calls Vrs in a directory without a .vrs directory?
 * It should handle that as a separate error, i.e. "Sorry, this is not a valid
 * Universe."
 */
char *VRS_PATH_FILE = ".vrspath";

void write_cwd(char *new_cwd)
{
    /* 
     * Write the old cwd to the .vrspath. We do not use this as a reference,
     * since we can just execute .. but we do it to show the user the
     * directories name.
     */
    char old_cwd[255];
    read_cwd(old_cwd);
    FILE *f = fopen(VRS_PATH_FILE, "w");
    fprintf(f, "%s\n", new_cwd);
    fprintf(f, "%s", old_cwd);
    fclose(f);
}

char *read_cwd(char *cwd_buff)
{
    FILE *f = fopen(VRS_PATH_FILE, "r");
    fgets(cwd_buff, 80, f);
    fclose(f);
    return cwd_buff;
}
