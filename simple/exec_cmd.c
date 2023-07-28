#include "main.h"
/**
 * exec_cmd - executes the users given commands
 * @args: commands given
 *
 * Return: void
 */
void exec_cmd(char **args)
{
	int status;
	pid_t pid = fork();

	if (pid < 0)
	{
		perror("fork");
	}
	else if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror(args[0]);
			_exit(1);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}
