#include "lib.hpp"

int Contact::is_valid(PhoneBook book, int i, std::string str)
{
	int check;
	int	pos;

	i = 0;
	check = 0;
	pos = 0;
	while (str[i])
	{
		if (std::isspace(str[i]))
		{
			i++;
			continue ;
		}
		if (pos == 0)
			pos = i;
		check++;
		if (check > 1 || (str[i] - 48) < 1 || (str[i] - 48) > 8)
			return (-1);
		i++;
	}
	check = str[pos] - 48;
	return (check);
}

static bool is_blank(const std::string s)
{
	return (std::any_of(s.begin(), s.end(), ::isspace));
}

int	Contact::show_list(PhoneBook book, int i, std::string str)
{
	int	j;
	int k;
	int l;
	std::string s;

	j = 0;
	k = 0;
	l = 0;
	i = str[0] - 48;
	if (is_valid(book, i, str) == -1)
	{
		std::cout << "The input needs to be numeric and between 1 and 8!\n";
		search_helper(book, i);
		return (-1);
	}
	i = is_valid(book, i, str);
	if (!book.contacts[i - 1].check)
	{
		if (i < 1 || i > 8)
			std::cout << "The input needs to be between 1 and 8!\n";
		else
			std::cout << "No saved contact at this index\n";
		return (-1);
	}
	std::cout << "|-------------------------------------------|\n";
	std::cout << "|     Index|First name| Last name|  Nickname|\n";
	std::cout << "|----------|----------|----------|----------|\n";
	std::cout << "|         " << i;
	i--;
	while (j < 3)
	{
		l = 0;
		s = book.contacts[i].info[k];
		if (s.size() > 10)
			s = s.substr(0, 9) + '.';
		std::cout << '|';
		while (l < (10 - s.size()))
		{
			std::cout << ' ';
			l++;
		}
		std::cout << s;
		j++;
		k++;
	}
	std::cout << "|\n";
	std::cout << "|-------------------------------------------|\n";
	return (0);
}

int main(int ac, char **av)
{
	PhoneBook book;
	std::string input;
	int i;

	if (ac > 1)
	{
		std::cout << "Don't give any arguments\n";
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
			if (book.contacts[i].add_helper(&book, i) == -1)
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
	std::cout << "Exiting the program\n";
	return (0);
}
