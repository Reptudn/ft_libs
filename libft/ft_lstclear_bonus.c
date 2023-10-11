/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonask <jonask@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 07:33:07 by jonask            #+#    #+#             */
/*   Updated: 2023/10/11 21:48:44 by jonask           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*last;
	t_list	*curr;

	while (last->next != 0)
	{
		curr = last;
		last = last->next;
		ft_lstdelone(curr, del);
	}
	free(lst);
	lst = 0;
}
