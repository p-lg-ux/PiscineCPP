/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:50:23 by pgros             #+#    #+#             */
/*   Updated: 2023/06/05 16:07:38 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>
# include "AForm.hpp"
# define GREEN	"\x1b[32m"
# define RED	"\x1b[31m"
# define RESET	"\x1b[0m"
# define INVERSE	"\x1b[7m"

class AForm;

class Bureaucrat
{
	private:
	const std::string	_name;
	int					_grade;
	
	public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat(std::string name, int grade);
	~Bureaucrat();
	Bureaucrat& 		operator=(const Bureaucrat& rhs);
	const std::string& 	getName() const;
	int 				getGrade() const;
	void				upgrade();
	void				downgrade();
	void				signForm(AForm &form);
	void				executeForm(AForm &form);
	
	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const throw();
	};
	
	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &os, const Bureaucrat& val);

#endif