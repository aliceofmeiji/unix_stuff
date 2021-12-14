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
	
	FILE *rom_input;
	rom_input = fopen("rom.bin", "r");
	i = 0;
	while(i < 65536) 
	{
		char c = fgetc(rom_input);
		*(mem + i) = c;
		if( feof(rom_input) ) { break;}
		printf("%02x", c);
		i++;
	}
	printf("\n");

	//finish loading program

	//start program

	//arr = arr + 1;
	//if(arr == 0) {arl = arl + 1;}
	//short c = (((short)arl) << 8) | arr;
	//printf("%d", *(mem + c));

	//printf("func\tarr\tir\tr0\tr1\tr2\tr3\tflags\n\n"); 
	
	while(ar < 0xFFFF)
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
				case 0x07: //write to external addr or read from external addr
					
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
					flags = 0x00;
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
