/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvarags@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:35:51 by dvargas           #+#    #+#             */
/*   Updated: 2022/06/11 19:09:40 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_strchr(char *str, int c)
{
	int		i;
	char	*s;

	s = (char *) str;
	i = 0;
	while (i <= ft_strlen(str))
	{
		if (s[i] == (char) c)
			return (&s[i]);
		i++;
	}
	return (0);
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
	char		*string;
	char		*buffer;
	static char	*sbuffer;
	int			npos;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!sbuffer)
		sbuffer = calloc(1, 1);
	bytes_read = 1;
	while (bytes_read)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		sbuffer = ft_strjoin(sbuffer, buffer);
		if (ft_strchr(sbuffer, '\n'))
			break ;
	}
	npos = lf_count(sbuffer, 2);
	if (lf_count(sbuffer, 1) > 0)
	{
		string = ft_substr(sbuffer, 0, npos + 1);
		sbuffer = ft_substr2(sbuffer, npos + 1, ft_strlen(sbuffer) - npos);
	}
	else
	{
		string = ft_substr(sbuffer, 0, ft_strlen(sbuffer));
		free(sbuffer);
		sbuffer = NULL;
	}
	if (ft_strlen(string) == 0)
	{
		free(string);
		return (NULL);
	}
	return (string);
}
// erro no read é -1
/*
 *GET NEXT LINE
 * O objetivo dessa função é imprimir o conteúdo de um arquivo de texto linha 
 * por linha com auxilio da funcao
 * read, aqui só será liberada a utilização das funcoes READ , MALLOC , FREE
 * Esse é meu primeiro esboço de como abordar o caso da GNL.
 *
 * A função Read tem os seguintes parametros "ssize_t read(int fd, void *buf, 
 * size_t count)"
 *
 * File descriptors só existem acima de 0 logo se FD < 0 deve retornar NULL
 * Se nao tivermos linhas o programa deve retornar NULL
 * Se o Buffersize for menor do que zero, retornamos NULL (se for zero tbm?)
 * Se read retornar -1 retornamos NULL
 *
 * A ideia aqui é que não podemos ler o arquivo novamente do inicio 
 * de onde paramos, logo se tiver um /n no meio do nosso
 * buffer precisamos guardar a informação depois dele para ser utilizada, para 
 * isso podemos usar uma
 * variavel do tipo Static
 * ----------------------------
 * Fazemos StrJoin de ReadBuffer(RESULTADO DE READ) para um static StringBuffer 
 * Procuramos um /n no StringBuffer (podemos usar strchr)
 *		SIM -> Monte a linha em uma string de retorno lembrar de delimitar por 
 *		/n
 *		Depois disso Stringbuffer precisa ser malocada com o novo conteúdo (tud
 *		o depois de /n)
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
