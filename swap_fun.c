#include "monty.h"
/**
 * fun_swap - Swaps the top two elements of the stack.
 * @head: A pointer to the head of the stack.
 * @counter: The line number.
 *
 * Description: This function swaps the top two elements of the stack.
 */
void fun_swap(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, aux;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(vglob.file);
		free(vglob.content);
		stack_free_fun(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	aux = h->n;
	h->n = h->next->n;
	h->next->n = aux;
}
