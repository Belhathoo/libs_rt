/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibel-kha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 16:27:42 by ibel-kha          #+#    #+#             */
/*   Updated: 2019/05/04 13:10:59 by ibel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_atod(char *str)
{
	double		nbr;
	int			i;
	double		chfr;
	static int	signe;

	nbr = (double)ft_atoi(str);
	i = 0;
	chfr = 10;
	while ((str[i] == '\n') || (str[i] == ' ') || (str[i] == '\t')
			|| (str[i] == '\f') || (str[i] == '\v') || (str[i] == '\r'))
		i++;
	signe = str[i] == '-' ? 1 : 0;
	i = ((str[i] == '-') || (str[i] == '+')) ? i + 1 : i;
	while (str[i] && str[i++] != '.')
		i = i + 0;
	while (str[i] && str[i] >= 48 && str[i] <= 57)
	{
		nbr = nbr >= 0 && !signe ? nbr + (double)(str[i++] - 48) / chfr :
			nbr - (double)(str[i++] - 48) / chfr;
		chfr *= 10;
	}
	return (nbr);
}
