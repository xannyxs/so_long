/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: xander <xander@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/18 17:53:50 by xander        #+#    #+#                 */
/*   Updated: 2022/06/18 18:30:46 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define NONVALID_FILE "-- Non valid extension. Need a .ber file! --"
# define ARGC_ERROR "-- I only need a .ber file --"
# define EMPTY_FILE "-- File is empty --"
# define GNL_ERROR "-- Something went wrong while reading .ber file --"
# define MISSING_WALL "-- Missing wall surrounding the map --"
# define MISSING_PLAYER "-- Missing player --"
# define TOO_MANY_PLAYERS "-- Too many players in the map --"
# define UNKNOWN_CHAR "-- Unknown character in map --"
# define MISSING_MISCS "-- Missing exit or collectable --"

/*
	ERROR
*/

void	non_fatal_error(char *msg);

void	fatal_perror(char *msg);

/*
	List of mallocs:
	1.
	2.
*/

#endif
