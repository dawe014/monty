#include "monty.h"
/**
 * rotl_fun - Rotate the stack to the left.
 * @head: Pointer to the head of the stack.
 * @counter: Unused unsigned integer parameter.
 *
 * Description: This function rotates the stack to the left.
 */
void rotl_fun(stack_t **head,  __attribute__((unused)) unsigned int counter)
{
	stack_t *tmp = *head, *aux;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	aux = (*head)->next;
	aux->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = aux;
}
