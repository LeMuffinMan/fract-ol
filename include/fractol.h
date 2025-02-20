/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:31:56 by oelleaum          #+#    #+#             */
/*   Updated: 2025/01/21 12:31:07 by oelleaum         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx-linux/mlx.h"
# include <float.h>

// a virer
// # define pi 3.141592653589793
# define LDMIN LDBL_MIN
// pas mettre de define et include uniquement ou j'ai besoin

# define MAX_I 200
# define MIN_I 50

# define WIN_X 17

// keyboard inputs
# define ESC 65307
# define PLUS 65451
# define MINUS 65453

// Mouse inputs
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5
# define MOUSE_WHEEL_CLICK 2
# define MOUSE_L 1
# define MOUSE_R 3

// Window datas // mettre une seule variable
# define WINSIZE 800

# define BLACK 0x000000

typedef struct s_img
{
	void				*img_p;
	char				*pixels;
	int					bpp;
	int					endian;
	int					line_len;
}						t_img;

typedef struct s_mlx
{
	void				*mlx;
	void				*win;
	t_img				img;
}						t_mlx;

// renommer en real et imaginary ?
typedef struct s_coords
{
	double x; // real
	double y; // imaginary
}						t_coords;

typedef struct s_data
{
	t_mlx				mlx;
	t_coords			shift_view;
	t_coords			julia_constant;
	t_coords z; // des mots, en anglais pour la norme
	t_coords			c;
	int					fractal_number;
	double				escape_value;
	double				max_iterations;
	double				zoom;
}						t_data;

typedef union u_color
{
	unsigned int color; // type de 32b
	struct
	{
		unsigned char b; // 8 bits
		unsigned char	g;
		unsigned char	r;
		unsigned char	a;
	};
}						t_color;

// a classer ou virer : dans utils ?
int						quit(t_data *f);

// check_input.c
void					param_error(void);
void					check_input(int ac, char **av, t_data *f);
void					get_coords(int ac, char **av, t_data *f,
							int *check_double);
double					get_double(char *s, int sign, int *max_digits);
double					atodbl(char *s, int *max_digits);

// check_input_utils.c la libft ?
int						skip_spaces(char *s, int *sign, int *max_digits);

// init.c
int						init_data(t_data *f);
int						init_win(t_data *f);

// inputs.c
int						kb_inputs(int key, t_data *f);
int						mouse_inputs(int key, int x, int y, t_data *f);

// render_fractal.c
void					iterate_on_pixels(t_data *f);
void					render_fractal(int x, int y, t_data *f);
void					colorize_pixel(int x, int y, t_img *img, int color);
void					set_complexes(int x, int y, t_data *f);
void					bit_shift_rgb(int i, int *color, t_data *f);
double					scale(double unscaled_num, double new_min,
							double new_max, double old_min, double old_max);

#endif
