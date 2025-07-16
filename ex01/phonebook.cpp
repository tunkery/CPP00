#include "lib.hpp"

int	Contact::show_list(PhoneBook book, int i)
{
	int	j;
	int k;
	std::string str[10];

	j = 1;
	i++;
	k = 0;
	while (j < i)
	{
		while (k < 5)
		{
			std::cout << book.contacts[j - 1].info[k] << "\n";
			k++;
		}
		// std::cout << " ----------|----------|----------|---------- \n";
		// std::cout << "|     " << j << "    |"; 
		// std::cout << "          |          |          |\n";
		// std::cout << " ----------|----------|----------|---------- \n";
		j++;
		k = 0;
	}
	return (0);
}

static bool is_blank(const std::string s)
{
	return (std::any_of(s.begin(), s.end(), ::isspace));
}

int main(int ac, char **av)
{
	PhoneBook book;
	std::string input;
	int i;

	if (ac > 1)
	{
		std::cout << "don't give any arguments\n";
		return (0);
	}
	i = 0;
	while (1)
	{
		std::cout << "Enter command: ";
		if (!std::getline(std::cin, input))
		{
			std::cout << "\nEnd of the input\n";
			return (0);
		}
		if (input == "EXIT")
			break ;
		else if (input == "ADD")
		{
			if (i == 8)
				i--;
			if (book.contacts[i].add_helper(book, i) == -1)
			{
				std::cout << "\nEnd of the input\n";
				return (0);
			}
			i++;
		}
		else if (input == "SEARCH")
		{
			if (i > 8)
				i--;
			if (book.contacts[i].search_helper(book, i) == -1)
			{
				std::cout << "\nEnd of the input\n";
				return (0);
			}
		}
		else if (input.empty() || is_blank(input))
			continue ;
	}
	return (0);
}
