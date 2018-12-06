#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct s_point
{
	int x;
	int y;
}	t_point;

typedef struct s_container 
{
	void *mlx_ptr;
	void *win_ptr;
	int color;
	t_point p1;
	t_point p2;
}	t_container;

typedef struct s_player_p
{
	float x;
	float y;
}	t_player_p;


typedef struct s_player
{
	t_player_p location;
	t_point normal;
	int fov;
	int height;
}	t_player;


typedef struct s_window_info
{
	void *mlx;
	void *window;
} t_window_info;

typedef struct s_line_info
{
	t_point p1;
	t_point p2;
	int rise;
	int run;
	float m;
	int adjust;
	int offset;
	int threshold;
	int thresholdInc;
	int delta;
	int y;
	int x;
	int color;
}	t_line_info;


#endif