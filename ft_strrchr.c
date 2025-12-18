/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzafra <dzafra@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 19:36:06 by dzafra            #+#    #+#             */
/*   Updated: 2025/12/18 19:44:24 by dzafra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	ch;

	i = 0;
	ch = (unsigned char)c;
	while (s[i] != '\0')
		i++;
	while (i >= 0)
	{
		if ((unsigned char)s[i] == ch)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}
