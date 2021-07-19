#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
void	ft_putchar(char c, int *len)
{
	(*len)++;
	write(1, &c, 1);
}

void	ft_putnbr_len(long n, unsigned long radix, int *len, char flag)
{
	unsigned long	ans;
	if (n < 0)
	{
		ft_putchar('-', len);
		ans = (unsigned long)(n * -1);
	}
	else
		ans = (unsigned long)n;
	if (ans >= radix)
		ft_putnbr_len(ans / radix, radix, len, flag);
	if ((ans % radix) >= 10 && flag == 'x')
		ft_putchar((ans % radix) - 10 + 'a', len);
	else if ((ans % radix) >= 10 && flag == 'X')//ここで'%X'に対応
		ft_putchar((ans % radix) - 10 + 'A', len);
	else
		ft_putchar((ans % radix + '0'), len);
	return ;
}

// void	ft_putnbr_len_X(long n, unsigned long radix, int *len)
// {
// 	unsigned long	ans;

// 	if (n < 0)
// 	{
// 		ft_putchar('-', len);
// 		ans = (unsigned int)(n * -1);
// 	}
// 	else
// 	{
// 		ans = (unsigned int)n;
// 	}
// 	if (ans >= radix)
// 	{
// 		ft_putnbr_len_X(ans / radix, radix, len);
// 	}
// 	if ((ans % radix) >= 10)
// 		ft_putchar((ans % radix) - 10 + 'A', len);
// 	else
// 		ft_putchar((ans % radix + '0'), len);
// 	return ;
// }

void	ft_diuxXp_output(va_list *args, int *len, char *s)
{
	if (*s == 'd' || *s == 'i')
		ft_putnbr_len(va_arg(*args, int), 10, len, 'x');
	else if (*s == 'u')
		ft_putnbr_len(va_arg(*args, unsigned int), 10, len, 'x');
	else if (*s == 'x')
		ft_putnbr_len(va_arg(*args, unsigned int), 16, len, 'x');//引数を足した
	else if (*s == 'X')
		ft_putnbr_len(va_arg(*args, unsigned int), 16, len, 'X');//
	else if (*s == 'p')
	{
		ft_putchar('0', len);
		ft_putchar('x', len);
		ft_putnbr_len(va_arg(*args, unsigned long), 16, len, 'x');
	}
	else if (*s == '%')
		ft_putchar('%', len);
	return ;
}
void ft_put_s(char *point_s, int *len)
{
	if (point_s == NULL){//アドレス値とNULLを比較
		ft_putchar('(', len);
		ft_putchar('n', len);
		ft_putchar('u', len);
		ft_putchar('l', len);
		ft_putchar('l', len);
		ft_putchar(')', len);
	}
	while (point_s != NULL && *point_s != '\0')//ここでpoint_s != NULLを*point_s != '\0'の後ろに置くとセグフォになるが、前だと機能する。
		ft_putchar(*point_s++, len);
	return ;
}

int	ft_printf(const char *s, ...)
{
	int		len;
	va_list	args;
	char	*point_s;

	len = 0;
	va_start(args, s);
	while (*s != '\0')
		if (*s != '%')
			ft_putchar(*s++, &len);
	else if (*s++ == '%')
	{
		if (*s == 'c')
			ft_putchar((unsigned char)va_arg(args, int), &len);
		else if (*s == 's')
		{
			point_s = va_arg(args, char *);//point_sはアドレス値
			ft_put_s(point_s, &len);
			// if (point_s == NULL)//アドレス値とNULLを比較
			// 	ft_put_null(&len);
			// while (point_s != NULL && *point_s != '\0')//ここでセグフォしてしまう//ここでpoint_s != NULLを*point_s != '\0'の後ろに置くとセグフォになるが、前だと機能する。
			// 	ft_putchar(*point_s++, &len);
		}
		else
			ft_diuxXp_output(&args, &len, (char *)s);
		s++;
	}
	va_end(args);
	return (len);
}
