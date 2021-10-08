
#include "tester.h"
#include "get_next_line.h"

void	test_little_lines()
{
	char	*s;
	int		fd;

	fd = open("test_little_lines.txt", O_RDONLY);
	
	s = get_next_line(fd);
	ft_putline(s);
	ft_test_str(s, "Hello\n");
	ft_putchar('\n');
	ft_putchar('\n');
	s = get_next_line(fd);
	ft_putline(s);
	ft_test_str(s, "F*CK*NG\n");
	ft_putchar('\n');
	ft_putchar('\n');
	s = get_next_line(fd);
	ft_putline(s);
	ft_test_str(s, "World !\n");
	ft_putchar('\n');
	ft_putchar('\n');
	close(fd);
}

void	test_long_lines()
{
	char 	*s;
	int	fd;

	fd = open("test_long_lines.txt", O_RDONLY);

	s = get_next_line(fd);
	ft_putline(s);
	ft_test(ft_strlen(s) > BUFFER_SIZE);
	ft_putchar('\n');
	ft_putchar('\n');
	s = get_next_line(fd);
	ft_putline(s);
	ft_test_str(s, "Yeah, but i'll still take you home\n");
	ft_putchar('\n');
	ft_putchar('\n');
	close(fd);
}

void	test_empty_lines()
{
	int	fd;
	int	i;
	char	*s;

	i = 0;
	fd = open("test_empty_lines.txt", O_RDONLY);
	while (i < 4)
	{
		s = get_next_line(fd);
		ft_test_str(s, "\n");
		ft_putline(s);
		i++;
	}
	s = get_next_line(fd);
	ft_test_str(s, "Hello 42\n");
	close(fd);
}

void	test_same_lines()
{
	int	fd;
	int	i;
	char	*s;

	i = 0;
	fd = open("text_same_lines.txt", O_RDONLY);
	while ((s = get_next_line(fd)))
	{
		ft_test_str(s, "Hello 42\n");
		free(s);
		i++;
	}
	ft_test(i == 26);
	close(fd);
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;	
	test_little_lines();
	test_long_lines();
	test_empty_lines();
	test_same_lines();
}
