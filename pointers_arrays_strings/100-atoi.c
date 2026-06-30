#include "main.h"

/**
 * _atoi - Convert a string to an integer
 * @s: String to convert
 * Return: An int
 */

int _atoi(char *s)
{
	int res = 0;
	int i;
	int plus = 0;
	int minus = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == 43)
		{
			plus++;
		}

		if (s[i] == 45)
		{
			minus++;
		}

		while (s[i] >= 48 && s[i] <= 57)
		{
			res = res * 10 + (s[i] - '0');
			i++;

			if (s[i] == 59)
			{
				break;
			}
		}
	}

	if (plus == minus || plus > minus)
	{
		return (res);
	}
	else
	{
		return (-res);
	}
}


