// CS50 Lecture 1 - abstractions and types

/* 
	bool, a Boolean expression of either true or false
	char, a single character like a or 2
	double, a floating-point value with more digits than a float
	float, a floating-point value, or real number with a decimal value
	int, integers up to a certain size, or number of bits
	long, integers with more bits, so they can count higher than an int
	string, a string of characters
*/

#include <stdio.h>
#include <cs50.h>

int const GLOBAL_SIZE_LIMIT = 10;

int get_size(char message[]);
void print_grid(int width, int height);

int main(void)
{
	printf("Global size limit of your blocks is %i\n", GLOBAL_SIZE_LIMIT);

	int width = get_size("Gimme width");
	int height = get_size("Gimme height");

	print_grid(width, height);
}

int get_size(char message[])
{
	printf("%s", message);
	printf("\n");

	int n;
	do
	{
		n = get_int("Size: ");
	}
	while(n < 1 && n > GLOBAL_SIZE_LIMIT);

	return n;
}

void print_grid(int width, int height)
{
	for(int i=0; i<height; i++)
	{
		for(int j=0; j<width; j++)
		{
			printf("#");
		}
		printf("\n");
	}
}
