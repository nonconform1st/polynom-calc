#pragma once
#include <iostream>

#define STR_SIZE 256

using namespace std;

struct Node
{
	// only one of this 3 parameters can be specified
	// another 2 should be set to NULL
	double coef;
	char var, sign;

	Node * left;
	Node * right;
};

// kernel

Node * New(double coef, char var, char sign);
Node * parse(char * str);
double calc(Node * node, double x);
void set_asterisks(char* s);

// strings

void substr(char * src, char * dest, int start, int end);
void remove_spaces(char* s);
void insert_char(char* s, int pos, char ins);

// utils

bool is_num(char *s);
bool is_var(char *s);
int last_low_priority_sign(char * str);
double op(double n1, double n2, char op);
double power(double base, double powr);