/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzafra <dzafra@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 19:48:35 by dzafra            #+#    #+#             */
/*   Updated: 2025/12/23 20:13:53 by dzafra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FT_INT_MAX 2147483647U
#define FT_INT_MIN_ABS 2147483648U
#include "libft.h"

static int	ft_is_space(char c)
{
	return (c == ' ' || c == '\n' || c == '\v' || c == '\r'
		|| c == '\f' || c == '\t');
}

int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	unsigned long	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (str[i] && ft_is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
		if (nb > FT_INT_MIN_ABS && sign == -1)
			return (0);
		if (nb > FT_INT_MAX && sign == 1)
			return (-1);
	}
	return ((int)nb * sign);
}
