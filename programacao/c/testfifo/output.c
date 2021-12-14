#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	while(1)
	{
		int fd = open("bus", O_WRONLY);
		write(fd, "aaa", 4);
		close(fd);
		sleep(1);
	}
}
