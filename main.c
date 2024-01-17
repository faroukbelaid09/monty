#include "monty.h"

/**
 * main - entry
 * @argc: arguments count
 * @argv: arguments list
 * Return: 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	openFile(argv[1]);
	clearNodes();
	return (0);
}

/**
 * createCustomNode - Creates a custom node.
 * @n: Number to go inside custom node.
 * Return: Pointer to the custom node. Otherwise NULL.
 */
stack_t *createCustomNode(int n)
{
	stack_t *customNode;

	customNode = malloc(sizeof(stack_t));
	if (customNode == NULL)
		errorHandling(4);
	customNode->next = NULL;
	customNode->prev = NULL;
	customNode->n = n;
	return (customNode);
}

/**
 * clearNodes -Free nodes in the stack
 */
void clearNodes(void)
{
	stack_t *head = NULL;
	stack_t *tmp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

/**
 * pushToQueue - push a node to the queue
 * @newNode: Pointer to new node
 * @ln: line number of the opcode
 */
void pushToQueue(stack_t **newNode, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;
	stack_t *head = NULL;

	if (newNode == NULL || *newNode == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *newNode;
		return;
	}
	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *newNode;
	(*newNode)->prev = tmp;

}
