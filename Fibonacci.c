#include<ctype.h>
#include<limits.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include<stdbool.h>
#include<time.h>

#define MAX_DIGITS 999999999
#define RANGE_MAX_DIGITS 32


struct fibonacci{
	uint8_t number[MAX_DIGITS];
	unsigned long long int size;
}fibonacci[3];

void PrintFibonacci(struct fibonacci* fibonacciPtr, unsigned long long int ordinal)
{
	//Print the fibonacci number
	printf("%lluth Fibonacci Number : \n\n", ordinal + 2);
	for(int i = (MAX_DIGITS - fibonacciPtr -> size); i < MAX_DIGITS; i++)
	{
		printf("%d", fibonacciPtr -> number[i]);
	}
	return;
}

long double CalculateExecutionTime(clock_t startTime, clock_t endTime)
{
	return (long double)(endTime - startTime)/(CLOCKS_PER_SEC);
}

void DisplayCommandLineArgumentsHelp()
{
	printf("\n\nUsage: ./Fibonacci [RANGE ...]\n");
	printf("Examples:\n");
	printf("\tSpecifying range:\n");
	printf("  --range=max\t\tGenerates the maximum possible fibonacci number that can be generated with the given heap.\n");
	printf("  --range=N\t\tGenerates the Nth fibonacci number if enough heap space is available.\n");
}

long long int RangeValueParser(char* string)
{
	int index = 0;
	unsigned long long int range = 0;
	const char* rangeString = "--range=\0";

	// Parse text
	for(; rangeString[index] != '\0'; index++)
	{
		if(string[index] != rangeString[index])
		{
			printf("\nUnknown character '%c' in argument.", string[index]);
			DisplayCommandLineArgumentsHelp();
			return -1;
		}
	}

	// Read argument value
	for(; string[index] != '\0'; index++)
	{
		if(isalpha(string[index] == 0))
		{
			return -1;
		}
		else
		{

		}
	}

	// Case: No number
	if(string[index] == '\0')
	{
		return -1;
	}

	// Case: Number Exists
	if(string)


	// Parse number
	for(; string[index] != '\0', index++;)
	{
		range += (int)string[index];
		range *= 10;
	}

	return range;
}

int RangeDecider(char* arg)
{
	long long int range = 0;

	if(strcmp(arg, "--range=max"))
	{
		//TODO: Write the logic for setting range so that the loop runs infinetly.
		/**Currently using the max limit since it's impossible to estimate the highest
		fibonacci number with 'n' digits.**/
		range = ULLONG_MAX;
	}
	else
	{
		range = RangeValueParser(arg);
		if(range == NULL)
		{
			return -1;
		}
	}

	return 0;
}

bool CommandLineValidator(int argc, char* argv[])
{
	//Decision variable
	// -1 -> Failed
	//  0 -> Success
	int decision = -1;

	if(argc != 1)
	{
		DisplayCommandLineArgumentsHelp();
	}
	else
	{
		decision = RangeDecider(argv[1]);
	}

	return decision == -1 ? false : true;

}

int main(int argc, char* argv[])
{
	system("clear");

	//Validate commandline arguments


	//Initializing arrays
	memset(fibonacci[0].number, 0, sizeof(fibonacci[0].number));
	memset(fibonacci[1].number, 0, sizeof(fibonacci[1].number));
	memset(fibonacci[2].number, 0, sizeof(fibonacci[2].number));

	//Initialize size
	fibonacci[0].size = 1;
	fibonacci[1].size = 1;
	fibonacci[2].size = fibonacci[1].size;

	//Mathematical parameters
	uint8_t carry = 0;
	uint8_t sum = 0;
	unsigned long long int i = 0;
	unsigned long long int j = 0;
	unsigned long long int range = atoi(argv[1]);

	//Setting intial conditions
	fibonacci[0].number[MAX_DIGITS - 1] = 0;
	fibonacci[1].number[MAX_DIGITS - 1] = 1;

	//Performance testing parameters
	clock_t startTime = 0;
	clock_t endTime = 0;
	long double totalTime = 0;

	//Performance testing
	startTime = clock();

	//Calculate fibonacci series
	for(; j < (range - 2); j++)
	{
		for(i = (MAX_DIGITS - 1); i > (MAX_DIGITS - fibonacci[2].size - 1); i--)
		{
			sum = fibonacci[0].number[i] + fibonacci[1].number[i] + carry;
			carry = 0;

			//Case: carry generated
			if (sum > 9)
			{
				carry = 1;
				if((MAX_DIGITS - fibonacci[1].size) == i)
				{
					fibonacci[2].size++;
				}
				fibonacci[2].number[i] = sum % 10;
			}
			else
			{
				fibonacci[2].number[i] = sum;
			}

			//Overflow detection
			if (fibonacci[2].number[0] != 0)
			{
				system("clear");
				printf("Possible overflow in next iteration.\n Terminating..\n");
				PrintFibonacci(&fibonacci[2], j);
				totalTime = CalculateExecutionTime(startTime, clock());
				printf("\n\n\nCalculation Time: %Lf secs\n\n", totalTime);
			}
		}

		//Swap the arrays [Copying]
		for(i = (MAX_DIGITS - 1); i > (MAX_DIGITS - fibonacci[1].size - 1); i--)
		{
			fibonacci[0].number[i] = fibonacci[1].number[i];
		}

		for(i = (MAX_DIGITS - 1); i > (MAX_DIGITS - fibonacci[2].size - 1); i--)
		{
			fibonacci[1].number[i] = fibonacci[2].number[i];
		}

		//Swap the array sizes
		fibonacci[0].size = fibonacci[1].size;
		fibonacci[1].size = fibonacci[2].size;
	}

	//Performance testing
	endTime = clock();

	//Print the fibonacci number
	PrintFibonacci(&fibonacci[2], j);

	//Print performance results
	totalTime = CalculateExecutionTime(startTime, endTime);
	printf("\n\n\nCalculation Time: %Lf secs\n\n", totalTime);

	return 0;
}
