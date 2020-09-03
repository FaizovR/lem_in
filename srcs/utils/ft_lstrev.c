#include "lem_in.h"

void ft_lstrev(t_list **list) {
	t_list *cur;
	t_list *prev;
	t_list *next;

	prev = NULL;
	cur = *list;
	while (cur != NULL)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	*list = prev;
}
