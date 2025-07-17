#include <iostream>

void	convert_and_print(char **av)
{
	int	i;
	std::string str;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
			j++;
		str = av[i];
		std::transform(str.begin(), str.end(), str.begin(), ::toupper);
		std::cout << str;
		if (av[i][j - 1] != ' ' && av[i + 1] && av[i + 1][j] && av[i + 1][0] != ' ')
			std::cout << ' ';
		i++;
	}
	std::cout << "\n";
}

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}
	convert_and_print(av);
	return (0);
}
