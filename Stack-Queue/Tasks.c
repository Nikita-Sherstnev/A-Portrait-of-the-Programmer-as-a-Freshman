#include "Header.h"

void task1() {
	int i, max;
	FILE *h = fopen("input.txt", "r");
	FILE *g = fopen("output.txt", "w");
	stack *head;
	init_stack(&head);
	while (!feof(h))
	{
		fscanf(h, "%d", &i);
		push(&head, i);
	}
	i = pop(&head);
	max = i;
	while (!empty_stack(head))
	{
		i = pop(&head);
		if (i > max) max = i;
	}
	rewind(h);
	while (!feof(h))
	{
		fscanf(h, "%d", &i);
		if (i != max) fprintf(g, "%d ", i);
	}
	fclose(h);
	fclose(g);
	return;
}

void task2() {
	int i, max, min;
	FILE *h, *g;
	h = fopen("input.txt", "r");
	g = fopen("output.txt", "w");
	tqueue *head, *tail;
	init_queue(&head,&tail);
	while (!feof(h)) {
		fscanf(h, "%d", &i);
		insert(&head,&tail,i);
	}
	i = take(&head,&tail);
	max = min = i;
	while (!empty_queue(head, tail)) {
		i = take(&head, &tail);
		if (i > max) max = i;
		if (i < min) min = i;
	}
	rewind(h);
	while (!feof(h)) {
		fscanf(h, "%d", &i);
		if (i == max) fprintf(g, "%d ", min);
		else if (i == min) fprintf(g, "%d ", max);
		else fprintf(g, "%d ", i);
	}
	fclose(h);
	fclose(g);
	return;
}

void task3() {
	int i=0;
	char c, prev;
	FILE *h, *g;
	h = fopen("inputw.txt", "r");
	g = fopen("outputw.txt", "w");
	tqueuew *head, *tail;
	init_queuew(&head, &tail);
	while (!feof(h)) {
		fscanf(h, "%c", &c);
		insertw(&head, &tail, c);
	}
	c = takew(&head, &tail);
	while (!empty_queuew(head, tail)) {
		if (c == ' ' && i == 1) {
			fprintf(g, " %c ", prev);
			i = 0;
		}
		else fprintf(g, "%c", c);
		prev = c;
		i++;
		if (c == ' ') i = 0;
		c = takew(&head, &tail);
	}
	if (i==1) fprintf(g, " %c", prev);
	fclose(h);
	fclose(g);
	return;
}

void task4() {
	int i=0, j, k;
	char c, str[15] = { 0 }, s[100] = { 0 }, temp;
	FILE *h = fopen("inputw.txt", "r");
	FILE *g = fopen("outputw.txt", "w");
	stacks *head;
	init_stacks(&head);

	while (!feof(h))
	{
		fscanf(h, "%s", str);
		pushs(&head, str);
	}

	while (!empty_stacks(head))
	{
		strcpy(str, pops(&head));
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
	fclose(h);
	fclose(g);
	return;
}