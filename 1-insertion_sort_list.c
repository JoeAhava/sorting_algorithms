#include "sort.h"
/**
 * insertion_sort_list - sorts a list using
 * insertion sort algorithm
 * @list: the list to sort
 * Return: (void)
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *head1, *head2, *next;
	int stop;

	if (list)
	{
		head1 = *list;
		head2 = *list;
		while (list && head1->next)
		{
			if (head1->next)
			{
				stop = 0;
				head2 = head1;
				while (head2 && head2->n > head2->next->n)
				{
					current = head2;
					next = head2->next;
					current->next = next->next;
					if (next->next)
						next->next->prev = current;
					if (next)
					{
						next->prev = current->prev;
						next->next = current;
					}
					if (current)
						current->prev = next;
					if (next->prev)
						next->prev->next = next;
					head2 = next->prev;
					if (!next->prev)
						*list = next;
					print_list(*list);
					stop = 1;
				}
			}
			if (stop == 0)
				head1 = head1->next;
		}
	}
}
