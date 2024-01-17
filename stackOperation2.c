#include "monty.h"

/**
 * empty - Do nothing
 * @stack: Pointer to top node of the stack
 * @linNumber: IOpcode Interger
 */
void empty(stack_t **stack, unsigned int linNumber)
{
	(void)stack;
	(void)linNumber;
}

/**
 * swapNodes - Swaps the top two elements of stack
 * @stack: Pointer to top node of the stack
 * @linNumber: Opcode Interger
 */
void swapNodes(stack_t **stack, unsigned int linNumber)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		errorHandling(8, linNumber, "swap");
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}

/**
 * addNodes - Add the top two elements of the stack
 * @stack: Pointer to top node of the stack
 * @ln: Opcode Interger
 */
void addNodes(stack_t **stack, unsigned int ln)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		errorHandling(8, ln, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * subNodes - Adds the top two elements of the stack
 * @stack: Pointer to top node of the stack.
 * @ln: Opcode Interger
 */
void subNodes(stack_t **stack, unsigned int ln)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		errorHandling(8, ln, "sub");


	(*stack) = (*stack)->next;
	sum = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * divNodes - Adds the top two elements of the stack
 * @stack: Pointer to top node of the stack.
 * @ln: Opcode Interger
 */
void divNodes(stack_t **stack, unsigned int ln)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		errorHandling(8, ln, "div");

	if ((*stack)->n == 0)
		errorHandling(9, ln);
	(*stack) = (*stack)->next;
	sum = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
