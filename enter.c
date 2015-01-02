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
}
