#ifndef STACK_H
#define STACK_H
#include <stdlib.h>
#include <stdio.h>

typedef struct n {
	unsigned long long size;
	void* data;
	struct n* next;
} Node;

typedef Node* NodePtr;

typedef struct {
	unsigned long long size;
	NodePtr head;
} stack;

typedef stack* stackPtr;

stackPtr createStack();

int stackPush(stackPtr st,void* data, int size);

void* stackPop(stackPtr st);

void stackClean(stackPtr st);

void stackDestory(stackPtr st);

#endif