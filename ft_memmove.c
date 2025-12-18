/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzafra <dzafra@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 19:49:36 by dzafra            #+#    #+#             */
/*   Updated: 2025/12/18 19:49:48 by dzafra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (dst == src || len == 0)
		return (dst);
	if (dst < src)
	{
		i = 0;
		while (i < len)
			d[i++] = s[i];
	}
	else
		while (len--)
			d[len] = s[len];
	return (dst);
}
