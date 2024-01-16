#include "monty.h"
/**
 * openFile - opens a file
 * @fileName: file name
 * Return: void
 */

void openFile(char *fileName)
{
	FILE *fileDescriptor = fopen(fileName, "r");

	if (fileName == NULL || fd == NULL)
		err(2, fileName);

	readFile(fileDescriptor);
	fclose(fileDescriptor);
}

/**
 * readFile - reads a file
 * @fileDescriptor: pointer to file descriptor
 * Return: void
 */

void readFile(FILE *fileDescriptor)
{
	int lineNum, form = 0;
	char *buf = NULL;
	size_t len = 0;

	for (lineNum = 1; getline(&buf, &len, fileDescriptor) != -1; lineNum++)
	{
		form = parseLn(buf, lineNum, form);
	}
	free(buf);
}

/**
 * parseLn - Separates each line into tokens
 * @buf: line from the file
 * @lineNum: line number
 * @form:  storage format
 * Return: 0 if stack, 1 if queue
 */

int parseLn(char *buf, int lineNum, int form)
{
	char *opcode, *val;
	const char *delim = "\n ";

	if (buf == NULL)
		err(4);

	opcode = strtok(buf, delim);
	if (opcode == NULL)
		return (form);
	val = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	findFunction(opcode, val, lineNum, form);
	return (form);
}

/**
 * findFunction - find the right function for opcode
 * @opcode: opcode
 * @val: opcode argument
 * @form:  storage format
 * @lineNum: line number
 * Return: void
 */
void findFunction(char *opcode, char *val, int lineNum, int form)
{
	int itr;
	int flag;

	instruction_t listOfFunctions[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, itr = 0; listOfFunctions[itr].opcode != NULL; itr++)
	{
		if (strcmp(opcode, listOfFunctions[itr].opcode) == 0)
		{
			callFunction(listOfFunctions[itr].f, opcode, val, lineNum, form);
			flag = 0;
		}
	}
	if (flag == 1)
		err(3, lineNum, opcode);
}

/**
 * callFunction - Calls required function
 * @func: Pointer to the function that about to be called
 * @opcodeString: string representing the opcode
 * @val: string representing a numeric value
 * @lineNum: line numeber
 * @form: Format specifier
 */
void callFunction(op_func func, char *opcodeString, char *val, int lineNum, int form)
{
	stack_t *node;
	int flag;
	int itr;

	flag = 1;
	if (strcmp(opcodeString, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			err(5, lineNum);
		for (itr = 0; val[itr] != '\0'; itr++)
		{
			if (isdigit(val[itr]) == 0)
				err(5, lineNum);
		}
		node = createCustomNode(atoi(val) * flag);
		if (form == 0)
			func(&node, lineNum);
		if (form == 1)
			pushToQueue(&node, lineNum);
	}
	else
		func(&head, lineNum);
}
