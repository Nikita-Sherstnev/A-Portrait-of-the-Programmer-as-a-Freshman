#include "Header.h"


int main()
{
	int ntask;
	for (;;) {
		PF("\nChoose task (1-2) or exit (3):\n");
		PF("1. Build a binary search tree and determine the degree of a given node a.\n");
		PF("2. Build a binary search tree and print its elements in ascending order of their values.\n");

		do {
			SC("%d", &ntask);
		} while (ntask < 0 || ntask > 3);

		switch (ntask) {
		case 1: task1(); break;
		case 2: task2(); break;
		case 3: fcloseall(); exit(0);
		default: fcloseall(); exit(0);
		}
	}
    return 0;
}

