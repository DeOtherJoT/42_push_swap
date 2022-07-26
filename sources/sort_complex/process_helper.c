/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 20:34:29 by jthor             #+#    #+#             */
/*   Updated: 2022/08/26 20:34:31 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
Depending on the processes, just cleans up the node to contain the correct
instructions to execute on stack_a and/or stack_b to arrange them in a
way that would place the element at the top of stack_b at the correct
spot in stack_a
	1 - execute rb and rra.
	2 - execute rr and either ra or rb.
	3 - execute ra and rrb.
	4 - execute rrr and either rra or rrb.
*/

void	process_one(t_data *ret)
{
	ret->do_ra = 0;
	ret->do_rr = 0;
	ret->do_rrr = 0;
	ret->total_moves = ret->do_rb + ret->do_rra;
}

void	process_two(t_data *ret)
{
	ret->do_rra = 0;
	ret->do_rrr = 0;
	ret->total_moves = ft_most(ret->do_rb, ret->do_ra);
	if (ret->do_rb == ret->total_moves)
	{
		ret->do_rb -= ret->do_ra;
		ret->do_rr = ret->do_ra;
		ret->do_ra = 0;
	}
	else
	{
		ret->do_ra -= ret->do_rb;
		ret->do_rr = ret->do_rb;
		ret->do_rb = 0;
	}
}

void	process_three(t_data *ret)
{
	ret->do_rra = 0;
	ret->do_rr = 0;
	ret->do_rrr = 0;
	ret->total_moves = ret->do_rrb + ret->do_ra;
}

void	process_four(t_data *ret)
{
	ret->do_ra = 0;
	ret->do_rr = 0;
	ret->total_moves = ft_most(ret->do_rrb, ret->do_rra);
	if (ret->do_rrb == ret->total_moves)
	{
		ret->do_rrb -= ret->do_rra;
		ret->do_rrr = ret->do_rra;
		ret->do_rra = 0;
	}
	else
	{
		ret->do_rra -= ret->do_rrb;
		ret->do_rrr = ret->do_rrb;
		ret->do_rrb = 0;
	}
}
