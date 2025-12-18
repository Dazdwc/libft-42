/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzafra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 23:13:41 by dzafra            #+#    #+#             */
/*   Updated: 2025/12/18 19:56:32 by dzafra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    size_t  i;
    size_t  j;

    if (!needle[0])
        return ((char *)haystack);

    i = 0;
    while (haystack[i] && i < len)
    {
        j = 0;
        while (needle[j] && (i + j) < len && haystack[i + j] == needle[j])
            j++;
        if (needle[j] == '\0')
            return ((char *)&haystack[i]);
        i++;
    }
    return (NULL);
}
