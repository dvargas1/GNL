/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvarags@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:35:51 by dvargas           #+#    #+#             */
/*   Updated: 2022/06/10 01:55:22 by dvargas          ###   ########.fr       */
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

char	*get_next_line(int fd)
{
	char	*string;
	static char	*stringbuffer;
	int	nposition;
	ssize_t readed;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stringbuffer)
		stringbuffer = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	readed = read(fd, stringbuffer, BUFFER_SIZE);
	while (readed)
	{
		stringbuffer[readed] = '\0';
		if (lf_count(stringbuffer, 1) > 0)
			break;
		readed = read(fd, stringbuffer, BUFFER_SIZE);
	}
	nposition = lf_count(stringbuffer, 2);
	if(lf_count(stringbuffer, 1) > 0)
	{
		string = ft_substr(stringbuffer, 0 , nposition);
		// criar uma função que de strjoin no restante do stringbuffer;
	}
	else
	{
		string = ft_substr(stringbuffer, 0, ft_strlen(stringbuffer));
	}
	if (*string == 0 && readed == 0)
		return (NULL);
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
