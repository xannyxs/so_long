/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isprint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 14:50:30 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/11/24 16:56:46 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int argc)
{
	if (argc < 32 || argc > 126)
		return (0);
	return (1);
}
