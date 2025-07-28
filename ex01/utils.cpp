#include "lib.hpp"

int PhoneBook::add(PhoneBook book)
{
	return (0);
}
int PhoneBook::search()
{
	return (0);
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

int Contact::add_helper(PhoneBook *book, int i)
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
	book->contacts[i].info[0] = str;

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
	book->contacts[i].info[1] = str;

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
	book->contacts[i].info[2] = str;

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
	book->contacts[i].info[3] = str;
	
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
	book->contacts[i].info[4] = str;
	book->contacts[i].check = true;
	return (0);
}

std::string Contact::search_helper(PhoneBook book, int i)
{
	std::string str;

	std::cout << "Give a number between 1 and 8: ";
	if (!std::getline(std::cin, str))
		return (NULL);
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
				return (NULL);
		}
		else
		{
			std::cout << "This field can't be left empty" << std::endl;
			std::cout << "Give a number between 1 and 8: ";
			if (!std::getline(std::cin, str))
				return (NULL);
		}
	}
	// show_list(book, i, str);
	return (str);
}
