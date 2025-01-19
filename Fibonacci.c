#include<ctype.h>
#include<limits.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include<stdbool.h>
#include<time.h>

#define MAX_DIGITS 99999999
#define NO_OF_ARRAYS 3


struct CommandLineValidationResult{
	bool decision;
	long long int range;
}commandLineValidationResult;

struct Fibonacci{
	uint8_t number[MAX_DIGITS];
	long long int size;
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
	long long int range = 0;
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

	// If no number
	if(argument[index] == '\0')
	{
		printf("\nValue not specified for argument: %s", argument);
		DisplayCommandLineArgumentsHelp();
		return -1;
	}

	for(; argument[index] != '\0'; index++)
	{
		// If malformed range input
		if(isalpha(argument[index]) != 0)
		{
			printf("\nInvalid range: %s", argument);
			DisplayCommandLineArgumentsHelp();
			return -1;		
		}

		// If number exists
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
	// Validate commandline arguments
	struct CommandLineValidationResult result = CommandLineValidator(argc, argv);
	if(!result.decision)
	{
		exit(0);
	}

	system("clear");

	// Performance testing parameters
	clock_t startTime = 0;
	clock_t endTime = 0;
	long double totalTime = 0;
	
	// TODO: Write code such that the elements of the error will be set to zero prior to their setting of values.
	// Initializing arrays
	memset(fibonacci[0].number, 0, sizeof(fibonacci[0].number));
	memset(fibonacci[1].number, 0, sizeof(fibonacci[1].number));
	memset(fibonacci[2].number, 0, sizeof(fibonacci[2].number));

	// Mathematical parameters
	uint8_t carry = 0;
	uint8_t sum = 0;
	long long int i = 0;
	long long int j = 0;
	long long int range = result.range;

	// Initial Run
	bool isInitialRun = true;

	// Array Pointers - Initial Conditions
	struct Fibonacci *fibonacciNumber1Ptr;
	struct Fibonacci *fibonacciNumber2Ptr;
	struct Fibonacci *fibonacciSumPtr;

	// Performance testing
	startTime = clock();

	// Calculate fibonacci series
	for(; j < (range - 1); j++)
	{
		// Pointer Swapping
		fibonacciNumber1Ptr = &fibonacci[(j + 0) % NO_OF_ARRAYS];
		fibonacciNumber2Ptr = &fibonacci[(j + 1) % NO_OF_ARRAYS];
		fibonacciSumPtr = &fibonacci[(j + 2) % NO_OF_ARRAYS];
		fibonacciSumPtr -> size = fibonacciNumber2Ptr -> size;
		
		if(isInitialRun)
		{
			// Initialize size
			fibonacciNumber1Ptr -> size = 1;
			fibonacciNumber2Ptr -> size = 1;
			fibonacciSumPtr -> size = 1;

			// Setting intial conditions
			fibonacciNumber1Ptr -> number[MAX_DIGITS - 1] = 0;
			fibonacciNumber2Ptr -> number[MAX_DIGITS - 1] = 1;

			isInitialRun = false;
		}

		for(i = (MAX_DIGITS - 1); i > (MAX_DIGITS - fibonacciSumPtr -> size - 1); i--)
		{
			sum = fibonacciNumber1Ptr -> number[i] + fibonacciNumber2Ptr -> number[i] + carry;
			carry = 0;

			// If carry generated
			if (sum > 9)
			{
				carry = 1;
				if((MAX_DIGITS - fibonacciNumber2Ptr -> size) == i)
				{
					fibonacciSumPtr -> size++;
				}
				fibonacciSumPtr -> number[i] = sum % 10;
			}
			else
			{
				fibonacciSumPtr -> number[i] = sum;
			}

			// Overflow detection
			if (fibonacciSumPtr -> number[0] != 0)
			{
				printf("Possible overflow in next iteration.\nTerminating....\n\n");
				PrintFibonacci(fibonacciSumPtr, j);
				totalTime = CalculateExecutionTime(startTime, clock());
				printf("\n\n\nCalculation Time: %Lf secs\n\n", totalTime);
				exit(0);
			}
		}
	
		// Performance testing
		endTime = clock();
		totalTime = CalculateExecutionTime(startTime, endTime);
	}

	// Print the fibonacci number
	PrintFibonacci(fibonacciSumPtr, j);

	// Print performance results
	totalTime = CalculateExecutionTime(startTime, endTime);
	printf("\n\nCalculation Time: %Lf secs\n\n", totalTime);

	return 0;
}
