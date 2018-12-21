#include "header.h"

/**
	Обрезка строки
*/
void substr(char * src, char * dest, int start, int end)
{
	int i, a;
	if (end == -1)
		for (i = start, a = 0; src[i]; i++, a++)
			dest[a] = src[i];
	else
		for (i = start, a = 0; i <= end && (src[i]); i++, a++)
			dest[a] = src[i];

	dest[a] = '\0';
	return;
}

/**
	Удаляет все пробелы из строки
*/
void remove_spaces(char* s)
{
	char* cpy = s;
	char* temp = s;

	while (*cpy)
	{
		if (*cpy != ' ')
			*temp++ = *cpy;
		cpy++;
	}
	*temp = 0;
}

/**
	Утилита для функции set_asterisks :
	Вставляет строку substr начиная с позиции pos
*/
void insert_char(char *s, int pos, char ins)
{
	char t1, t2;
	int i = 0;
	while (s[i]) {
		if (i == pos) {
			t1 = s[i];
			s[i] = ins;
		}
		else if (i > pos) {
			t2 = s[i];
			s[i] = t1;
			t1 = t2;
		}
		i++;
	}
	s[i++] = t1;
	s[i] = 0;
}