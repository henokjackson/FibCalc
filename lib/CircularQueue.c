#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

struct Node{
	int data;
	struct Node *nextPtr;
};

struct Node *startPtr = NULL;
struct Node *endPtr = NULL;
struct Node *cursorPtr = NULL;

void Initialize(int data)
{
	// Initialization
	startPtr = (struct Node *)malloc(sizeof(struct Node));
	endPtr = startPtr;

	// Data Insertion
	startPtr -> data = data;
	startPtr -> nextPtr = startPtr;

	// Initilaize Cursor
	cursorPtr = startPtr;
}

void Insert(int data)
{
	if(startPtr == NULL && endPtr == NULL)
	{
		Initialize(data);
	}
	else
	{
		struct Node *tempPtr = (struct Node *)malloc(sizeof(struct Node));
		tempPtr -> data = data;
		endPtr -> nextPtr = tempPtr;
		tempPtr -> nextPtr = startPtr;
		endPtr = tempPtr;
	}
}

int Peek()
{
	int data = cursorPtr -> data;
	cursorPtr = cursorPtr -> nextPtr;
	return data;
}
