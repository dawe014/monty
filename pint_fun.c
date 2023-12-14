#include "monty.h"
/**
 * pint_fun - prints the top
 * @ptr: Head of stack
 * @i: line_number
*/
void pint_fun(stack_t **ptr, unsigned int i)
{
	if (*ptr == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", i);
		fclose(vglob.file);
		free(vglob.content);
		stack_free_fun(*ptr);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*ptr)->n);
}
