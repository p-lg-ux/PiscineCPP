/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:40:40 by pgros             #+#    #+#             */
/*   Updated: 2023/05/30 18:02:27 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Form
{
	private:
	const std::string	_name;
	bool				_is_signed;
	const int			_sign_grade;
	const int			_exec_grade;

	public:
	//constructors and destructors
	Form();
	Form(const Form& other);
	Form(std::string name, int sign_grade, int exec_grade);
	~Form();
	
	//overloads
	Form& operator=(const Form& rhs);

	//getters
	const std::string 	&getName() const;
	int					getSignGrade() const;
	int					getExecGrade() const;
	bool				getIsSigned() const;

	//other member functions
	void	beSigned(Bureaucrat guy);

	//exceptions
	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const throw();
	};
	
	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const Form &val);

#endif