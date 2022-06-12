/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvarags@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 15:01:12 by dvargas           #+#    #+#             */
/*   Updated: 2022/06/12 11:49:20 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd);
int	ft_strlen(char *str);
size_t	ft_strlcpy(char *dest, char *str, size_t size);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_substr2(char *s, unsigned int start, size_t len);
char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
int		lf_count(char *str);

#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
#endif
