#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char memory[65536];

int * const MEM = &memory[0];

char r0, r1, r2, r3;

int * const R0 = &r0;
int * const R1 = &r1;
int * const R2 = &r2;
int * const R3 = &r3;

char arl, arr, ir, tmp;

int * const ARL = &arl;
int * const ARR = &arr;
int * const IR = &ir;
int * const TMP = &tmp;

bool flags[4];

int * const FLAGS = &flags[0];

char read_next_ram_addr_to_ir()
{
	*FLAGS = 1;
	*TMP = add(*ARR, 0);
	*ARR = *TMP;
	*TMP = add(*ARL, 0);
	*ARL = *TMP;
	*IR = *(MEM + (((short)*ARL) << 8) | (0x00ff & *ARR));
	*FLAGS = 0;
}

int main()
{
	while(1)
	{
		*IR = read_next_ram_addr_to_ir();
		//execute();
	}
}
