/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day-07.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:05:11 by bebrandt          #+#    #+#             */
/*   Updated: 2023/12/07 14:39:24 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "days.h"

static t_hand	*ft_get_hand(t_list *input);
static int		ft_get_type(char *hand);
static int 		ft_get_strength_type(char *hand, int *card_strength, int size);
static int 		ft_compute_rank(t_hand *hand);
static void 	set_joker(int *card_strength, int size);

void	day_07(void)
{
	t_list	*input;
	t_hand 	*hand;
	t_hand 	*tmp;
	int			fd;
	char		*file;

	file = "input/day-07.txt";
	fd = open(file, O_RDONLY);
	input = from_txt_to_struct_of_str(fd);
	// display_struct(input, 's', "line");
	hand = ft_get_hand(input);
	tmp = hand;
	while (tmp)
	{
		// ft_printf("hand: %s - bid: %d - type: %d\n", tmp->hand, tmp->bid, tmp->type);
		tmp = tmp->next;
	}
	ft_printf("total winnings = %d\n", ft_compute_rank(hand));
	close(fd);
	// ft_printf("calibration : %d\n", calibration);
}

static t_hand	*ft_get_hand(t_list *input)
{
	t_list	*tmp;
	t_hand	*lst_hand;
	char	*hand;
	int		bid;
	int		type;
	int		i;

	tmp = input;
	lst_hand = NULL;
	while (tmp)
	{
		i = 6;
		hand = ft_substr(tmp->content, 0, 5);
		bid = ft_get_digit((tmp->content) + 6, &i);
		type = ft_get_type(hand);
		lsthand_addordered(&lst_hand, lsthand_new(hand, bid, type));
		tmp = tmp->next;
	}
	return (lst_hand);
}

/*
Five of a kind = 1
Four of a kind = 2
Full house = 3
Three of a kind = 4
Two pair = 5
One pair = 6
High card = 7
else = 8;
*/

static int	ft_get_type(char *hand)
{
	int		*card_strength;
	int		i;

	i = 0;
	card_strength = ft_calloc(13, sizeof(int));
	while (hand[i])
		card_strength[ft_cards_strength(hand[i++])] += 1;
	// ft_printf("result of your hand : %s\n", hand);
	// display_int_array(card_strength, 13, "card");
	return (ft_get_strength_type(hand, card_strength, 13));
}

static int ft_get_strength_type(char *hand, int *card_strength, int size)
{
	int i;

	ft_printf("card in our hand: %s\n", hand);
	display_int_array(card_strength, 13, "card");
	if (ft_strchr(hand, 'J'))
		set_joker(card_strength, size);
	else if (ft_check_high(hand))
		return (7);
	ft_printf("new hand\n");
	display_int_array(card_strength, 13, "card");
	i = 0;
	while (i < size)
	{
		if (card_strength[i] == 5)
			return (1);
		else if (card_strength[i] == 4)
			return (2);
		else if (card_strength[i] == 3)
			return (ft_check_full_house(card_strength, i + 1, size));
		else if (card_strength[i] == 2)
			return (ft_check_pairs_or_full(card_strength, i + 1, size));
		i++;
	}
	return (8);
}

/*
Five of a kind = 1
Four of a kind = 2
Full house = 3
Three of a kind = 4
Two pair = 5
One pair = 6
High card = 7
else = 8;
*/

static void set_joker(int *card_strength, int size)
{
	int i;
	int j;
	int count_1;

	i = 1;
	count_1 = 0;
	if (card_strength[0] == 5)
		return ;
	while (i < size)
	{
		if (card_strength[i] == 1)
			count_1++;
		i++;
	}
	if ((count_1 + card_strength[0]) == 5)
	{
		i = 1;
		while (i < size)
		{
			if (card_strength[i] == 1)
			{
				card_strength[i] += 1;
				card_strength[0] -= 1;
				break ;
			}
			i++;
		}
	}
	while (card_strength[0])
	{
		card_strength[0] -= 1;
		i = 1;
		while (i < size)
		{
			if (card_strength[i] == 4)
				card_strength[i] += 1;
			else if (card_strength[i] == 3)
				card_strength[i] += 1;
			else if (card_strength[i] == 2)
			{
				j = i;
				while (j < size)
				{
					if (card_strength[j] == 2)
					{
						card_strength[j] += 1;
						break ;
					}
					j++;
					ft_printf("j: %d\n", j);
				}
				if (j == size)
					card_strength[i] += 1;
				ft_printf("i: %d\n", i);
				// card_strength[0] -= 1;
				ft_printf("J: %d\n", card_strength[0]);
				break ;
			}
			i++;
		}
	}
}

static int ft_compute_rank(t_hand *hand)
{
	int		i;
	int		total;
	t_hand	*tmp;

	i = 1;
	tmp = hand;
	total = 0;
	while (tmp)
	{
		total += tmp->bid * i;
		ft_printf("hand: %s type: %d | bid * i = total (result) => %.3d * %.4d = %.6d (%.9d)\n", tmp->hand, tmp->type, tmp->bid, i, tmp->bid * i, total);
		i++;
		tmp = tmp->next;
	}
	return (total);
}
