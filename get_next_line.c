/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvarags@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:35:51 by dvargas           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/06/10 01:55:22 by dvargas          ###   ########.fr       */
=======
/*   Updated: 2022/06/08 19:13:57 by dvargas          ###   ########.fr       */
>>>>>>> parent of 605618a (New implement of GNL)
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
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

int lf_count (char *str, int flag)
{
	int position = 0;
	int lfcount = 0;

	while (str[position])
	{
		if (str[position] == '\n')
			lfcount++;
		break;
		position++;
	}
	if (flag == 1)
		return (lfcount);
	else if (flag == 2)
		return (position);
	return (0);
}
char	*ft_strchr(const char *str, int c)
{
	size_t	i;
	char	*s;

	s = (char *) str;
	i = 0;
	while (i <= ft_strlen(str))
	{
		if (s[i] == (char) c)
			return(&s[i]);
		i++;
	}
	return(0);
}
char	*ft_strjoin(char const *s1, char const *s2)
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
	return (newstr);
}

char	*get_next_line(int fd)
{
	char	*string;
	char	*buffer;
	static char	*stringbuffer;
	int	nposition;
	ssize_t bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stringbuffer)
		stringbuffer = malloc(1);
	buffer = malloc(sizeof(char) * BUFFER_SIZE +1);
	bytes_read = 1;
	while (bytes_read)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = '\0';
		stringbuffer = ft_strjoin(stringbuffer, buffer);
		if (ft_strchr(stringbuffer, '\n'))
			break;
	}
	free(buffer);
	nposition = lf_count(stringbuffer, 2);
	if(lf_count(stringbuffer, 1) > 0)
	{
		string = ft_substr(stringbuffer, 0 , nposition+1);
		stringbuffer = ft_substr(stringbuffer, nposition+1, ft_strlen(stringbuffer) - nposition);
	}
	else
	{
		string = ft_substr(stringbuffer, 0, ft_strlen(stringbuffer));
		free(stringbuffer);
	}
	return (string);
}
// preciso colocar um while para repetir a leitura de Read
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
