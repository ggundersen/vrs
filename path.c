#include "path.h"


char *VRS_PATH_FILE = ".vrspath";

/* We do not have to check for the current working directory, because Vrs's
 * execution path never changes. Vrs only *simulates* the directory changing.
 *
 * What happens if the user calls Vrs in a directory without a .vrs directory?
 * It should handle that as a separate error, i.e. "Sorry, this is not a valid
 * Universe."
 */
void write_cwd(char *new_cwd)
{
    FILE *f;
    f = fopen(VRS_PATH_FILE, "w");
    if (f == NULL)
        return;
    
    fprintf(f, "%s\n", new_cwd);
    fclose(f);
}

void read_cwd()
{
}
