#include "lib.hpp"

// void Contact::loopy(PhoneBook book, int i, char *message, std::string str)
// {
// 	while (str.size() == 0)
// 	{
// 		std::cout << "The contact details can't be empty\n";
// 		std::cout << message;
// 		std::cin >> str;
// 	}
// }

static bool is_alpha(const std::string s)
{
	return (std::any_of(s.begin(), s.end(), :: isalpha));
}

static bool is_digit(const std::string s)
{
	return (std::any_of(s.begin(), s.end(), ::isdigit));
}

static bool is_blank(const std::string s)
{
	return (std::any_of(s.begin(), s.end(), ::isspace));
}

int Contact::add_helper(PhoneBook book, int i)
{
	std::string str;

	// std::cin.ignore(1000, '\n');
	std::cout << "first name: ";
	if (!std::getline(std::cin, str))
		return (-1);
	while (str.empty() || is_blank(str))
	{
		std::cout << "The contact details can't be empty\n";
		std::cout << "first name: ";
		if (!std::getline(std::cin, str))
			return (-1);
	}
	book.contacts[i].info[0] = str;
	std::cout << "last name: ";
	if (!std::getline(std::cin, str))
		return (-1);
	while (str.empty() || is_blank(str))
	{
		std::cout << "The contact details can't be empty\n";
		std::cout << "last name: ";
		if (!std::getline(std::cin, str))
			return (-1);
	}
	book.contacts[i].info[1] = str;
	std::cout << "nickname: ";
	if (!std::getline(std::cin, str))
		return (-1);
	while (str.empty() || is_blank(str))
	{
		std::cout << "The contact details can't be empty\n";
		std::cout << "nickname: ";
		if (!std::getline(std::cin, str))
			return (-1);
	}
	book.contacts[i].info[2] = str;
	std::cout << "phone number: ";
	if (!std::getline(std::cin, str))
		return (-1);
	while (str.empty() || is_blank(str) || !is_digit(str))
	{
		if (!is_digit(str))
			std::cout << "Enter a numeric value\n";
		else
			std::cout << "The contact details can't be empty\n";
		std::cout << "phone number: ";
		if (!std::getline(std::cin, str))
			return (-1);
	}
	book.contacts[i].info[3] = str;
	std::cout << "darkest secret: ";
	if (!std::getline(std::cin, str))
		return (-1);
	while (str.empty() || is_blank(str))
	{
		std::cout << "The contact details can't be empty\n";
		std::cout << "darkest secret: ";
		if (!std::getline(std::cin, str))
			return (-1);
	}
	book.contacts[i].info[4] = str;
	return (0);
}

int Contact::search_helper(PhoneBook book, int i)
{
	std::string str;
	

	// std::cin.ignore(1000, '\n');
	std::cout << "give a number between 1 and 8: ";
	if (!std::getline(std::cin, str))
		return (-1);
	while (str.empty() || is_blank(str) || !is_digit(str))
	{
		if (!is_digit(str))
		{
			std::cout << "give a number between 1 and 8: ";
			if (!std::getline(std::cin, str))
				return (-1);
		}
		else
		{
			std::cout << "This field can't be left empty\n";
			std::cout << "give a number between 1 and 8: ";
			if (!std::getline(std::cin, str))
				return (-1);
		}
	}
	return (0);
}
