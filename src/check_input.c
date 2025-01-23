//HEADER
//

#include <stdio.h>
#include <stdlib.h>
#include "../include/fractol.h"

int skip_spaces(char *s, int *sign, int *max_digits)
{
	int i;

	i = 0;
	while (s[i] <= 32 || s[i] == '+') //on avance tant qu'on n'a pas de digit ou de -
		i++;
	if (s[i] == '-') //on prend le moins si jamais
	{
		if (*sign == 1)
			*sign = -1;
		else 
			(*max_digits = -1);
		i++;
	}
	return (i);
}

double get_double(char *s, int sign, int *max_digits)
{
  int i;
  double res1;
	double res2;
	double factor;

  factor = 1.0;
	res1 = 0;
	res2 = 0;
  i = 0;
	while (s[i] < '0' || s[i] > '9')
		i++;
	while (s[i] >= '0' && s[i] <= '9' && (*max_digits)-- > 0)
		res1 = res1 * 10 + s[i++] - '0';
	if (s[i++] == '.')
	{
		while (s[i] >= '0' && s[i] <= '9' && (*max_digits)-- > 0)
		{
			res2 = res2 * 10 + s[i++] - '0';
			factor *= 10;
		}
	}
	res1 = (res1 + res2 / factor) * sign;
	return (res1);
}

double atodbl(char *s, int *max_digits)
{
	int i;
	int dot;
	int sign;

	sign = 1;
	dot = 0;
	i = skip_spaces(s, &sign, max_digits); 
	while (s[i++])
	{
		if (s[i] < '0' && s[i] > '9' && s[i] != '.' && s[i] != '+' && s[i] != '-') //n'importe quel autre char donne une erreur
			*max_digits = -1;
		if (s[i] == '.')
		{
			if (dot > 0 || s[i - 1] > '9' || s[i - 1] < '0')
				*max_digits = -1;
			else 
				dot++;
		}
	}
	if (*max_digits >= 0)
	  return(get_double(s, sign, max_digits)); 
	else 
		printf("Coordinates incorrect\n"); // a revoir 
	return (0.0);
}


void param_error()
{
    printf("=========================================\n");
    printf("||          Incorrect input !          ||\n");
    printf("||-------------------------------------||\n");
    printf("||  ./fractol <set_name>               ||\n");
    printf("||  ./fractol julia <x> <y>            ||\n");
    printf("||                                     ||\n");
    printf("||-----------------SETS----------------||\n");
    printf("||   mandelbrot     ||      julia      ||\n");
    printf("||   burning_ship   ||      tricorn    ||\n");
    printf("=========================================\n");
  exit (1);
}

void check_input(int ac, char **av, t_fractal *f)
{
	int check_double;

	check_double = 15;
		if (ac == 1 || ac > 4)
			param_error();
		if (ft_strcmp(av[1], "mandelbrot") == 0 && ac == 2)
			f->fractal_number = 1;
		else if (ft_strcmp(av[1], "burning_ship") == 0 && ac == 2)
			f->fractal_number = 3;
		else if (ft_strcmp(av[1], "tricorn") == 0 && ac == 2)
			f->fractal_number = 4;
		else if (ft_strcmp(av[1], "multibrot") == 0 && ac == 2)
			f->fractal_number = 7;
		else if (ft_strcmp(av[1], "julia_mandel") == 0 && (ac == 2 || ac == 4))
		{
			if (ac == 4)
			{
				f->j_x = atodbl(av[2], &check_double);
				f->j_y = atodbl(av[3], &check_double);
			}
			f->fractal_number = 2;
		}
		else if (ft_strcmp(av[1], "julia_ship") == 0 && (ac == 2 || ac == 4))
		{
			if (ac == 4)
			{
				f->j_x = atodbl(av[2], &check_double);
				f->j_y = atodbl(av[3], &check_double);
			}
			f->fractal_number = 5;
		}
		else 
			param_error();
	}
