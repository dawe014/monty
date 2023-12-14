#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct globals - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifo: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct globals
{
	char *arg;
	FILE *file;
	char *content;
	int lifo;
}  global_t;
extern global_t vglob;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *content);
void push_fun(stack_t **head, unsigned int number);
void pall_fun(stack_t **head, unsigned int i);
void pint_fun(stack_t **ptr, unsigned int i);
int execute_fun(char *content, stack_t **head, unsigned int counter, FILE *file);
void stack_free_fun(stack_t *head);
void pop_fun(stack_t **head, unsigned int counter);
void fun_swap(stack_t **head, unsigned int counter);
void add_fun(stack_t **head, unsigned int counter);
void fun_nop(stack_t **head, unsigned int counter);
void sub_fun(stack_t **head, unsigned int counter);
void div_fun(stack_t **head, unsigned int counter);
void fun_mul(stack_t **head, unsigned int counter);
void mod_fun(stack_t **head, unsigned int counter);
void fun_pchar(stack_t **head, unsigned int counter);
void pstr_fun(stack_t **head, unsigned int counter);
void rotl_fun(stack_t **head, unsigned int counter);
void rotr_fun(stack_t **head, __attribute__((unused)) unsigned int counter);
void fun_addnode(stack_t **head, int n);
void fun_addqueue(stack_t **head, int n);
void queue_fun(stack_t **head, unsigned int counter);
void stack_fun(stack_t **head, unsigned int counter);
#endif