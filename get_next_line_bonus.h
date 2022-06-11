/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvarags@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 15:01:12 by dvargas           #+#    #+#             */
/*   Updated: 2022/06/11 00:48:17 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
size_t	ft_strlcpy(char *dest, char *str, size_t size);
char	*ft_strdup(char *src);
char	*ft_substr(char *s, unsigned int start, size_t len);
int	lf_count(char *str, int flag);

#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif
