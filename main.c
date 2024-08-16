#include "main.h"

// Is this function written correctly? Should it be *argv[] for the list?
// argc = argument count = lengh of the argument vector
// argv = argument vector = array of character pointers
// argv is a tokenized verwsion of the cli commands you put in 

int main(int argc, char **argv){
    // Load config files

    // Run command loop
    lsh_loop();

    // Perform any shutdown/cleanup

    return EXIT_SUCCESS;
}

/*
Basic command handling looks like RPE:
1. Read: Read the command from standard input
2. Parse: Separate the command string into the program and arguments
3. Execute: Run the parsed command
*/

void lsh_loop(void){
    char *line;
    char **args;
    int status;

    do {
        printf("> ");
        line = lsh_read_line();
        args = lsh_split_line(line);
        status = lsh_execute(args);

        free(line);
        free(args);

    } while (status);
}