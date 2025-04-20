#include<ctype.h>
#include<limits.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include<stdbool.h>
#include<time.h>
#define MAX_DIGITS 99999999
#define NO_OF_ARRAYS 2

struct CommandLineValidationResult{
	bool decision;
	long long int range;
}commandLineValidationResult;

struct Fibonacci{
	uint8_t number[MAX_DIGITS];
	long long int size;
}fibonacci[NO_OF_ARRAYS];

void PrintFibonacci(struct Fibonacci* fibonacciPtr, unsigned long long int ordinal)
{
	printf("F(%lld) = ", ordinal);
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

void ShowCommandLineArgumentsHelp()
{
	printf("\n\nUsage: ./Fibonacci [n...]\n");
	printf("Specifying range:\n");
	printf("\t-n=max\tGenerates the maximum possible fibonacci number that can be generated with the given heap.\n");
	printf("\t-n=N\tGenerates the Nth fibonacci number if enough heap space is available.\n");

	return;
}

long long int ParseRange(char* argument)
{
	int index = 0;
	long long int range = 0;
	const char* rangeArgumentString = "-n=\0";
	for(; rangeArgumentString[index] != '\0'; index++)
	{
		if(argument[index] != rangeArgumentString[index])
		{
			printf("\nUnknown argument: %s", argument);
			ShowCommandLineArgumentsHelp();

			return -1;
		}
	}

	// If the value of range is not specified.
	if(argument[index] == '\0')
	{
		printf("\nValue not specified for argument: %s", argument);
		ShowCommandLineArgumentsHelp();

		return -1;
	}

	for(; argument[index] != '\0'; index++)
	{
		// If input range is malformed
		if(isdigit((unsigned char)argument[index]) == 0)
		{
			printf("\nInvalid range: %s", argument);
			ShowCommandLineArgumentsHelp();

			return -1;
		}
		// Parse the number
		else
		{
			range *= 10;
			// char -> int
			range += (int)(argument[index] - '0');
		}
	}

	// Invalid range
	if(range <= 0)
	{
		printf("\nn should be greater than zero.");
		ShowCommandLineArgumentsHelp();
	}

	return range;
}

long long int DecideRange(char* argument)
{
	long long int range = 0;
	if(strcmp(argument, "-n=max") == 0)
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
		ShowCommandLineArgumentsHelp();
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
	// Validate Command-Line Arguments
	struct CommandLineValidationResult result = CommandLineValidator(argc, argv);
	if(!result.decision)
	{
		exit(0);
	}

	system("clear");

	// Performance Testing Parameters
	clock_t startTime = 0;
	clock_t endTime = 0;
	long double totalTime = 0;
	
	// TODO: Write code such that the elements of the error will be set to zero prior to their setting of values.
	// Initializing Arrays
	memset(fibonacci[0].number, 0, sizeof(fibonacci[0].number));
	memset(fibonacci[1].number, 0, sizeof(fibonacci[1].number));

	// Mathematical Parameters
	uint8_t carry = 0;
	uint8_t sum = 0;
	long long int i = 0;
	long long int j = 0;
	long long int range = result.range;

	// Initial Run
	bool isInitialRun = true;

	// Array Pointers - Initial Conditions
	struct Fibonacci *fibonacciNumberPtr = &fibonacci[0];
	fibonacciNumberPtr -> size = 1;

	struct Fibonacci *fibonacciSumPtr = &fibonacci[1];
	fibonacciSumPtr -> size = 1;

	// Performance Testing - Start
	startTime = clock();

	// Calculate the Fibonacci Series
	for(; j <= (range - 1); j++)
	{
		// Pointer Swapping
		fibonacciNumberPtr = &fibonacci[(j + 0) % NO_OF_ARRAYS];
		fibonacciSumPtr = &fibonacci[(j + 1) % NO_OF_ARRAYS];

		fibonacciSumPtr -> size = fibonacciNumberPtr -> size;
		
		if(isInitialRun)
		{
			fibonacciNumberPtr -> size = 1;
			fibonacciSumPtr -> size = 1;

			fibonacciNumberPtr -> number[MAX_DIGITS - 1] = 0;
			fibonacciSumPtr -> number[MAX_DIGITS - 1] = 1;

			isInitialRun = false;
		}

		for(i = (MAX_DIGITS - 1); i > (MAX_DIGITS - fibonacciSumPtr -> size - 1); i--)
		{
			sum = fibonacciNumberPtr -> number[i] + fibonacciSumPtr -> number[i] + carry;
			carry = 0;

			// When Carry Is Generated
			if (sum > 9)
			{
				carry = 1;
				if((MAX_DIGITS - fibonacciNumberPtr -> size) == i)
				{
					fibonacciSumPtr -> size++;
				}
				fibonacciSumPtr -> number[i] = sum % 10;
			}
			else
			{
				fibonacciSumPtr -> number[i] = sum;
			}

			// Overflow Detection
			if (fibonacciSumPtr -> number[0] != 0)
			{
				printf("Possible overflow in next iteration.\nTerminating....\n\n");
				PrintFibonacci(fibonacciSumPtr, j + 1);
				totalTime = CalculateExecutionTime(startTime, clock());
				printf("\n\n\nCalculation Time: %Lf secs\n\n", totalTime);
				exit(0);
			}
		}
	}
	
	// Performance Testing - Stop
	endTime = clock();
	totalTime = CalculateExecutionTime(startTime, endTime);

	// Print the Fibonacci Number
	PrintFibonacci(fibonacciSumPtr, range);

	// Print Performance Results
	totalTime = CalculateExecutionTime(startTime, endTime);
	printf("\n\nCalculation Time: %Lf seconds.\n\n", totalTime);

	return 0;
}