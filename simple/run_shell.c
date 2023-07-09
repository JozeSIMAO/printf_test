#include "main.h"
/**
 * run_shell - runs the shell
 * Return: void
*/
void run_shell()
{
    char *buff = NULL;
    size_t n = 0;
    ssize_t bytes_read;
    char *args[SIZE];
    int argc;

    while (1)
    {
        prompt();
        if ((bytes_read = getline(&buff, &n, stdin)) == -1)
        {
            break;
        }
        buff[bytes_read - 1] = '\0';

        argc = parse_args(buff, args);

        if (argc == 0)
        {
            continue;
        }

        exec_cmd(args);
    }
    free(buff);
}