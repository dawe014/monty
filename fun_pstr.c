#include "monty.h"
/**
 * pstr_fun - Print the string contained in the stack.
 * @head: Pointer to the head of the stack.
 * @counter: Unsigned integer representing a counter.
 *
 * Description: This function prints the string contained in the stack
 * starting from the top of the stack.
 */
void pstr_fun(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
