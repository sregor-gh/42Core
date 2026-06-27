/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzenteno <rzenteno@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 14:38:01 by rzenteno          #+#    #+#             */
/*   Updated: 2026/05/26 14:38:11 by rzenteno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)

{
	t_list	*node;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	node = *lst;
	while (node->next)
		node = node->next;
	node->next = new;
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
t_list	*head;      // puntero al inicio de la lista
t_list	*node1;     // primer nodo
t_list	*node2;     // segundo nodo
t_list	*node3;     // tercer nodo
t_list	*temp;      // puntero temporal para recorrer la lista

head = NULL; // la lista comienza vacía

node1 = ft_lstnew("Uno");   // crea el primer nodo
node2 = ft_lstnew("Dos");   // crea el segundo nodo
node3 = ft_lstnew("Tres");  // crea el tercer nodo

ft_lstadd_back(&head, node1); // añade el primer nodo al final
ft_lstadd_back(&head, node2); // añade el segundo nodo al final
ft_lstadd_back(&head, node3); // añade el tercer nodo al final

temp = head; // inicializa el recorrido desde el inicio
while (temp) // recorre e imprime la lista
{
printf("%s\n", (char *)temp->content); // imprime el contenido del nodo
temp = temp->next; // avanza al siguiente nodo
}

// No olvides liberar la memoria si lo necesitas
return (0);
}*/
