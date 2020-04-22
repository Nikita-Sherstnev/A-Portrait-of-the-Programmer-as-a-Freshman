#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"

#define PF printf
#define SC scanf
#define MAX 100

struct data {
	int day;
	int month;
	int year;
};

struct data data_list[MAX];

void int_list(void) {
	int t;
	for (t = 0; t < MAX; t++)
		data_list[t].day = 0;
	return;
}

int menu_select(void) {
	char s[80];
	int c;
	system("cls");
	PF("1.Ввод даты\n2.Вывод дат\n3.Какие даты високосного года\n4.Выход");
	do {
		PF("\nВыберите нужный пункт: ");
		fgets(s,80,stdin);
		c = atoi(s);
	} while (c < 1 || c>4);
	return c;
}

void output(void) {
	int t=0;
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

int find_free(void) {
	register int slot;
	for (slot = 0; data_list[slot].day != 0 && slot < MAX; ++slot);
	if (slot+1 == MAX) return -1;
	return slot;
}

void enter(void) {
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
	int t=0;
	while (data_list[t].day != 0) {
			PF("%d) ", t+1);
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
	int t, all=0, count=0;
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
	if (count==0) PF("Таких дат нет!\n");
	system("pause");
	return;
}

int main(void)
{
	system("chcp 1251");
	char choice, c;
	int i=0;
	int_list();
	FILE *fp;
	if ((fp=fopen("file.txt","r"))!=NULL) 
		while ((c = fgetc(fp)) != EOF) {
			ungetc(c, fp);
			fscanf(fp,"%d", &data_list[i].day);
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
    return 0;
}

