#include "ft_printf.h"

int		ft_c_padding_right(char c, t_flags *flags)
{
	int		i;
	char	*s;

	s = ft_calloc(flags->width + 1);
	if (!s)
		return (-1);
	i = 1;
	s[0] = c;
	while (i < flags->width)
		s[i++] = ' ';
	return (ft_putstr(s));
}

int		ft_c_padding_left(char c, t_flags *flags)
{
	int		i;
	char	*s;

	s = ft_calloc(flags->width + 1);
	if (!s)
		return (-1);
	i = 0;
	while (i < flags->width - 1)
		s[i++] = ' ';
	s[i] = c;
	return (ft_putstr(s));
}

int		ft_printf_c(char c, t_flags *flags)
{
	if (flags->width <= 1)
		return (ft_putchar(c));
	if (flags->minus)
		return (ft_c_padding_right(c , flags));
	return (ft_c_padding_left(c , flags));
}