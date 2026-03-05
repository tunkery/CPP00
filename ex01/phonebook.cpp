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

static bool any_blank(const std::string s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (isspace(s[i]))
			return (true);
		i++;
	}
	return (false);
}

std::string	Contact::contact_returner(Contact *contact, int i)
{
	return (contact->info[i]);
}

bool Contact::check_checker(Contact contacts)
{
	return (contacts.check);
}

int	PhoneBook::list_all_contacts(PhoneBook *book, int i)
{
	std::string	s;
	int			j;
	int			k;
	int			l;
	int			m;

	j = 1;
	l = 0;
	while (j < book->count || j == book->count)
	{
		std::cout << " " << std::setfill('-') << std::setw(44) << " " << std::endl;
		std::cout << "|" << std::setfill(' ') << std::setw(10) << "Index" << "|" << "First name" << "|"
				<< std::setw(10) << "Last name" << "|" << std::setw(10) << "Nickname" << "|" << std::endl;
		std::cout << "|" << std::setfill('-') << std::setw(11) << "|" << std::setw(11) << "|"
				<< std::setw(11) << "|" << std::setw(11) << "|" << std::endl;
		std::cout << "|" << std::setfill(' ') << std::setw(10) << j;
		m = 0;
		k = 0;
		while (m < 3)
		{
			s = book->contacts[l].contact_returner(&book->contacts[l], k);
			if (s.size() > 10)
				s = s.substr(0, 9) + '.';
			std::cout << '|' << std::setw(10) << s;
			k++;
			m++;
		}
		std::cout << "|" << std::endl;
		std::cout << " " << std::setfill('-') << std::setw(44) << " " << std::endl;
		j++;
		l++;
	}
	return (0);
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
	s = contact.info[k];
	std::cout << "First name: " << s << std::endl;
	k++;
	s = contact.info[k];
	std::cout << "Last name: " << s << std::endl;
	k++;
	s = contact.info[k];
	std::cout << "Nickname: " << s << std::endl;
	k++;
	s = contact.info[k];
	std::cout << "Phone number: " << s << std::endl;
	k++;
	s = contact.info[k];
	std::cout << "Darkest secret: " << s << std::endl;
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
	book.set_count(&book);
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
			book.increment_count(&book);
			if (i == 8)
				i = 0;
			if (book.add(&book, i) == -1)
			{
				std::cout  << std::endl << "End of the input" << std::endl;
				return (0);
			}
			i++;
		}
		else if (input == "SEARCH")
		{
			if (i == 0)
			{
				std::cout << "The Phonebook is empty, to add a contact please type 'ADD'" << std::endl;
				continue ;
			}
			book.list_all_contacts(&book, 0);
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
		else if (input.empty() || any_blank(input))
			continue ;
	}
	std::cout << "Exiting the program" << std::endl;
	return (0);
}
