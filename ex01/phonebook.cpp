#include "lib.hpp"

int Contact::is_valid(int i, std::string str)
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

bool Contact::check_checker(Contact contacts)
{
	return (contacts.check);
}

int	Contact::show_list(PhoneBook book, Contact contact, int i, std::string str)
{
	int	j;
	int k;
	int l;
	std::string s;

	j = 0;
	k = 0;
	l = 0;
	i = str[0] - 48;
	if (contact.is_valid(i, str) == -1)
	{
		std::cout << "The input needs to be numeric and between 1 and 8!" << std::endl;
		return (-2);
	}
	i = contact.is_valid(i, str);
	if (!contact.check_checker(contact))
	{
		if (i < 1 || i > 8)
		{
			std::cout << "The input needs to be between 1 and 8!" << std::endl;
			return (-2);
		}
		else
		{
			std::cout << "No saved contact at this index" << std::endl;
			return (0);
		}
	}
	std::cout << " ------------------------------------------- " << std::endl;
	std::cout << "|     Index|First name| Last name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	std::cout << "|         " << i;
	i--;
	while (j < 3)
	{
		l = 0;
		s = contact.info[k];
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
	std::cout << "|" << std::endl;
	std::cout << " ------------------------------------------- " << std::endl;
	return (0);
}

int main(int ac, char **av)
{
	PhoneBook book;
	std::string input;
	std::string str;
	(void)av;
	int i;
	int check;

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
			std::cout  << std::endl << "End of the input" << std::endl;
			return (0);
		}
		if (input == "EXIT")
			break ;
		else if (input == "ADD")
		{
			if (i == 8)
				i--;
			if (book.add(&book, i) == -1)
			{
				std::cout  << std::endl << "End of the input" << std::endl;
				return (0);
			}
			i++;
		}
		else if (input == "SEARCH")
		{
			while (1)
			{
				check = book.search(&book, (i - 1));
				if (check == -1)
				{
					std::cout << std::endl << "End of the input" << std::endl;
					return (0);
				}
				if (check == 0)
					break ;
			}
		}
		else if (input.empty() || is_blank(input))
			continue ;
	}
	std::cout << "Exiting the program" << std::endl;
	return (0);
}
