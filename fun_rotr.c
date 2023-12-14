#include "monty.h"
/**
 * rotr_fun - Rotate the stack to the right.
 * @head: Pointer to the head of the stack.
 * @counter: Unused unsigned integer parameter.
 *
 * Description: This function rotates the stack to the right.
 */
void rotr_fun(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *copy;

	copy = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *head;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*head)->prev = copy;
	(*head) = copy;
}
