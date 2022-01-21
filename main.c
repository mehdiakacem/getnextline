#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <unistd.h>

#include <stdlib.h>
#include <stdio.h>

#include "get_next_line.c"
#include "get_next_line.h"


int main()
{
	int fd;
	int i;
	char *line;

	i = 4;
	fd = open("textfile.txt", O_RDONLY);


	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	

	close(fd);
	return 0;
}