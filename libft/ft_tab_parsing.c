/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 17:21:35 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/04 22:23:19 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		print_menu_new_network(void)
{
	C_ORANGE
	ft_putstr("\t0  : Create vertices\n");
	ft_putstr("\t1  : Link vertices unidirectionnel\n");
	ft_putstr("\t2  : Link vertices bidirectionnel\n");
	ft_putstr("\t3  : Delete vertices\n");
	ft_putstr("\t4  : Delete edges\n");
	ft_putstr("\t5  : Link data to vertices\n");
	ft_putstr("\t6  : Save Network\n");
	C_RED
	ft_putstr("\t\\n : Back to main menu\n");
	C_BLUE
	ft_putstr("\tPlease enter your selection :\t");
	C_RESET
}

int		parsing_create_vertice(t_tab *god, int fd)
{
	char *instruction;

	C_ORANGE
	printf("Please name your new vetice\n");
	C_CYAN
	if (0 >= get_next_line(fd, &instruction))
	return (-1);
	C_RESET
	while (instruction[0] != '\0')
	{
		C_MAGENTA
		//printf("Here's the string: %s\n", instruction);
		C_RESET
		ft_tabnew_ptr(instruction, sizeof(instruction));
		ft_strdel(&instruction);
		C_ORANGE
		printf("Please name your new vetice\n");
		C_CYAN
		if (0 >= get_next_line(fd, &instruction))
			return (-1);
		C_RESET
	}
	return (1);
}

int		parsing_link_vertice(t_god *god, int choice)
{
	char	*ver_one;
	char	*ver_two;

	if (choice == 2)
	{
		//printf("%s\n", __func__);

		print_god_vert(god);
		C_YELLOW
		printf("Please choose 2 vertices\n");
		C_RESET
		C_CYAN
		if (0 >= get_next_line(0, &ver_one))
			return (-1);
		//printf("ver_one: |%s|\n", ver_one);
		if (0 >= get_next_line(0, &ver_two))
			return (-1);
		//printf("ver_two: |%s|\n", ver_two);
		C_RESET
		while (ver_one[0] != '\0' || ver_two[0] != '\0')
		{
			//printf("NUMBER CHOOSED : %s-%d & %s-%d\n", ver_one, atoi(ver_one), ver_two, atoi(ver_two));
			add_vers_in_edgs(god->ver[ft_atoi(ver_one)], god->ver[ft_atoi(ver_two)]);
			ft_strdel(&ver_one);
			ft_strdel(&ver_two);
			print_god_vert(god);
			C_CYAN
			if (0 >= get_next_line(0, &ver_one))
				return (-1);
			//printf("ver_one: |%s|\n", ver_one);
			if (0 >= get_next_line(0, &ver_two))
				return (-1);
			//printf("ver_two: |%s|\n", ver_two);
			C_RESET
		}
		return (1);
	}
	else if (choice == 1)
	{
		//printf("%s\n", __func__);

		print_god_vert(god);
		C_YELLOW
		printf("Please choose 2 vertices\n");
		C_RESET
		C_CYAN
		if (0 >= get_next_line(0, &ver_one))
			return (-1);
		//printf("ver_one: |%s|\n", ver_one);
		if (0 >= get_next_line(0, &ver_two))
			return (-1);
		//printf("ver_two: |%s|\n", ver_two);
		C_RESET
		while (ver_one[0] != '\0' || ver_two[0] != '\0')
		{
			//printf("NUMBER CHOOSED : %s-%d & %s-%d\n", ver_one, atoi(ver_one), ver_two, atoi(ver_two));
			add_ver_in_edg(god->ver[ft_atoi(ver_one)], god->ver[ft_atoi(ver_two)]);
			ft_strdel(&ver_one);
			ft_strdel(&ver_two);
			print_god_vert(god);
			C_CYAN
			if (0 >= get_next_line(0, &ver_one))
				return (-1);
			//printf("ver_one: |%s|\n", ver_one);
			if (0 >= get_next_line(0, &ver_two))
				return (-1);
			//printf("ver_two: |%s|\n", ver_two);
			C_RESET
		}
		return (1);
	}
	return (0);
}

int		parsing_new_network(t_tab *god, int fd)
{
	char *instructions;
	int choice;

	print_menu_new_network();
	C_CYAN
	if (-1 == get_next_line(fd, &instructions))
		return (-1);
	C_RESET
	while (instructions)
	{
		if (instructions[0] == '\0')
			return (0);
		choice = ft_atoi(instructions);
		if (choice == 0)
			parsing_create_vertice(god);
		else if (choice == 1)
			parsing_link_vertice(god, choice);
		else if (choice == 2)
			parsing_link_vertice(god, choice);
		else if (choice == 3)
			ft_putstr("This functionality hasn't been coded yet\n");
		else if (choice == 4)
			ft_putstr("_RED This functionality hasn't been coded yet\n");
		else if (choice == 5)
			ft_putstr("_RED This functionality hasn't been coded yet\n");
		else if (choice == 6)
			ft_putstr("_RED This functionality hasn't been coded yet\n");
		else
			ft_putstr("_RED Usage: please enter the number associated with your selection\n");
		ft_strdel(&instructions);
		print_menu_new_network();
		C_CYAN
		if (-1 == get_next_line(fd, &instructions))
		return (-1);
			C_RESET
	}
	return (0);
}

void		print_menu(void)
{
	C_ORANGE
	ft_putstr("0  : Load Network\n");
	ft_putstr("1  : New Network\n");
	C_RED
	ft_putstr("2  : Quit Program\n");
	C_BLUE
	ft_putstr("Please enter your selection :\t");
	C_RESET
}

void	print_welcome(void)
{
	CLEAR_SCREEN
	CURSOR_RESET
	C_YELLOW
	write(1, "\e[48;2;0;0;0m", ft_strlen("\e[48;2;0;0;0m"));
	ft_putstr("          _                 _               _                   _               _       _           _                _       _           _               _                _       _        _   \n");
	ft_putstr("         /\\ \\              /\\ \\            / /\\                /\\ \\            / /\\    / /\\        /\\ \\             / /\\    / /\\        /\\ \\            /\\ \\             /\\ \\    /\\ \\     /\\_\\ \n");
	ft_putstr("        /  \\ \\            /  \\ \\          / /  \\              /  \\ \\          / / /   / / /        \\_\\ \\           / / /   / / /       /  \\ \\          /  \\ \\           /  \\ \\   \\ \\ \\   / / / \n");
	ft_putstr("       / /\\ \\_\\          / /\\ \\ \\        / / /\\ \\            / /\\ \\ \\        / /_/   / / /         /\\__ \\         / /_/   / / /       / /\\ \\ \\        / /\\ \\ \\         / /\\ \\ \\   \\ \\ \\_/ / /  \n");
	ft_putstr("      / / /\\/_/         / / /\\ \\_\\      / / /\\ \\ \\          / / /\\ \\_\\      / /\\ \\__/ / /         / /_ \\ \\       / /\\ \\__/ / /       / / /\\ \\_\\      / / /\\ \\ \\       / / /\\ \\_\\   \\ \\___/ /   \n");
	ft_putstr("     / / / ______      / / /_/ / /     / / /  \\ \\ \\        / / /_/ / /     / /\\ \\___\\/ /         / / /\\ \\ \\     / /\\ \\___\\/ /       / /_/_ \\/_/     / / /  \\ \\_\\     / / /_/ / /    \\ \\ \\_/    \n");
	ft_putstr("    / / / /\\_____\\    / / /__\\/ /     / / /___/ /\\ \\      / / /__\\/ /     / / /\\/___/ /         / / /  \\/_/    / / /\\/___/ /       / /____/\\       / / /   / / /    / / /__\\/ /      \\ \\ \\     \n");
	ft_putstr("   / / /  \\/____ /   / / /_____/     / / /_____/ /\\ \\    / / /_____/     / / /   / / /         / / /          / / /   / / /       / /\\____\\/      / / /   / / /    / / /_____/        \\ \\ \\    \n");
	ft_putstr("  / / /_____/ / /   / / /\\ \\ \\      / /_________/\\ \\ \\  / / /           / / /   / / /         / / /          / / /   / / /       / / /______     / / /___/ / /    / / /\\ \\ \\           \\ \\ \\   \n");
	ft_putstr(" / / /______\\/ /   / / /  \\ \\ \\    / / /_       __\\ \\_\\/ / /           / / /   / / /         /_/ /          / / /   / / /       / / /_______\\   / / /____\\/ /    / / /  \\ \\ \\           \\ \\_\\  \n");
	ft_putstr("  /___________/    \\/_/    \\_\\/    \\_\\___\\     /____/_/\\/_/            \\/_/    \\/_/          \\_\\/           \\/_/    \\/_/        \\/__________/   \\/_________/     \\/_/    \\_\\/            \\/_/  \n");
	C_RESET
}

//int		parsing(t_tab *god)
int		ft_tab_parser(t_tab **god, int fd)
{
	int choice;
	char *instructions;

	print_welcome();
	print_menu();
	C_CYAN
	if (-1 == get_next_line(fd, &instructions))
		return (-1);
	C_RESET
	while (instructions)
	{
		choice = ft_atoi(instructions);
		if (choice == 0)
		{
			ft_putstr_color("This functionality hasn't been coded yet\n", 255, 0, 0);
		}
		else if (choice == 1)
			parsing_new_network(*god, fd);
		else if (choice == 2)
			return (1);
		ft_strdel(&instructions);
		print_menu();
		C_CYAN
		if (-1 == get_next_line(fd, &instructions))
			return (-1);
		C_RESET
	}
	return (1);
}

typedef struct		s_parser
{
	char			**instruction;
	int				(*f)(t_tab *, size_t, char*);
	int				fd;
}					t_parser;
