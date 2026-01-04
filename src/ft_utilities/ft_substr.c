/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 02:42:56 by anasinda          #+#    #+#             */
/*   Updated: 2025/12/21 20:18:57 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_utilities.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	size_t	i;
	char	*ptr;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	size = ft_strlen(s + start);
	if (size > len)
		size = len;
	ptr = malloc(sizeof(char) * (size + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
/*
int main(void)
{
    char *str = "HelloWorld";

    char *sub1 = ft_substr(str, 0, 5);   // Expect "Hello"
    char *sub2 = ft_substr(str, 5, 5);   // Expect "World"
    char *sub3 = ft_substr(str, 3, 50);  // Expect "loWorld"
    char *sub4 = ft_substr(str, 10, 5);  // Expect "" (start beyond length)
    char *sub5 = ft_substr(str, 2, 0);   // Expect "" (len = 0)
    char *sub6 = ft_substr("", 0, 5);    // Expect ""

    printf("Test 1: '%s'\n", sub1);
    printf("Test 2: '%s'\n", sub2);
    printf("Test 3: '%s'\n", sub3);
    printf("Test 4: '%s'\n", sub4);
    printf("Test 5: '%s'\n", sub5);
    printf("Test 6: '%s'\n", sub6);

    // Free the allocated memory
    free(sub1);
    free(sub2);
    free(sub3);
    free(sub4);
    free(sub5);
    free(sub6);

    return 0;
}*/
