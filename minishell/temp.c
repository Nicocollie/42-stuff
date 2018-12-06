//testing function
//b_printf("%s\n", ft_strjoin(ft_addchar(get_path("any"), '/'), argv[0]));  --V remove me
//*******VVVV remove

// void	print_paths(char **argv)
// {
// 	char	**data;
// 	int		n;
	
// 	(void)argv[0];
// 	data = ft_strsplit(ft_getenv_value("PATH"), ':');
// 	n = -1;
// 	while (data[++n])
// 		b_printf("%s\n", data[n]);
// 	ft_free(data, NULL);
// }




void ft_ft_getenv(char **argv)
{
	char *temp;

	if (argv && argv[1])
	{
		temp = ft_getenv_value(argv[1]);
		b_printf("%s\n", temp);
	}
	else
		b_printf("Sorry not sorry, bad env varaible \n");
}\



int		count_words(char *str)
{
	int n;
	n = 0;
	str = move_to_next_word(str);
	while (*str)
	{
		if (*str && *str != 9 && *str != 11 && *str != 32)
			n++;
		str = move_to_char_after_end_of_word(str);
		if (*str && *str == '"') // or .
		{
			;	
		}
		else
			str = move_to_next_word(str);

	}
}