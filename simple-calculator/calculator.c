#include <stdio.h>

void print_menu(void);
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);

/**
 * print_menu - Print the main menu of the calculator
 * Return: None
 */

void print_menu(void)
{
	printf("Simple Calculator\n");
	printf("1) Add\n");
	printf("2) Subtract\n");
	printf("3) Multiply\n");
	printf("4) Divide\n");
	printf("0) Quit\n");
	printf("Your choice: ");
}

/**
 * add - Add two decimal
 * @a: First value to add
 * @b: Second value to add
 * Return: a + b
 */

int add(int a, int b)
{
	return (a + b);
}

/**
 * subtract - Sub two decimal
 * @a: First value to sub
 * @b: Second value to sub
 * Return: a - b
 */

int subtract(int a, int b)
{
	return (a - b);
}

/**
 * multiply - Multiply two decimal
 * @a: First value to multiply
 * @b: Second value to multiply
 * Return: a * b
 */

int multiply(int a, int b)
{
	return (a * b);
}

/**
 * divide - Divide two decimal
 * @a: First value to divide
 * @b: Second value to divide
 * Return: a / b
 */

int divide(int a, int b)
{
	return (a / b);
}

/**
 * main - Entry point for the calculator, run all functions
 * Return: Always 0 (Success)
 */

int main(void)
{
	int is_running = 1;
	int menu_choice, first_num, second_num;

	while (is_running)
	{
		print_menu();
		scanf("%d", &menu_choice);

		switch (menu_choice)
		{
			case 0:
				printf("Bye !");
				return (0);

			case 1:
				printf("Type your first number to add: ");
				scanf("%d", &first_num);

				printf("Type your second number to add: ");
				scanf("%d", &second_num);

				printf("The result of %d + %d is %d.\n\n",
					 first_num, second_num, add(first_num, second_num));
				break;

			case 2:
				printf("Type your first number to subtract: ");
				scanf("%d", &first_num);

				printf("Type your second number to subtract: ");
				scanf("%d", &second_num);

				printf("The result of %d - %d is %d.\n\n",
					 first_num, second_num, subtract(first_num, second_num));
				break;

			case 3:
				printf("Type your first number to multiply: ");
				scanf("%d", &first_num);

				printf("Type your second number to multiply: ");
				scanf("%d", &second_num);

				printf("The result of %d * %d is %d.\n\n",
					 first_num, second_num, multiply(first_num, second_num));
				break;

			case 4:
				printf("Type your first number to divide: ");
				scanf("%d", &first_num);

				printf("Type your second number to divide: ");
				scanf("%d", &second_num);

				if (second_num <= 0)
				{
					printf("You can't divide by 0 or by a negative number !\n\n");
					break;
				}
				else
				{
					printf("The result of %d / %d is %d.\n\n",
						 first_num, second_num, divide(first_num, second_num));
					break;
				}
			default:
				printf("Invalid choice");
		}
	}
	return (0);
}
