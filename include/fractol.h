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
# define WINSIZE_X 800
# define WINSIZE_Y 800

// A virer en fonction de comment on gere les couleurs
# define PALETTE_SIZE 20
# define BLACK 0x000000
// # define WHITE 0xFFFFFF

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
// une structure commune pour toutes les coordonnees
// une structure math ?
// une structure flags / switch ?
// une structure zoom ?
// structure bind combo
// une structure tmp
typedef struct s_fractal
{
	t_mlx				mlx;
	int					fractal_number;
	double				escape_value;
	long double			max_iterations;
	int					switch_iterations;
	long double shift_x; // struct coords
	long double shift_y; // struct coords
	long double j_x;     // struct coords
	long double j_y;     // struct coords
	long double mouse_x; // struct coords
	long double mouse_y; // struct coords
	long double			mu;
	double				power;
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
	int zooming_out_x; // structure coords dans structure zoom ?
	int					zooming_out_y;
	int					bind_combo_shift;
	int					bind_combo_ctrl_l;
	int					bind_combo_alt_l;
	long double tmp_shift_x; // structure tmp
	long double			tmp_shift_y;
	long double			tmp_zoom;
	int					tmp_fractal_number;
	int psychedelic_colors; // renommer et regrouper dans une struct ?
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

// a classer ou virer
int						quit(t_fractal *f);

// animations.c
void					animated_zoom_out(int x, int y, t_fractal *f);
void					animated_zoom_in(t_fractal *f);
void					animated_zoom(int key, int x, int y, t_fractal *f);
int						update_animations(t_fractal *f);

// animations_utils.c
int						get_mouse_coords(int x, int y, t_fractal *f);
void					dynamic_iterations(t_fractal *f);
void					wheel_set_arrival(t_fractal *f);
void					wheel_set_origin(t_fractal *f);
void					set_animated_zoom_out(int x, int y, t_fractal *f);

// check_input.c
void					param_error(void);
void					check_julia_input(int ac, char **av, t_fractal *f,
							int *check_double);
void					check_input(int ac, char **av, t_fractal *f);

// check_input_utils.c
void					get_coords(int ac, char **av, t_fractal *f,
							int *check_double);
double					atodbl(char *s, int *max_digits);
double					get_double(char *s, int sign, int *max_digits);
int						skip_spaces(char *s, int *sign, int *max_digits);

// color.c
int						generate_smooth_color(int iteration, double mu,
							int max_iterations, t_palette *palette);
void					colorize_pixel(int x, int y, t_img *img, int color);

// color_switch.c
void					switch_red(t_fractal *f);
void					switch_green(t_fractal *f);
void					switch_blue(t_fractal *f);
void					color_shift(int key, t_fractal *f);

// switch_palette.c
void					switch_prev_palette(t_fractal *f);
void					switch_next_palette(t_fractal *f);
void					switch_palette(int key, t_fractal *f);

// init.c
int						init_fractal(t_fractal *f);

// init_palette.c
void					palette_init(t_palette *palette);
void					init_palette_r(int palette_R[20]);
void					init_palette_g(int palette_G[20]);
void					init_palette_b(int palette_B[20]);

// init_utils_1.c
void					init_index(t_fractal *f);
void					init_switch(t_fractal *f);
void					init_limits(t_fractal *f);
void					init_coords(t_fractal *f);
void					init_anims(t_fractal *f);

// init_utils_2.c
void					init_flag(t_fractal *f);
void					init_pov(t_fractal *f);
void					init_tmp(t_fractal *f);
int						init_win(t_fractal *f);

// kb_anumations.c
void					animation_speed_keys(int key, t_fractal *f);
void					space_pause(int key, t_fractal *f);

// kb_inputs.c
int						arrows(int key, t_fractal *f);
void					combo_keys(int key, t_fractal *f);
int						shift_toggle(int key, t_fractal *f);
int						kb_inputs(int key, t_fractal *f);

// kb_julia.c // renommer fichier et fonctions
void					julia_moves(int key, t_fractal *f);
void					set_origin(t_fractal *f);
void					set_arrival(t_fractal *f);
void					julia_constant_selector(int key, t_fractal *f);

// pav_num.c
int						pav_num_enter(int key, t_fractal *f);
int						pav_num_operators(int key, t_fractal *f);

// kb_switch.c
void					debug_switch(int key, t_fractal *f);
void					psyche_switch(int key, t_fractal *f);
void					num_fractal_switch(int key, t_fractal *f);
void					multibrot_power_switch(int key, t_fractal *f);
void					backspace_switch(int key, t_fractal *f);

// mouse_inputs.c
void					wheel(int key, int x, int y, t_fractal *f);
void					clicks_combo(int key, t_fractal *f);
void					clicks(int key, int x, int y, t_fractal *f);
int						mouse_inputs(int key, int x, int y, t_fractal *f);

// wheel_zoom.c
void					wheel_zoom_out(int key, int x, int y, t_fractal *f);
void					wheel_zoom_in(int key, int x, int y, t_fractal *f);
void					wheel_zoom(int key, int x, int y, t_fractal *f);

// wheel_combo.c
void					wheel_combo(int key, t_fractal *f);
void					wheel_combo_down(t_fractal *f);
void					wheel_combo_up(t_fractal *f);

// calculate_fractal.c
void					burning_ship(t_fractal *f);
void					tricorn(t_fractal *f);
void					multibrot(t_fractal *f);
void					calculate_f(t_fractal *f);

// maths.c
double					norm_complex(t_complex z);
t_complex				sum_complex(t_complex z1, t_complex z2);
t_complex				square_complex(t_complex z);
double					scale(double unscaled_num, double new_min,
							double new_max, double old_min, double old_max);
void					travel_between_fractals(t_fractal *f);

// render_fractal.c
void					set_complexes(int x, int y, t_fractal *f);
void					iterate_on_pixels(t_fractal *f);
void					render_fractal(int x, int y, t_fractal *f);

// libft
int						ft_strcmp(const char *s1, const char *s2);
int						mouse_inputs(int key, int x, int y, t_fractal *f);



#endif
