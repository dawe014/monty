#include "monty.h"
/**
 * queue_fun - Perform some operation in a queue-like manner with a stack.
 * @head: Pointer to the head of the stack.
 * @counter: Unsigned integer representing a counter.
 *
 * Description: This function performs some operation in a queue-like manner
 * with the given stack and counter.
 */
void queue_fun(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	vglob.lifo = 1;
}

/**
 * fun_addqueue - Add a new node to the end of the stack (queue-like operation)
 * @head: Pointer to the head of the stack.
 * @n: Integer value to be stored in the new node.
 *
 * Description: This function adds a new node to the end of the stack
 * (queue-like operation) with the specified integer value.
 */
void fun_addqueue(stack_t **head, int n)
{
	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (aux)
	{
		while (aux->next)
			aux = aux->next;
	}
	if (!aux)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		aux->next = new_node;
		new_node->prev = aux;
	}
}
