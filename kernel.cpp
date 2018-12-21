#include "header.h"

/**
	Cоздание нового узла
*/
Node * New(double coef, char var, char sign)
{
	Node* n;
	n = (Node*)malloc(sizeof Node);

	n->coef = coef;
	n->var = var;
	n->sign = sign;

	n->left = n->right = NULL;
	return n;
}

/**
	Рекурсивно вычисляет значение
	дерева арифметического выражения
*/
double calc(Node * node, double x)
{
	if (node->left != NULL && node->right != NULL)
		return op(calc(node->left, x), calc(node->right, x), node->sign);
	else if (node->var)
		return x;
	else
		return node->coef;
}

/**
	Рекурсивно строит бинарное дерево
	арифметического выражения
*/
Node * parse(char * str)
{
	int sign_pos;
	double num;
	char sign;
	char str_l[STR_SIZE], str_r[STR_SIZE];
	Node * node;

	if (!is_num(str) && !is_var(str)) {
		sign_pos = last_low_priority_sign(str);
		sign = str[sign_pos];

		node = New(NULL, NULL, sign);

		substr(str, str_l, 0, sign_pos - 1);
		substr(str, str_r, sign_pos + 1, -1);

		node->left = parse(str_l);
		node->right = parse(str_r);
	}
	else if (is_var(str))
		node = New(NULL, 'x', NULL);
	else {
		node = New(atof(str), NULL, NULL);
	}

	return node;
}

/**
	Расставляет знаки умножения там, где они подразумеваются
*/
void set_asterisks(char* s)
{
	for (int i = 1; s[i]; i++)
		if ((s[i - 1] >= 48 && s[i - 1] <= 57 && s[i] == 'x')
			|| (s[i] >= 48 && s[i] <= 57 && s[i-1] == 'x')) {
			insert_char(s, i, '*');
			// пройти строку еще раз
			set_asterisks(s);
		}
	return;
}
