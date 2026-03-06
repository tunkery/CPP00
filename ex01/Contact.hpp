#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>
# include <limits>
# include <string>
# include <iomanip>
class PhoneBook;

class Contact
{
	private:
		std::string info[5];
		bool check;
	public:
		int 		add_helper(PhoneBook *book, int i, Contact *contact);
		std::string search_helper(Contact contact, int i);
		int			show_list(PhoneBook book, Contact contact, int i, std::string str);
		int			is_valid(int i, std::string str);
		bool		check_checker(Contact contacts);
		std::string	contact_returner(Contact *contact, int i);
};

#endif