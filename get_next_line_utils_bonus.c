/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmendy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 10:13:16 by rmendy            #+#    #+#             */
/*   Updated: 2020/07/03 13:54:52 by rmendy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strsub(char *str, int start, size_t len)
{
	char	*s;
	int		i;

	i = 0;
	s = (char*)malloc(sizeof(char) * (len + 1));
	if (!str || !s)
		return (NULL);
	while (i < len && str[start])
	{
		s[i] = str[start];
		i++;
		start++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_strdup(char *str)
{
	char	*s;
	int		i;

	i = -1;
	if (!(s = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (NULL);
	while (str[++i])
		s[i] = str[i];
	s[i] = '\0';
	return(s);
}

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	if (str == NULL)
		return(NULL);
	while ((*str) && (*str) != c)
		str++;
	if ((*str) == c)
		return (str);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		a;

	i = -1;
	if (!(str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	a = 0;
	while (s2[a])
		str[i++] = s2[a++];
	str[i] = '\0';
	return (str);
}


/*int		main(int ac, char **av)
{
	printf("%s\n",ft_strsub(av[1],8,8));
	return 0;
}*/
