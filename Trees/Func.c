#include "Header.h"


void preorder(Ttree *tr) {
	if (tr) {
		PF("%d ", tr->inf);
		preorder(tr->left);
		preorder(tr->right);
	}
}

void inorder(Ttree *tr) {
	if (tr) {
		inorder(tr->left);
		printf("%d ", tr->inf);
		inorder(tr->right);
	}
}

void postorder(Ttree *tr) {
	if (tr) {
		postorder(tr->left);
		postorder(tr->right);
		printf("%d ", tr->inf);
	}
}

void add(int x, Ttree **tr) {
	if (!(*tr)) {
		*tr = (Ttree*)malloc(sizeof(Ttree));
		(*tr)->inf = x;
		(*tr)->left = (*tr)->right = NULL;

	}
	else if (x < (*tr)->inf) add(x, &(*tr)->left);
	else if (x > (*tr)->inf) add(x, &(*tr)->right);
}

void search(int x, Ttree *tr) {
	if (!tr) PF("error");
	else if (x < tr->inf) search(x, tr->left);
	else if (x > tr->inf) search(x, tr->right);
	else PF("%d", tr->inf);
}

void del_tree(Ttree *tr) {
	if (!tr) {
		del_tree(tr->left);
		del_tree(tr->right);
		free(tr);
		tr = NULL;
	}
}

void print_list(Ttree *tr, FILE *h) {
	if (tr) {
		print_list(tr->left, h);
		fprintf(h,"%d ", tr->inf);
		print_list(tr->right, h);
	}
}

void degree(int x, Ttree *tr) {
	if (!tr) PF("Error");
	else if (x < tr->inf) degree(x, tr->left);
	else if (x > tr->inf) degree(x, tr->right);
	else {
		if (tr->left == NULL && tr->right == NULL)
			PF("Degree: 0");
		if (tr->left != NULL && tr->right == NULL)
			PF("Degree: 1");
		if (tr->left == NULL && tr->right != NULL)
			PF("Degree: 1");
		if (tr->left != NULL && tr->right != NULL)
			PF("Degree: 2");
	}
}

void task1() {
	int a, node;
	Ttree *tree = NULL;
	FILE *f = fopen("input.txt", "r");
	FILE *h = fopen("output.txt", "w");

	while (!feof(f)) {
		fscanf(f, "%d", &a);
		add(a, &tree);
	}
	print_list(tree, h);
	fclose(h);

	inorder(tree);
	PF("\nEnter the required node: ");
	SC("%d", &node);
	degree(node, tree);
	del_tree(tree);
	rewind(f);
	fclose(f);
	return;
}

void task2() {
	int a;
	Ttree *tree = NULL;
	FILE *f = fopen("input.txt", "r");
	FILE *h = fopen("output.txt", "w");

	while (!feof(f)) {
		fscanf(f, "%d", &a);
		add(a, &tree);
	}
	print_list(tree, h);
	fclose(h);

	inorder(tree);
	del_tree(tree);
	rewind(f);
	fclose(f);
	return;
}