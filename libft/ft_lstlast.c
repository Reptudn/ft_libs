/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonask <jonask@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 07:18:35 by jonask            #+#    #+#             */
/*   Updated: 2023/10/09 07:22:30 by jonask           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lastlast(t_list *lst)
{
	t_list	*last;
	
	last = lst;
	while (last->next != 0)
		last = last->next;
	return (last);
}
