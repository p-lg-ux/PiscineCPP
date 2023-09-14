/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:30:26 by pgros             #+#    #+#             */
/*   Updated: 2023/09/14 21:04:29 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP
# include <iostream>
# include <string>
# include <stack>
# include <list>
# include <sstream>

# define OPERATORS "+-/*"
// # define ERRORMSG	std::cerr << "Error" << std::endl

class RPN
{
	typedef	int	(RPN::*OperatorFunc)(int a, int b);
	
	private:
	int	plus(int a, int b);
	int	minus(int a, int b);
	int	times(int a, int b);
	int	divide(int a, int b);

	public:
	std::stack<int, std::list<int> > _stack;
	//constructors and destructors
	RPN();
	RPN(const RPN& other);
	~RPN();
	//overloads
	RPN& operator=(const RPN& rhs);
	void	processInput(std::string inpt);
	void	computeOperator(int oper);

	class ErrorException : public std::exception
	{
		virtual const char* what() const throw();
	};
	class OverflowException : public std::exception
	{
		virtual const char* what() const throw();
	};
};
#endif