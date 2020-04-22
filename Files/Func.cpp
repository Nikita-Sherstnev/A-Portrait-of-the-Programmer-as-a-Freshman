#include "Header.h"

void task1(void) {
	int i=1;
	char s[100], c;
	FILE *fp;
	if ((fp = fopen("file.txt", "r")) == NULL) {
		PF("Ошибка!");
		exit(1);
	}
		while ((c = fgetc(fp)) != EOF) {
			ungetc(c, fp);
			fgets(s, 100, fp);
			if (i % 2 == 1) {
				PF("%s", s);
			}
			i++;
		}
		PF("\n");
	fclose(fp);
	return;
}

void task2(void) {
	char len[100], ch;
	int i=0;
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
			i=0;
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

void task3(void) {
	char str[100], c;
	int length=0;
	FILE *fi, *fo;
	if ((fi = fopen("input.txt", "r")) == NULL) {
		PF("Error");
		exit(1);
	}
	fo = fopen("output.txt", "w");
	PF("\nВведите длину строк: ");
	SC("%d", &length);
	while ((c = fgetc(fi)) != EOF) {
		ungetc(c, fi);
		fgets(str, 100, fi);
		if (strlen(str)-1 > length)
			fputs(str, fo);
	}
	fclose(fi);
	fclose(fo);
	return;
}

void task4(void) {
	int num=0, countnum=0;
	float sum=0;
	char c;
	FILE *fp;
	if ((fp = fopen("numbers.txt", "r")) == NULL) {
		PF("Error");
		exit(1);
	}
	while ((c = fgetc(fp)) != EOF) {
		ungetc(c,fp);
		fscanf(fp, "%d", &num);
		sum += num;
		countnum++;
	}
	fclose(fp);
	if ((fp = fopen("numbers.txt", "a")) == NULL) {
		PF("Error");
		exit(1);
	}
	fprintf(fp, "\n%.3f", sum / countnum);
	fclose(fp);
	return;
}