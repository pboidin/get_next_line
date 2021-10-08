#include "get_next_line.h"

void	ft_putchard(char c)
{
	write(1, &c, 1);
}

void	ft_putstrn(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

char	*ft_next_str(char *next_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (next_str[i] && next_str[i] != '\n')
		i++;
	if (!next_str[i])
	{
		free(next_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(next_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (next_str[i])
		str[j++] = next_str[i++];
	str[j] = '\0';
	free (next_str);
	return (str);
}

char	*ft_gstr(char *next_str)
{
	int		i;
	char	*str;

	i = 0;
	if (!next_str[i])
		return (NULL);
	while (next_str[i] && next_str[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (next_str[i] && next_str[i] != '\n')
	{
		str[i] = next_str[i];
		i++;
	}
	if (next_str[i] == '\n')
	{
		str[i] = next_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_reader(int fd, char *next_str)
{
	char	*buffer;
	int		i;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	i = 1;	
	while (!ft_strchr(next_str, '\n') && i != 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[i] = '\0';
		next_str = ft_strjoin(next_str, buffer);
		
	}
	free (buffer);
	return (next_str);
}

char	*get_next_line(int fd)
{
	char	*str;
	static char	*next_str;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (0);
	next_str = ft_reader(fd, next_str);
	if (!next_str)
		return (NULL);
	str = ft_gstr(next_str);
	next_str = ft_next_str(next_str);
	return (str);
}