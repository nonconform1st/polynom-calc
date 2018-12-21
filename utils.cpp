#include "header.h"

/**
	Проверяет, является ли строка числом ПОЛНОСТЬЮ
*/
bool is_num(char *s)
{
	for (int i = 0; s[i]; i++)
		if ((s[i] >= 48 && s[i] <= 57) || s[i] == '.') continue;
		else return false;
	return true;
}

/**
	Проверяет, является ли строка иксом
*/
bool is_var(char *s)
{
	return (strcmp(s, "x") == 0) ? true : false;
}

/**
	Найти последний символ
	с наименьшим приоритетом
*/
int last_low_priority_sign(char * str)
{
	int i, l = strlen(str);

	// first look for + or -
	for (i = l; i--; )
		if (str[i] == '+' || str[i] == '-')
			return i;
	// if nothing found, 
	// look for high-priority signs (* or /)
	for (i = l; i--; )
		if (str[i] == '*' || str[i] == '/')
			return i;
	// else look for ^ (highest priority)
	for (i = l; i--; )
		if (str[i] == '^')
			return i;
	return -1;
}

/**
	Произвести операцию op над числами n1 и n2
*/
double op(double n1, double n2, char op)
{
	switch (op)
	{
	case '+':
		return n1 + n2;
	case '-':
		return n1 - n2;
	case '*':
		return n1 * n2;
	case '/':
		return n1 / n2;
	case '^':
		return power(n1,n2);
	}
}

/**
	Более оптимально возводит в степень, чем Math.pow() (наверное)
*/
double power(double base, double powr)
{
	if (round(powr) == powr) // проверить, является ли показатель степени
	{
		double res = base;
		for (int i = 1; i < powr; i++, res *= base)
			;
		return res;
	}
	else
		return pow(base, powr);
}