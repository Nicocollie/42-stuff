#ifndef GRIMLY_H
# define GRIMLY_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct      s_puzzle
{
    int             rows;
    int             cols;
    char            header[5];
    char            **body;
}                   t_puzzle;

// grimly
char                *ft_readsdin(void);
char                *ft_readfile(char *file);

// grimly2
char        *setheader(t_puzzle **pz, char *buf, int *counter);
int         showerror(void);

// verify
int                 ft_verify(char *str, int counter, int i, int line_n);
t_puzzle            *create_puzzle(void);



#endif
