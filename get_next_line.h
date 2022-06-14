/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvarags@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 15:01:12 by dvargas           #+#    #+#             */
/*   Updated: 2022/06/14 17:10:22 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
int		ft_strlen(char *str);
size_t	ft_strlcpy(char *dest, char *str, size_t size);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_substr2(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
int		lf_count(char *str);
char	*create(char *sbuffer, int fd);
char	*beautiful(char **sbuffer);
#endif
