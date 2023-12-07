/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day-07-utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 07:16:40 by bebrandt          #+#    #+#             */
/*   Updated: 2023/12/07 10:30:57 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "days.h"

int	ft_check_full_house(int *card_strength, int j, int size)
{
	while (j < size)
	{
		if (card_strength[j] == 2)
			return (3);
		j++;
	}
	return (4);
}

int	ft_check_pairs_or_full(int *card_strength, int j, int size)
{
	while (j < size)
	{
		if (card_strength[j] == 3)
			return (3);
		if (card_strength[j] == 2)
			return (5);
		j++;
	}
	return (6);
}

// hand: 59678 - bid: 663 - type: 7
// hand: 8679T - bid: 27 - type: 7
// hand: JQAKT - bid: 799 - type: 7

int	ft_check_high(char *hand)
{
	int	i;

	i = 1;
	while (hand[i])
	{
		if (ft_cards_strength(hand[i - 1])  == ft_cards_strength(hand[i]) - 1)
			i++;
		else
			return (0);
	}
	return (1);
}

int ft_is_weaker(t_hand *new, t_hand *lst)
{
	int i;

	if (new->type < lst->type)
		return (0);
	else if (new->type > lst->type)
		return (1);
	else
	{
		i = 0;
		while ((new->hand)[i])
		{
			if (ft_cards_strength((new->hand)[i]) < ft_cards_strength((lst->hand)[i]))
				return (1);
			if (ft_cards_strength((new->hand)[i]) > ft_cards_strength((lst->hand)[i]))
				return (0);
			else
				i++;
		}
	}
	return (-1);
}

/*
Return the strength of the card, it correspond to the index of all cards
2 == index 0 and A == index 12
*/
int ft_cards_strength(char card)
{
	char 	*cards;
	int		i;

	cards = "J23456789TQKA";
	i = 0;
	while (cards[i])
	{
		if (cards[i] == card)
			return (i);
		i++;
	}
	return (-1);
}
