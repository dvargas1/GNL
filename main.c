#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
//	char	*temp;
	int	fd;
	char	*s1;

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
	s1 = get_next_line(fd);
	printf("1 - %s", s1);
	free(s1);
	close(fd);
}

