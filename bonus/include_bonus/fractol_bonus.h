/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:31:56 by oelleaum          #+#    #+#             */
/*   Updated: 2025/02/22 10:53:04 by oelleaum         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# define LDMIN 1E-37

# define MAX_I 300
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
# define ENTER 65293
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

# define PALETTE_SIZE 20
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
	long double			x;
	long double			y;
}						t_coords;

typedef struct s_palette
{
	int					n;
	int					palette_r[20];
	int					palette_g[20];
	int					palette_b[20];
	int					palettes[3][20];
}						t_palette;

typedef struct s_tmp
{
	long double			shift_x;
	long double			shift_y;
	long double			zoom;
	int					fractal_number;

}						t_tmp;

typedef struct s_flags
{
	int					origin;
	int					zooming_in;
	int					zooming_out;
	int					bind_combo_shift;
	int					bind_combo_ctrl_l;
	int					bind_combo_alt_l;
	int					psychedelic_colors;
	int					psyche_switch;
	int					red_toggle;
	int					green_toggle;
	int					blue_toggle;
	int					traveling;
	int					fractal_switch;
	long double			zooming_out_start;
	long double			zooming_in_start;
}						t_flags;

typedef struct s_data
{
	t_mlx				mlx;
	t_coords			shift_view;
	t_coords			julia_constant;
	t_coords			mouse;
	t_coords			z;
	t_coords			c;
	t_coords			o;
	t_coords			a;
	t_coords			d;
	t_coords			zooming_out_coords;
	t_tmp				tmp;
	t_palette			palette;
	t_flags				flags;
	int					fractal_number;
	double				escape_value;
	long double			max_iterations;
	int					switch_iterations;
	long double			mu;
	double				power;
	double				t;
	double				tc;
	long double			zoom;
	double				speed_factor;
	long double			max_iterations_start;
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

// a classer ou virer
int						quit(t_data *f);
int						first_render(t_data *f);

// animations.c
void					animated_zoom_out(int x, int y, t_data *f);
void					animated_zoom_in(t_data *f);
void					animated_zoom(int key, int x, int y, t_data *f);
int						update_animations(t_data *f);

// animations_utils.c
int						get_mouse_coords(int x, int y, t_data *f);
void					dynamic_iterations(t_data *f);
void					wheel_set_arrival(t_data *f);
void					wheel_set_origin(t_data *f);
void					set_animated_zoom_out(int x, int y, t_data *f);

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
int						generate_smooth_color(int iteration, double mu,
							int max_iterations, t_palette *palette);
int						colorize_pixel(t_coords coords, t_data *f, int color,
							int i);

// color_switch.c
void					switch_red(t_data *f);
void					switch_green(t_data *f);
void					switch_blue(t_data *f);
void					color_shift(int key, t_data *f);

// switch_palette.c
void					switch_prev_palette(t_data *f);
void					switch_next_palette(t_data *f);
void					switch_palette(int key, t_data *f);

// init.c
int						init_data(t_data *f);

// init_palette.c
void					palette_init(t_palette *palette);
void					init_palette_r(int palette_R[20]);
void					init_palette_g(int palette_G[20]);
void					init_palette_b(int palette_B[20]);

// init_utils_1.c
void					init_index(t_data *f);
void					init_switch(t_data *f);
void					init_limits(t_data *f);
void					init_coords(t_data *f);
void					init_anims(t_data *f);

// init_utils_2.c
void					init_flag(t_data *f);
void					init_pov(t_data *f);
void					init_tmp(t_data *f);
int						init_win(t_data *f);

// kb_animations.c
void					animation_speed_keys(int key, t_data *f);
void					space_pause(int key, t_data *f);

// kb_inputs.c
int						arrows(int key, t_data *f);
void					combo_keys(int key, t_data *f);
int						shift_toggle(int key, t_data *f);
int						kb_inputs(int key, t_data *f);

// kb_julia.c // renommer fichier et fonctions
void					julia_moves(int key, t_data *f);
void					set_origin(t_data *f);
void					set_arrival(t_data *f);
void					julia_constant_selector(int key, t_data *f);

// pav_num.c
int						pav_num_enter(int key, t_data *f);
int						pav_num_operators(int key, t_data *f);

// kb_switch.c
void					psyche_switch(int key, t_data *f);
void					num_fractal_switch(int key, t_data *f);
void					multibrot_power_switch(int key, t_data *f);
void					backspace_switch(int key, t_data *f);

// mouse_inputs.c
void					wheel(int key, int x, int y, t_data *f);
void					clicks_combo(int key, t_data *f);
void					clicks(int key, int x, int y, t_data *f);
int						mouse_inputs(int key, int x, int y, t_data *f);

// wheel_zoom.c
void					wheel_zoom_out(int key, int x, int y, t_data *f);
void					wheel_zoom_in(int key, int x, int y, t_data *f);
void					wheel_zoom(int key, int x, int y, t_data *f);

// wheel_combo.c
void					wheel_combo(int key, t_data *f);
void					wheel_combo_down(t_data *f);
void					wheel_combo_up(t_data *f);

// calculate_fractal.c
void					burning_ship(t_data *f);
void					tricorn(t_data *f);
void					multibrot(t_data *f);
void					calculate_f(t_data *f);

// maths.c
double					norm_complex(t_coords z);
t_coords				sum_complex(t_coords z1, t_coords z2);
t_coords				square_complex(t_coords z);
double					scale(double unscaled_num, double new_min,
							double new_max, double old_max);
void					travel_between_fractals(t_data *f);

// render_fractal.c
void					set_coordses(int x, int y, t_data *f);
void					iterate_on_pixels(t_data *f);
void					render_fractal(int x, int y, t_data *f);

// libft
int						ft_strcmp(const char *s1, const char *s2);
int						mouse_inputs(int key, int x, int y, t_data *f);

#endif
