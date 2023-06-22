#include "monty.h"

/**
 * f_push - Adds a node to the stack.
 * @head: Stack head.
 * @counter: Line number.
 *
 * Return: No return value.
 */
void f_push(stack_t **head, unsigned int counter)
{
	int value, i = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			i++;
		for (; bus.arg[i] != '\0'; i++)
		{
			if (bus.arg[i] > '9' || bus.arg[i] < '0')
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	value = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode(head, value);
	else
		addqueue(head, value);
}
