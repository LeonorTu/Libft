
#include <stdio.h>
#include <fcntl.h>
int	main(void)
{
	char	*line;
	int		i;
	int		fd;

	i = 1;
	fd = open("test1.txt", O_RDONLY);

	// line = get_next_line(fd);
	// line = get_next_line(fd);
	// line = get_next_line(fd);
	// printf("%p",line);
	while ((line = get_next_line(fd)))
	{
		printf("%d->%s", i++, line);
		free(line);
	}
}
