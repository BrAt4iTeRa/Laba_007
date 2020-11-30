#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "RUS");
	char* str;
	int n, i = 0, end, beg, i1, i2, min; 
	do {                                                                   //блок выделения памяти
		if (i == 0)printf_s("Введите размерность строки:\n n = ");
		else printf("Недостаточно памяти.\nПовторите попытку:\nn = ");
		scanf_s("%d", &n);
		if (!(str = (char*)malloc(n * sizeof(char)))) {                 
			system("CLS");
			rewind(stdin);
			i++;
		}
	} while (!str);
	fflush(stdin);
	rewind(stdin);
	for (i = 0; i < n+1; i++) {
		if (i == n)
			*(str + i) = '\0';
		scanf_s("%c", str + i);
		if (*(str + i) == '\n') {
			*(str + i) = '\0';
			break;
		}
	}
	printf_s("\nВаша строка:\n");
	//puts(str);
	for (int k = 0; *(str + k); k++) {          //for (int k = 0; k < i; k++) - второй вариант
		printf_s("%c", *(str + k));
	}
	i = i2 = beg = end = 0;
	min = n;                                            //задаем минимальное слово, по совместительсту максимальное :) нужно для цикла
	while (*(str+i)) {
		while (*(str + i) == ' ') i++;                  //пропускаем пробелы
		i1 = i;        
		while (*(str + i) != ' ' && *(str + i)) {
			i2 = i;
			i++;
		}
		if (i2 - i1 < min) {                    
			end = i2;
			beg = i1;
			min = end - beg;
		}
	}
	printf_s("\nСамое маленькое слово в строке: \n");    //вывод слова 
	for (i = beg; i < end+1; i++) {
		printf_s("%c", *(str + i));
	}
}
