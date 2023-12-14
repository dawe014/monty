#include "monty.h"
/**
 * fun_addnode - Add a new node to the stack.
 * @head: Pointer to the head of the stack.
 * @n: Integer value to be stored in the new node.
 *
 * Description: This function adds a new node to the stack with the specified
 * integer value.
 */
void fun_addnode(stack_t **head, int n)
{

	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (aux)
		aux->prev = new_node;
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}
