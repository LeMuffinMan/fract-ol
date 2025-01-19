/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:31:56 by oelleaum          #+#    #+#             */
/*   Updated: 2025/01/16 19:46:15 by oelleaum         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx-linux/mlx.h"

// inputs
# define ESC 65307
# define WIN_X 17
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5
// # define MOUSE_BTN 1
# define PLUS 65451
# define MINUS 65453
# define LEFT 65361
# define RIGHT 65363
# define UP 65362
# define DOWN 65364

// Window
# define WINSIZE 1600

// //set space of representation
// # define X_MAX 3
// # define X_MIN -3
// # define Y_MAX -3
// # define Y_MIN 3

# define BLACK 0x000000
// # define WHITE 0xFFFFFF
//
# define PURE_GREEN 0x00FF00
# define PURE_BLUE 0x0000FF
// #define COLOR_1 0xFF00FF  // Magenta
// #define COLOR_2 0x00FFFF  // Cyan
// #define COLOR_3 0xFFFF00  // Yellow
// #define COLOR_4 0xFF6347  // Tomato Red
// #define COLOR_5 0x7FFF00  // Chartreuse Green
// #define COLOR_6 0x8A2BE2  // BlueViolet
// #define COLOR_7 0xFF1493  // DeepPink
// #define COLOR_8 0x00FF7F  // SpringGreen
// #define COLOR_9 0xFFD700  // Gold
// #define COLOR_10 0xFF4500 // OrangeRed
// #define COLOR_11 0x32CD32 // LimeGreen
// #define COLOR_12 0x00BFFF // DeepSkyBlue
// #define COLOR_13 0x8B008B // DarkMagenta
// #define COLOR_14 0xFF69B4 // HotPink
// #define COLOR_15 0xD2691E // Chocolate
// #define COLOR_16 0x4B0082 // Indigo

typedef struct s_img
{
	void	*img_p;
	char	*pixels;
	int		bpp;
	int		endian;
	int		line_len;
}			t_img;

typedef struct s_fractal
{
	void	*mlx;
	void	*win;
	t_img	img;
	double escape_value;
	int max_iterations;
	double	shift_x;
	double	shift_y;
	double	zoom;
}			t_fractal;

typedef struct s_complex
{
	double x; // real
	double y; // imaginary
}			t_complex;

// int			zoom_inputs(int key, int x, int y, t_fractal *f);
// int			move_inputs(int key, int x, int y, t_fractal *f);
// int			quit_inputs(int key, int x, int y, t_fractal *f);
// int	iterations_inputs(int key, t_fractal *f); // keyboard inputs
// int			quit_and_free(t_fractal *f);
// void		init(t_fractal *f);
// int			inputs(int key, t_fractal *f);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
void		mandelbrot_f(int x, int y, t_fractal *f);
void		iterate_on_pixels(t_fractal *f);
double		scale(double unscaled_num, double new_min, double new_max,
				double old_min, double old_max);
void		colorize_pixel(int x, int y, t_img *img, int color);
double	abs_complex(t_complex z);
// int			mouse_wheel_events(int keycode, int x, int y, t_fractal *f);
// int			zoom_inputs(int key, int x, int y, t_fractal *f);

#endif
