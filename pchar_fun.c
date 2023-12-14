#include "monty.h"
/**
 * fun_pchar - Prints the char at the top of the stack.
 * @head: A pointer to the head of the stack.
 * @counter: The line number.
 *
 * Description: This function prints the char at the top of the stack.
 */
void fun_pchar(stack_t **head, unsigned int counter)
{
	stack_t *h;

	h = *head;
	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		fclose(vglob.file);
		free(vglob.content);
		stack_free_fun(*head);
		exit(EXIT_FAILURE);
	}
	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
		fclose(vglob.file);
		free(vglob.content);
		stack_free_fun(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h->n);
}