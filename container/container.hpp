/*
 * Container.hpp
 *
 *  Created on: Jul 3, 2025
 *      Author: Hp-Victus
 */

#ifndef Container_HPP_
#define Container_HPP_

#include <iostream>
#include <cstdlib>
using namespace std;

template <typename T>
class Container
{
	static const int Default_capacity = 10;
public:
	Container<T>(size_t capacity = Default_capacity);
	Container<T>(const Container<T>& obj);
	size_t get_size() const;
	size_t get_capacity() const;
	T get_item(size_t index) const;
	bool add(const T& item);
	bool remove_item(const T& item);
	bool expand(size_t new_cap);
	bool remove_all_items();
	void dummy_init();

private:
	size_t m_capacity;
	size_t m_size;
	T* m_items;
};

template <typename T>
inline ostream& operator<<(ostream& os, const Container<T>& obj1)
{
	os << "container : [ size : " << obj1.get_size() << ", capacity :" << obj1.get_capacity() << ",items : ";

	for (size_t i = 0; i < obj1.get_size();++i)
	{
		os << obj1.get_item(i) << " ";
	}

	os << "] ";

	return os;
}

template <typename T>
Container<T>::Container(size_t capacity)
{
	m_items = new T[capacity];
	m_capacity = capacity;
	m_size = 0;
}

//copy constructor
template <typename T>
Container<T>::Container(const Container<T>& obj)
{
	m_items = new T[obj.m_capacity];
	m_capacity = obj.m_capacity;
	m_size = obj.m_size;

	for (size_t i = 0; i < obj.get_size();i++)
	{
		m_items[i] = obj.m_items[i];
	}

}

template <typename T>
bool Container<T>::expand(size_t new_cap)
{
	T* new_items;

	if (new_cap <= m_capacity)
	{
		return false;

	} else
	{
		new_items = new T[new_cap];
	}

	for (size_t i = 0; i < m_size;i++)
	{
		new_items[i] = m_items[i];
	}

	delete[] m_items;
	m_items = new_items;
	m_capacity = new_cap;

	return true;
}

template <typename T>
bool Container<T>::add(const T& item)
{
	if (m_size == m_capacity)
	{
		expand(m_size + 2);
	}

	m_items[m_size] = item;
	++m_size;

	return true;
}

template <typename T>
bool Container<T>::remove_item(const T& item)
{
	int index = 0;

	if (m_size == 0)
	{
		return false;
	}

	for (size_t i =0; i < m_size; ++i)
	{
		if (m_items[i] == item)
		{
			index = i;
			break;
		}
	}

	m_items[index] = m_items[m_size - 1];
	m_size--;

	return true;
}

template <typename T>
bool Container<T>::remove_all_items()
{
	while (remove_item(m_items[0]));

	return true;
}

template <typename T>
size_t Container<T>::get_size() const
{
	return m_size;
}

template <typename T>
size_t Container<T>::get_capacity() const
{
	return m_capacity;
}

template <typename T>
T Container<T>::get_item(size_t index) const
{
	return m_items[index];
}

template <typename T>
void Container<T>::dummy_init()
{
	for(size_t i = 0; i < 5; ++i)
	{
		m_items[i] = i;
	}

	m_size = 5;
}

#endif /* Container_HPP_ */
