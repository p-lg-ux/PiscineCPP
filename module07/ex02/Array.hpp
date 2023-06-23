/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:46:27 by pgros             #+#    #+#             */
/*   Updated: 2023/06/23 17:14:22 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>
# include <string>

template<typename T>
class Array
{
	private:
	T*				_array;
	unsigned int	_n;
	
	public:
	//constructors and destructors
	Array<T>() : _array(NULL), _n(0)
	{
		std::cout << "Default constructor of Array called." << std::endl;
	};
	
	Array<T>(unsigned int n)
	{
		_n = n;
		_array = new T[n];
		for (unsigned int i=0;i<_n;i++)
			_array[i] = 0;
		std::cout << "Parameters constructor of Array called." << std::endl;
	};
	
	Array<T>(const Array<T>& other) : _array(NULL), _n(0)
	{
		*this = other;
		std::cout << "Copy constructor of Array called." << std::endl;
	};

	~Array<T>()
	{
		if (_array != NULL)
			delete [] _array;
		std::cout << "Destructor of Array called." << std::endl;
	};

	//overloads
	Array<T>& operator=(const Array<T>& rhs)
	{
		if (_array != NULL)
			delete [] _array;
		_n  = rhs.size();
		_array = new T[_n];
		for (unsigned int i=0;i<_n;i++)
			_array[i] = rhs[i];
		return (*this);
	};

	T& operator[](unsigned int i) const
	{
		if (i < _n)
			return _array[i];
		throw Array<T>::OutOfRangeException();
	};
	
	unsigned int size() const
	{
		return (_n);
	};

	class OutOfRangeException : public std::exception
	{
		virtual const char* what() const throw()
		{
			return ("Index out of range.");
		};
	};
};


#endif