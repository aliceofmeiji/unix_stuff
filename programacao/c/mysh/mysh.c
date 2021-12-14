#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

//=0 -> child process
//>0 -> parent process
//<0 -> error

input_to_args(char *input, char **args)
{
	
}
int main()
{
	//char *args[] = {"ls", NULL};
	char *input[256*256];
	char **args[256][256];
	while(1)
	{
		scanf("%s", input);
		printf("%s\n", input);
		/*if(fork() == 0)
		{
			printf("hoh\n");
			execvp(args[0], args);
		}
		else
		{
			printf("hah\n");
			execvp(args[0], args);
		}*/
	}
}
