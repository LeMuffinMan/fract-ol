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
# define pi 3.141592653589793
# define LDMIN LDBL_MIN 
// mettre float.h pour mettre la limite des l double ?

// a implementer
# define MAX_I 100
# define MIN_I 20

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
# define SHIFT 65505
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
# define WIN_X 17
// define les switch de fractales

// Mouse inputs
# define MOUSE_WHEEL_UP 4   // zoom in
# define MOUSE_WHEEL_DOWN 5 // zoom out
# define MOUSE_WHEEL_CLICK 2
# define MOUSE_L 1
# define MOUSE_R 3

// Window datas // mettre une seule variable
# define WINSIZE_X 500
# define WINSIZE_Y 500

// A virer en fonction de comment on gere les couleurs
# define PALETTE_SIZE 20
# define BLACK 0x000000
# define WHITE 0xFFFFFF

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

// complex numbers
typedef struct s_complex
{
	long double x; // real
	long double y; // imaginary
}						t_complex;

// 1 mandel
// 2 julia
// 3 bruning
// 4 tricorn
// 5 julia burning ship
// 6 julia tricorn
// 7 multibrot
// 8 julia multibrot
// 9 perpendicular burning ship // a virer partout

// typedef struct s_tmp //on veut garder 2 tmp en memoire a chaque fois
// {
// 	double shift_x;
// 	double shift_y;
// 	double zoom;
// 	int 		fractal_number;
// } t_tmp;

// to divide : mlx win / fractal / pointofview
typedef struct s_mlx
{
	void				*mlx;
	void				*win;
	t_img				img;
}						t_mlx;

typedef struct s_palette
{
	int					n;
	int					palette_R[20];
	int					palette_G[20];
	int					palette_B[20];
	int					palettes[3][20];
}						t_palette;

// longueur max ?
// si non : diviser logiquement
typedef struct s_fractal
{
	t_mlx				mlx;
	int					fractal_number;
	double				escape_value;
	long double				max_iterations;
	int					switch_iterations;
	long double			shift_x;
	long double			shift_y;
	long double			j_x;
	long double			j_y;
	long double			mouse_x;
	long double			mouse_y;
	long double			mu;
	double power; // essayer des floats power
	int					origin;
	t_complex			z;
	t_complex			c;
	t_complex			o;
	t_complex			a;
	t_complex			d;
	double				t;
	double				tc;
	int					debug;
	int					traveling;
	long double			zoom;
	double				speed_factor;
	long double			zooming_out_start;
	long double			zooming_in_start;
	long double			max_iterations_start;
	int					zooming_in;
	int					zooming_out;
	int					zooming_out_x;
	int					zooming_out_y;
	int					bind_combo_shift;
	int					bind_combo_ctrl_l;
	int					bind_combo_alt_l;
	long double			tmp_shift_x;
	long double			tmp_shift_y;
	long double			tmp_zoom;
	int					tmp_fractal_number;
	int					psychedelic_colors;
	int					psyche_switch;
	int					red_toggle;
	int					green_toggle;
	int					blue_toggle;
	t_palette			palette;
}						t_fractal;

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

// functions in files
// a classer ou virer
void					set_mandelbrot(int x, int y, t_fractal *f);
int						quit(t_fractal *f);

// color.c
int						generate_smooth_color(int iteration, double mu,
							int max_iterations, t_palette *palette);
void					colorize_pixel(int x, int y, t_img *img, int color);
void 					palette_init(t_palette *palette);
void 					init_palette_R(int palette_R[20]);
void 					init_palette_G(int palette_G[20]);
void 					init_palette_B(int palette_B[20]);

// render_fractal.c
void					set_complexes(int x, int y, t_fractal *f);
void					iterate_on_pixels(t_fractal *f);
void					render_fractal(int x, int y, t_fractal *f);
double					scale(double unscaled_num, double new_min,
							double new_max, double old_min, double old_max);

// inputs.c
int						mouse_inputs(int key, int x, int y, t_fractal *f);
int						kb_inputs(int key, t_fractal *f);
int						shift_toggle(int key, t_fractal *f);
int						travel_update(void *param);

// init.c
int						init_win(t_fractal *f);
int						init_fractal(t_fractal *f);

// maths.c
double					norm_complex(t_complex z);
void					burning_ship(t_fractal *f);
void					tricorn(t_fractal *f);
void					multibrot(t_fractal *f);
void					calculate_f(t_fractal *f);
t_complex				sum_complex(t_complex z1, t_complex z2);
t_complex				square_complex(t_complex z);

// check_input.c
void					check_input(int ac, char **av, t_fractal *f);
void					param_error(void);
double					atodbl(char *s, int *max_digits);
double					get_double(char *s, int sign, int *max_digits);
int						skip_spaces(char *s, int *sign, int *max_digits);

// mouse_inputs.c
int						julia_dynamic(int x, int y, t_fractal *f);
void					travel_between_fractals(t_fractal *f);

// libft
int						ft_strcmp(const char *s1, const char *s2);
int						mouse_inputs(int key, int x, int y, t_fractal *f);

#endif
