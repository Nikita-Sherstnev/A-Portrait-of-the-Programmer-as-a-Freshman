#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define PF printf
#define SC scanf

struct Ttree {
	int inf;
	Ttree *left, *right;
};

void degree(int x, Ttree *tr);
void preorder(Ttree *tr);
void inorder(Ttree *tr);
void postorder(Ttree *tr);
void add(int x, Ttree *&tr);
void search(int x, Ttree *tr);
void del_tree(Ttree *&tr);
void print_list(Ttree *tr);
void task1();
void task2();