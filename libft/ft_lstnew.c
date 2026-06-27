/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzenteno <rzenteno@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 20:20:32 by rzenteno          #+#    #+#             */
/*   Updated: 2026/05/26 20:28:13 by rzenteno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)

{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
/*
#include "libft.h"
#include <stdio.h>

int	main(void)
{
    t_list	*node1;      // primer nodo con string
    t_list	*node2;      // segundo nodo con NULL
    char	*text;        // string para probar

    text = "Hola mundo"; // contenido para el nodo

    // Prueba 1: crear nodo con contenido
    node1 = ft_lstnew(text);
    printf("node1: %p\n", (void *)node1);
    printf("node1->content: %s\n", (char *)node1->content);
    printf("node1->next: %p\n", (void *)node1->next);
    printf("\n");

    // Prueba 2: crear nodo con NULL
    node2 = ft_lstnew(NULL);
    printf("node2: %p\n", (void *)node2);
    printf("node2->content: %p\n", (void *)node2->content);
    printf("node2->next: %p\n", (void *)node2->next);
    printf("\n");

    // Limpieza (opcional para testing simple)
    free(node1);
    free(node2);

    return (0);
}*/