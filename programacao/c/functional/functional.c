#include <stdlib.h>
#include <stdio.h>
#include "functional.h"
#include "utilities.h"

vector vec_create(int size)
{
	return (vector){malloc(sizeof(int) * size), size};
}

void vec_destroy(vector *in)
{
	free(in->arr);
	//free(in);
}

vector vec_dup(vector in)
{
	int i;
	vector out;
	out = vec_create(in.size);
	for(i = 0; i < in.size; i++)
		out.arr[i] = in.arr[i];
	return out;
}

vector vec_concat(vector left, vector right)
{
	int i, j;
	vector out;
	out = vec_create(left.size + right.size);
	for(i = 0; i < left.size; i++)
		out.arr[i] = left.arr[i];
	for(j = 0; j < right.size; j++)
		out.arr[i + j] = right.arr[j];
	return out;
}

vector vec_unit(int in)
{
	vector out;
	out = vec_create(1);
	out.arr[0] = in;
	return out;
}

vector vec_drop(int qtt, vector in)
{
	int i;
	vector out;
	out = vec_create(in.size - abs(qtt));
	if(qtt >= 0)
		for(i = qtt; i < in.size; i++)
			out.arr[i - qtt] = in.arr[i];
	else
		for(i = 0; i < (in.size - abs(qtt)); i++)
			out.arr[i] = in.arr[i];
	return out;
}

vector vec_take(int qtt, vector in)
{
	int i, diff;
	diff = in.size + qtt;
	vector out;
	out = vec_create(abs(qtt));
	if(qtt >= 0)
		for(i = 0; i < qtt; i++)
			out.arr[i] = in.arr[i];
	else
		for(i = 0; i < abs(qtt); i++)
			out.arr[i] = in.arr[i + diff];
	return out;
}

vector vec_fill(int size, int value)
{
	int i;
	vector out;
	out = vec_create(size);
	for(i = 0; i < size; i++)
		out.arr[i] = value;
	return out;
}

vector vec_iota(int size)
{
	int i;
	vector out;
	out = vec_create(size);
	for(i = 0; i < size; i++)
		out.arr[i] = i + 1;
	return out;
}

void vec_print(vector in)
{
	int i;
	for(i = 0; i < in.size; i++)
		printf("%d ", in.arr[i]);
	putchar('\n');
}

vector vec_map(int (*f)(int), vector in)
{
	int i;
	vector out;
	out = vec_create(in.size);

	for(i = 0; i < in.size; i++)
		out.arr[i] = f(in.arr[i]);

	return out;
}

vector vec_operate(vector left, int (*f)(int, int), vector right)
{
	int i;
	vector out;
	out = vec_create(left.size);

	for(i = 0; i < left.size; i++)
		out.arr[i] = f(left.arr[i], right.arr[i]);

	return out;
}

int vec_reduce(int (*f)(int, int), vector in)
{
	int out, i;
	for(i = 0, out = 0; i < in.size; i++)
		out = f(out, in.arr[i]);
	return out;
}

vector vec_scan(int (*f)(int, int), vector in)
{
	int i, cur;
	vector out = vec_create(in.size);
	for(i = 0, cur = 0; i < in.size; i++)
	{
		cur = f(cur, in.arr[i]);
		out.arr[i] = cur;
	}
	return out;
}

int vec_int_in(int value, vector vec)
{
	int i;
	for(i = 0; i < vec.size; i++)
		if(value == vec.arr[i])
			return 1;
	return 0;
}

vector vec_in(vector left, vector right)
{
	int i;
	vector out;
	out = vec_create(left.size);
	for(i = 0; i < left.size; i++)
		out.arr[i] = vec_int_in(left.arr[i], right);
	return out;
}

vector vec_sel(vector left, vector right)
{
	int i, qtt, cur;
	vector out;
	qtt = vec_reduce(add, left);
	out = vec_create(qtt);
	for(i = 0, cur = 0; i < left.size; i++)
		if(left.arr[i] == 1)
			out.arr[cur++] = right.arr[i];
	return out;
}
