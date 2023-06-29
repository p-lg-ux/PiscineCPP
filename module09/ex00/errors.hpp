/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 20:35:00 by pgros             #+#    #+#             */
/*   Updated: 2023/06/29 20:36:38 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_HPP
# define ERRORS_HPP

# define FILE_ERRMSG "couldn't open file"

typedef	int	error_t;

enum error_e
{
	NO_ERROR = 0,
	NO_DELIM = 1,
	BAD_INPT_DATE = 2,
	BAD_INPT_VALUE = 4,
	INVALID_DATE = 8,
	NEG_VALUE = 16,
	LARGE_VALUE = 32,
};



#endif