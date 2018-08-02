// (C) 2016, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _ADDRESS_BOOK_HPP_
#define _ADDRESS_BOOK_HPP_

/*****************************************************************************/

#include <string>
#include <iostream>
#include <unordered_map>
#include "messages.hpp"

/*****************************************************************************/


class AddressBook
{

	/*-----------------------------------------------------------------*/

public:

	/*-----------------------------------------------------------------*/

	AddressBook() = default;

	~AddressBook() = default;

	AddressBook(AddressBook const &) = delete;

	AddressBook const & operator=(AddressBook const &) = delete;

	int getEntriesCount() const;

	void addEntry(
		std::string const & _name,
		std::string const & _phoneNumber
	);

	bool hasEntryByName(std::string const & _name) const;

	bool hasEntryByPhoneNumber(std::string const & _phoneNumber) const;

	std::string const & getPhoneNumber(std::string	const & _name) const;

	std::string const & getName(std::string const & _phoneNumber) const;

	void removeEntryByName(std::string const & _name);

	void removeEntryByPhoneNumber(std::string const & _phoneNumber);

	void removeEntry(
		std::string const & _name,
		std::string const & _phoneNumber
	);

	int getEntriesCountByName(std::string const & _name) const;

	int getEntriesCountByPhoneNumber(std::string const & _phoneNumber) const;

	std::vector<std::string> createOrdered();
	
	friend std::ostream & operator << (std::ostream & _os, const AddressBook & _ab);

	/*-----------------------------------------------------------------*/

private:

	/*-----------------------------------------------------------------*/

	std::unordered_map<std::string, std::string> m_phoneBook;

	std::unordered_map<std::string, std::string> m_nameBook;
	
	/*-----------------------------------------------------------------*/

};

/*****************************************************************************/

inline
int AddressBook::getEntriesCount() const
{
	return m_phoneBook.size();
}

/*****************************************************************************/

inline
bool AddressBook::hasEntryByName(std::string const & _name) const
{
	return m_nameBook.find(_name) != m_nameBook.end();
}

/*****************************************************************************/

inline
bool AddressBook::hasEntryByPhoneNumber(std::string const & _phoneNumber) const
{
	return m_phoneBook.find(_phoneNumber) != m_phoneBook.end();
}

/*****************************************************************************/

inline
std::string const & 
AddressBook::getPhoneNumber(std::string	const & _name) const
{
	if (_name.empty())
		throw std::logic_error(Messages::EmptyName);

	auto it = m_nameBook.find(_name);
	if (it == m_nameBook.end())
		throw std::logic_error(Messages::EntryDoesNotExist);

	return it->second;
}

/*****************************************************************************/

inline
std::string const &
AddressBook::getName(std::string const & _phoneNumber) const
{
	if (_phoneNumber.empty())
		throw std::logic_error(Messages::EmptyPhoneNumber);

	auto it = m_phoneBook.find(_phoneNumber);
	if (it == m_phoneBook.end())
		throw std::logic_error(Messages::EntryDoesNotExist);

	return it->second;
}

/*****************************************************************************/

#endif // _ADDRESS_BOOK_HPP_