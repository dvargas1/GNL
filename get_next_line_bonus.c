/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvarags@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:35:51 by dvargas           #+#    #+#             */
/*   Updated: 2022/06/11 16:27:27 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(char *str)
{
	size_t	i;

	if(!str)
		return(0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	if ((ft_strlen(s) + start) < len)
		len = ft_strlen(s) + start;
	substr = malloc(sizeof(*s) * len + 1);
	if (!substr)
		return (NULL);
	i = 0;
	while (i < start)
		i++;
	j = 0;
	while (j < len)
	{
		substr[j] = s[i];
		i++;
		j++;
	}
	substr[j] = '\0';
	return (substr);
}

char	*ft_substr2(char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	if ((ft_strlen(s) + start) < len)
		len = ft_strlen(s) + start;
	substr = malloc(sizeof(*s) * len + 1);
	if (!substr)
		return (NULL);
	i = 0;
	while (i < start)
		i++;
	j = 0;
	while (j < len)
	{
		substr[j] = s[i];
		i++;
		j++;
	}
	substr[j] = '\0';
	free(s);
	return (substr);
}

int lf_count (char *str, int flag)
{
	int position = 0;
	int lfcount = 0;

	if (!str)
		return(-1);
	while (str[position])
	{
		if (str[position] == '\n')
		{
			lfcount++;
			break;
		}
		position++;
	}
	if (flag == 1)
		return (lfcount);
	else if (flag == 2)
		return (position);
	return (0);
}
int	ft_strchr(char *str, int c)
{
	size_t	i;
	char	*s;

	s = (char *) str;
	i = 0;
	if (!str)
		return (-1);
	while (i <= ft_strlen(str))
	{
		if (s[i] == (char) c)
			return(1);
		i++;
	}
	return(0);
}
char	*ft_strjoin(char *s1, char *s2)
{
	char	*newstr;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	newstr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!newstr)
		return (NULL);
	while (s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		newstr[i + j] = s2[j];
		j++;
	}
	newstr[i + j] = '\0';
	free(s1);
	free(s2);
	return (newstr);
}

char	*get_next_line(int fd)
{
	char	*string;
	char	*buffer;
	static char	*stringbuffer[1024] = {0};
	int	nposition;
	ssize_t bytes_read;

	if (fd < 0 || BUFFER_SIZE < 1 || !BUFFER_SIZE)
		return (NULL);
	bytes_read = 1;
	while (bytes_read)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if(bytes_read < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		stringbuffer[fd] = ft_strjoin(stringbuffer[fd], buffer);
		if (ft_strchr(stringbuffer[fd], '\n'))
			break;
	}
	//free(buffer);
	nposition = lf_count(stringbuffer[fd], 2);
	if(lf_count(stringbuffer[fd], 1) > 0)
	{
		string = ft_substr(stringbuffer[fd], 0 , nposition+1);
		stringbuffer[fd] = ft_substr2(stringbuffer[fd], nposition+1, ft_strlen(stringbuffer[fd]) - nposition);
	}
	else
	{
		string = ft_substr(stringbuffer[fd], 0, ft_strlen(stringbuffer[fd]));
		free(stringbuffer[fd]);
		stringbuffer[fd] = NULL;
	}
	if (ft_strlen(string) == 0)
	{
		free(string);
		return(NULL);
	}
	return (string);
}
// erro no read é -1
/*
 *GET NEXT LINE
 * O objetivo dessa função é imprimir o conteúdo de um arquivo de texto linha por linha com auxilio da funcao
 * read, aqui só será liberada a utilização das funcoes READ , MALLOC , FREE
 * Esse é meu primeiro esboço de como abordar o caso da GNL.
 *
 * A função Read tem os seguintes parametros "ssize_t read(int fd, void *buf, size_t count)"
 *
 * File descriptors só existem acima de 0 logo se FD < 0 deve retornar NULL
 * Se nao tivermos linhas o programa deve retornar NULL
 * Se o Buffersize for menor do que zero, retornamos NULL (se for zero tbm?)
 * Se read retornar -1 retornamos NULL
 *
 * A ideia aqui é que não podemos ler o arquivo novamente do inicio 
 * de onde paramos, logo se tiver um /n no meio do nosso
 * buffer precisamos guardar a informação depois dele para ser utilizada, para isso podemos usar uma
 * variavel do tipo Static
 * ----------------------------
 * Fazemos StrJoin de ReadBuffer(RESULTADO DE READ) para um static StringBuffer 
 * Procuramos um /n no StringBuffer (podemos usar strchr)
 *		SIM -> Monte a linha em uma string de retorno lembrar de delimitar por /n
 *		Depois disso Stringbuffer precisa ser malocada com o novo conteúdo (tudo depois de /n)
 *	Leia um Buffer_size novamente
 * ----------------------------
 * Questões que me vem a cabeça
 * Se o buffer tiver mais do que um /n? criamos uma regra especifica pra isso?
 * R: Sim, podeoms fazer isso dentro da montagem de linha por exemplo.
 *
 *
 * Lembrar -
 * If N Def BUFFER_SIZE 42
 */
