#include "monty.h"
/**
 * sub_fun - Perform some subtraction operation with a stack.
 * @head: Pointer to the head of the stack.
 * @counter: Unsigned integer representing a counter.
 *
 * Description: This function performs some subtraction operation with
 * the given stack and counter.
 */
void sub_fun(stack_t **head, unsigned int counter)
{
	stack_t *aux;
	int sus, nodes;

	aux = *head;
	for (nodes = 0; aux != NULL; nodes++)
		aux = aux->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(vglob.file);
		free(vglob.content);
		stack_free_fun(*head);
		exit(EXIT_FAILURE);
	}
	aux = *head;
	sus = aux->next->n - aux->n;
	aux->next->n = sus;
	*head = aux->next;
	free(aux);
}
