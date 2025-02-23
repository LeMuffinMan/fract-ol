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

# define LDMIN LDBL_MIN

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

typedef struct s_coords
{
	double				x;
	double				y;
}						t_coords;

typedef struct s_data
{
	t_mlx				mlx;
	t_coords			shift_view;
	t_coords			julia_constant;
	t_coords			z;
	t_coords			c;
	int					fractal_number;
	double				escape_value;
	double				max_iterations;
	double				zoom;
}						t_data;

typedef union u_color
{
	unsigned int		color;
	struct
	{
		unsigned char	b;
		unsigned char	g;
		unsigned char	r;
		unsigned char	a;
	};
}						t_color;

// check_input.c
void					check_input(int ac, char **av, t_data *f);

// check_input_utils.c
int						check_format(char *s);
int						skip_spaces(char *s, int *sign, int *max_digits);

// init.c
int						init_data(t_data *f);
int						init_win(t_data *f);
int						quit(t_data *f);

// inputs.c
int						kb_inputs(int key, t_data *f);
int						mouse_inputs(int key, int x, int y, t_data *f);

// render_fractal.c
void					render_fractal(t_data *f);

#endif
