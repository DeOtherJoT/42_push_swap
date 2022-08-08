#include "../../includes/push_swap.h"

size_t	ft_elem_index(int *src, int elem)
{
	size_t	x;

	x = 0;
	while (src[x] != elem)
		x++;
	return (x);
}

/*
Function that finds a specific element in a stack and moves it to the other
stack with the lowest number of operations. It decides this by seeing how
far the element is from the beginning of the stack and compares it with
how far it is from the end of the stack.
*/

void	move_elem_a(t_stacks *stacks, int elem)
{
	size_t	x;

	x = ft_elem_index(stacks->stack_a, elem);
	if (x <= ((stacks->len_a - 1) - x))
	{
		while (x > 0)
		{
			ft_exec_op(stacks, "ra", op_ra);
			x--;
		}
		ft_exec_op(stacks, "pb", op_pb);
	}
	else
	{
		x = (stacks->len_a - 1) - x;
		while (x > 0)
		{
			ft_exec_op(stacks, "rra", op_rra);
			x--;
		}
		ft_exec_op(stacks, "pb", op_pb); 
	}
}