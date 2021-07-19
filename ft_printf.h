#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <assert.h>

void	ft_putchar(char c, int *len);
void	ft_putnbr_len(long n, unsigned long radix, int *len, char flag);
void	ft_putnbr_len_X(long n, unsigned long raidx, int *len);
void	ft_diuxXp_output(va_list *args, int *len, char *s);
int		ft_printf(const char *s, ...);

#endif