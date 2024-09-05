/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:11:43 by agiguair          #+#    #+#             */
/*   Updated: 2022/11/16 21:47:50 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <bsd/bsd.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	if ((!dst || !src) && !size)
		return (0);
	k = 0;
	i = ft_strlen(dst);
	j = ft_strlen(src);
	if (!size)
		return (j);
	k = j + i;
	if (i > size)
		return (j + size);
	j = 0;
	while (src[j] && i + j < size - 1)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	if (k >= i + size && i > k - i)
		return (i + size);
	return (k);
}

/*void  main(void)
{
    char dest[30]; memset(dest, 0, 30);
    char * src = (char *)"AAAAAAAAA";
    dest[0] = 'B';
    memset(dest, 'B', 4);
    //printf("%ld",strlcat(dest, src, 3));
    printf("%ld",ft_strlcat(dest, src, 3));
}*/
/*
int main()
{
    char dst[7] = "000";
    char src[7] = "123";
    char dst1[7] = "000";
    char src1[7] = "123";
    printf("my: return:%d, dest:%s\n",ft_strlcat(dst,src,8), dst);
    printf("real: return:%d, dest:%s\n\n",strlcat(dst1,src1,8), dst1);

    char dst2[7] = "";
    char src2[7] = "123";
    char dst3[7] = "";
    char src3[7] = "123";
    printf("my: return:%d, dest:%s\n", ft_strlcat(dst2,src2,2), dst2);
    printf("real: return:%d, dest:%s\n\n", strlcat(dst3,src3,2), dst3);

    char dst4[7] = "000";
    char src4[7] = "";
    char dst5[7] = "000";
    char src5[7] = "";
    printf("my: return:%d, dest:%s\n", ft_strlcat(dst4,src4,7), dst4);
    printf("real: return:%d, dest:%s\n\n", strlcat(dst5,src5,7), dst5);

    char dst6[7] = "000";
    char src6[7] = "123";
    char dst7[7] = "000";
    char src7[7] = "123";
    printf("my: return:%d, dest:%s\n", ft_strlcat(dst6,src6,0), dst6);
    printf("real: return:%d, dest:%s\n\n", strlcat(dst7,src7,0), dst7);
}*/
