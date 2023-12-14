#include "monty.h"
/**
 * pop_fun - Removes the top element of the stack.
 * @head: A pointer to the head of the stack.
 * @counter: The line number.
 *
 * Description: This function removes the top element from the stack.
 */
void pop_fun(stack_t **head, unsigned int counter)
{
	stack_t *ptr;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(vglob.file);
		free(vglob.content);
		stack_free_fun(*head);
		exit(EXIT_FAILURE);
	}
	ptr = *head;
	*head = ptr->next;
	free(ptr);
}
