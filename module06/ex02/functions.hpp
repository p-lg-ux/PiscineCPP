/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:06:57 by pgros             #+#    #+#             */
/*   Updated: 2023/06/18 17:11:33 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_HPP
# define FUNCTIONS_HPP
# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

typedef	Base* (*instantiateFunc)(void);

Base*	generate(void);
void	identify(Base *p);
void	identify(Base &p);
Base*	instantiateA(void);
Base*	instantiateB(void);
Base*	instantiateC(void);

#endif