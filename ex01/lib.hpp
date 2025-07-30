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
		int add_helper(PhoneBook *book, int i, Contact *contact);
		std::string search_helper(Contact contact, int i);
		int show_list(PhoneBook book, Contact contact, int i, std::string str);
		int is_valid(int i, std::string str);
		bool check_checker(Contact contacts);
		int heyyo(Contact *contact, int i, std::string str);
		void printy(Contact contact);
};

class PhoneBook
{
	private:
		Contact contacts[8];
	public:
		int add(PhoneBook *book, int i);
		int search(PhoneBook *book, int i);
		void access_printy(PhoneBook book, int i);
		// int show_list(PhoneBook book, int i, std::string str);
};

#endif