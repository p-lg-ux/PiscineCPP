/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:33:09 by pgros             #+#    #+#             */
/*   Updated: 2023/06/02 15:27:25 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include <iostream>
# include <string>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
	std::string	_target;
	
	public:
	//constructors and destructors
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	~ShrubberyCreationForm();
	//overloads
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);
	//getters
	const std::string	&getTarget() const;
	//member functions
	void				launchExecution(Bureaucrat const &executor) const;
	
};

#endif