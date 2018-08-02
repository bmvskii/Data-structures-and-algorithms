// (C) 2016, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#include "addressbook.hpp"
#include "messages.hpp"
#include <algorithm>
#include <map>

/*****************************************************************************/

void AddressBook::addEntry(
	std::string const & _name,
	std::string const & _phoneNumber
)
{
	if (_name.empty())
		throw std::logic_error(Messages::EmptyName);

	if (_phoneNumber.empty())
		throw std::logic_error(Messages::EmptyPhoneNumber);

	auto it1 = m_nameBook.find(_name);
	auto it2 = m_phoneBook.find(_phoneNumber);

	if (it1 != m_nameBook.end() && it2 != m_phoneBook.end() &&
		it2->second != _name && it1->second != _phoneNumber)
	{
		m_nameBook.erase(it2->second);
		m_phoneBook.erase(it1->second);

		m_nameBook.find(_name)->second = _phoneNumber;
		m_phoneBook.find(_phoneNumber)->second = _name;
	}
	else if (it1 != m_nameBook.end())
	{
		m_phoneBook.erase(m_phoneBook.find(it1->second));
		it1->second = _phoneNumber;
		m_phoneBook.insert(std::make_pair(_phoneNumber, _name));
	}
	else if (it2 != m_phoneBook.end())
	{
		m_nameBook.erase(m_nameBook.find(it2->second));
		it2->second = _name;
		m_nameBook.insert(std::make_pair(_name, _phoneNumber));
	}
	else
	{
		m_nameBook.insert(std::make_pair(_name, _phoneNumber));
		m_phoneBook.insert(std::make_pair(_phoneNumber, _name));
	}
}

/*****************************************************************************/

void AddressBook::removeEntryByName(std::string const & _name)
{
	if (_name.empty())
		throw std::logic_error(Messages::EmptyName);

	auto it = m_nameBook.find(_name);
	if (it == m_nameBook.end())
		throw std::logic_error(Messages::EntryDoesNotExist);

	m_phoneBook.erase(m_phoneBook.find(it->second));
	m_nameBook.erase(it);
}

/*****************************************************************************/

void AddressBook::removeEntryByPhoneNumber(std::string const & _phoneNumber)
{

	if (_phoneNumber.empty())
		throw std::logic_error(Messages::EmptyPhoneNumber);

	auto it = m_phoneBook.find(_phoneNumber);
	if (it == m_phoneBook.end())
		throw std::logic_error(Messages::EntryDoesNotExist);

	m_nameBook.erase(m_nameBook.find(it->second));
	m_phoneBook.erase(it);
}

/*****************************************************************************/

void AddressBook::removeEntry(
	std::string const & _name,
	std::string const & _phoneNumber
)
{
	if (_name.empty())
		throw std::logic_error(Messages::EmptyName);

	if (_phoneNumber.empty())
		throw std::logic_error(Messages::EmptyPhoneNumber);

	auto it1 = m_phoneBook.find(_phoneNumber);
	auto it2 = m_nameBook.find(_name);
	if (it1 == m_phoneBook.end() || it2 == m_nameBook.end())
		throw std::logic_error(Messages::EntryDoesNotExist);

	m_nameBook.erase(it2);
	m_phoneBook.erase(it1);
}

/*****************************************************************************/

int AddressBook::getEntriesCountByName(std::string const & _name) const
{
	int total = 0;
	for (auto const & entry : m_nameBook)
		if (entry.first.find(_name) != std::string::npos)
			total++;

	return total;
}

/*****************************************************************************/

int AddressBook::getEntriesCountByPhoneNumber(std::string const & _phoneNumber) const
{
	int total = 0;
	for (auto const & entry : m_phoneBook)
		if (entry.first.find(_phoneNumber) != std::string::npos)
			total++;

	return total;
}

/*****************************************************************************/

std::vector<std::string> AddressBook::createOrdered()
{
	std::vector<std::string> result;

	for (auto const & entry : m_nameBook)
		result.push_back(entry.first);

	std::sort(result.begin(), result.end());

	return result;
}

/*****************************************************************************/

std::ostream & operator << (std::ostream & _o, const AddressBook & _book)
{
	std::map<std::string, std::string> copy(
		_book.m_nameBook.begin(),
		_book.m_nameBook.end()
	);

	for (auto const & entry : copy)
		_o << entry.first << " - " << entry.second << "\n";
	
	return _o;
}

/*****************************************************************************/
