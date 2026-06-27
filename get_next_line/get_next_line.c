/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzenteno <rzenteno@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 18:48:33 by rzenteno          #+#    #+#             */
/*   Updated: 2026/06/26 22:30:53 by rzenteno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*free_all(char *stash, char *buffer)
{
	free(stash);
	free(buffer);
	return (NULL);
}

static char	*get_line(char *stash)
{
	char	*p;
	char	*aux;

	if (!stash || !*stash)
		return (NULL);
	p = stash;
	while (*p && *p != '\n')
		p++;
	if (*p == '\n')
		p++;
	aux = ft_substr(stash, 0, p - stash);
	if (!aux)
		return (NULL);
	return (aux);
}

static char	*keep_rest(char *stash)
{
	char	*p;
	char	*aux;

	p = stash;
	while (*p && *p != '\n')
		p++;
	if (*p == '\0')
	{
		free(stash);
		return (NULL);
	}
	p++;
	aux = ft_substr(stash, p - stash, ft_strlen(stash) - (p - stash));
	free(stash);
	if (!aux)
		return (NULL);
	return (aux);
}

char	*read_fd(int fd, char *stash)
{
	char	*buffer;
	char	*aux;
	ssize_t	bytes;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(stash, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (free_all(stash, buffer));
		buffer[bytes] = '\0';
		aux = ft_strjoin(stash, buffer);
		free(stash);
		if (!aux)
		{
			free(buffer);
			return (NULL);
		}
		stash = aux;
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	line = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
	{
		stash = malloc(1);
		if (!stash)
			return (NULL);
		stash[0] = '\0';
	}
	stash = read_fd(fd, stash);
	if (!stash)
		return (NULL);
	line = get_line(stash);
	stash = keep_rest(stash);
	return (line);
}

/*
int	main(void)
{
	int		fd;
	char	*line;
	char	*p;
	int		call;

	fd = open("text.txt", O_RDONLY);
	if (fd < 0)
		return (1);

	call = 1;
	while ((line = get_next_line(fd)))
	{
		printf("Llamada %d -> [", call);

		p = line;
		while (*p)
		{
			if (*p == '\n')
				printf("\\n");
			else
				printf("%c", *p);
			p++;
		}

		printf("]\n");

		free(line);
		call++;
	}

	close(fd);
	return (0);
}*/
/*
int	main(void)
{
	fd = open("text.txt", O_RDONLY);
	if (fd < 0)
		return(1);
	line = get_next_line(fd);
	while(line)
	{
		printf("Línea: [%s]\n", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return(0);
}*/
/*
	while (*line)
		if(line == "\n")
			printf("encontrado: %s", line);
	//line = strchr(buffer, '\n');
	printf("ejemplo1: %s\n", line);
	printf("\nejemplo: %s\n", buffer);
	//printf("buffer = [%s]\n", buffer);
	if (line)
		printf("strchr encontro: [%s]\n", line);
	else
		printf("No encontro '\\n'\n");
*/
/*
bytes = read(fd, buffer, BUFFER_SIZE);
while(1)
	line = strchr(buffer, '\n');
buffer[bytes] = '\0';
line = strchr(buffer, '\n');
printf("buffer = [%s]\n", buffer);
if (line)
	printf("strchr encontro: [%s]\n", line);
else
	printf("No encontro '\\n'\n");
//--------------------------------------------------
printf("%li", bytes);
line = (char *)buff_pos;
buffer[bytes] = '\0';
printf("bytes = %zd\n", bytes);
printf("buffer = [%s]\n", buffer);
printf("line= %s\n", line);
*/
/*
	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes <= 0)
		return (NULL);
	buffer[bytes] = '\0';
	line = strchr(buffer, '\n');
	printf("buffer = [%s]\n", buffer);
	if (line)
		printf("strchr encontro: [%s]\n", line);
	else
		printf("No encontro '\\n'\n");
//--------------------------------------------------
return(line);
}
*/

/* LOOP: buscar línea completa
	MIENTRAS verdadero:

		// ¿Hay un \n desde buf_pos?
		Buscar \n en buffer[buf_pos...]

		SI encontraste \n:
			// EXTRAER LÍNEA
			linea = copiar desde buf_pos hasta \n (incluido)
			buf_pos = actualizar a después del \n
			Retornar linea

		SI no encontraste \n:
			// ¿Hay más datos por leer?
			bytes = read(fd, buffer, BUFFER_SIZE)

			SI bytes == 0 (EOF):
				// No hay más líneas
				SI buf_pos tiene datos:
					linea = copiar todo lo que queda
					buf_pos = 0
					Retornar linea
				SINO:
					Retornar NULL

			SI bytes < 0 (error):
				Retornar NULL

				Hay nuevos datos, vuelve al inicio del MIENTRAS*/
/*
read() lee: "Hola\nMundo"
buffer = "Hola\nMundo"
buf_pos = 0
→ Encuentra \n en posición 4
→ Extrae "Hola\n"
→ buf_pos = 5
→ Devuelve "Hola\n"

*/
// 1. Validar fd
// if Null return NULL
// 2. Si el buffer está vacío, llenar con read()
// 3. Buscar \n en el buffer
//    - Si lo encuentras: copiar línea, actualizar buffer
//    - Si no: pedir más datos o devolver lo que hay
// 4. Manejar EOF (read devuelve 0)
// 5. Devolver la línea (o NULL si no hay más)
