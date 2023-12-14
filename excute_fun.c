#include "monty.h"
/**
 * execute - Execute commands from the content.
 * @content: A pointer to the content.
 * @stack: A pointer to the stack.
 * @counter: The line number.
 * @file: A pointer to the FILE structure.
 *
 * Description: This function executes commands based on the provided content,
 * updating the stack accordingly.
 * Returns: An integer indicating success (0) or failure (-1).
 */
int execute_fun(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", push_fun}, {"pall", pall_fun}, {"pint", pint_fun},
				{"pop", pop_fun},
				{"swap", fun_swap},
				{"add", add_fun},
				{"nop", fun_nop},
				{"sub", sub_fun},
				{"div", div_fun},
				{"mul", fun_mul},
				{"mod", mod_fun},
				{"pchar", fun_pchar},
				{"pstr", pstr_fun},
				{"rotl", rotl_fun},
				{"rotr", rotr_fun},
				{"queue", queue_fun},
				{"stack", stack_fun},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	vglob.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		stack_free_fun(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}