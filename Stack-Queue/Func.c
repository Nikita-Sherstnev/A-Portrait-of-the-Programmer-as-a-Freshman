#include "Header.h"

void init_stack(stack **s) {
	*s = NULL;
}

void push(stack **s, int item) {
	stack *r;
	r = (stack*)malloc(sizeof(stack));
	r->inf = item;
	r->next = *s;
	*s = r;
}

int pop(stack **s) {
	stack *r = *s;
	int i = r->inf;
	*s = r->next;
	free(r);
	return i;
}

int peek(stack *s) {
	return s->inf;
}

int empty_stack(stack *s) {
	return (s) ? 0 : 1;
}

//

void init_queue(tqueue **h, tqueue **t) {
	*h = *t = NULL;
}

void insert(tqueue **h, tqueue **t, int item) {
	tqueue *r = (tqueue*)malloc(sizeof(tqueue));
	r->inf = item;
	r->next = NULL;
	if (!*h && !*t) *h = *t = r;
	else {
		(*t)->next = r;
		*t = r;
	}
}

int take(tqueue **h, tqueue **t) {
	tqueue *r = *h;
	int i = r->inf;
	*h = r->next;
	if (!*h) t = NULL;
	free(r);
	return i;
}

int peek_queue(tqueue **h, tqueue **t) {
	return (*t)->inf;
}

int empty_queue(tqueue *h, tqueue *t) {
	return (h&&t) ? 0 : 1;
}

//

void init_queuew(tqueuew **h, tqueuew **t) {
	*h = *t = NULL;
}

void insertw(tqueuew **h, tqueuew **t, char item) {
	tqueuew *r = (tqueuew*)malloc(sizeof(tqueuew));
	r->word = item;
	r->next = NULL;
	if (!*h && !*t) *h = *t = r;
	else {
		(*t)->next = r;
		*t = r;
	}
}

int takew(tqueuew **h, tqueuew **t) {
	tqueuew *r = *h;
	int i = r->word;
	*h = r->next;
	if (!*h) t = NULL;
	free(r);
	return i;
}

int peek_queuew(tqueuew **h, tqueuew **t) {
	return (*t)->word;
}

int empty_queuew(tqueuew *h, tqueuew *t) {
	return (h&&t) ? 0 : 1;
}

//

void init_stackw(stackw **s) {
	*s = NULL;
}

void pushw(stackw **s, char item) {
	stackw *r;
	r = (stackw*)malloc(sizeof(stackw));
	r->word = item;
	r->next = *s;
	*s = r;
}

int popw(stackw **s) {
	stackw *r = *s;
	int i = r->word;
	*s = r->next;
	free(r);
	return i;
}

int peekw(stackw *s) {
	return s->word;
}

int empty_stackw(stackw *s) {
	return(s) ? 0 : 1;
}

//

void init_stacks(stacks **s) {
	*s = NULL;
}

void pushs(stacks **s, char *item) {
	stacks *r;
	r = (stacks*)malloc(sizeof(stacks));
	strcpy(r->inf, item);
	r->next = *s;
	*s = r;
}

char* pops(stacks **s) {
	stacks *r = *s;
	char *i = (char*) malloc(15 * sizeof(char));
	strcpy(i, r->inf);
	*s = r->next;
	free(r);
	return i;
}

char* peeks(stacks *s) {
	return s->inf;
}

int empty_stacks(stacks *s) {
	return(s) ? 0 : 1;
}
