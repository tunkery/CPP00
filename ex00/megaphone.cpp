#include <iostream>

int	main(int ac, char **av)
{
	std::string	s;
	int			i;

	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}
	i = 1;
	while (av[i])
	{
		s = av[i];
		for (auto &x : s)
			x = toupper(x);
		std::cout << s;
		if (av[i + 1] && av[i + 1][0] != ' ' && av[i][s.size() - 1] != ' ')
			std::cout << " ";
		i++;
	}
	std::cout << std::endl;
	return (0);
}
