#include "lib.hpp"

void Contact::printy(Contact contact)
{
	std::cout << contact.info[0] << std::endl;
	std::cout << contact.info[1] << std::endl;
	std::cout << contact.info[2] << std::endl;
	std::cout << contact.info[3] << std::endl;
	std::cout << contact.info[4] << std::endl;
}

int PhoneBook::add(PhoneBook *book, int i)
{
	if (book->contacts[i].add_helper(book, i, &book->contacts[i]) == -1)
		return (-1);
	// book->contacts[i].printy(book->contacts[i]);
	return (0);
}
int PhoneBook::search(PhoneBook *book, int i)
{
	std::string str;

	if (i > 8)
		i--;
	str = book->contacts[i].search_helper(book->contacts[i - 1], i);
	if (str == "")
	{
		// std::cout << std::endl << "End of the input" << std::endl;
		return (-1);
	}
	book->contacts[i].show_list(*book, book->contacts[i], i, str);
	// str = book.show_list(book, i, )
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

int Contact::heyyo(Contact *contact, int i, std::string str)
{
	contact->info[i] = str;
	return (0);
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
	// std::cout << str;
	// book->contacts[i].heyyo(book->contacts, 0, str);

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
	// book->contacts[i].info[1] = str;

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
	// book->contacts[i].info[2] = str;

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
	// book->contacts[i].info[3] = str;
	
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
	// book->contacts[i].info[4] = str;
	// book->contacts[i].check = true;
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
	// show_list(contact, i, str);
	return (str);
}
