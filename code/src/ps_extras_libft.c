/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_libft_extras.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 22:52:14 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/04 23:02:13 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief		Displays errors when args or process not successful
/// @param s	The string to check length
/// @return		length of the string
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/// @brief 		checks if a char is a decimal digit
/// @param c 	the char to check
/// @return 	1 if true 1 otherwise
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (TRUE);
	return (FALSE);
}

/// @brief 		Checks if a char is a sign
/// @param c	The char to check
/// @return		 -1 if '-', 1 if '+', 0 otherwise
int	ft_issign(char c)
{
	if (c == '-')
		return (-1);
	else if (c == '+')
		return (1);
	else
		return (0);
}

/// @brief 		Checks if a char is a space
/// @param c	The char to check
/// @return		TRUE if is sapce, FALSE otherwise
static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' \
	|| c == '\v' || c == '\f' || c == '\r')
		return (TRUE);
	return (FALSE);
}

/// @brief 		Allocates (with malloc(3)) and returns a substring from the string ’s’.
/// @param n	The start index of the substring in the string ’s’.
/// @return		The substring
int	ft_itoa_len(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n && i++ >= 0)
		n /= 10;
	return (i);
}

/// @brief 		Allocates (with malloc(3)) and returns a substring from the string ’s’.
/// @param n	The start index of the substring in the string ’s’.
/// @return		The substring
char	*ft_itoa(int n)
{
	char		*res;
	int			a_len;
	long int	ln;

	ln = n;
	a_len = ft_itoa_len(n);
	res = (char *)malloc((a_len + 1) * sizeof(char));
	if (res)
	{
		res[a_len] = '\0';
		if (!ln)
			res[0] = '0';
		if (ln < 0)
		{
			ln = -ln;
			res[0] = '-';
		}
		while (ln && a_len-- >= 0)
		{
			res[a_len] = ln % 10 + 48;
			ln /= 10;
		}
		return (res);
	}
	return (NULL);
}

/// @brief 		Converts the initial portion of the string pointed to by nptr to int
/// @param nptr	The string to convert
/// @return		The converted int
int	ft_atoi(const char *nptr)
{
	int	signal;
	int	number;

	signal = 1;
	number = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (ft_issign(*nptr))
		signal *= ft_issign(*nptr++);
	while (ft_isdigit(*nptr))
		number = number * 10 + (*nptr++ - '0');
	return (number * signal);
}

/// @brief 		Concatenate two strings s1 and s2
/// @param s1		Destination string
/// @param s2		Source string
/// @return			The new string
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*dest;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1)+ft_strlen(s2)+1;
	dest = malloc(sizeof(char) * len);
	if (!dest)
		return (NULL);
	while (*s1)
	{
		*dest++ = *s1++;
	}
	while (*s2)
	{
		*dest++ = *s2++;
	}
	*dest = '\0';
	dest -= (len - 1);
	return (dest);
}

/// @brief 		Allocates (with malloc(3)) and returns a substring from the string ’s’.
/// @param s	The string from which to create the substring.
/// @param c	The delimiter character.
/// @return		The substring
size_t	ft_split_count(const char *s, char c)
{
	size_t	splits;
	int		split_new;

	splits = 0;
	split_new = 0;
	while (*s)
	{
		if (*s != c && split_new == 0)
		{
			split_new = 1;
			splits++;
		}
		else if (*s == c)
			split_new = 0;
		s++;
	}
	return (splits);
}

/// @brief 		Allocates (with malloc(3)) and returns a substring from the string ’s’.
/// @param s	The string from which to create the substring.
/// @param c	The delimiter character.
/// @return		 The substring
char	*ft_split_slice(const char *s, char c)
{
	size_t	split_len;
	char	*split;

	split_len = 0;
	while (s[split_len] && s[split_len] != c)
		split_len++;
	split = (char *)malloc((split_len + 1) * sizeof(char));
	if (!split)
	{
		free (split);
		return (NULL);
	}
	while (*s && *s != c)
		*split++ = *s++;
	*split = '\0';
	return (split - split_len);
}

/// @brief 		Allocates (with malloc(3)) and returns an array
/// @param s	The string from which to create the array.
/// @param c	The delimiter character.
/// @return		The array
char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	i_split;
	size_t	splits;

	if (!s)
		return (NULL);
	i_split = 0;
	splits = ft_split_count(s, c);
	array = (char **)malloc(sizeof(char *) * (splits + 1));
	if (!array)
	{
		free (array);
		return (NULL);
	}
	while (*s && i_split <= splits)
	{
		while (*s == c && *s)
			s++;
		if (*s && *s != c)
			array[i_split++] = ft_split_slice(s, c);
		while (*s && *s != c)
			s++;
	}
	array[i_split] = NULL;
	return (array);
}
