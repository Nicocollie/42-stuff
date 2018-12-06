#ifndef HEADER_H
#define HEADER_H
#include "structs.h"

int get_dimensions(char *ch, t_maze_data *data);
int fill_data(char *ch, int n, t_maze_data *data);
int read_first_line_of_fd(t_maze_data *data);
void test_me(t_maze_data *data);
int stdin_maze();

int read_full_maze(t_maze_data *data);
int malloc_maze(t_maze_data *data);
int fill_maze(t_maze_data *data, char *buff);

int create_point(char c, t_maze_data *data);

void    print_map(t_maze_data *data);
#endif