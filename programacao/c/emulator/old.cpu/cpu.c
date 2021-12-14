#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main()
{
	//create memory and hardware registers

	unsigned char * mem = malloc(65536);
	unsigned char arl = 0,
	arr = 0, 
	ir = 0;

	unsigned char flags = 0;

	unsigned char * reg = malloc(4);
	
	//r1
	//r2
	//acc
	//tmp

	//finish creating mem and hr
	
	//useful flags
	
	unsigned short ar = 0;
	unsigned char i = 0;
	bool alu;
	unsigned char ra, rb, func, func_flags; 

	//end
	
	//load program into ram
	
	//fib test
	
	*(mem + 0x00) = 0xB0;	// lod r0
	*(mem + 0x01) = 0x01;	// # 01
	*(mem + 0x02) = 0xB4;	// lod r1
	*(mem + 0x03) = 0x01;	// # 01
	*(mem + 0x04) = 0x86;	// cp r1 r2
	*(mem + 0x05) = 0x08;	// add r2 r0
	*(mem + 0x06) = 0x84;	// cp r1 r0
	*(mem + 0x07) = 0x89;	// cp r2 r1
	*(mem + 0x08) = 0xE0;	// wta r0
	*(mem + 0x09) = 0x00;	// @ 00
	*(mem + 0x0A) = 0x01;	// @ 01
	*(mem + 0x0B) = 0xE4;	// wta r1
	*(mem + 0x0C) = 0x00;	// @ 00
	*(mem + 0x0D) = 0x03;	// @ 03
	*(mem + 0x0E) = 0xE8;	// wta r2
	*(mem + 0x0F) = 0x10;	// @ 10
	*(mem + 0x10) = 0x00;	// @ 00
	*(mem + 0x11) = 0xBC;	// lod r3
	*(mem + 0x12) = 0x30;	// @ 30
	*(mem + 0x13) = 0x2E;	// cmp r3 r2
	*(mem + 0x14) = 0x94;	// jmp 0100
	*(mem + 0x15) = 0x00;	// @ 00
	*(mem + 0x16) = 0x00;	// @ 00
	

	//cmp test
	/*(mem + 0x00) = 0xB0;	// lod r0
	*(mem + 0x01) = 0x33;	// # 33
	*(mem + 0x02) = 0xB4;	// lod r1
	*(mem + 0x03) = 0x33;	// # 2E
	*(mem + 0x04) = 0x21;	// cmp r0 r1
	*(mem + 0x05) = 0x91;	// jmp 0001
	*(mem + 0x06) = 0x00;	// @ 00
	*(mem + 0x07) = 0x00;	// @ 00 */
	
	//*(mem + 0x) = 0x;	// 

	//addition test ok
	//*(reg + 0) = 0x05;
	//*(reg + 1) = 0x04;
	//*(mem + 0) = 0x01;
	//*(mem + 1) = 0x01;
	
	//write to addr in next addr test
	/**(mem + 0x00) = 0xB0;	// lod r0
	*(mem + 0x01) = 0x11;	// # 04
	*(mem + 0x02) = 0xB4;	// lod r1
	*(mem + 0x03) = 0x22;	// # 06
	*(mem + 0x04) = 0x01;	// add r0 r1
	*(mem + 0x05) = 0xE0;	// wta r0
	*(mem + 0x06) = 0x10;	// @ 10
	*(mem + 0x07) = 0x00;	// @ 00
	*(mem + 0x08) = 0xDC;	// lda r3
	*(mem + 0x09) = 0x10;	// @ 10
	*(mem + 0x10) = 0x00;	// @ 00
	*(mem + 0x11) = 0x98;	// jmp 0000
	*(mem + 0x12) = 0x00;	// @ 00
	*(mem + 0x13) = 0x00;	// @ 01 */

	//subtraction test
	/*(mem + 0x00) = 0xB0;	// lod r0
	*(mem + 0x01) = 0x99;	// # 08
	*(mem + 0x02) = 0xB4;	// lod r1
	*(mem + 0x03) = 0x72;	// # 02
	*(mem + 0x04) = 0x14;	// not r1
	*(mem + 0x05) = 0x01;	// add r0 r1
	*(mem + 0x06) = 0xE0;	// wta r0
	*(mem + 0x07) = 0x10;	// @ 10
	*(mem + 0x08) = 0x00;	// @ 00 */

	//read test / alu test
	
	/**(mem + 0) = 0xB0;
	*(mem + 1) = 0xFF;
	*(mem + 2) = 0xB4;
	*(mem + 3) = 0x01;
	*(mem + 4) = 0xC0;
	*(mem + 5) = 0x00;
	*(mem + 6) = 0xB8;*/
	//*(mem + 4) = 0x01; //add
	//*(mem + 5) = 0x01; //add
	//*(mem + 4) = 0x11; //not
	//*(mem + 4) = 0x31; //and
	//*(mem + 4) = 0x41; //or
	//*(mem + 4) = 0x51; //xor
	//*(mem + 4) = 0x61; //shl
	//*(mem + 4) = 0x71; //shr

	/* 
	*(mem + 1) = 0x03;
	*(mem + 2) = 0x81;
	*(mem + 3) = 0x01;
	*(mem + 4) = 0xC0;
	*(mem + 5) = 0xFF;
	*(mem + 6) = 0xFF;
	*(mem + 7) = 0xFF;
	*(mem + 8) = 0xFF;
	*(mem + 9) = 0xFF;
	*/

	//finish loading program

	//start program

	//arr = arr + 1;
	//if(arr == 0) {arl = arl + 1;}
	//short c = (((short)arl) << 8) | arr;
	//printf("%d", *(mem + c));

	//printf("func\tarr\tir\tr0\tr1\tr2\tr3\tflags\n\n"); 
	
	while(ar < 18)
	{
		i++;
		//start reading next instruction

		ir =  *(mem + ((((short)arl) << 8) | arr));
		//printf("%d", *(mem + ar));

		//finish loading next instruction

		//decode instruction

		alu = !((ir & 0x80) >> 7);
		
		ra = ((ir & 0x0C) >> 2);
		rb = (ir & 0x03);

		func = ((ir & 0x70) >> 4);

		func_flags = (ir & 0x0F);

		//printf("%d %x %x %x\n", alu, ir, ra, rb );
		//printf("%x func\t%x ar\t%x ir\t%x r0\t%x r1\t%x r2\t%x r3\t%x flags\n", func, ar, ir, *reg, *(reg +1), *(reg +2), *(reg +3), flags); 

		arr = arr + 1;
		if(arr == 0) {arl = arl + 1;}
		
		ar =  ((((short)arl) << 8) | arr);

		//finish decoding instruction

		//start function

		if(alu == 0) //non-alu
		{
			switch(func)
			{
				case 0x00: //copy ra to rb
					printf("cpy\t%x\n", ar);
					*(reg + rb) = *(reg + ra);
					break;
				case 0x01: //jump if flags
					printf("jmp\t%x\n", ar);
					if(flags == func_flags)
					{
						arl = *(mem + ar);
						arr = *(mem + ar + 1);
					}
					else
					{	
						arr = arr + 1;
						if(arr == 0) {arl = arl + 1;}
						arr = arr + 1;
						if(arr == 0) {arl = arl + 1;}
					}
					break;
				case 0x02: //change flags
					printf("chf\t%x\n", ar);
					flags = func_flags;
					break;
				case 0x03: //read to reg a from ram next addr
					printf("lod\t%x\n", ar);
					//arr = arr + 1;
					//if(arr == 0) {arl = arl + 1;}
					*(reg + ra) =  *(mem + ((((short)arl) << 8) | arr));
					arr = arr + 1;
					if(arr == 0) {arl = arl + 1;}
					break;
				case 0x04: //write the ram value on ra to next addr
					printf("wrt\t%x\n", ar);
					//arr = arr + 1;
					//if(arr == 0) {arl = arl + 1;}
					*(mem + ((((short)arl) << 8) | arr)) = *(reg + ra);
					arr = arr + 1;
					if(arr == 0) {arl = arl + 1;}
					break;
				case 0x05: //load value specified in next two ram addresses to ra
					printf("lda\t%x\n", ar);
					*(reg + ra) = 
					*(
						mem +
						(((short) *(mem + ar) << 8) | *(mem + ar + 1))
					);
					arr = arr + 1;
					if(arr == 0) {arl = arl + 1;}
					arr = arr + 1;
					if(arr == 0) {arl = arl + 1;}
					
					break;
				case 0x06: //write value in ra to address specified in next two ram addresses
					printf("wta\t%x\n", ar);
					*(
						mem +
						(((short) *(mem + ar) << 8) | *(mem + ar + 1))
					) = *(reg + ra);
					arr = arr + 1;
					if(arr == 0) {arl = arl + 1;}
					arr = arr + 1;
					if(arr == 0) {arl = arl + 1;}
					break;
			}
		}
		else //alu
		{
			switch(func)
			{
				case 0x00: //addition
					printf("add\t%x\n", ar);
					if( (*(reg + ra) + *(reg + rb) ) > 0xFF )  {flags = flags | 0x08;}
					else { flags = flags & 0xF7;}
					*(reg + ra) = *(reg + ra) + *(reg + rb) + (flags >> 3);
					break;
				case 0x01: //not
					printf("not\t%x\n", ar);
					*(reg + ra) = (*(reg + ra) ^ 0xFF);
					break;
				case 0x02: //compare
					printf("cmp\t%x\n", ar);
					if( *(reg + ra) > *(reg + rb) ) {flags = flags | 0x04;}
					if( *(reg + ra) == *(reg + rb) ) {flags = flags | 0x02;}
					if( *(reg + ra) == 0x00 ) { flags = flags | 0x01;}
					break;
				case 0x03: // and
					printf("and\t%x\n", ar);
					*(reg + ra) = (*(reg + ra) & *(reg + rb));
					break;
				case 0x04: //or
					printf("or\t%x\n", ar);
					*(reg + ra) = (*(reg + ra) | *(reg + rb));
					break;
				case 0x05: //xor
					printf("xor\t%x\n", ar);
					*(reg + ra) = (*(reg + ra) ^ *(reg + rb));
					break;
				case 0x06: //shl
					printf("shl\t%x\n", ar);
					if( (*(reg + ra) & 0x80) >> 7 ) { flags = 0x08;}
					*(reg + ra) = (*(reg + ra) << 1);
					break;
				case 0x07: //shr
					printf("shr\t%x\n", ar);
					if( *(reg + ra) & 0x01 ) { flags = 0x08;}
					*(reg + ra) = (*(reg + ra) >> 1);
					break;
					


			}
		}

		//printf("%x\t%x\t%x\t%x\t%x\n\n", func, arr, ir, *reg, *(reg +1)); 
		//printf("%x\t%x\t%x\t%x\t%x\t%x\t%x\t%x\n\n", func, arr, ir, *reg, *(reg +1), *(reg +2), *(reg +3), flags); 
		printf("%x func\t%x ar\t%x ir\t%x r0\t%x r1\t%x r2\t%x r3\t%x flags\n\n", func, ar, ir, *reg, *(reg +1), *(reg +2), *(reg +3), flags); 
		//end function
	}

	printf("%x", *(mem + 0x1000));
	//end program
	//printf("\n\n%x", *(mem + 5));
}
