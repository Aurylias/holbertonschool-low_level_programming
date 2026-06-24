#include "main.h"

/**
 * jack_bauer - Print the hour from 00:00 to 23:59
 * Return: None
 */

void jack_bauer(void)
{
	int hours;
	int minutes;

	for (hours = 0; hours <= 23; hours++)
	{
		for (minutes = 0; minutes <= 59; minutes++)
		{
			if (hours < 10)
			{
				printf("0");
			}

			printf("%d", hours);
			printf(":");

			if (minutes < 10)
			{
				printf("0");
			}

			printf("%d", minutes);
			printf("\n");
		}
	}
}
