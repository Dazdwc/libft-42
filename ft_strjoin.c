/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzafra <dzafra@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 20:54:47 by dzafra            #+#    #+#             */
/*   Updated: 2025/12/18 20:54:51 by dzafra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strslen(int size, char **strs, char *sep)
{
	int	len;
	int	sep_len;
	int	i;

	len = 0;
	sep_len = 0;
	while (sep[sep_len])
		sep_len++;
	while (size > 0)
	{
		i = 0;
		while (strs[size - 1][i])
		{
			i++;
			len++;
		}
		if ((size - 1) > 0)
			len += sep_len;
		size--;
	}
	return (len + 1);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*ptr;
	int		i;
	int		j;
	int		major_while_index;

	i = 0;
	major_while_index = -1;
	ptr = malloc(ft_strslen(size, strs, sep) * sizeof(char));
	while (size > ++major_while_index)
	{
		j = -1;
		while (strs[major_while_index][++j])
		{
			ptr[i] = strs[major_while_index][j];
			i++;
		}
		j = -1;
		while (sep[++j] && (size - 1) > major_while_index)
		{
			ptr[i] = sep[j];
			i++;
		}
	}
	ptr[i] = 0;
	return (ptr);
}
