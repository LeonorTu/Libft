#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int main(void) {
	int fd1, fd2, fd3;
	char *line;

	// Open three files for testing
	fd1 = -5;
	fd2 = open("test2.txt", O_RDONLY);
	fd3 = open("test3.txt", O_RDONLY);

	if (fd1 == -1 || fd2 == -1 || fd3 == -1) {
		perror("Error opening files");
		return 1;
	}

	// Test reading one line from each file descriptor in a repeated manner
	do {
		line = get_next_line(fd1);
		if (line) {
			printf("File 1: %s\n", line);
			free(line);
		}

		line = get_next_line(fd2);
		if (line) {
			printf("File 2: %s\n", line);
			free(line);
		}

		line = get_next_line(fd3);
		if (line) {
			printf("File 3: %s\n", line);
			free(line);
		}

	} while (line);  // Continue until there are no more lines to read

	// Close file descriptors
	close(fd1);
	close(fd2);
	close(fd3);

	return 0;
}
