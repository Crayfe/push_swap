/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayuso-f <cayuso-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:14:41 by cayuso-f          #+#    #+#             */
/*   Updated: 2024/09/24 10:07:54 by cayuso-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
//#include <bsd/string.h>

void	test_isalpha();
void	test_isdigit();
void	test_isalnum();
void	test_isascii();
void	test_isprint();
void	test_strlen();
void	test_memset(char *test_str, char *test_str1);
void	test_bzero(char *test_str, char *test_str1);
void	test_memcpy(char *test_str, char *test_str1);
void	test_memmove(char *test_str, char *test_str1);
void	test_strlcpy(char *test_str, char *test_str1);
void	test_strlcat(char *test_str, char *test_str1);
void	test_toupper();
void	test_tolower();
void	test_strchr(char *test_str);
void	test_strrchr(char *test_str);
void	test_strncmp(char *test_str, char *test_str1);
void	test_memchr(char *test_str);
void	test_memcmp(char *test_str, char *test_str1);
void	test_strnstr(char *test_str, char *test_str1);
void	test_atoi();
void	test_calloc();
void	test_strdup();
void	test_substr();
void	test_strjoin();
void	test_strtrim();
void	test_split();
void	test_itoa();
void	test_strmapi();
void	test_strteri();
void	test_putchar_fd();
void	test_putstr_fd();
void	test_putendl_fd();
void	test_putnbr_fd();


int	main(void)
{
	
	char test_str[125] = "";
	char test_str1[125] = "";
	/*
	test_isalpha();
	test_isdigit();
	test_isalnum();
	test_isascii();
	test_isprint();
	test_strlen();
	test_memset(test_str, test_str1);
	memcpy(test_str, "lorem ipsum", 11);
	memcpy(test_str1, "lorem ipsum", 11);
	test_bzero(test_str, test_str1);
	memcpy(test_str, "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua", 100);
	memcpy(test_str1, "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua", 100);
	memcpy(test_str, "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua", 100);
	memcpy(test_str1, "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua", 100);
	test_memmove(test_str, test_str1);
	test_atoi();
	*/
	test_memcpy(test_str, test_str1);
	test_strlcpy(test_str, test_str1);
	test_strlcat(test_str, test_str1);
	test_toupper();
	test_tolower();
	test_strchr(test_str);
	test_strrchr(test_str);
	test_strncmp(test_str, test_str1);
	test_memchr(test_str);
	test_memcmp(test_str, test_str1);
	test_strnstr(test_str, test_str1);
	test_calloc();
	test_strdup();

	return (0);
}

void test_isalpha()
{
	printf("*** isalpha() ***\n");
	printf("Is %c alpha? %i\n", 0, isalpha(0));
	printf("Is %c alpha? %i\n", '5', isalpha('5'));
	printf("Is %c alpha? %i\n", 'g', isalpha('g'));
	printf("Is %c alpha? %i\n", 'G', isalpha('G'));

	printf("*** ft_isalpha() ***\n");
	printf("Is %c alpha? %i\n", 0, ft_isalpha(0));
	printf("Is %c alpha? %i\n", '5', ft_isalpha('5'));
	printf("Is %c alpha? %i\n", 'g', ft_isalpha('g'));
	printf("Is %c alpha? %i\n", 'G', ft_isalpha('G'));
}
void test_isdigit()
{
	printf("\n\n*** isdigit() ***\n");
	printf("Is %c digit? %i\n", 0, isdigit(0));
	printf("Is %c digit? %i\n", '5', isdigit('5'));
	printf("Is %c digit? %i\n", 'g', isdigit('g'));
	printf("Is %c digit? %i\n", 'G', isdigit('G'));

	printf("*** ft_isdigit() ***\n");
	printf("Is %c digit? %i\n", 0, ft_isdigit(0));
	printf("Is %c digit? %i\n", '5', ft_isdigit('5'));
	printf("Is %c digit? %i\n", 'g', ft_isdigit('g'));
	printf("Is %c digit? %i\n", 'G', ft_isdigit('G'));
}
void	test_isalnum()
{
	printf("\n\n*** isalnum() ***\n");
	printf("Is %c alphanumeric? %i\n", 0, isalnum(0));
	printf("Is %c alphanumeric? %i\n", '5', isalnum('5'));
	printf("Is %c alphanumeric? %i\n", 'g', isalnum('g'));
	printf("Is %c alphanumeric? %i\n", 'G', isalnum('G'));

	printf("*** ft_isalnum() ***\n");
	printf("Is %c alphanumeric? %i\n", 0, ft_isalnum(0));
	printf("Is %c alphanumeric? %i\n", '5', ft_isalnum('5'));
	printf("Is %c alphanumeric? %i\n", 'g', ft_isalnum('g'));
	printf("Is %c alphanumeric? %i\n", 'G', ft_isalnum('G'));
	
}
void	test_isascii()
{
	printf("\n\n*** isascii() ***\n");
	printf("Is %c ascii? %i\n", 0, isascii(0));
	printf("Is %c ascii? %i\n", '5', isascii('5'));
	printf("Is %c ascii? %i\n", 'g', isascii('g'));
	printf("Is %c ascii? %i\n", 'G', isascii('G'));
	printf("Is %c ascii? %i\n", 128, isascii(128));

	printf("*** ft_isascii() ***\n");
	printf("Is %c ascii? %i\n", 0, ft_isascii(0));
	printf("Is %c ascii? %i\n", '5', ft_isascii('5'));
	printf("Is %c ascii? %i\n", 'g', ft_isascii('g'));
	printf("Is %c ascii? %i\n", 'G', isascii('G'));
	printf("Is %c ascii? %i\n", 128, ft_isascii(128));

}
void	test_isprint()
{
	printf("\n\n*** isprint() ***\n");
	printf("Is %c printable? %i\n", 0, isprint(0));
	printf("Is %c printable? %i\n", '5', isprint('5'));
	printf("Is %c printable? %i\n", 'g', isprint('g'));
	printf("Is %c printable? %i\n", 'G', isprint('G'));
	printf("Is %c printable? %i\n", 128, isprint(128));

	printf("*** ft_isprint() ***\n");
	printf("Is %c printable? %i\n", 0, ft_isprint(0));
	printf("Is %c printable? %i\n", '5', ft_isprint('5'));
	printf("Is %c printable? %i\n", 'g', ft_isprint('g'));
	printf("Is %c printable? %i\n", 'G', ft_isprint('G'));
	printf("Is %c printable? %i\n", 128, ft_isprint(128));

}
void	test_strlen()
{
	printf("\n\n*** strlen() ***\n");
	printf("Lenght of %s is: %lu\n", "\0", strlen("\0"));
	printf("Lenght of %s is: %lu\n", "4", strlen("4"));
	printf("Lenght of %s is: %lu\n", "42", strlen("42"));
	printf("Lenght of %s is: %lu\n", "cadena", strlen("cadena"));

	printf("*** ft_strlen() ***\n");
	printf("Lenght of %s is: %lu\n", "\0", ft_strlen("\0"));
	printf("Lenght of %s is: %lu\n", "4", ft_strlen("4"));
	printf("Lenght of %s is: %lu\n", "42", ft_strlen("42"));
	printf("Lenght of %s is: %lu\n", "cadena", ft_strlen("cadena"));

}
void	test_memset(char *test_str, char *test_str1)
{
	size_t zero = 0;
	printf("\n\n*** memset() ***\n");
	printf("before: %s\n", test_str);
	memset(test_str, 64, zero);
	printf("after: %s\n\n", test_str);

	printf("before: %s\n", test_str);
	memset(test_str, 64, 5);
	printf("after: %s\n\n", test_str);

	printf("before: %s\n", test_str);
	memset(test_str, 35, 99);
	printf("after: %s\n\n", test_str);


	printf("*** ft_memset() ***\n");
	printf("before: %s\n", test_str1);
	ft_memset(test_str1, 64, zero);
	printf("after: %s\n\n", test_str1);

	printf("before: %s\n", test_str1);
	ft_memset(test_str1, 64, 5);
	printf("after: %s\n\n", test_str1);

	printf("before: %s\n", test_str1);
	ft_memset(test_str1, 35, 99);
	printf("after: %s\n\n", test_str1);
	
}
void	test_bzero(char *test_str, char *test_str1)
{

	printf("\n\n*** bzero() ***\n");
	printf("before: %s\n", test_str);
	bzero(test_str + 11, 4);
	printf("after: %s\n\n", test_str);

	printf("*** ft_bzero() ***\n");
	printf("before: %s\n", test_str1);
	ft_bzero(test_str1 + 11, 4);
	printf("after: %s\n\n", test_str1);

}
void	test_memcpy(char *test_str, char *test_str1)
{
	memcpy(test_str, "lorem ipsum", 11);
	memcpy(test_str1, "dolor", 11);
	printf("\n\n*** memcpy() ***\n");
	printf("before: %s\n", test_str);
	memcpy(test_str, test_str + 5, 20);
	printf("after: %s\n\n", test_str);
	memcpy(test_str, "lorem ipsum", 11);
	printf("before: %s\n", test_str);
	memcpy(test_str, test_str1, 4);
	printf("after: %s\n\n", test_str);

	memcpy(test_str, "lorem ipsum", 11);
	memcpy(test_str1, "dolor", 11);
	printf("*** ft_memcpy() ***\n");
	printf("before: %s\n", test_str);
	ft_memcpy(test_str, test_str + 5, 20);
	printf("after: %s\n\n", test_str);
	memcpy(test_str, "lorem ipsum", 11);
	printf("before: %s\n", test_str);
	ft_memcpy(test_str, test_str1, 4);
	printf("after: %s\n\n", test_str);
}
void	test_memmove(char *test_str, char *test_str1)
{
	printf("\n\n*** memmove() ***\n");
	printf("before: %s\n", test_str);
	memmove(test_str, test_str + 10, 20);
	printf("after: %s\n\n", test_str);
	memcpy(test_str, "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua", 100);
	printf("before: %s\n", test_str);
	memmove(test_str + 10, test_str, 20);
	printf("after: %s\n\n", test_str);

	printf("*** ft_memmove() ***\n");
	printf("before: %s\n", test_str1);
	ft_memmove(test_str1, test_str1 + 10, 20);
	printf("after: %s\n\n", test_str1);
	memcpy(test_str1, "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua", 100);
	printf("before: %s\n", test_str1);
	ft_memmove(test_str1 + 10, test_str1, 20);
	printf("after: %s\n\n", test_str1);
}
void	test_strlcpy(char *test_str, char *test_str1)
{
	memcpy(test_str, "lorem ipsum", 11);
	memcpy(test_str1, "dolor", 11);
	printf("\n\n*** strlcpy() ***\n");
	printf("before: %s\n", test_str);
	strlcpy(test_str, test_str + 5, 20);
	printf("after: %s\n\n", test_str);
	memcpy(test_str, "lorem ipsum", 11);
	printf("before: %s\n", test_str);
	strlcpy(test_str, test_str1, 4);
	printf("after: %s\n\n", test_str);

	memcpy(test_str, "lorem ipsum", 11);
	memcpy(test_str1, "dolor", 11);
	printf("*** ft_strlcpy() ***\n");
	printf("before: %s\n", test_str);
	ft_strlcpy(test_str, test_str + 5, 20);
	printf("after: %s\n\n", test_str);
	memcpy(test_str, "lorem ipsum", 11);
	printf("before: %s\n", test_str);
	ft_strlcpy(test_str, test_str1, 4);
	printf("after: %s\n\n", test_str);

}
void	test_strlcat(char *test_str, char *test_str1)
{
	memcpy(test_str, "lorem ipsum", 12);
	memcpy(test_str1, "", 1);
	printf("\n\n*** strlcat() ***\n");
	//printf("before: %s\n", test_str);
	//printf("Size: %zu\n", strlcat(test_str, test_str + 5, 20));
	//printf("after: %s\n\n", test_str);
	//memcpy(test_str, "lorem ipsum", 12);
	printf("before: %s\n", test_str);
	printf("Size: %zu\n", strlcat(test_str, test_str1, 20));
	printf("after: %s\n\n", test_str);
	memcpy(test_str, "lorem ipsum", 12);
	memcpy(test_str1, "dolor dolore dolorin", 25);
	printf("before: %s\n", test_str);
	printf("Size: %zu\n", strlcat(test_str, test_str1, 90));
	printf("after: %s\n\n", test_str);
	memcpy(test_str, "lorem ipsum", 12);
	printf("before: %s\n", test_str);
	printf("Size: %zu\n", strlcat(test_str, test_str1, 10));
	printf("after: %s\n\n", test_str);

	memcpy(test_str, "lorem ipsum", 12);
	memcpy(test_str1, "", 1);
	printf("\n\n*** ft_strlcat() ***\n");
	//printf("before: %s\n", test_str);
	//printf("Size: %zu\n", ft_strlcat(test_str, test_str + 5, 20));
	//printf("after: %s\n\n", test_str);
	//memcpy(test_str, "lorem ipsum", 12);
	printf("before: %s\n", test_str);
	printf("Size: %zu\n", ft_strlcat(test_str, test_str1, 20));
	printf("after: %s\n\n", test_str);
	memcpy(test_str, "lorem ipsum", 12);
	memcpy(test_str1, "dolor dolore dolorin", 25);
	printf("before: %s\n", test_str);
	printf("Size: %zu\n", ft_strlcat(test_str, test_str1, 90));
	printf("after: %s\n\n", test_str);
	memcpy(test_str, "lorem ipsum", 12);
	printf("before: %s\n", test_str);
	printf("Size: %zu\n", ft_strlcat(test_str, test_str1, 10));
	printf("after: %s\n\n", test_str);

}
void	test_toupper()
{
	printf("\n\n*** toupper() ***\n");
	printf("before: %c\n", 'h');
	printf("after: %c\n", toupper('h'));
	printf("before: %c\n", '7');
	printf("after: %c\n", toupper('7'));
	printf("before: %c\n", 'F');
	printf("after: %c\n", toupper('F'));


	printf("\n\n*** ft_toupper() ***\n");
	printf("before: %c\n", 'h');
	printf("after: %c\n", ft_toupper('h'));
	printf("before: %c\n", '7');
	printf("after: %c\n", ft_toupper('7'));
	printf("before: %c\n", 'F');
	printf("after: %c\n", ft_toupper('F'));

}
void	test_tolower()
{
	printf("\n\n*** tolower() ***\n");
	printf("before: %c\n", 'h');
	printf("after: %c\n", tolower('h'));
	printf("before: %c\n", '7');
	printf("after: %c\n", tolower('7'));
	printf("before: %c\n", 'F');
	printf("after: %c\n", tolower('F'));


	printf("\n\n*** ft_tolower() ***\n");
	printf("before: %c\n", 'h');
	printf("after: %c\n", ft_tolower('h'));
	printf("before: %c\n", '7');
	printf("after: %c\n", ft_tolower('7'));
	printf("before: %c\n", 'F');
	printf("after: %c\n", ft_tolower('F'));

}
void	test_strchr(char *test_str)
{
	char *aux = 0;
	memcpy(test_str, "lorem ipsum dorlor dolore dolorin", 50);
	printf("\n\n*** strchr() ***\n");
	printf("String: %s, char: %c\n", test_str, 'l');
	aux = strchr(test_str, 'l');
	printf("found in position: %li\n", aux - test_str);
	printf("String: %s, char: %c\n", test_str, 'm');
	aux = strchr(test_str, 'm');
	printf("found in position: %li\n", aux - test_str);
	aux = 0;
	printf("\n\n*** ft_strchr() ***\n");
	printf("String: %s, char: %c\n", test_str, 'l');
	aux = strchr(test_str, 'l');
	printf("found in position: %li\n", aux - test_str);
	printf("String: %s, char: %c\n", test_str, 'm');
	aux = strchr(test_str, 'm');
	printf("found in position: %li\n", aux - test_str);

}
void	test_strrchr(char *test_str)
{
	char *aux = 0;
	memcpy(test_str, "lorem ipsum dorlor dolore dolorin", 50);
	printf("\n\n*** strrchr() ***\n");
	printf("String: %s, char: %c\n", test_str, 'l');
	aux = strrchr(test_str, 'l');
	printf("found in position: %li\n", aux - test_str);
	printf("String: %s, char: %c\n", test_str, 'm');
	aux = strrchr(test_str, 'm');
	printf("found in position: %li\n", aux - test_str);
	printf("String: %s, char: %c\n", test_str, '3');
	aux = strrchr(test_str, '3');
	printf("found in position: %li\n", aux - test_str);
	aux = 0;
	printf("\n\n*** ft_strrchr() ***\n");
	printf("String: %s, char: %c\n", test_str, 'l');
	aux = ft_strrchr(test_str, 'l');
	printf("found in position: %li\n", aux - test_str);
	printf("String: %s, char: %c\n", test_str, 'm');
	aux = ft_strrchr(test_str, 'm');
	printf("found in position: %li\n", aux - test_str);
	printf("String: %s, char: %c\n", test_str, '3');
	aux = ft_strrchr(test_str, '3');
	printf("found in position: %li\n", aux - test_str);

}
void	test_strncmp(char *test_str, char *test_str1)
{
	int n = 0;
	printf("\n\n*** strncmp() ***\n");
	printf("String 1: %s,\n", test_str);
	printf("String 2: %s,\n", test_str1);
	n = 90;
	printf("Comparation with n = %i: %i,\n", n, strncmp(test_str, test_str1, n));
	printf("String 1: %s,\n", test_str);
	printf("String 2: %s,\n", test_str1);
	n = 0;
	printf("Comparation with n = %i: %i,\n", n, strncmp(test_str, test_str1, n));


	printf("*** ft_strncmp) ***\n");
	printf("String 1: %s,\n", test_str);
	printf("String 2: %s,\n", test_str1);
	n = 90;
	printf("Comparation with n = %i: %i,\n", n, ft_strncmp(test_str, test_str1, n));
	printf("String 1: %s,\n", test_str);
	printf("String 2: %s,\n", test_str1);
	n = 0;
	printf("Comparation with n = %i: %i,\n", n, ft_strncmp(test_str, test_str1, n));

}
void	test_memchr(char *test_str)
{

}
void	test_memcmp(char *test_str, char *test_str1)
{
	int n = 0
	printf("\n\n*** memcmp() ***\n");
	printf("String 1: %s,\n", test_str);
	printf("String 2: %s,\n", test_str1);
	n = 90;
	printf("Comparation with n = %i: %i,\n", n, memcmp(test_str, test_str1, n);
	printf("String 1: %s,\n", test_str);
	printf("String 2: %s,\n", test_str1);
	n = 0;
	printf("Comparation with n = %i: %i,\n", n, memcmp(test_str, test_str1, n);

	printf("*** ft_memcmp) ***\n");
	printf("String 1: %s,\n", test_str);
	printf("String 2: %s,\n", test_str1);
	n = 90;
	printf("Comparation with n = %i: %i,\n", n, ft_memcmp(test_str, test_str1, n);
	printf("String 1: %s,\n", test_str);
	printf("String 2: %s,\n", test_str1);
	n = 0;
	printf("Comparation with n = %i: %i,\n", n, ft_memcmp(test_str, test_str1, n);

}
void	test_strnstr(char *test_str, char *test_str1)
{
	char *aux = 0;
	memcpy(test_str, "lorem ipsum dorlor dolore dolorin", 50);
	memcpy(test_str1, "ipsum", 10);
	printf("\n\n*** strnstr() ***\n");
	printf(" Big string: %s, Little string: %s,\n", test_str, test_str1);
	aux = strnstr(test_str, test_str1, 90);
	printf("found in position: %li\n", aux - test_str);
	memcpy(test_str1, "dolore", 10);
	printf(" Big string: %s, Little string: %s,\n", test_str, test_str1);
	aux = strnstr(test_str, test_str1, 90);
	printf("found in position: %li\n", aux - test_str);
	aux = 0;
	memcpy(test_str, "lorem ipsum dorlor dolore dolorin", 50);
	memcpy(test_str1, "ipsum", 10);
	printf("*** ft_strnstr() ***\n");
	printf(" Big string: %s, Little string: %s,\n", test_str, test_str1);
	aux = ft_strnstr(test_str, test_str1, 90);
	printf("found in position: %li\n", aux - test_str);
	memcpy(test_str1, "dolore", 10);
	printf(" Big string: %s, Little string: %s,\n", test_str, test_str1);
	aux = ft_strnstr(test_str, test_str1, 90);
	printf("found in position: %li\n", aux - test_str);

}
void	test_atoi()
{
	printf("\n\n*** atoi() ***\n");
	printf("string: %s\n", "0");
	printf("integer: %i\n\n", atoi("0"));
	printf("string: %s\n", "451");
	printf("integer: %i\n\n", atoi("451"));
	printf("string: %s\n", "-99");
	printf("integer: %i\n\n", atoi("-99"));
	printf("string: %s\n", "gfh");
	printf("integer: %i\n\n", atoi("gfh"));
	printf("string: %s\n", "-gfh8");
	printf("integer: %i\n\n", atoi("-gfh8"));
	printf("string: %s\n", "-76gfh8");
	printf("integer: %i\n\n", atoi("-76gfh8"));
	printf("string: %s\n", "--76gfh8");
	printf("integer: %i\n\n", atoi("--76gfh8"));

	printf("\n\n*** ft_atoi() ***\n");
	printf("string: %s\n", "0");
	printf("integer: %i\n\n", ft_atoi("0"));
	printf("string: %s\n", "451");
	printf("integer: %i\n\n", ft_atoi("451"));
	printf("string: %s\n", "-99");
	printf("integer: %i\n\n", ft_atoi("-99"));
	printf("string: %s\n", "gfh");
	printf("integer: %i\n\n", ft_atoi("gfh"));
	printf("string: %s\n", "-gfh8");
	printf("integer: %i\n\n", ft_atoi("-gfh8"));
	printf("string: %s\n", "-76gfh8");
	printf("integer: %i\n\n", ft_atoi("-76gfh8"));
	printf("string: %s\n", "--76gfh8");
	printf("integer: %i\n\n", ft_atoi("--76gfh8"));

}
test_calloc()
{

}
test_strdup()
{

}
void	test_substr()
{

}
void	test_strjoin()
{

}
void	test_strtrim()
{

}
void	test_split()
{
        char **words;
		int	i;

		i = 0;
        words = ft_split("  lorem     ipsum dolor   sit, a met", ' ');
		while (words[i++])
        	printf("Word[%i] = %s\n", i, words[i]);
        i = 0;
		while (words[i++])
        	free(words[i]);
        free(words);

}
void	test_itoa()
{

}
void	test_strmapi()
{

}
void	test_strteri()
{

}
void	test_putchar_fd()
{

}
void	test_putstr_fd()
{

}
void	test_putendl_fd()
{

}
void	test_putnbr_fd()
{
	
}
