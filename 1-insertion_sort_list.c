#include "sort.h"
//test
/**
 * swap_nodes - swap 2 nodes in listint_t
 * @list: doubly linked list
 * @big: first element
 * @sml: second element
 */
void swap_nodes(listint_t **list, listint_t *big, listint_t *sml)
{
	listint_t *tmp;

	tmp = sml->next;
	if (big->prev)
		big->prev->next = sml;
	else
		*list = sml;
	if (sml->next)
		sml->next->prev = big;
	sml->next = big;
	sml->prev = big->prev;
	big->next = tmp;
	big->prev = sml;
}

/**
 * insertion_sort_list - sorts a listint_t using Insertion sort algorithm
 * @list: doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head;
	listint_t *tmp;

	if (!list || !*list || !(*list)->next)
		return;
	head = *list;
	while (head)
	{
		tmp = head->next;
		if (head->next && head->n > head->next->n)
		{
			head = head->next;
			while (tmp->prev && tmp->prev->n > tmp->n)
			{
				swap_nodes(list, tmp->prev, tmp);
				print_list(*list);
			}
		}
		else
			head = head->next;
	}
}
