#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define PF printf
#define SC scanf

struct stack {
	int inf;
	stack *next;
};

struct stackw {
	char word;
	stackw *next;
};

struct stacks {
	char inf[15];  
	stacks *next;
};

struct tqueue {
	int inf;
	tqueue *next;
};

struct tqueuew {
	char word;
	tqueuew *next;
}; 

void init_stack(stack *&s);
void push(stack *&s, int item);
int pop(stack *&s);
int peek(stack *s);
int empty_stack(stack *s);

void init_stackw(stackw *&s);
void pushw(stackw *&s, char item);
int popw(stackw *&s);
int peekw(stackw *s);
int empty_stackw(stackw *s);

void init_queue(tqueue *&h, tqueue *&t);
void insert(tqueue *&h, tqueue *&t, int item);
int take(tqueue *&h, tqueue *&t);
int peek_queue(tqueue *&h, tqueue *&t);
int empty_queue(tqueue *&h, tqueue *&t);

void init_queuew(tqueuew *&h, tqueuew *&t);
void insertw(tqueuew *&h, tqueuew *&t, char item);
int takew(tqueuew *&h, tqueuew *&t);
int peek_queuew(tqueuew *&h, tqueuew *&t);
int empty_queuew(tqueuew *&h, tqueuew *&t);

void init_stacks(stacks *&s);
void pushs(stacks *&s, char *item);
char* pops(stacks *&s);
char* peeks(stacks *s);
int empty_stacks(stacks *s);

void task1();
void task2();
void task3();
void task4();