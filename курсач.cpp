#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"


struct FIO {
	char name[30];
	char surname[30];
	char mid_name[30];
};

struct DATE_OF_CEL {
	int day;
	int month;
	int year;
};

struct SINGER {
	FIO person;
	char pseudo[30];
	char *sex;
	int years;
	DATE_OF_CEL date;
	char sity[30];
	char song[40];
	int number;
};

int goal() {
	FILE *f;
	if (!(f = fopen("list.txt", "r"))) {
		printf("Файла не существует\n");
		return -1;
	}
	if (getc(f) == EOF) {
		printf("Файл пуст\n");
		fclose(f);
		return -1;
	}
	system("cls");
	int i = 0;
	fseek(f, 0, SEEK_SET);
	char str[255];
	while (fgets(str, 255, f) != NULL) {
		i++;
	}
	fseek(f, 0, SEEK_SET);
	SINGER *arr = (SINGER*)malloc(i*sizeof(SINGER));
	char *sex=new char;
	i = 0;
	while (fscanf(f, " %d %d %d %s %s %s %s %s %d %s %s %d", &arr[i].date.day, &arr[i].date.month, &arr[i].date.year, &arr[i].person.surname, &arr[i].person.name, &arr[i].person.mid_name, sex, &arr[i].pseudo, &arr[i].years, &arr[i].sity, &arr[i].song, &arr[i].number) != EOF) {
		arr[i].sex = sex;
		i++;
		sex = new char;
	}
	int max = i;
	for (int k = 0; k < i; k++) {
		for (int j = 0; j < i - k; j++) {
			if (arr[j].number < arr[j + 1].number) {
				SINGER tmp;
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	for (int i = 0; i < 144; i++)
		printf("~");
	printf("\n");
		printf("|                                                         Топ 5 лучших певцов                                                                  |\n");
		for (int i = 0; i < 144; i++)
			printf("~");
		for (i = 0; i < max; i++) {
			if (i > 4) break;	
			if (arr[i].date.day < 10 && arr[i].date.month >= 10)
				printf("\n| 0%d.%d.%d |%15s %10s %15s | %7s | %15s |   %3d   | %15s | %20s |  %2d  |\n", arr[i].date.day, arr[i].date.month, arr[i].date.year, arr[i].person.surname, arr[i].person.name, arr[i].person.mid_name, arr[i].sex, arr[i].pseudo, arr[i].years, arr[i].sity, arr[i].song, arr[i].number);
			if (arr[i].date.day >= 10 && arr[i].date.month < 10)
				printf("\n| %d.0%d.%d |%15s %10s %15s | %7s | %15s |   %3d   | %15s | %20s |  %2d  |\n", arr[i].date.day, arr[i].date.month, arr[i].date.year, arr[i].person.surname, arr[i].person.name, arr[i].person.mid_name, arr[i].sex, arr[i].pseudo, arr[i].years, arr[i].sity, arr[i].song, arr[i].number);
			if (arr[i].date.day < 10 && arr[i].date.month < 10)
				printf("\n| 0%d.0%d.%d |%15s %10s %15s | %7s | %15s |   %3d   | %15s | %20s |  %2d  |\n", arr[i].date.day, arr[i].date.month, arr[i].date.year, arr[i].person.surname, arr[i].person.name, arr[i].person.mid_name, arr[i].sex, arr[i].pseudo, arr[i].years, arr[i].sity, arr[i].song, arr[i].number);
			if (arr[i].date.day >= 10 && arr[i].date.month >= 10)
				printf("\n| %d.%d.%d |%15s %10s %15s | %7s | %15s |   %3d   | %15s | %20s |  %2d  |\n", arr[i].date.day, arr[i].date.month, arr[i].date.year, arr[i].person.surname, arr[i].person.name, arr[i].person.mid_name, arr[i].sex, arr[i].pseudo, arr[i].years, arr[i].sity, arr[i].song, arr[i].number);
			for (int k = 0; k < 144; k++)
				printf("~");
		}
		printf("\nНажмите любую клавишу для выхода в меню пользователя\n");
		_getch();
		system("cls");
	fclose(f);
	return 0;
}

int show_us() {
	system("cls");
	FILE *f;
	if (!(f = fopen("users.txt", "r"))) {
		printf("Файла не существует\n");
		return -1;
	}
	if (getc(f) == EOF) {
		printf("Файл пуст\n");
		fclose(f);
		return -1;
	}
	fseek(f, 0, SEEK_SET);
	char login[255], pass[255];
	printf("Зарегестрированные пользователи\n~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	while (fscanf(f, "%s %s\n", login, pass) != EOF)
		printf("%s\n", login);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("Нажмите любую кнопку для выхода в меню управления пользователями\n");
	fclose(f);
	_getch();
	system("cls");
	return 0;
}

int verify(char *str, int n) {
	for (int i = 0; i < n; i++) {
		if (str[i] == '\0') break;
		if (str[i] == '-' || str[i] == ' ' || str[i] == '!' || str[i] == '#' || str[i] == '%' || str[i] == '^' || str[i] == '&' || str[i] == '*' || str[i] == '(' || str[i] == ')' || str[i] == '=' || str[i] == '@' || str[i] == '№' || str[i] == ';' || str[i] == ':' || str[i] == '?' || str[i] == '~' || str[i] == '^' || str[i] == '.' || str[i] == ',' || str[i] == '/' || str[i] == '|' || str[i] == '"\"' || str[i] == ',' || str[i] == '+') {
			return -1;
		}
	}
	return 0;
}

int output_data() {
	FILE *f;
	if (!(f = fopen("list.txt", "r"))) {
		printf("Ошибка открытия файла\n");
		return -1;
	}
	if (getc(f) == EOF) {
		system("cls");
		printf("Файл пуст\n");
		fclose(f);
		return -1;
	}
	fseek(f, 0, SEEK_SET);
	char name[30], surname[30], midname[30], ps[30], sex[30], sity[30], song[30];
	int yrs, numb, d, m, y;
	for (int i = 0; i < 144; i++)
		printf("~");
	printf("\n");
	printf("|    Дата    |                    ФИО                    |   Пол   |    Псевдоним    | Возраст |      Город      |         Песня        | Балл |\n");
	for (int i = 0; i < 144; i++)
		printf("~");
	printf("\n");
	while (fscanf(f, "%d %d %d %s %s %s %s %s %d %s %s %d", &d, &m, &y, surname, name, midname, sex, ps, &yrs, sity, song, &numb) != EOF) {
		if (d < 10 && m >= 10)
			printf("| 0%d.%d.%d |%15s %10s %15s | %7s | %15s |   %3d   | %15s | %20s |  %2d  |\n", d, m, y, surname, name, midname, sex, ps, yrs, sity, song, numb);
		if (d >= 10 && m < 10)
			printf("| %d.0%d.%d |%15s %10s %15s | %7s | %15s |   %3d   | %15s | %20s |  %2d  |\n", d, m, y, surname, name, midname, sex, ps, yrs, sity, song, numb);
		if (d < 10 && m < 10)
			printf("| 0%d.0%d.%d |%15s %10s %15s | %7s | %15s |   %3d   | %15s | %20s |  %2d  |\n", d, m, y, surname, name, midname, sex, ps, yrs, sity, song, numb);
		if (d > 10 && m > 10)
			printf("| %d.%d.%d |%15s %10s %15s | %7s | %15s |   %3d   | %15s | %20s |  %2d  |\n", d, m, y, surname, name, midname, sex, ps, yrs, sity, song, numb);
		for (int i = 0; i < 144; i++)
			printf("~");
		printf("\n");

	}
	printf("\nНажмите любую клавишу для возвращения в меню администратора\n");
	_getch();
	system("cls");
	fclose(f);
}

char code(char *pass) {
	for (int i = 0; pass[i] != '\0'; i++)
		pass[i] = pass[i] + 19;
	return *pass;
}

char encode(char *pass) {
	for (int i = 0; pass[i] != '\0'; i++)
		pass[i] = pass[i] - 19;
	return *pass;
}

void input_l(char *login) {
st:
	int i = 0;
	for (i; i < 99; i++) {
	iter:
		login[i] = _getch();
		if (login[0] == 8) {
			goto iter;
		}
		if (i < 4 && login[i] == 13) {
			printf("\nОшибка ввода, требуется ввести 4 и более символов, повторите ввод\n\n");
			goto st;
		}
		if (i > 14) {
			printf("\nОшибка ввода, требуется ввести менее 15 символов, повторите ввод\n\n");
			goto st;
		}
		if (login[i] == 13) {
			login[i] = '\0';
			break;
		}
		if (login[i] != 8) {
			putchar(login[i]);
		}
		else {
			printf("\b \b");
			i = i - 2;
		}
	}
	if (verify(login, i) == -1) {
		printf("\nНекорректный ввод\n");
		goto st;
	}
}

void input_p(char *password) {
st:
	int i = 0;
	for (i; i < 99; i++) {
	iter:
		password[i] = _getch();
		if (password[0] == 8) {
			goto iter;
		}
		if (i < 4 && password[i] == 13) {
			printf("\nОшибка ввода, требуется ввести 4 и более символов, повторите ввод\n\n");
			goto st;
		}
		if (i > 14) {
			printf("\nОшибка ввода, требуется ввести менее 15 символов, повторите ввод\n\n");
			goto st;
		}
		if (password[i] == 13) {
			password[i] = '\0';
			break;
		}
		if (password[i] != 8) {
			putchar('*');
		}
		else {
			printf("\b \b");
			i = i - 2;
		}
		if (verify(password, i) == -1) {
			printf("\nНекорректный ввод\n");
				goto st;
		}
	}
}

int search() {
	FILE *f;
	if (!(f = fopen("list.txt", "r"))) {
		printf("Файла не существует\n");
		return -1;
	}
	if (getc(f) == EOF) {
		printf("Файл пуст\n");
		fclose(f);
		return -1;
	}
	system("cls");
	fseek(f, 0, SEEK_SET);
	char name[30], surname[30], midname[30], ps[30], sex[8], sity[30], song[30], *sx;
	int yrs, numb, d, m, y;
	char *sch_song = (char*)malloc(sizeof(SINGER));
	int flag = 0;
	printf("Введите песню для поиска\n\n");
	input_l(sch_song);
	printf("\n\n");
	while (fscanf(f, "%d %d %d %s %s %s %s %s %d %s %s %d", &d, &m, &y, surname, name, midname, sex, ps, &yrs, sity, song, &numb) != EOF) {
		if (strcmp(sch_song, song) == 0) {
			for (int i = 0; i < 144; i++)
				printf("~");
			printf("\n");
				if (flag == 0) {
					printf("|                                                             Найденные записи                                                                 |\n");
					for (int i = 0; i < 144; i++)
						printf("~");
					printf("\n");
				}
			if (d < 10 && m >= 10)
				printf("| 0%d.%d.%d |%15s %10s %15s | %7s | %15s |   %3d   | %15s | %20s |  %2d  |\n",d ,m, y, surname, name, midname, sex, ps, yrs, sity, song, numb);
			if (d >= 10 && m < 10)
				printf("| %d.0%d.%d |%15s %10s %15s | %7s | %15s |   %3d   | %15s | %20s |  %2d  |\n", d, m, y, surname, name, midname, sex, ps, yrs, sity, song, numb);
			if (d < 10 && m < 10)
				printf("| 0%d.0%d.%d |%15s %10s %15s | %7s | %15s |   %3d   | %15s | %20s |  %2d  |\n", d, m, y, surname, name, midname, sex, ps, yrs, sity, song, numb);
			if (d >= 10 && m >= 10)
				printf("| %d.%d.%d |%15s %10s %15s | %7s | %15s |   %3d   | %15s | %20s |  %2d  |\n", d, m, y, surname, name, midname, sex, ps, yrs, sity, song, numb);
			flag++;
		}
	}
	if (flag != 0) {
		for (int i = 0; i < 144; i++)
			printf("~");
		fclose(f);
		printf("\n\nНажмите любую клавишу для выхода в меню сортировки и поиска\n");
		_getch();
		system("cls");
	}
	else {
		system("cls");
		printf("Совпадений не найдено\n\nНажмите любую клавишу для выхода в меню сортировки и поиска\n");
		_getch();
		system("cls");
		fclose(f);
	}
		return 0;

}

int filtr() {
	//фильтрация по дате
	FILE *f;
	if (!(f = fopen("list.txt", "r"))) {
		printf("Файла не существует\n");
		return -1;
	}
	if (getc(f) == EOF) {
		printf("Файл пуст\n");
		fclose(f);
		return -1;
	}
	fseek(f, 0, SEEK_SET);
start:
	int age1, age2, i=0;
	char str[255];
	printf("Введите возрастные рамки\n~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("С: ");
	if (scanf("%d", &age1) != 1) {
		while (getchar() != '\n');
		printf("Ошибка ввода\n");
		goto start;
	}
	if (age1 < 1) {
		printf("Ошибка ввода\n");
		goto start;
	}
	printf("\nПо: ");
	if (scanf("%d", &age2) != 1) {
		while (getchar() != '\n');
		printf("Ошибка ввода\n");
		goto start;
	}
	if (age2 < 1) {
		printf("Ошибка ввода\n");
		goto start;
	}
	while (fgets(str, 255, f) != NULL) {
		i++;
	}
	int max = i;
	SINGER *arr = (SINGER*)malloc(i*sizeof(SINGER));
	char *sex= new char;
	i = 0;
	fseek(f, 0, SEEK_SET);
	while (fscanf(f, "%d %d %d %s %s %s %s %s %d %s %s %d\n",&arr[i].date.day, &arr[i].date.month, &arr[i].date.year, &arr[i].person.surname, &arr[i].person.name, &arr[i].person.mid_name, sex, &arr[i].pseudo, &arr[i].years, &arr[i].sity, &arr[i].song, &arr[i].number) != EOF) {
		arr[i].sex = sex;
		i++;
		sex = new char;
	}
	system("cls");
	int flag = 0;
	for (int k = 0; k < max; k++) {
		if ((arr[k].years<=age2 && arr[k].years>=age1)|| (arr[k].years >= age2 && arr[k].years <= age1)) {
			if (flag == 0) {
				for (int i = 0; i < 144; i++)
					printf("~");
				printf("\n");
				printf("|                                                             Найденные записи                                                                 |\n");
				for (int i = 0; i < 144; i++)
					printf("~");
				printf("\n");
			}
			if (arr[k].date.day < 10 && arr[k].date.month >= 10)
				printf("| 0%d.%d.%d |%15s %10s %15s | %7s | %15s |   %3d   | %15s | %20s |  %2d  |\n", arr[k].date.day, arr[k].date.month, arr[k].date.year, arr[k].person.surname, arr[k].person.name, arr[k].person.mid_name, arr[k].sex, arr[k].pseudo, arr[k].years, arr[k].sity, arr[k].song, arr[k].number);
			if (arr[k].date.day >= 10 && arr[k].date.month < 10)
				printf("| %d.0%d.%d |%15s %10s %15s | %7s | %15s |   %3d   | %15s | %20s |  %2d  |\n", arr[k].date.day, arr[k].date.month, arr[k].date.year, arr[k].person.surname, arr[k].person.name, arr[k].person.mid_name, arr[k].sex, arr[k].pseudo, arr[k].years, arr[k].sity, arr[k].song, arr[k].number);
			if (arr[k].date.day < 10 && arr[k].date.month < 10)
				printf("| 0%d.0%d.%d |%15s %10s %15s | %7s | %15s |   %3d   | %15s | %20s |  %2d  |\n", arr[k].date.day, arr[k].date.month, arr[k].date.year, arr[k].person.surname, arr[k].person.name, arr[k].person.mid_name, arr[k].sex, arr[k].pseudo, arr[k].years, arr[k].sity, arr[k].song, arr[k].number);
			if (arr[k].date.day >= 10 && arr[k].date.month >= 10)
				printf("| %d.%d.%d |%15s %10s %15s | %7s | %15s |   %3d   | %15s | %20s |  %2d  |\n", arr[k].date.day, arr[k].date.month, arr[k].date.year, arr[k].person.surname, arr[k].person.name, arr[k].person.mid_name, arr[k].sex, arr[k].pseudo, arr[k].years, arr[k].sity, arr[k].song, arr[k].number);
			for (int i = 0; i < 144; i++)
				printf("~");
			printf("\n");
			flag++;
		}
	}
	if (flag == 0) {
		system("cls");
		printf("Записей из указанного диапозона не было найдено\n\n");
		printf("Для выхода в меню сортировки и фильтрации нажмите любую кнопку\n");
		_getch();
		system("cls");
		fclose(f);
		return 0;
	}
	printf("Для выхода в меню сортировки и фильтрации нажмите любую кнопку\n");
	_getch();
	system("cls");
	fclose(f);
	return 0;
}

int sort() {
	FILE *f;
	if (!(f = fopen("list.txt", "r"))) {
		printf("Файла не существует\n");
		return -1;
	}
	if (getc(f) == EOF) {
		printf("Файл пуст\n");
		fclose(f);
		return -1;
	}
	fseek(f, 0, SEEK_SET);
	int i = 0;
	char str[255];
	while (fgets(str, 255, f) != NULL) {
		i++;
	}
	fseek(f, 0, SEEK_SET);
	SINGER *arr = new SINGER[i+1];
	char *sex= new char;
	i = 0;
	while (fscanf(f, " %d %d %d %s %s %s %s %s %d %s %s %d",&arr[i].date.day, &arr[i].date.month, &arr[i].date.year, &arr[i].person.surname, &arr[i].person.name, &arr[i].person.mid_name, sex, &arr[i].pseudo, &arr[i].years, &arr[i].sity, &arr[i].song, &arr[i].number) != EOF) {
		arr[i].sex = sex;
		i++;
		sex = new char;
	}
	for (int k = 0; k < i; k++) {
		for (int j = 0; j < i - k; j++) {
			if (arr[j].number < arr[j + 1].number) {
				SINGER tmp;
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	FILE *ex;
	if (!(ex = fopen("list_sorted.txt", "w"))) {
		printf("Файла не существует\n");
		return -1;
	}
	for (int k = 0; k < i; k++) {
		if(arr[k].date.day < 10 && arr[k].date.month >= 10)
			fprintf(ex,  "0%d %d %d %s %s %s %s %s %d %s %s %d\n", arr[k].date.day, arr[k].date.month, arr[k].date.year, arr[k].person.surname, arr[k].person.name, arr[k].person.mid_name, arr[k].sex, arr[k].pseudo, arr[k].years, arr[k].sity, arr[k].song, arr[k].number);
		if (arr[k].date.day >= 10 && arr[k].date.month < 10)
			fprintf(ex, "%d 0%d %d %s %s %s %s %s %d %s %s %d\n", arr[k].date.day, arr[k].date.month, arr[k].date.year, arr[k].person.surname, arr[k].person.name, arr[k].person.mid_name, arr[k].sex, arr[k].pseudo, arr[k].years, arr[k].sity, arr[k].song, arr[k].number);
		if (arr[k].date.day < 10 && arr[k].date.month < 10)
			fprintf(ex, "0%d 0%d %d %s %s %s %s %s %d %s %s %d\n", arr[k].date.day, arr[k].date.month, arr[k].date.year, arr[k].person.surname, arr[k].person.name, arr[k].person.mid_name, arr[k].sex, arr[k].pseudo, arr[k].years, arr[k].sity, arr[k].song, arr[k].number);
		if (arr[k].date.day >= 10 && arr[k].date.month >= 10)
			fprintf(ex, "0%d %d %d %s %s %s %s %s %d %s %s %d\n", arr[k].date.day, arr[k].date.month, arr[k].date.year, arr[k].person.surname, arr[k].person.name, arr[k].person.mid_name, arr[k].sex, arr[k].pseudo, arr[k].years, arr[k].sity, arr[k].song, arr[k].number);
	}
	fclose(f);
	fclose(ex);
	remove("list.txt");
	rename("list_sorted.txt", "list.txt");
	return 0;
}

int rem_list() {
	FILE *f;
	system("cls");
	if (!(f = fopen("list.txt", "r"))) {
		printf("Ошибка открытия файла\n");
		return -1;
	}
	if (getc(f) == EOF) {
		printf("Файл пуст\n");
		fclose(f);
		return -1;
	}
	fseek(f, 0, SEEK_SET);
	char name[30], surname[30], midname[30], ps[30], sex[8], sity[30], song[30], *sx;
	int yrs, numb, d, m, y;
ch:
	printf("Выберите данные для удаления\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	int i = 0, chs;
	while (fscanf(f, "%d %d %d %s %s %s %s %s %d %s %s %d", &d, &m, &y, surname, name, midname, sex, ps, &yrs, sity, song, &numb) != EOF) {
		i++;
		printf("%d) %s %s %s\n", i, surname, name, midname);
	}
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
	fseek(f, 0, SEEK_SET);
	fclose(f);
	if ((scanf("%d", &chs))!=1) {
		while (getchar() != '\n');
		printf("Ошибка ввода\n");
		goto ch;
	}
	if (chs<1 || chs>i) {
		printf("Такой записи не существует\n");
		goto ch;
	}
	if (!(f = fopen("list.txt", "r"))) {
		printf("Ошибка открытия файла\n");
		return -1;
	}
	fseek(f, 0, SEEK_SET);
	FILE *chng;
	if (!(chng = fopen("list_old.txt", "w"))) {
		printf("Ошибка открытия файла\n");
		return -1;
	}
	int dr = 0;
	while (fscanf(f, "%d %d %d %s %s %s %s %s %d %s %s %d", &d, &m, &y, surname, name, midname, &sex, ps, &yrs, sity, song, &numb) != EOF) {
		sx = sex;
		dr++;
		if (dr != chs) {

			if (d < 10 && m >= 10)
				fprintf(chng, "0%d %d %d %s %s %s %s %s %d %s %s %d\n", d, m, y, surname, name, midname, sex, ps, yrs, sity, song, numb);
			
			if (d >= 10 && m < 10)
				fprintf(chng, "%d 0%d %d %s %s %s %s %s %d %s %s %d\n", d, m, y, surname, name, midname, sex, ps, yrs, sity, song, numb);
			
			if (d < 10 && m < 10)
				fprintf(chng, "0%d 0%d %d %s %s %s %s %s %d %s %s %d\n", d, m, y, surname, name, midname, sex, ps, yrs, sity, song, numb);
			
			if (d > 10 && m > 10)
				fprintf(chng, "%d %d %d %s %s %s %s %s %d %s %s %d\n", d, m, y, surname, name, midname, sex, ps, yrs, sity, song, numb);
		}
	}
	system("cls");
	printf("Запись успешно удалена\n\nНажмите любую кнопку для возврата в меню администратора\n");
	_getch();
	system("cls");
	fclose(chng);
	fclose(f);
	remove("list.txt");
	rename("list_old.txt", "list.txt");
	system("cls");
}

int change_list() {
	FILE *f;
	if (!(f = fopen("list.txt", "r"))) {
		printf("Ошибка открытия файла\n");
		return -1;
	}
	if (getc(f) == EOF) {
		printf("Файл пуст\n");
		fclose(f);
		return -1;
	}
	fseek(f, 0, SEEK_SET);
	char name[30], surname[30], midname[30], ps[30], sex[8], sity[30], song[30], *sx;
	int yrs, numb, day, m, y;
	printf("Выберите данные для редактирования\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	int i = 0, chs;
	while (fscanf(f, "%d %d %d %s %s %s %s %s %d %s %s %d", &day, &m, &y, surname, name, midname, sex, ps, &yrs, sity, song, &numb) != EOF) {
		i++;
		printf("%d) %s %s %s\n", i, surname, name, midname);
	}
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
ch:
	if ((scanf("%d", &chs)) != 1) {
		while (getchar() != '\n');
		printf("Ошибка ввода, повторите ввод\n");
		goto ch;
	}
	if (chs < 1 || chs > i) {
		printf("Ошибка ввода, повторите ввод\n");
		goto ch;
	}
	fclose(f);
	if (!(f = fopen("list.txt", "r"))) {
		printf("Ошибка открытия файла\n");
		return -1;
	}
	fseek(f, 0, SEEK_SET);
	FILE *chng;
	if (!(chng = fopen("list_old.txt", "w"))) {
		printf("Ошибка открытия файла\n");
		return -1;
	}
	int d = 0;
	while (fscanf(f, "%d %d %d %s %s %s %s %s %d %s %s %d", &day, &m, &y, surname, name, midname, &sex, ps, &yrs, sity, song, &numb) != EOF) {
		sx = sex;
		d++;
		if (d != chs) {
			fprintf(chng, "%d %d %d %s %s %s %s %s %d %s %s %d\n", day, m, y, surname, name, midname, sex, ps, yrs, sity, song, numb);
		}
		else {
			system("cls");
		pck:
			printf("\nЧто вы хотите поменять?\n");
			printf("~~~~~~~~~~~~~~~~\n1-Дату\n2-Имя\n3-Фамилию\n4-Отчество\n5-Пол\n6-Псевдоним\n7-Возраст\n8-Город\n9-Песня\n10-Оценка\n~~~~~~~~~~~~~~~~\n");
			int p;
			if (scanf("%d", &p) != 1) {
				printf("Ошибка ввода\n");
				goto pck;
			}
			if (p <1 || p>10) {
				printf("Ошибка ввода\n");
				goto pck;
			}
			switch (p) {
			case 1: {
				system("cls");
				printf("\nВведите новую дату\n");
			D:
				printf("День: ");
				if ((scanf("%d", &day)) != 1) {
					while (getchar() != '\n');
					printf("Ошибка ввода\n");
					goto D;
				}
				if (day < 1 || day > 31) {
					printf("Такого дня не существует\n");
					goto D;
				}
			M:
				printf("\nМесяц: ");
				if ((scanf("%d", &m)) != 1) {
					while (getchar() != '\n');
					printf("Ошибка ввода\n");
					goto M;
				}
				if (m < 1 || m>12) {
					printf("Такого месяца не существует\n");
					goto M;
				}
			Y:
				printf("\nГод: ");
				if ((scanf("%d", &y)) != 1) {
					while (getchar() != '\n');
					printf("Ошибка ввода\n");
					goto Y;
				}
				if ( y < 2000 || y >3000) {
					printf("А ты мечтатель)\n");
					goto Y;
				}
				system("cls");
				break;
			}
			case 2: {
				system("cls");
				printf("\nВведите новое имя\n");
				input_l(name);
				printf("\n");
				system("cls");
				break;
			}
			case 3:
			{
				system("cls");
				printf("\nВведите новую фамилию\n");
				input_l(surname);
				printf("\n");
				system("cls");
				break;
			}
			case 4:
			{
				system("cls");
				printf("\nВведите новое отчество\n");
				input_l(midname);
				printf("\n");
				system("cls");
				break;
			}
			case 5:
			{
				system("cls");
			def:
				printf("\nВыберите пол участника\n");
				printf("~~~~~~~~~~\n1.Мужской\n2.Женский\n~~~~~~~~~~\n");
				char sex_chs = _getche();
				if (sex_chs != '1' && sex_chs != '2') {
					system("cls");
					printf("Ошибка ввода, повторите ввод\n");
					goto def;
				}
				if (sex_chs == '1')
					sx = "Мужской";
				else
					sx = "Женский";
				system("cls");
				break;
			}
			case 6:
			{
				system("cls");
				printf("\nВведите новый псевдоним\n");
				input_l(ps);
				printf("\n");
				system("cls");
				break;
			}
			case 7:
			{
				system("cls");
				olding:
				printf("\nВведите новый возраст\n");
				if ((scanf("%d", &yrs)) != 1) {
					while (getchar() != '\n');
					system("cls");
					printf("Ошибка ввода\n");
					goto olding;
				}
				if (yrs < 0 || yrs>100) {
					system("cls");
					printf("Ошибка ввода\n");
					goto olding;
				}
				system("cls");
				break;
			}
			case 8:
			{
				system("cls");
				printf("\nВведите новый город\n");
				input_l(sity);
				printf("\n");
				system("cls");
				break;
			}
			case 9:
			{
				system("cls");
				printf("\nВведите новую песню\n");
				input_l(song);
				printf("\n");
				system("cls");
				break;
			}
			case 10:
			{
				system("cls");
				mark:
				printf("\nВведите новую оценку\n");
				if ((scanf("%d", &numb)) != 1) {
					while (getchar() != '\n');
					system("cls");
					printf("Ошибка ввода\n");
					goto mark;
				}
				if (numb > 10 || numb < 0) {
					system("cls");
					printf("Ошибка ввода\n");
					goto mark;
				}
				system("cls");
				break;
			}
		}
		if (day < 10 && m >= 10)
			fprintf(chng, "0%d %d %d %s %s %s %s %s %d %s %s %d\n", day, m, y, surname, name, midname, sx, ps, yrs, sity, song, numb);
		if (day >= 10 && m < 10)
			fprintf(chng, "%d 0%d %d %s %s %s %s %s %d %s %s %d\n", day, m, y, surname, name, midname, sx, ps, yrs, sity, song, numb);
		if (day < 10 && m < 10)
			fprintf(chng, "0%d 0%d %d %s %s %s %s %s %d %s %s %d\n", day, m, y, surname, name, midname, sx, ps, yrs, sity, song, numb);
		if (day >= 10 && m >= 10)
			fprintf(chng, "%d %d %d %s %s %s %s %s %d %s %s %d\n", day, m, y, surname, name, midname, sx, ps, yrs, sity, song, numb);
		}
	}
	system("cls");
	printf("Запись успешно отредактирована\n\nДля возврата в меню администратора нажмите любую кнопку\n");
	_getch();
	system("cls");
	    fclose(chng);
		fclose(f);
		remove("list.txt");
		rename("list_old.txt", "list.txt");
}

int change_us() {
	FILE *f;
	if (!(f = fopen("users.txt", "r"))) {
		printf("Ошибка открытия файла\n");
		return -1;
	}
	if (getc(f) == EOF) {
		printf("Файл пуст\n");
		fclose(f);
		return -1;
	}
	fseek(f, 0, SEEK_SET);
	char user_l[100], user_p[100];

	printf("Выберите пользователя для редактирования\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	int i = 0, chs;
	while (fscanf(f, "%s %s", user_l, user_p) != EOF) {
		i++;
		*user_p = encode(user_p);
		printf("%d)Логин: %s       Пароль: %s\n", i, user_l, user_p);
	}
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
ch:
	if ((scanf("%d", &chs)) != 1) {
		while (getchar() != '\n');
		printf("Ошибка ввода, повторите ввод\n");
		goto ch;
	}
	printf("\n");
	if (chs < 1 || chs > i) {
		printf("Ошибка ввода, повторите ввод\n");
		goto ch;
	}
	system("cls");
	fclose(f);
	if (!(f = fopen("users.txt", "r"))) {
		system("cls");
		printf("Ошибка открытия файла\n");
		return -1;
	}
	fseek(f, 0, SEEK_SET);
	FILE *chng;
	if (!(chng = fopen("users_old.txt", "w"))) {
		system("cls");
		printf("Ошибка открытия файла\n");
		return -1;
	}
	int d = 0;
	while (fscanf(f, "%s\t%s", user_l, user_p) != EOF) {
		*user_p = encode(user_p);
		d++;
		if (d != chs) {
			*user_p = code(user_p);
			fprintf(chng, "%s\t%s\n", user_l, user_p);
		}
		else {
			pck:
			printf("~~~~~~~~~~~~~~~~~~~\n1-Поменять логин\n2-Поменять пароль\n~~~~~~~~~~~~~~~~~~\n");
			char p;
			p = _getch();
			if (p != '1' && p != '2' && p!='3') {
				printf("Ошибка ввода\n");
					goto pck;
			}
			system("cls");
			switch (p) {
			case '1': {
				new_log:
				printf("Введите новый логин\n");
				input_l(user_l);
				char user_ver[100];
				FILE *read;
				if ((read = fopen("users.txt", "r"))) {
					while (fscanf(read, "%s\n", user_ver) != EOF) {
						if (strcmp(user_ver, user_l) == 0) {
							printf("\nТакой пользователь уже существует, повторите ввод\n");
							fclose(read);
							goto new_log;
						}
					}
				}
				fclose(read);
				fflush(stdin);
				break;
			}
			case '2':
				printf("Введите новый пароль\n");
				input_l(user_p);
				fflush(stdin);
				break;
			}
			*user_p = code(user_p);	
			fprintf(chng, "%s\t%s\n", user_l, user_p);
		}
	}
	fclose(f);
	fclose(chng);
	remove("users.txt");
	rename("users_old.txt", "users.txt");
	system("cls");
	printf("Пользователь успешно отредоктирован\n\n");
	printf("Нажмите любую клавишу для выхода в меню управления пользователями\n");
	_getch();
	system("cls");
}

int user_delete() {
	FILE *f;
	if (!(f = fopen("users.txt", "r"))) {
		printf("Ошибка открытия файла\n");
		return -1;
	}
	if (getc(f) == EOF) {
		printf("Файл пуст\n");
		fclose(f);
		return -1;
	}
	fseek(f, 0, SEEK_SET);
	char user_l[100], user_p[100];
	printf("Выберите пользователя для удаления\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	int i = 0, chs;
	while (fscanf(f, "%s\t%s", user_l, user_p) != EOF) {
		*user_p = encode(user_p);
		i++;
		printf("%d) %s\n", i, user_l	);
	}
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
	rem:
	scanf("%d", &chs);
	if (chs < 1 || chs > i) {
		system("cls");
		printf("Ошибка ввода\n");
		goto rem;
	}
	fclose(f);
	if (!(f = fopen("users.txt", "r"))) {
		system("cls");
		printf("Ошибка открытия файла\n");
		return -1;
	}
	fseek(f, 0, SEEK_SET);
	FILE *del;
	if (!(del = fopen("users_old.txt", "w"))) {
		system("cls");
		printf("Ошибка открытия файла\n");
		return -1;
	}
	int d=0;
	while (fscanf(f, "%s\t%s", user_l, user_p) != EOF) {
		*user_p = encode(user_p);
		d++;
		if (d != chs) {
			*user_p = code(user_p);
			fprintf(del, "%s\t%s\n",user_l, user_p);
		}
	}
	fclose(f);
	fclose(del);
	remove("users.txt");
	rename("users_old.txt", "users.txt");
	return 0;
}

void menu() {
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~\n1.Вход под администратором\n2.Вход под пользователем\n3.Выход\n~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

int add_user() {
	FILE *f;
	if (!(f = fopen("users.txt", "a"))) {
		printf("Ошибка открытия файла\n");
		return -1;
	}
	add_us:
	printf("Введите логин\n");
	char log[100], password[100];
	input_l(log);
	printf("\nВведите пароль\n");
	input_p(password);
	if (verify(log, 99) == -1) {
		printf("\nНеверно введен логин или пароль, повторите ввод\n\n");
		goto add_us;
	}
	if (verify(password, 99) == -1) {
		printf("\nНеверно введен логин или пароль, повторите ввод\n\n");
		goto add_us;
	}
	FILE *read;
	if (!(read = fopen("users.txt", "r"))) {
		printf("Ошибка открытия файла\n");
		return -1;
	}
	char user_l[100];
	while (fscanf(read, "%s\n", user_l) != EOF) {
		if (strcmp(log, user_l) == 0) {
			printf("\nТакой пользователь уже существует, повторите ввод\n\n");
			fclose(read);
			goto add_us;
		}
	}
	fclose (read);
	printf("\n\n");
	*password = code(password);
	fprintf(f, "%s\t%s\n", log, password);
	fclose(f);
}

int menu_adm() {
	system("cls");
start_a:
	printf("\n     Меню администратора:\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n1)Создание нового файла с данными\n2)Добавление записи\n3)Редактирование записи\n4)Удаление записи\n5)Просмотр данных\n6)Поиск и фильтрация\n7)Управление пользователем\n8)Выход и первоначальное меню\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
	int n;
	n = _getch();
	if (n!='1' && n != '2' && n != '3' && n != '4' & n != '5' && n != '6' && n != '7' && n != '8') {
		system("cls");
		printf("\nОшибка ввода\n\n");
		printf("Нажмите любую клавишу для возвращения в меню администратора\n");
		_getch();
		system("cls");
		goto start_a;
	}
	switch (n) {
	case '1':
		FILE *fa;
		if (!(fa = fopen("list.txt", "w"))) {
			printf("Ошибка создания файла\n");
			goto start_a;
		}
		system("cls");
		printf("Новый файл успешно создан\n");
		fclose(fa);
		goto start_a;
	case '2':
	{
		FILE *fo;
		if (!(fo = fopen("list.txt", "r"))) {
			printf("Вы не создали файла\n");
			goto start_a;
		}
		fclose(fo);
		system("cls");
		SINGER psn;
		char sex_chs;
		printf("\nВведите дату выступления\n\n");
		fflush(stdin);
		D:
		printf("День: ");
		if ((scanf("%d", &psn.date.day)) != 1) {
			while (getchar() != '\n');
			printf("Ошибка ввода\n");
			goto D;
		}
		if (psn.date.day < 1 || psn.date.day>31) {
			printf("Такого дня не существует\n");
			goto D;
		}
		M:	
		printf("\nМесяц: ");
		if ((scanf("%d", &psn.date.month)) != 1) {
			while (getchar() != '\n');
			printf("Ошибка ввода\n");
			goto M;
		}
		if (psn.date.month < 1 || psn.date.month>12) {
			printf("Такого месяца не существует\n");
			goto M;
		}
		Y:
		printf("\nГод: ");
		if ((scanf("%d", &psn.date.year)) != 1) {
			while (getchar() != '\n');
			printf("Ошибка ввода\n");
			goto Y;
		}
		if (psn.date.year < 2000 || psn.date.year>3000) {
			printf("А ты мечтатель)\n");
			goto Y;
		}
		printf("\nВведите фамилию участника\n");
		input_l(psn.person.surname);
		printf("\nВведите имя участника\n");
		input_l(psn.person.name);
		printf("\nВведите отчество участника\n");
		input_l(psn.person.mid_name);
		printf("\nВведите псевдоним участника\n");
		input_l(psn.pseudo);
	old:
		printf("\nВведите возраст участника\n");
		if ((scanf("%d", &psn.years)) != 1) {
			while (getchar() != '\n');
			printf("Ошибка ввода\n");
			goto old;
		}
		if (psn.years > 100 || psn.years<0 ) {
			printf("Выход за пределы разумного\n");
			goto old;
		}
	sex:
		printf("\nВыберите пол участника\n");
		printf("1.Мужской\n2.Женский\n");
		sex_chs = _getche();
		if (sex_chs != '1' && sex_chs != '2') {
			printf("Ошибка ввода\n");
			goto sex;
		}
		if (sex_chs == '1')
			psn.sex = "Мужской";
		else
			psn.sex = "Женский";
		printf("\nВведите родной город участника\n");
		input_l(psn.sity);
		printf("\nВведите название песни\n");
		input_l(psn.song);
		printf("\nОценка жюри(целое число по 10ибальной шкале)\n");
	marking:
		if ((scanf("%d", &psn.number)) != 1) {
			while (getchar() != '\n');
			printf("Ошибка ввода\n");
			goto marking;
		}
		if (psn.number < 0 || psn.number>10) {
			printf("Такой оценки не существует, повторите ввод\n");
			goto marking;
		}
		FILE *fw;
		if (!(fw = fopen("list.txt", "a"))) {
			printf("Ошибка открытия файла для записи\n");
			goto start_a;
		}
		fprintf(fw, " %d %d %d %s %s %s %s %s %d %s %s %d\n", psn.date.day, psn.date.month, psn.date.year, psn.person.surname, psn.person.name, psn.person.mid_name, psn.sex, psn.pseudo, psn.years, psn.sity, psn.song, psn.number);
		fclose(fw);
		system("cls");
		goto start_a;
	}
	case '3':
		system("cls");
		if (change_list() == -1)
			goto start_a;
		goto start_a;
	case '4':
		printf("\n");
		if (rem_list() != 1)
			goto start_a;
		goto start_a;
	case '5':
		printf("\n");
		system("cls");
		if (output_data() == -1)
			goto start_a;
		goto start_a;
	case '6':
		system("cls");
		sands:
		int a;
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n1)Отсортировать данные по оценкам жюри\n2)Поиск по исполняемой песне\n3)Фильтрация по возрасту исполнителей\n4)Выход в меню администратора\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		a = _getch();
		if (a != '1' && a != '2' && a != '3' && a != '4') {
			system("cls");
			printf("\nТакой функции не существует\n");
			goto sands;
		}
		printf("\n");
		switch (a) {
		case '1':
			if (sort() != -1) {
				system("cls");
				printf("Данные успешно отсортированы по наивысшему баллу");
				printf("\n\nНажмите любую клавишу для выхода в меню сортировки и поиска\n");
				_getch();
				system("cls");
				goto sands;
			}
			system("cls");
			goto sands;
		case '2':
			if (search() != -1) {
				goto sands;
			}
			goto sands;
		case '3':
			system("cls");
			filtr();
			system("cls");
			goto sands;
			
		case '4':
			system("cls");
			goto start_a;
		}
	case '7':
		char chs;
		system("cls");
		managing:
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n1)Добавление пользователя\n2)Удаление пользователя\n3)Редактирование пользователя\n4)Просмотр всех пользоватеей\n5)Выход в меню администратора\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
		chs = _getch();
		if (chs != '1' && chs != '2' && chs != '3' && chs!='4'&& chs != '5') {
			system("cls");
			printf("Ошибка ввода\n");
			goto managing;
		}
		switch (chs) {
		case '1':
			system("cls");
			switch (add_user()) {
			case 0:
				system("cls");
				printf("Пользователь успешно добавлен\n");
				printf("\nНажмите любую кнопку для выхода в меню управления пользователями\n");
				_getch();
				system("cls");
				goto managing;
			case -1:
				system("cls");
				return -1;
			}
		case '2':
			system("cls");
			if (user_delete() == -1) {
				goto managing;
			}
			else {
				system("cls");
				printf("Пользователь успешно удален\n");
				printf("\nНажмите любую кнопку для выхода в меню управления пользователями\n");
				_getch();
				system("cls");
				goto managing;
			}
		case '3':
			system("cls");
			change_us();
			goto managing;
		case '4':
			if (show_us() == -1) {
				goto managing;
			}
			goto managing;
		case '5':
			menu_adm();
		}
	case '8':
		system("cls");
		return 0;
	}
}

void menu_user() {
	system("cls");
	int ver = 0;
m_u:
	printf("\n     Меню пользователя\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n1)Открытие файла с данными\n2)Просмотр всех данных в табличной форме\n3)Процедуры поиска и фильтрации данных\n4)Топ 5 лучших исполнителей\n5)Выход в первоначальное меню\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
	char in;
	in = _getch();
	if (in != '1' && in != '2' && in != '3' && in != '4' && in != '5') {
		system("cls");
		printf("\nОшибка ввода\n");
		printf("\nДля возвращения в меню пользователя нажмите любую кнопку\n");
		_getch();
		system("cls");
		goto m_u;
	}
	switch (in) {
	case '1':
	{
		FILE *f;
		if (ver != 0) {
			system("cls");
			printf("Файл уже открыт\n");
			printf("\nДля возвращения в меню пользователя нажмите любую кнопку\n");
			_getch();
			system("cls");
			goto m_u;
		}
		if (!(f = fopen("list.txt", "r"))) {
			system("cls");
			printf("Файл не найден\n");
			printf("\nДля возвращения в меню пользователя нажмите любую кнопку\n");
			_getch();
			system("cls");
			goto m_u;
		}
		if (getc(f) == EOF) {
			system("cls");
			printf("Файл пуст\n");
			fclose(f);
			printf("\nДля возвращения в меню пользователя нажмите любую кнопку\n");
			_getch();
			system("cls");
			goto m_u;
		}
		fseek(f, 0, SEEK_SET);
		fclose(f);
		system("cls");
		printf("Файл успешно открыт\n");
		printf("\nДля возвращения в меню пользователя нажмите любую кнопку\n");
		_getch();
		system("cls");
		ver++;
		goto m_u;
	}
	case '2':
	{
		if (ver == NULL) {
			system("cls");
			printf("Вы не открыли файл с данными\n");
			printf("\nДля возвращения в меню пользователя нажмите любую кнопку\n");
			_getch();
			system("cls");
			goto m_u;
		}
		FILE *f;
		f = fopen("list.txt", "r");
		fseek(f, 0, SEEK_SET);
		if (getc(f) == EOF) {	
			printf("Файл пуст\n");
			fclose(f);
			goto m_u;
		}
		fseek(f, 0, SEEK_SET);
		char str[255];
		system("cls");
		output_data();
		fclose (f);
		goto m_u;
	}
	case '3':
	{
		if (ver == NULL) {
			system("cls");
			printf("Вы не открыли файл с данными\n");
			printf("\nДля возвращения в меню пользователя нажмите любую кнопку\n");
			_getch();
			system("cls");
			goto m_u;
		}
		FILE *f;
		f = fopen("list.txt", "r");
		fseek(f, 0, SEEK_SET);
		if (getc(f) == EOF) {
			printf("Файл пуст\n");
			fclose(f);
			goto m_u;
		}
		fseek(f, 0, SEEK_SET);
		fclose(f);
	sands:
		system("cls");
		int a;
		printf("1)Отсортировать данные по оценкам жюри\n2)Поиск по исполняемой песне\n3)Фильтрация по возрасту исполнителей\n4)Выход в меню авторизации\n");
		a = _getch();
		if (a != '1' && a != '2' && a != '3' && a != '4') {
			printf("\nТакой функции не существует\n");
			goto sands;
		}
		system("cls");
		switch (a) {
		case '1':
			if (sort() == 0) {
				printf("Данные успешно отсортированы по наивысшему баллу\n");
				printf("\nДля возвращения в меню пользователя нажмите любую кнопку\n");
				_getch();
				goto sands;
			}
			goto sands;
		case '2':
			if (search() != -1) {
				goto sands;
			}
			goto sands;
		case '3':
			system("cls");
			filtr();
			system("cls");
			goto sands;
		case '4':
			system("cls");
			goto m_u;
		}
	}
	case '4':
		if (ver == NULL) {
			system("cls");
			printf("Вы не открыли файл с данными\n");
			printf("\nДля возвращения в меню пользователя нажмите любую кнопку\n");
			_getch();
			system("cls");
			goto m_u;
		}
		if (goal() == -1) {
			goto m_u;
		}
		goto m_u;
	case '5':
		break;
	}
	system("cls");
}

int vhod_adm() {
	FILE *adm;
	if (!(adm = fopen("adm.txt", "w"))) {
		printf("Ошибка открытия файла\n");
		return -1;
	}
	char log_adm[] = { "TrueFire" };
	char pass_adm[] = { "123True" };
	*pass_adm = code(pass_adm);
	fprintf(adm, "%s %s\n", log_adm, pass_adm);
	*pass_adm = encode(pass_adm);
	fclose(adm);
	int p = 3;
	login:
	printf("Введите логин\n");
	char log[100], password[100];
	input_l(log);
	printf("\n");
	printf("Введите пароль\n");
	input_p(password);
	printf("\n\n");
	if (strcmp(log, log_adm)!=0 || strcmp(password, pass_adm) != 0) {
		p--;
		if (p == 0) {
			printf("Вам не удалось войти под администратором\n");
			return -1;
		}
		printf("Такого администратора не существует\n У вас осталось %d попытки(-а)\n", p);
		goto login;
	}
	else {
		return 0;
	}
}

int vhod_user() {
	FILE *f;
	if (!(f = fopen("users.txt", "r"))) {
		printf("Ошибка открытия фаайла\n");
		return -1;
	}
	int p = 3;
	char log[100], password[100];
user_login:
	printf("Введите логин\n");
	input_l(log);
	printf("\n");
	printf("Введите пароль\n");
	input_p(password);
	int fl = 0;
	printf("\n\n");
	char user_l[100], user_p[100];
	fseek(f, 0, SEEK_SET);
	while (fscanf( f, "%s\t%s", user_l, user_p) != EOF) {
		*user_p = encode(user_p);
		if (strcmp(log, user_l) == 0 && strcmp(password, user_p) == 0) {
			printf("Вы успешно вошли под пользователем\n");
			fl++;
			return 0;
		}
	}
	if(fl==0) {
		p--;
		if (p == 0) {
			printf("Вы использовали все попытки\n");
			return -1;
		}
		printf("Такого пользователя не существует\n У вас осталось %d попытки(-а)\n", p);
		goto user_login;
	}
	fclose(f);
}

int main()	
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n;
	start:
	menu();
	n = _getch();
	if (n != '1' && n != '2'&& n != '3') {
		system("cls");
		printf("\nОшибка ввода\n\n");
		printf("Нажмите любую клавишу для возвращения в меню\n");
		_getch();
		system("cls");
		goto start;
	}
	printf("\n");
	switch (n) {
	case '1':
		system("cls");
		switch(vhod_adm()){
		case 0:
			menu_adm();
		case -1: 
			goto start;
		}
	case '2':
		system("cls");
		switch (vhod_user()) {
		case 0: 
			menu_user();
		case -1:
			goto start;

		}
	case '3':
		return 0;
	}
    return 0;
}

