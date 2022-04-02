typedef struct
{
	int *arr;
	int size;
} vector;

vector vec_create(int size);
void vec_destroy(vector *in);
vector vec_dup(vector in);
vector vec_concat(vector left, vector right);
vector vec_unit(int in);
vector vec_drop(int qtt, vector in);
vector vec_take(int qtt, vector in);
vector vec_fill(int size, int value);
vector vec_iota(int size);
void vec_print(vector in);
vector vec_map(int (*f)(int), vector in);
vector vec_operate(vector left, int (*f)(int, int), vector right);
int vec_reduce(int (*f)(int, int), vector in);
vector vec_scan(int (*f)(int, int), vector in);
int vec_int_in(int value, vector vec);
vector vec_in(vector left, vector right);
vector vec_sel(vector left, vector right);
