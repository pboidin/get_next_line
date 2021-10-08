
#include "tester.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	ft_putchar('\n');
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_test(int result)
{
	if (result)
		ft_putchar('P');
	else
		ft_putchar('N');
}

void	ft_test_str(char *s1, char *s2)
{
	ft_test(ft_strcmp(s1, s2) == 0);
}
