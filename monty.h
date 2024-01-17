#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int lineNumber);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*file operations*/
void openFile(char *fileName);
void readFile(FILE *);
int parseLn(char *buf, int lineNum, int form);
void findFunction(char *opcode, char *val, int lineNum, int form);
void callFunction(op_func func, char*, char *val, int ln, int form);

/*Stack operations*/
stack_t *createCustomNode(int numValue);
void printStack(stack_t **stack, unsigned int lineNumber);
void addToStack(stack_t **newNode, __attribute__((unused))unsigned int ln);
void pushToQueue(stack_t **newNode, __attribute__((unused))unsigned int ln);
void clearNodes(void);

void printTop(stack_t **stack, unsigned int lineNumber);
void swapNodes(stack_t **stack, unsigned int linNumber);
void popTop(stack_t **stack, unsigned int lineNumber);
void empty(stack_t **stack, unsigned int linNumber);

/*Math operations with nodes*/
void addNodes(stack_t **stack, unsigned int linNumber);

/*Error hanlding*/
void errorHandling(int errCode, ...);

#endif
