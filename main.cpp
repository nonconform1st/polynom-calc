#include "header.h"

int main()
{
	system("chcp 1251 > nul");
	
	char expr[STR_SIZE] = "3x^2+4x+4x^3-10";
	Node * root;
	double x = 4, res;

	// read expression and X

	remove_spaces(expr);
	set_asterisks(expr);

	cout << expr << endl;
	root = parse(expr);
	res = calc(root, x);

	cout << res << endl;

	system("pause");
}