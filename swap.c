#include "monty.h"

/**
 * f_swap - Swaps the top two elements of the stack.
 * @head: Stack head.
 * @counter: Line number.
 *
 * Return: No return value.
 */
void f_swap(stack_t **head, unsigned int counter)
{
	stack_t *current;
	int stack_len, temp;

	current = *head;
	stack_len = 0;
	while (current != NULL)
	{
		current = current->next;
		stack_len++;
	}

	if (stack_len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	current = *head;
	temp = current->n;
	current->n = current->next->n;
	current->next->n = temp;
}
