#include "monty.h"

/**
 * addToStack - Add node to stack
 * @newNode: Pointer to the new node
 * @lineNumber: Opcode Interger
 */
void addToStack(stack_t **newNode, __attribute__((unused))unsigned int lineNumber)
{
	stack_t *tmp;

	if (newNode == NULL || *newNode == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *newNode;
		return;
	}
	tmp = head;
	head = *newNode;
	head->next = tmp;
	tmp->prev = head;
}

/**
 * printStack - Add a node to the stack
 * @stack: Pointer to the top node of stack
 * @lineNumber: line number of the opcode
 */
void printStack(stack_t **stack, unsigned int lineNumber)
{
	stack_t *tmp;

	(void) lineNumber;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * printTop - Prints top node of the stack
 * @stack: Pointer to top node of the stack
 * @lineNumber: Opcode Interger
 */
void printTop(stack_t **stack, unsigned int lineNumber)
{
	if (stack == NULL || *stack == NULL)
		errorHandling(6, lineNumber);
	printf("%d\n", (*stack)->n);
}

/**
 * popTop - Add a node to the stack
 * @stack: Pointer to the top node of stack
 * @lineNumber: Opcode Interger
 */
void popTop(stack_t **stack, unsigned int lineNumber)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		errorHandling(7, lineNumber);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}
