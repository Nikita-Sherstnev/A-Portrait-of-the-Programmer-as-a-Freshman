#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define PF printf
#define SC scanf
#define MAX 100

struct pupil {
	char fio[50];
	int year;
	char letter;
};

struct pupil pupil_list[MAX];

void int_list(void) {
	for (int t = 0; t < MAX; t++)
		pupil_list[t].fio[0] = '\0';
}

void output(void) {
	int t=0;
	FILE *fp;
	if ((fp = fopen("output.txt", "w")) != NULL) {
		    while (pupil_list[t].fio[0]) {
				fputs(pupil_list[t].fio, fp);
				fputc('\n', fp);
				fprintf(fp, "%d\n", pupil_list[t].year);
				fprintf(fp, "%c\n", pupil_list[t].letter);
				t++;
			}
	}
	else {
		PF("Error\n");
		exit(1);
	}
	fclose(fp);
	return;
}

int menu_select(void) {
	char s[80];
	int c;
    PF("1.Добавить ученика\n2.Вывести список\n3.Разделение на классы\n4.Выход\n");
	do {
		PF("Введите номер нужного пункта\n");
		fgets(s,80,stdin);
		c = atoi(s);
	} while (c < 1 || c > 4);
	return c;
}

int find_free(void) {
	register int t;
	for (t = 0; pupil_list[t].fio[0] != '\0' && t < MAX; ++t);
	if (t+1 == MAX) return -1;
	return t;
}

void enter(void) {
	int slot;
	char s[80];
	slot = find_free();
	if (slot == -1) {
		PF("\nСписок заполнен");
		return;
	}
	PF("Введите ФИО: ", pupil_list[slot].fio);
	fgets(pupil_list[slot].fio,50,stdin);
	pupil_list[slot].fio[strcspn(pupil_list[slot].fio, "\n")] = 0;
	PF("Введите год обучения: ");
	SC("%d", &pupil_list[slot].year);
	PF("Введите букву класса: ");
	int c;  do { c = getchar(); } while (c != '\n' && c != EOF);
	SC("%c", &pupil_list[slot].letter);
	PF("Запись добавлена.");
	output();
	return;
}

void list(void) {
	int t=0;
		while (pupil_list[t].fio[0]) {
			PF("%d.\n", t + 1);
			PF("ФИО: %s", pupil_list[t].fio);
			PF("\nГод обучения: %d", pupil_list[t].year);
			PF("\nБуква класса: %c\n", pupil_list[t].letter);
			t++;
		}
	output();
	system("pause");
	return;
}

void proverka(void) {
	int n, i, j=0, count=0, all=0;
	PF("Введите кол-во учеников в одном классе: ");
	SC("%d", &n);
	while (pupil_list[all].fio[0]) all++;
	for (i = 0; i < all; i++) {
		for (j=i+1; j<all;j++) {
			if (pupil_list[i].letter == pupil_list[j].letter) count++;
			if (count == n) {
				for (j; j < all; j++)
					if (pupil_list[i].letter == pupil_list[j].letter)
					pupil_list[j].letter++;
				break;
			}
		}
		count = 0;
	}
	output();
	return;
}

int main(void) {
	char choice, c;
	int i = 0;
	int_list();
	FILE *fp;
	if ((fp = fopen("file.txt", "r")) != NULL)
		while ((c = fgetc(fp)) != EOF) {
			ungetc(c, fp);
			fgets(pupil_list[i].fio,50,fp);
			pupil_list[i].fio[strcspn(pupil_list[i].fio, "\n")] = 0;
			fscanf(fp, "%d", &pupil_list[i].year);
			do { c = fgetc(fp); } while (c != '\n' && c != EOF);
			pupil_list[i].letter = fgetc(fp);
			do { c = fgetc(fp); } while (c != '\n' && c != EOF);
			i++;
		}
	else {
		PF("Error\n");
		exit(1);
	}
	fclose(fp);
	output();
	for (;;) {
		choice = menu_select();
		switch (choice) {
		case 1: enter(); break;
		case 2: list(); break;
		case 3: proverka(); break;
		case 4: exit(0);
		}
	}
    return 0;
}

