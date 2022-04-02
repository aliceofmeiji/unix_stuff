#include <stdio.h>
#include <stdlib.h>
#include "functional.h"
#include "utilities.h"

int doub(int);
int triple(int);

int main()
{
	vector list = vec_iota(5);
	vector list_2 = vec_map(triple, list); //same as vvv
	vec_print(list);
	vec_print(list_2);
/*
	vec_print(vec_concat(vec_iota(3), vec_iota(5)));

	vector listt = vec_drop(3, vec_iota(8));
	vector listt_2 = vec_dup(listt);
	vec_print(vec_take(-3, vec_iota(5)));
	vec_print(vec_unit(4));
	
	vector list = vec_iota(5);
	//vector list_2 = vec_map(doub, list); //same as vvv
	vector list_2 = vec_operate(vec_fill(list.size, 2), mul, list);
	vector res = vec_operate(list, add, list_2);
	vec_print(res);
	printf("%d\n", vec_reduce(add, vec_iota(5)));
	vec_print(vec_scan(add, vec_iota(5)));

	vector nums = vec_create(6);
	int n[] = {1, 0, 1, 1, 0, 1};
	nums.arr = n;
	vec_print(nums);
	vec_print(vec_sel(nums, vec_iota(6)));

	int vals[] = {1, 2, 3, 9, 5, 10};
	vector m = vec_create(6);
	m.arr = vals;
	vec_print(vec_in(m, vec_iota(6)));
*/
}

int doub(int in)
{
	return in * 2;
}

int triple(int in)
{
	return in * 3;
}
