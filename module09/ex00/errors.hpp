/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 20:35:00 by pgros             #+#    #+#             */
/*   Updated: 2023/07/01 19:28:28 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_HPP
# define ERRORS_HPP

# define FILE_ERRMSG			"couldn't open file"
# define NODELIM_ERRMSG			"no delimiter in input"
# define BAD_INPT_ERRMSG		"bad input"
# define INVALID_DATE_ERRMSG 	"date out of range [2009, 2022]"
# define NEGVAL_ERRMSG			"negative value"
# define LARGEVAL_ERRMSG		"value too large"
# define DB_ERRMSG				"problem with database file"

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