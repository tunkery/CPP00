#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <iostream>
# include <limits>
# include <string>
# include <iomanip>
# include "Contact.hpp"

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