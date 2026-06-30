#include <stdio.h>

void print_menu(void);

/**
 * print_menu - Print the main menu of the calculator
 * Return: None
 */

void print_menu(void)
{
	printf("1) Add\n");
	printf("2) Subtract\n");
	printf("3) Multiply\n");
	printf("4) Divide\n");
	printf("0) Quit\n");
	printf("Choice: ");
}

/**
 * main - Entry point for the calculator, run all functions
 * Return: Always 0 (Success)
 */

int main(void)
{
	printf("Simple Calculator\n");

	print_menu();
	scanf("%d", &menu_choice);

	switch (menu_choice)
	{
			case 0:
				printf("Bye !");
				return (0);
	}
}
