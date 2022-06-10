#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	char	*temp;
	int	fd;

	fd = open("myfile.txt", O_RDONLY);
/*
	while(1)
	{
		temp = get_next_line(fd);
		if (!temp)
			break ;
		printf("%s", temp);
		free(temp);
	}
	return (0);
*/

	printf("1 - %s", get_next_line(fd));
	printf("2 - %s", get_next_line(fd));
	printf("3 - %s", get_next_line(fd));
	printf("4 - %s", get_next_line(fd));
	printf("5 - %s", get_next_line(fd));
	printf("6 - %s", get_next_line(fd));
	printf("7 - %s", get_next_line(fd));
	printf("8 - %s", get_next_line(fd));
	printf("9 - %s", get_next_line(fd));
	printf("10 - %s", get_next_line(fd));
	close(fd);
}

