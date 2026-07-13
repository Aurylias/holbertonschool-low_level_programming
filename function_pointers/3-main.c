#include "3-calc.h"

/**
* main - Entry point
* Return: Always 0 (Success)
*/

int main(int argc, char *argv[])
{
	char *op;

	if ((argc - 1) < 3)
	{
		printf("Error\n");
		exit(98);
	}

	op = argv[2];

	if (get_op_func(op) == NULL || op[1] != '\0')
	{
		printf("Error\n");
		exit(99);
	}

	if (argv[3] == 0)
	{
		printf("Error\n");
		exit(100);
	}

	printf("%d\n", get_op_func(op)(atoi(argv[1]), atoi(argv[3])));

	return (0);
}
