/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 23:24:28 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/10 17:46:10 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief 			Allocates (with malloc(3)) and returns a substring from the
/// @param s		String from which to create the substring
/// @param start	Index of the beginning of the substring
/// @param len		Length of the substring
/// @return			The substring, or NULL if the allocation fails
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	len_ptr;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start || !len)
	{
		substr = (char *) malloc (sizeof (char));
		if (!substr)
			return (NULL);
		*substr = '\0';
		return (substr);
	}
	if (ft_strlen(s) - start >= len)
		len_ptr = len + 1;
	else
		len_ptr = ft_strlen(s) - start + 1;
	substr = (char *) malloc ((len_ptr) * sizeof (char));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, len_ptr);
	return (substr);
}
