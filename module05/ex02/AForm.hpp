/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:40:40 by pgros             #+#    #+#             */
/*   Updated: 2023/06/02 15:49:49 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	protected:
	const std::string	_name;
	bool				_is_signed;
	const int			_sign_grade;
	const int			_exec_grade;

	public:
	//constructors and destructors
	AForm();
	AForm(const AForm& other);
	AForm(std::string name, int sign_grade, int exec_grade);
	virtual ~AForm();
	
	//overloads
	AForm& operator=(const AForm& rhs);

	//getters
	const std::string 			&getName() const;
	int							getSignGrade() const;
	int							getExecGrade() const;
	bool						isSigned() const;
	virtual const std::string	&getTarget() const = 0;

	//other member functions
	void			beSigned(Bureaucrat &guy);
	void			execute(Bureaucrat const &executor) const;
	virtual void	launchExecution(Bureaucrat const &executor) const = 0;

	//exceptions
	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const throw();
	};
	
	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const throw();
	};
	class FormNotSignedException : public std::exception
	{
		virtual const char* what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const AForm &val);

#endif