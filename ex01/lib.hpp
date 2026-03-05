#ifndef LIB_HPP
# define LIB_HPP
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

class PhoneBook
{
	private:
		Contact contacts[8];
		int		count;
	public:
		int 	add(PhoneBook *book, int i);
		int 	search(PhoneBook *book, int i);
		void	increment_count(PhoneBook *book);
		void	set_count(PhoneBook *book);
		int		list_all_contacts(PhoneBook *book, int i);
};

#endif