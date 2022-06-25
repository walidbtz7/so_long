
#include "so_long.h"

char	*get_next_line(int fd)
{
	char	*buff;
	char	*saver;
	int		rd;

	if (fd < 0)
		return (0);
	rd = 1;
	saver = NULL;
	buff = (char *) malloc(2 * sizeof(char));
	if (!buff)
		return (NULL);
	buff[0] = 0;
	while (rd > 0)
	{
		rd = read(fd, buff, 1);
		if (rd < 0)
		{
			free(buff);
			return (0);
		}
		buff[rd] = 0;
		saver = ft_strjoin(saver, buff);
	}
	free(buff);
	if (rd == 0 && saver[0] == '\0')
	{
		free(saver);
		saver = NULL;
		return (0);
	}
	return (saver);
}
