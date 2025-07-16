#ifndef LIB_HPP
# define LIB_HPP
# include <iostream>
# include <limits>

class PhoneBook;
class Contact
{
	private:
		std::string info[5];
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;

	public:
		int add_helper(PhoneBook book, int i);
		int search_helper(PhoneBook book, int i);
		int show_list(PhoneBook book, int i);
};

class PhoneBook
{
	public:
		Contact contacts[8];

	public:
		// void add_helper(PhoneBook book, int i);
		// void search_helper(PhoneBook book, int i);
};

#endif