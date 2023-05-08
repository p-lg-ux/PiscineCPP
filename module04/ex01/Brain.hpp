/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:49:23 by pgros             #+#    #+#             */
/*   Updated: 2023/05/08 17:24:17 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>
# include <string>

class Brain
{
	private:
	std::string	ideas[100];

	public:
	//constructors and destructors
	Brain();
	Brain(const Brain& other);
	~Brain();
	//overloads
	Brain& operator=(const Brain& rhs);
	std::string getIdea(int i) const;
	void		setIdea(std::string);
};
#endif