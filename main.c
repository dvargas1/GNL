#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
//	char	*temp;
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
	printf("1 - %s", get_next_line(fd));
	printf("1 - %s", get_next_line(fd));
	printf("1 - %s", get_next_line(fd));
	printf("1 - %s", get_next_line(fd));
	printf("1 - %s", get_next_line(fd));
	printf("1 - %s", get_next_line(fd));
	printf("1 - %s", get_next_line(fd));
	printf("1 - %s", get_next_line(fd));
	close(fd);
}

