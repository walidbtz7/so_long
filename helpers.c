#include "so_long.h"

char *ft_strjoin(char *s1, char *s2)
{
	int i;
	int j;
	char *p;
	int a, b;

	j = 0;
	if (!s1 && !s2)
		return 0;
	if (!s1)
		s1 = ft_strldup("", 0);
	a = ft_strlen(s1);
	b = ft_strlen(s2);
	i = a + b;
	p = (char *)malloc(i + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (j < a)
	{
		p[j] = s1[i];
		j++;
		i++;
	}
	i = 0;
	while (i < b)
	{
		p[j] = s2[i];
		i++;
		j++;
	}
	p[j] = '\0';
	return (p);
}

char *ft_strldup(const char *s1, int len)
{
	char *p;
	int i;

	if (!s1)
		return (0);
	p = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	if (!p)
		return (NULL);
	while (s1[i] && i < len)
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
