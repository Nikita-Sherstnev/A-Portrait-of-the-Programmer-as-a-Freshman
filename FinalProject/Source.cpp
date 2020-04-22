#include "Header.h"

FILE *f = fopen("inputtree.txt", "r");
FILE *h = fopen("outputtree.txt", "w");

double Ger(int a, int n) {
	if (n == 0) return 200;
	else return (Ger(a, n - 1) + a / Ger(a, n - 1)) / 2;
}

int task1() {
	int a, b, c;
	PF("Введите три числа: \n");
	SC("%d%d%d", &a, &b, &c);
	for (int i = 1; i <= 10; i++)
		printf("№%d.  %.15lf %.15lf %.15lf\n", i, Ger(a, i), Ger(b, i), Ger(c, i));
	system("pause");
	return 0;
}

void task2() {
	char len[100], ch;
	int i = 0;
	FILE *fp;
	if ((fp = fopen("file.txt", "rb+")) == NULL) {
		PF("Ошибка!");
		exit(1);
	}
	fseek(fp, -1, SEEK_END);
	while (ftell(fp) > 0) {
		ch = fgetc(fp);
		len[i++] = ch;
		fseek(fp, -2, SEEK_CUR);
		if (ch == '\n' || ftell(fp) < 0) {
			for (i--; i >= 0; i--)
				PF("%c", len[i]);
			i = 0;
		}
	}
	ch = fgetc(fp);
	len[i++] = ch;
	PF("\n");
	for (i--; i >= 0; i--)
		PF("%c", len[i]);
	PF("\n");
	fclose(fp);
	return;
}

struct data {
	int day;
	int month;
	int year;
} data_list[MAX];

void int_list() {
	int t;
	for (t = 0; t < MAX; t++)
		data_list[t].day = 0;
	return;
}

int menu_select() {
	char s[80];
	int c;
	system("cls");
	PF("1.Ввод даты\n2.Вывод дат\n3.Какие даты високосного года\n4.Выход");
	do {
		PF("\nВыберите нужный пункт: ");
		fgets(s, 80, stdin);
		c = atoi(s);
	} while (c < 1 || c>4);
	return c;
}

void output() {
	int t = 0;
	FILE *fp;
	if ((fp = fopen("output.txt", "w")) != NULL) {
		while (data_list[t].day != 0) {
			fprintf(fp, "%d\n", data_list[t].day);
			fprintf(fp, "%d\n", data_list[t].month);
			fprintf(fp, "%d\n", data_list[t].year);
			t++;
		}
	}
	else {
		PF("Error!\n");
		exit(1);
	}
	fclose(fp);
	return;
}

int find_free() {
	register int slot;
	for (slot = 0; data_list[slot].day != 0 && slot < MAX; ++slot);
	if (slot + 1 == MAX) return -1;
	return slot;
}

void enter() {
	int slot;
	slot = find_free();
	if (slot == -1) {
		PF("Нет свободных слотов!");
		return;
	}
	PF("Введите число: ");
	SC("%d", &data_list[slot].day);
	PF("Введите месяц: ");
	SC("%d", &data_list[slot].month);
	PF("Введите год: ");
	SC("%d", &data_list[slot].year);
	PF("Запись добавлена!\n");
	output();
	system("pause");
	return;
}

void list() {
	int t = 0;
	while (data_list[t].day != 0) {
		PF("%d) ", t + 1);
		PF("%d.", data_list[t].day);
		PF("%d.", data_list[t].month);
		PF("%d\n", data_list[t].year);
		t++;
	}
	output();
	system("pause");
	return;
}

void leap_year() {
	int t, all = 0, count = 0;
	while (data_list[all].day) all++;
	PF("Даты, произошедшие в високосном году:\n");
	for (t = 0; t < all; t++) {
		if (data_list[t].year % 4 == 0 && data_list[t].year % 100 != 0 || data_list[t].year % 400 == 0) {
			PF("%d) ", t + 1);
			PF("%d.", data_list[t].day);
			PF("%d.", data_list[t].month);
			PF("%d\n", data_list[t].year);
			count++;
		}
	}
	if (count == 0) PF("Таких дат нет!\n");
	system("pause");
	return;
}

void task3() {
	char choice, c;
	int i = 0;
	int_list();
	FILE *fp;
	if ((fp = fopen("struct.txt", "r")) != NULL)
		while ((c = fgetc(fp)) != EOF) {
			ungetc(c, fp);
			fscanf(fp, "%d", &data_list[i].day);
			do { c = fgetc(fp); } while (c != '\n' && c != EOF);
			fscanf(fp, "%d", &data_list[i].month);
			do { c = fgetc(fp); } while (c != '\n' && c != EOF);
			fscanf(fp, "%d", &data_list[i].year);
			do { c = fgetc(fp); } while (c != '\n' && c != EOF);
			i++;
		}
	else {
		PF("Error!\n");
		exit(1);
	}
	fclose(fp);
	output();
	for (;;) {
		choice = menu_select();
		switch (choice) {
		case 1: enter(); break;
		case 2: list(); break;
		case 3: leap_year(); break;
		case 4: exit(0);
		}
	}
	return;
}

void task4() {
	int i = 0, j = 0, k = 0, sizearr = 0, size = 0, **arr, m = 0, x = 0;
	FILE *fp, *fwrite;
	if ((fp = fopen("array.txt", "r")) == NULL) {
		PF("Error");
		exit(1);
	}
	if ((fwrite = fopen("arraysorted.txt", "w")) == NULL) {
		PF("Error");
		exit(1);
	}
	fscanf(fp, "%d", &sizearr);
	arr = (int**)malloc(sizearr * sizeof(int*));
	for (i = 0; i < sizearr; i++)
		arr[i] = (int*)malloc(sizearr * sizeof(int));

	for (i = 0; i < sizearr; i++)
		for (j = 0; j < sizearr; j++)
			fscanf(fp, "%d", &arr[i][j]);

	for (k = 0; k < sizearr - 1; k++) {
		m = sizearr - k;
		for (i = 0; i <= m; i++) {
			for (j = m - 1; j >= i + 1; j--) {
				if (arr[j - 1][j + k - 1] < arr[j][j + k]) {
					x = arr[j - 1][j + k - 1];
					arr[j - 1][j + k - 1] = arr[j][j + k];
					arr[j][j + k] = x;
				}
				if (arr[j - 1 + k][j - 1] < arr[j + k][j]) {
					x = arr[j - 1 + k][j - 1];
					arr[j - 1 + k][j - 1] = arr[j + k][j];
					arr[j + k][j] = x;
				}
			}
		}
	}

	for (i = 0; i < sizearr; i++) {
		for (j = 0; j < sizearr; j++)
			fprintf(fwrite, "%d ", arr[i][j]);
		fprintf(fwrite, "\n");
	}

	for (i = 0; i < sizearr; i++)
		free(arr[i]);
	free(arr);
	fclose(fp);
	fclose(fwrite);
	return;
}


void task5() {
	int i = 0, j, k;
	char c, str[15] = { 0 }, s[100] = { 0 }, temp;
	FILE *h = fopen("inputw.txt", "r");
	FILE *g = fopen("outputw.txt", "w");
	stacks *head;
	init_stacks(head);

	while (!feof(h))
	{
		fscanf(h, "%s", str);
		pushs(head, str);
	}

	while (!empty_stacks(head))
	{
		strcpy(str, pops(head));
		fprintf(g, "%s ", str);
	}

	/* Если считывать посимвольно
	stackw *head;
	init_stackw(head);
	while (!feof(h)) {
	fscanf(h, "%c", &c);
	pushw(head, c);
	}
	c = popw(head);
	c = popw(head);
	while (!empty_stackw(head)) {
	if (c == ' ') {
	for (j = 0, k = i-1; j < (i / 2); j++, k--) {
	temp = s[k];
	s[k] = s[j];
	s[j] = temp;
	}
	for (j=0; j<i; j++)
	fprintf(g,"%c",s[j]);
	fprintf(g, " ");
	i = 0;
	}
	else s[i++] = c;
	c = popw(head);
	}
	fprintf(g, "%c", c); */
	_fcloseall();
	return;
}

void init_stackw(stackw *&s) {
	s = NULL;
}

void pushw(stackw *&s, char item) {
	stackw *r;
	r = (stackw*)malloc(sizeof(stackw));
	r->word = item;
	r->next = s;
	s = r;
}

int popw(stackw *&s) {
	stackw *r = s;
	int i = r->word;
	s = r->next;
	free(r);
	return i;
}

int peekw(stackw *s) {
	return s->word;
}

int empty_stackw(stackw *s) {
	return(s) ? 0 : 1;
}

void init_stacks(stacks *&s) {
	s = NULL;
}

void pushs(stacks *&s, char *item) {
	stacks *r;
	r = new stacks;
	strcpy(r->inf, item);
	r->next = s;
	s = r;
}

char* pops(stacks *&s) {
	stacks *r = s;
	char i[15];
	strcpy(i, r->inf);
	s = r->next;
	delete r;
	return i;
}

char* peeks(stacks *s) {
	return s->inf;
}

int empty_stacks(stacks *s) {
	return(s) ? 0 : 1;
}


void task6() {
	int a;
	Ttree *tree = NULL;
	while (!feof(f)) {
		fscanf(f, "%d", &a);
		add(a, tree);
		print_list(tree);
	}
	inorder(tree);
	del_tree(tree);
	rewind(f);
	return;
}

void inorder(Ttree *tr) {
	if (tr) {
		inorder(tr->left);
		printf("%d ", tr->inf);
		inorder(tr->right);
	}
}

void add(int x, Ttree *&tr) {
	if (!tr) {
		tr = (Ttree*)malloc(sizeof(Ttree));
		tr->inf = x;
		tr->left = tr->right = NULL;
	}
	else if (x < tr->inf) add(x, tr->left);
	else if (x > tr->inf) add(x, tr->right);
}

void search(int x, Ttree *tr) {
	if (!tr) PF("error");
	else if (x < tr->inf) search(x, tr->left);
	else if (x > tr->inf) search(x, tr->right);
	else PF("%d", tr->inf);
}

void del_tree(Ttree *&tr) {
	if (!tr) {
		del_tree(tr->left);
		del_tree(tr->right);
		free(tr);
		tr = NULL;
	}
}

void print_list(Ttree *tr) {
	if (tr) {
		if (tr->left == NULL && tr->right == NULL)
			fprintf(h, "%d ", tr->inf);
		else {
			print_list(tr->left);
			print_list(tr->right);
		}
	}
}

void degree(int x, Ttree *tr) {
	if (!tr) PF("Error");
	else if (x < tr->inf) degree(x, tr->left);
	else if (x > tr->inf) degree(x, tr->right);
	else {
		if (tr->left == NULL && tr->right == NULL)
			PF("Степень: 0");
		if (tr->left != NULL && tr->right == NULL)
			PF("Степень: 1");
		if (tr->left == NULL && tr->right != NULL)
			PF("Степень: 1");
		if (tr->left != NULL && tr->right != NULL)
			PF("Степень: 2");
	}
}

void task7() {
	int n, i, j, k, vertex, **gr;
	FILE *fp = fopen("inputgraphs.txt", "r");
	fscanf(fp, "%d", &n);
	gr = (int**)malloc(sizeof(int*)*n);
	for (i = 0; i<n; i++) {
		gr[i] = (int*)malloc(sizeof(int)*n);
		for (j = 0; j < n; j++) {
			fscanf(fp, "%d", &gr[i][j]);
		}
	}

	for (k = 0; k < n; k++) //Строим матрицу транзитив. замыкания
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				if (gr[i][j] > (gr[i][k] && gr[k][j]))
					gr[i][j] = gr[i][j];
				else
					gr[i][j] = gr[i][k] && gr[k][j];

	PF("Введите нужную вершину (первая - 1): ");
	SC("%d", &vertex);

	int check = 0;
	PF("Существует путь из вершин ");
	for (i = 0; i < n; i++)
		if (gr[i][vertex - 1] == 1 && i != vertex - 1)
			if (check == 0) {
				PF("%d", i + 1);
				check++;
			}
			else PF(", %d", i + 1);

			PF("\n");
			for (i = 0; i < n; i++)
				free(gr[i]);
			free(gr);
			fclose(fp);
			return;
}

