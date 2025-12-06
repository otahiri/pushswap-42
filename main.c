#include "ft_printf/ft_printf.h"
#include "push_swap.h"
int main()
{
	t_dlist *lst = new_list(1);
	add_back(&lst, new_list(2));
	add_back(&lst, new_list(3));
	add_back(&lst, new_list(4));
	add_back(&lst, new_list(5));
	add_back(&lst, new_list(6));
	add_back(&lst, new_list(7));
	add_back(&lst, new_list(8));
	add_back(&lst, new_list(9));
	add_back(&lst, new_list(10));
	add_back(&lst, new_list(11));
	add_back(&lst, new_list(12));
	add_back(&lst, new_list(13));
	rrotate_top_bottom(&lst);
	while (lst)
	{
		ft_printf("%d\n", lst->node->data);
		lst = lst->next;
	}
}
