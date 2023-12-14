#include "monty.h"
/**
 * stack_free_fun - Frees a stack.
 * @head: A pointer to the head of the stack.
 *
 * Description: This function frees the memory allocated for a stack.
 */
void stack_free_fun(stack_t *head)
{
	stack_t *aux;

	aux = head;
	while (head)
	{
		aux = head->next;
		free(head);
		head = aux;
	}
}
