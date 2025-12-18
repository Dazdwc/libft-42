/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzafra <dzafra@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 19:18:16 by dzafra            #+#    #+#             */
/*   Updated: 2025/12/18 19:32:03 by dzafra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	ch;

	ch = (unsigned char) c;
	i = 0;
	while (s[i] != '\0')
	{
		if ((unsigned char)s[i] == ch)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if (ch == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
