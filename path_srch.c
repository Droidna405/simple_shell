#include "shell.h"

/**
 * path_srch - Makes a complete path from path.
 *
 * @cmd: Command to make complete path from.
 * Return: Complete path.
 */
char *path_srch(char *cmd)
{
char *path = NULL, *token = NULL, ch = '/';
char *dirs[1024];
int i;
char *cwd = getcwd(NULL, 0);
struct stat sb;

path = getenv("PATH");
token = strtok(path, ":");
if (dirs == NULL)
i = 0;
while (token != NULL)
{
dirs[i] = token;
token = strtok(NULL, ":");
i++;
}
dirs[i] = NULL;

i = 0;
while (dirs[i] != NULL)
{
chdir(dirs[i]);
if (stat(cmd, &sb) == 0)
{
dirs[i] = string_ncat(dirs[i], &ch, 1);
cmd = string_cat(dirs[i], cmd);
break;
}
i++;
}
chdir(cwd);
return (cmd);
}
