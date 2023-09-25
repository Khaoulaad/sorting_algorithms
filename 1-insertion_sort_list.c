#include "sort.h"
/**
 *swaping_node - swap a node for his previous one
 *@node: node
 *@list: node list
 *Return: return a pointer to a node which was enter it
 */
listint_t *swaping_node(listint_t *node, listint_t **list)
{
	listint_t *back = node->prev, *curr = node;
	

	back->next = curr->next;
	if (curr->next)
		curr->next->prev = back;
	curr->next = back;
	curr->prev = back->prev;
	back->prev = curr;
	if (curr->prev)
		curr->prev->next = curr;
	else
		*list = curr;
	return (curr);
}

/**
 * insertion_sort_list -  sorts a doubly linked list
 * in ascending order 
 * @list: Dobule linked list 
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node;

	if ((*list)->next == NULL ||list == NULL ||*list == NULL )
		return;
	node = (*list)->next;
	while (node)
	{
		while ((node->prev) && (node->prev->n > node->n))
		{
			node = swaping_node(node, list);
			print_list(*list);
		}
		node = node->next;
	}
}
