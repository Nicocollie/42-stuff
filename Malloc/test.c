#include "header.h"
#include "structs.h"
#include "libft.h"

int main(void)
{
	char *tmp = malloc(150);	//make 81 take 2
	char *tmp3 = malloc(3000);	//make 81 take 2
	// char *tmp2;	//make 81 take 2
	// print_mem(NULL);
	// *tmp2 = 'A';
	// int n = -1;
	// while (++n < 100)
	// {
	// 	tmp2 = malloc(80);
	// 	memset(tmp2, 'A', 80);
	// 	// cycle_mem();
	// }
	// print_mem(1);
	// tmp = malloc(10000);
	// tmp = realloc(tmp, 130);

	show_alloc_mem();
	// char *tmp3 = malloc(80);	//make 81 take 2
	// cycle_mem();
	// free(tmp3);
	// tmp = realloc(tmp, 150);
	// print_mem(container.tiny);
	// tmp3 = malloc(80);	//make 81 take 2
	// tmp3 = malloc(250);	//make 81 take 2
	// tmp = malloc(600);	//make 81 take 2
	// tmp3 = malloc(802);	//make 81 take 2
	// tmp3 = malloc(8020);	//make 81 take 2
	// tmp3 = malloc(21120);	//make 81 take 2
	// tmp2 = malloc(4230);	//make 81 take 2
	// free(tmp);
	// free(tmp3);
	// for (int n = 0; n < 100; n++)
	// {
	// 	tmp = malloc(80);
	// 	cycle_mem();
	}


// 	// tmp = malloc(4097);	//make 81 take 2

// 	// free(tmp);
// 	// free((tmp - 200));
// 	// free((tmp + 9000));

// 	// tmp = malloc(400);	//make 81 take 2
// 	// tmp = malloc(1024);	//make 81 take 2
// 	// tmp = malloc(4000);	//make 81 take 2
// 	// char *tmp = malloc(8192);	//make 81 take 2
// 	// tmp = malloc(8193);	//make 81 take 2
// 	// char *tmp2 = malloc(6500);	//make 81 take 2
// 	// tmp = malloc(6500);	//make 81 take 2
// 	// cycle_mem();
// 	// free(tmp2);
// 	// tmp = malloc(9000);	//make 81 take 2
// 	// tmp = malloc(123123);	//make 81 take 2

// 	// for (int n = 0; n < 80; n++)
// 	// 	tmp[n] = 'A';
// 	// print_header(container.small);
// 	show_alloc_mem();
// }

// int main(void)
// {
// 	int i;

// 	char *addr;
// 	i = 0;
// 	while (i < 1024)
// 	{
// 		i++;
// 	}
// 	return (0);
// }

// int main(void)
// {
// 	int i;

// 	char *addr;
// 	i = 0;
// 	while (i < 1024)
// 	{
// 		addr = malloc(400);
// 		addr[0] = 42;
// 		i++;
// 	}
// 	return (0);
// }

// int main(void)
// {
// 	int i;

// 	char *addr;
// 	i = 0;
// 	while (i < 1024)
// 	{
// 		addr = malloc(400);
// 		addr[0] = 42;
// 		free(addr);
// 		i++;
// 	}
// 	return (0);
// }

// void print(char *a)
// {
// 	write(1, a, strlen(a));
// }

// int main(void)
// {
// 	int i;

// 	char *addr;
// 	i = 0;
// 	while (i < 1024)
// 	{
// 		addr = malloc(400);
// 		addr[0] = 42;
// 		free(addr);
// 		i++;
// 	}
// 	return (0);
// }