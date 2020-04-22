#include "Header.h"

void init_stack(stack *&s) {
	s = NULL;
}

void push(stack *&s, int item) {
	stack *r;
	r = (stack*)malloc(sizeof(stack));
	r->inf = item;
	r->next = s;
	s = r;
}

int pop(stack *&s) {
	stack *r = s;
	int i = r->inf;
	s = r->next;
	free(r);
	return i;
}

int peek(stack *s) {
	return s->inf;
}

int empty_stack(stack *s) {
	return(s) ? 0 : 1;
}

//

void init_queue(tqueue *&h, tqueue *&t) {
	h = t = NULL;
}

void insert(tqueue *&h, tqueue *&t, int item) {
	tqueue *r = (tqueue*)malloc(sizeof(tqueue));
	r->inf = item;
	r->next = NULL;
	if (!h && !t) h = t = r;
	else {
		t->next = r;
		t = r;
	}
}

int take(tqueue *&h, tqueue *&t) {
	tqueue *r = h;
	int i = r->inf;
	h = r->next;
	if (!h) t = NULL;
	free(r);
	return i;
}

int peek_queue(tqueue *&h, tqueue *&t) {
	return t->inf;
}

int empty_queue(tqueue *&h, tqueue *&t) {
	return (h&&t) ? 0 : 1;
}
