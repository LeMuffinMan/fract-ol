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

# define MAX_I 100
# define MIN_I 20

# define WIN_X 17

// keyboard inputs
# define ESC 65307
# define PLUS 65451
# define MINUS 65453
# define LEFT 65361
# define RIGHT 65363
# define UP 65362
# define DOWN 65364
# define ENTER 65293 // mettre click souris a la place
# define NUM_ENTER 65421
# define SWITCH1 109
# define SWITCH2 106
# define SWITCH3 98
# define SWITCH4 116
# define R 114
# define G 103
# define B 98
# define E 101
# define P 112
# define D 100
# define SPACE 32
# define BACKSPACE 65288
# define CTRL_L 65507
# define ALT_L 65513
# define SHIFT 65505

// Mouse inputs
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5
# define MOUSE_WHEEL_CLICK 2
# define MOUSE_L 1
# define MOUSE_R 3

// Window datas // mettre une seule variable
# define WINSIZE 800

// A virer en fonction de comment on gere les couleurs
# define PALETTE_SIZE 20
# define BLACK 0x000000
// # define WHITE 0xFFFFFF

// 1 mandel
// 2 julia
// 3 bruning
// 4 tricorn
// 5 julia burning ship
// 6 julia tricorn
// 7 multibrot
// 8 julia multibrot
// 9 perpendicular burning ship // a virer partout

// structures
// mlx-img
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
	t_coords			mouse;
	t_coords z; // des mots, en anglais pour la norme
	t_coords			c;
	int					fractal_number;
	double				escape_value;
	double				max_iterations;
	int					switch_iterations;
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

// a classer ou virer
int						quit(t_data *f);

// check_input.c
void					param_error(void);
void					check_julia_input(int ac, char **av, t_data *f,
							int *check_double);
void					check_input(int ac, char **av, t_data *f);

// check_input_utils.c
void					get_coords(int ac, char **av, t_data *f,
							int *check_double);
double					atodbl(char *s, int *max_digits);
double					get_double(char *s, int sign, int *max_digits);
int						skip_spaces(char *s, int *sign, int *max_digits);

// color.c
void					colorize_pixel(int x, int y, t_img *img, int color);

// color_switch.c
void					color_shift(int key, t_data *f);

// init.c
int						init_data(t_data *f);
int						init_win(t_data *f);

// kb_inputs.c
int						kb_inputs(int key, t_data *f);

// mouse_inputs.c
int						mouse_inputs(int key, int x, int y, t_data *f);

// wheel_zoom.c
void					wheel_zoom(int key, int x, int y, t_data *f);

// maths.c
double					norm_complex(t_coords z);
t_coords				sum_complex(t_coords z1, t_coords z2);
t_coords				square_complex(t_coords z);
double					scale(double unscaled_num, double new_min,
							double new_max, double old_min, double old_max);

// render_fractal.c
void					iterate_on_pixels(t_data *f);
void					render_fractal(int x, int y, t_data *f);

// libft
int						ft_strcmp(const char *s1, const char *s2);

#endif
