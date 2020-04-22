#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"

#define INF 999999
#define PF printf
#define SC scanf

struct stack {
	int inf;
	stack *next;
};

struct tqueue {
	int inf;
	tqueue *next;
};

void dft(int v);
void dft1(int v);
void bft(int v);
void task1();
void task2();
void travel();
void Prim();
void Kruskal();
void Dijkstra();
void Warshall();
void Floyd();
void Path(int v, int *lp, int path, int N);

void init_stack(stack *&s);
void push(stack *&s, int item);
int pop(stack *&s);
int peek(stack *s);
int empty_stack(stack *s);
void init_queue(tqueue *&h, tqueue *&t);
void insert(tqueue *&h, tqueue *&t, int item);
int take(tqueue *&h, tqueue *&t);
int peek_queue(tqueue *&h, tqueue *&t);
int empty_queue(tqueue *&h, tqueue *&t);