#include "monty.h"
/**
 * div_fun - Perform some operation with a stack.
 * @head: Pointer to the head of the stack.
 * @counter: Unsigned integer representing a counter.
 *
 * Description: This function performs some operation with the given stack
 * and counter.
 */
void div_fun(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(vglob.file);
		free(vglob.content);
		stack_free_fun(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(vglob.file);
		free(vglob.content);
		stack_free_fun(*head);
		exit(EXIT_FAILURE);
	}
	aux = h->next->n / h->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}
