/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarcevs <gkarcevs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:58:55 by gkarcevs          #+#    #+#             */
/*   Updated: 2024/06/20 15:31:45 by gkarcevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*current_node;

	if (!lst | !f)
		return ;
	current_node = lst;
	while (current_node->next != NULL)
	{
		f(current_node->content);
		current_node = current_node->next;
	}
	f(current_node->content);
}
