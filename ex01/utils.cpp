#include "lib.hpp"

int PhoneBook::add(PhoneBook *book, int i)
{
	if (book->contacts[i].add_helper(book, i, &book->contacts[i]) == -1)
		return (-1);
	return (0);
}
int PhoneBook::search(PhoneBook *book, int i)
{
	std::string str;
	int check;
	int j;

	check = 0;
	str = book->contacts[i].search_helper(book->contacts[i], i);
	if (str == "")
		return (-1);
	j = str[0] - 48;
	if (j > 0)
		j--;
	if (j > 7)
	{
			std::cout << "The input needs to be between 1 and 8!" << std::endl;
			return (0);
	}
	check = book->contacts[i].show_list(*book, book->contacts[j], i, str);
	return (check);
}

static bool is_alpha(const std::string s)
{
	return (std::all_of(s.begin(), s.end(), :: isalpha));
}

static bool is_digit(const std::string s)
{
	return (std::all_of(s.begin(), s.end(), ::isdigit));
}

static bool is_blank(const std::string s)
{
	return (std::all_of(s.begin(), s.end(), ::isspace));
}

int Contact::add_helper(PhoneBook *book, int i, Contact *contact)
{
	std::string str;

	std::cout << "First name: ";
	if (!std::getline(std::cin, str))
		return (-1);
	while (str.empty() || is_blank(str) || !is_alpha(str))
	{
		if (!is_alpha(str))
			std::cout << "This field can only contain alphabetical characters" << std::endl;
		else
			std::cout << "The contact details can't be empty" << std::endl;
		std::cout << "First name: ";
		if (!std::getline(std::cin, str))
			return (-1);
	}
	contact->info[0] = str;

	std::cout << "Last name: ";
	if (!std::getline(std::cin, str))
		return (-1);
	while (str.empty() || is_blank(str) || !is_alpha(str))
	{
		if (!is_alpha(str))
			std::cout << "This field can only contain alphabetical characters" << std::endl;
		else
			std::cout << "The contact details can't be empty" << std::endl;
		std::cout << "Last name: ";
		if (!std::getline(std::cin, str))
			return (-1);
	}
	contact->info[1] = str;

	std::cout << "Nickname: ";
	if (!std::getline(std::cin, str))
		return (-1);
	while (str.empty() || is_blank(str))
	{
		std::cout << "The contact details can't be empty" << std::endl;
		std::cout << "Nickname: ";
		if (!std::getline(std::cin, str))
			return (-1);
	}
	contact->info[2] = str;

	std::cout << "Phone number: ";
	if (!std::getline(std::cin, str))
		return (-1);
	while (str.empty() || is_blank(str) || !is_digit(str))
	{
		if (!is_digit(str))
			std::cout << "Enter a numeric value" << std::endl;
		else
			std::cout << "The contact details can't be empty" << std::endl;
		std::cout << "Phone number: ";
		if (!std::getline(std::cin, str))
			return (-1);
	}
	contact->info[3] = str;
	
	std::cout << "Darkest secret: ";
	if (!std::getline(std::cin, str))
		return (-1);
	while (str.empty() || is_blank(str))
	{
		std::cout << "The contact details can't be empty" << std::endl;
		std::cout << "Darkest secret: ";
		if (!std::getline(std::cin, str))
			return (-1);
	}
	contact->info[4] = str;
	contact->check = true;
	return (0);
}

std::string Contact::search_helper(Contact contact, int i)
{
	std::string str;

	std::cout << "Give a number between 1 and 8: ";
	if (!std::getline(std::cin, str))
		return ("");
	while (str.empty() || is_blank(str) || !is_digit(str))
	{
		if (std::any_of(str.begin(), str.end(), ::isdigit)
			&& std::any_of(str.begin(), str.end(), ::isspace))
			break ;
		if (!is_digit(str))
		{
			std::cout << "The input needs to be numeric and between 1 and 8!" << std::endl;
			std::cout << "Give a number between 1 and 8: ";
			if (!std::getline(std::cin, str))
				return ("");
		}
		else
		{
			std::cout << "This field can't be left empty" << std::endl;
			std::cout << "Give a number between 1 and 8: ";
			if (!std::getline(std::cin, str))
				return ("");
		}
	}
	return (str);
}
