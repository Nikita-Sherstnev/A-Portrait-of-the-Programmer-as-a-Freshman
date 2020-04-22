#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"
#include "time.h"

#define PF printf
#define SC scanf
#define MAX 100

double Ger(int a, int n);
int task1();
void task2();

void task3();
void int_list();
int menu_select();
void output();
int find_free();
void enter();
void list();
void leap_year();

void task4();

struct stackw {
	char word;
	stackw *next;
};

struct stacks {
	char inf[15];
	stacks *next;
};

void task5();
void init_stackw(stackw *&s);
void pushw(stackw *&s, char item);
int popw(stackw *&s);
int peekw(stackw *s);
int empty_stackw(stackw *s);
void init_stacks(stacks *&s);
void pushs(stacks *&s, char *item);
char* pops(stacks *&s);
char* peeks(stacks *s);
int empty_stacks(stacks *s);

struct Ttree {
	int inf;
	Ttree *left, *right;
};

void task6();
void degree(int x, Ttree *tr);
void inorder(Ttree *tr);
void add(int x, Ttree *&tr);
void search(int x, Ttree *tr);
void del_tree(Ttree *&tr);
void print_list(Ttree *tr);

void task7();