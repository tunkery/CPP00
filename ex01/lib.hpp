#ifndef LIB_HPP
# define LIB_HPP
# include <iostream>
# include <limits>
# include <string>

class PhoneBook;
class Contact
{
	private:
		std::string info[5];
		bool check;

	public:
		int add_helper(PhoneBook *book, int i);
		int search_helper(PhoneBook book, int i);
		int show_list(PhoneBook book, int i, std::string str);
		int is_valid(PhoneBook book, int i, std::string str);
};

class PhoneBook
{
	public:
		Contact contacts[8];
};

#endif