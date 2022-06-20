#include "so_long.h"

int main(int argc, char **argv)
{
	int fd;

	fd = checkarg(argc, argv[1]);
	if (fd == 0)
		return (0);
	rectangular(fd);
	return (0);
}