#include "monty.h"
/**
* push_fun - Pushes an element onto the stack.
* @head: A pointer to the head of the stack.
* @i: The line number being processed.
*/
void push_fun(stack_t **head, unsigned int i)
{
	int num, j = 0, flag = 0;

	if (vglob.arg)
	{
		if (vglob.arg[0] == '-')
			j++;
		for (; vglob.arg[j] != '\0'; j++)
		{
			if (vglob.arg[j] > 57 || vglob.arg[j] < 48)
				flag = 1; }
		if (flag == 1)
{fprintf(stderr, "L%d: usage: push integer\n", i);
			fclose(vglob.file);
			free(vglob.content);
			stack_free_fun(*head);
			exit(EXIT_FAILURE); }
}

	else
	{fprintf(stderr, "L%d: usage: push integer\n", i);
		fclose(vglob.file);
		free(vglob.content);
		stack_free_fun(*head);
		exit(EXIT_FAILURE); }
	num = atoi(vglob.arg);
	if (vglob.lifo == 0)
		fun_addnode(head, num);
	else
		fun_addqueue(head, num);
}

/**
 * pall_fun - Prints all elements of a stack.
 * @head: A pointer to the head of the stack.
 * @i: The line number (unused).
 *
 * Description: This function prints all elements of a stack starting
 * from the top (head).
*/
void pall_fun(stack_t **head, unsigned int i)
{
	stack_t *ptr;
	(void)i;

	ptr = *head;
	if (ptr == NULL)
		return;
	while (ptr)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}
