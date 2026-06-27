/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzenteno <rzenteno@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 22:19:39 by rzenteno          #+#    #+#             */
/*   Updated: 2026/05/26 10:31:20 by rzenteno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstadd_front(t_list **lst, t_list *new)

{
	new->next = *lst;
	*lst = new;
}
/*
int main(void)
{
t_list *head;      // puntero al inicio de la lista
t_list *nuevo;     // puntero al nodo nuevo que vamos a añadir
t_list *temp;      // puntero temporal para recorrer e imprimir

head = NULL;       // lista vacía al inicio

// Crear primer nodo
nuevo = ft_lstnew("Nodo 1");
ft_lstadd_front(&head, nuevo);

// Crear segundo nodo
nuevo = ft_lstnew("Nodo 2");
ft_lstadd_front(&head, nuevo);

// Crear tercer nodo
nuevo = ft_lstnew("Nodo 3");
ft_lstadd_front(&head, nuevo);

// Imprimir la lista (debería salir: Nodo 3 -> Nodo 2 -> Nodo 1)
temp = head;
while (temp)
{
printf("%s\n", (char *)temp->content);
temp = temp->next;
}

return (0);
}
*/
