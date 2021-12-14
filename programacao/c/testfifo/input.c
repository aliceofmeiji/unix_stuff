#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	char str[255];
	while(1)
	{
		int fd = open("bus", O_RDONLY);
		read(fd, str, 255);
		printf("%s", str);
		close(fd);
		sleep(1);
	}
}
