#include "utilities.h"

int add(int left, int right)
{
	return left + right;
}

int sub(int left, int right)
{
	return left - right;
}

int mul(int left, int right)
{
	return left * right;
}

int rat(int left, int right)
{
	return left / right;
}

int mod(int left, int right)
{
	return left % right;
}

int eql(int left, int right)
{
	return left == right;
}

int dif(int left, int right)
{
	return left != right;
}

int grt(int left, int right)
{
	return left > right;
}

int les(int left, int right)
{
	return left < right;
}

int leq(int left, int right)
{
	return left <= right;
}

int geq(int left, int right)
{
	return left >= right;
}

int and(int left, int right)
{
	return left && right;
}

int orr(int left, int right)
{
	return left || right;
}

int max(int left, int right)
{
	return left > right ? left : right;
}

int min(int left, int right)
{
	return left < right ? left : right;
}

int not(int in)
{
	return !in;
}

int sgn(int in)
{
	return in == 0 ? 0 : (in > 0 ? 1 : -1);
}
