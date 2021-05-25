/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 20:42:42 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/03/21 23:14:45 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*nxt;

	if (!*lst || !del)
		return ;
	if ((*lst)->next)
	{
		tmp = *lst;
		while (tmp)
		{
			(*del)((tmp)->content);
			nxt = tmp->next;
			free(tmp);
			tmp = nxt;
		}
	}
	else
		ft_lstdelone(*lst, del);
	*lst = 0;
}
