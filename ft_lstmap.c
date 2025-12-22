/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Daniel Z <daniel.zafra@student.42barcelon  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 18:37:22 by Daniel Z          #+#    #+#             */
/*   Updated: 2025/12/22 19:00:22 by Daniel Z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*tmp;
	void	*c;

	if (!f || !del)
		return (NULL);
	res = NULL;
	while (lst)
	{
		c = f(lst->content);
		if (!c)
			return (ft_lstclear(&res, del), NULL);
		tmp = ft_lstnew(c);
		if (!tmp)
			return (del(c), ft_lstclear(&res, del), NULL);
		ft_lstadd_back(&res, tmp);
		lst = lst->next;
	}
	return (res);
}
