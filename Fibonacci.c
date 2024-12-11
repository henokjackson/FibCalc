#include<ctype.h>
#include<limits.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include<stdbool.h>
#include<time.h>

#define MAX_DIGITS 999999999

struct CommandLineValidationResult{
	bool decision;
	long long int range;
}commandLineValidationResult;

struct Fibonacci{
	uint8_t number[MAX_DIGITS];
	unsigned long long int size;
}fibonacci[3];

void PrintFibonacci(struct Fibonacci* fibonacciPtr, unsigned long long int ordinal)
{
	//Print the fibonacci number
	printf("%lluth Fibonacci Number : \n\n", ordinal + 1);
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
	printf("\t\t--range=max\tGenerates the maximum possible fibonacci number that can be generated with the given heap.\n");
	printf("\t\t--range=N\tGenerates the Nth fibonacci number if enough heap space is available.\n");

	return;
}

long long int ParseRange(char* argument)
{
	int index = 0;
	unsigned long long int range = 0;
	const char* rangeArgumentString = "--range=\0";

	for(; rangeArgumentString[index] != '\0'; index++)
	{
		if(argument[index] != rangeArgumentString[index])
		{
			printf("\nUnknown argument: %s", argument);
			DisplayCommandLineArgumentsHelp();
			return -1;
		}
	}

	// Case: No number
	if(argument[index] == '\0')
	{
		return -1;
	}

	for(; argument[index] != '\0'; index++)
	{
		// Case: If malformed range input
		if(isalpha(argument[index] == 0))
		{
			return -1;
		}

		// Case: Number Exists
		else
		{
			range *= 10;
			// char -> int
			range += (int)(argument[index] - '0');
		}
	}

	return range;
}

long long int DecideRange(char* argument)
{
	long long int range = 0;

	if(strcmp(argument, "--range=max") == 0)
	{
		//TODO: Write the logic for setting range so that the loop runs infinetly.
		/**Currently using the max limit since it's impossible to estimate the highest
		fibonacci number with 'n' digits.**/
		range = ULLONG_MAX;
	}
	else
	{
		range = ParseRange(argument);
	}

	return range;
}

struct CommandLineValidationResult CommandLineValidator(int argumentCount, char* arguments[])
{
	// Decision variable
	// -1 -> Failed
	//  0 -> Success
	int decision = -1;
	long long int range = 0;

	if(argumentCount != 2)
	{
		printf("\nToo many arguments !");
		DisplayCommandLineArgumentsHelp();
	}
	else
	{
		range = DecideRange(arguments[1]);
	}

	struct CommandLineValidationResult result;
	result.decision = (range == -1 || 0 ? false : true);
	result.range = range;

	return result;
}

int main(int argc, char* argv[])
{
	//Validate commandline arguments
	struct CommandLineValidationResult result = CommandLineValidator(argc, argv);
	if(!result.decision)
	{
		exit(0);
	}

	system("clear");

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
	long long int range = result.range;
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
	for(; j < (range - 1); j++)
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
	printf("\n\nCalculation Time: %Lf secs\n\n", totalTime);

	return 0;
}
