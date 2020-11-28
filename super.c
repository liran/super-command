#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        fprintf(stderr, "There are no commands to execute.");
        return EXIT_FAILURE;
    }

    // Set ourselves as root
    setuid(0);

    // Run our command
    FILE *output;
    char *cmd = argv[1];
    output = popen(cmd, "w");
    if (!output)
    {
        fprintf(stderr, "incorrect parameters or too many files.\n");
        return EXIT_FAILURE;
    }
    int exitCode = pclose(output);
    return WEXITSTATUS(exitCode);
}
