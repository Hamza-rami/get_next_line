/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrami <hrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:11:07 by hrami             #+#    #+#             */
/*   Updated: 2024/11/23 23:36:09 by hrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <libc.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*ft_strncpy(char *dest, char const *src, unsigned int n);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(char *src);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
int		ft_strlen(char *s);

#endif