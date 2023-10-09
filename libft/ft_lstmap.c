/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonask <jonask@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 07:42:38 by jonask            #+#    #+#             */
/*   Updated: 2023/10/09 08:42:47 by jonask           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *pog;

	pog = malloc(sizeof(lst)); //check bcuz defrefwerence okay or not?
	if (!pog)
		return (0);
	pog = lst;
	while (lst->next != 0)
	{
		pog->content = f(pog->content);
		if (pog->content == 0)
			del(pog);
		pog = pog->next;
	}
	lst = 0;
	return (pog);
}