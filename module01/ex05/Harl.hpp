/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:35:11 by pgros             #+#    #+#             */
/*   Updated: 2023/04/07 17:10:02 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP
# include <iostream>
# include <string>

class Harl
{
	typedef  void (Harl::*ComplainFunc)(void);
	
	private:
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);

	public:
	//constructors and destructors
	Harl();
	~Harl();
	void	complain(std::string level);
};
#endif