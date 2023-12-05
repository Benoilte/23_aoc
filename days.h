/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   days.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:48:16 by bebrandt          #+#    #+#             */
/*   Updated: 2023/12/05 07:37:28 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DAYS_H
# define DAYS_H

# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "printf/ft_printf.h"

void	day_01(void);
void	day_02(void);
void	day_03(void);
void	day_04(void);
void	day_05(void);
void	day_06(void);
void	day_07(void);
void	day_08(void);
void	day_09(void);
void	day_10(void);
void	day_11(void);
void	day_12(void);
void	day_13(void);
void	day_14(void);
void	day_15(void);
void	day_16(void);
void	day_17(void);
void	day_18(void);
void	day_19(void);
void	day_20(void);
void	day_21(void);
void	day_22(void);
void	day_23(void);
void	day_24(void);
void	day_25(void);

//get input function

t_list	*from_txt_to_struct_of_int(int fd);
t_list	*from_txt_to_struct_of_str(int fd);
int		*from_txt_to_array_of_int(int fd, int size);
char	**from_txt_to_array_of_str(int fd, int size);
int		count_line(int fd);
int		*get_int_ptr(int value);

//daily function

void	*copy(void *content);
int		power_of_two(int n);
int		ft_get_digit(const char *s, int *j);
int		ft_sum(int *num, int size);

// safe free function

void	del(void *content);
void	free_array(char **array, int size);

// error function

int		file_not_exist(void);

// display function

void	display_struct(t_list *lst, char data, char *text);
void	display_str_array(char **tab, char *text);
void	display_int_array(int *tab, int size, char *text);

// day 03 utils - lst
int		is_sym(char c);
int		is_star(char c);
int		*set_xy(int x, int y);
char	*convert_xy_to_str(int x, int y);

typedef struct s_ord
{
	char			*ord;
	int				p_num_1;
	int				p_num_2;
	struct s_ord	*next;
}		t_ord;

void	lstord_iter(t_ord **lst, char *xy, int p_num);
t_ord	*lstord_new(char *xy, int p_num);
void	lstord_addback(t_ord **lst, t_ord *new);
void	lstord_add_pnum(t_ord *lst, int p_num);
int		gear_ratio(t_ord *lst);

// day 04 utils

char	**parse_win_num(char *str);
char	**parse_my_num(char *str);
void	add_copy(int i, int n, int *copy, int size);

// day 05 utils

void	set_map_str(t_list *map, int fd);

#endif
