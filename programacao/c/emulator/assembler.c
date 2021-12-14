#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main()
{
	unsigned char function[4], ra, rb, flags, line[255];

	int i, j, k;

	unsigned char output = 0x00;

	char args[4];

	for(k = 0; k < 65536; k++)
	{
	//read line
	fgets(line, 255, stdin);
	//printf("%s", line);

	//read function (or number)
	for(i = 0; i < 4; i++)
	{
		if(line[i] != ' ')
		{function[i] = line[i];}
		else{break;}
	}
	
	for(j=0; j < 4; j++)
	{
		args[j] = line[i + (j * 2) + 1];
	}
	
	output = 0x00;

	output = output | ((args[0] & 0x0F) << 2);
	output = output | (args[1] & 0x0F);

	if((line[0] == '#') || (line[0] == '@'))
	{
		output = 0x00;
		switch (line[2])
		{
		case '0':
			output = 0x00;
			break;
		case '1':
			output = 0x10;
			break;
		case '2':
			output = 0x20;
			break;
		case '3':
			output = 0x30;
			break;
		case '4':
			output = 0x40;
			break;
		case '5':
			output = 0x50;
			break;
		case '6':
			output = 0x60;
			break;
		case '7':
			output = 0x70;
			break;
		case '8':
			output = 0x80;
			break;
		case '9':
			output = 0x90;
			break;
		case 'A':
			output = 0xA0;
			break;
		case 'B':
			output = 0xB0;
			break;
		case 'C':
			output = 0xC0;
			break;
		case 'D':
			output = 0xD0;
			break;
		case 'E':
			output = 0xE0;
			break;
		case 'F':
			output = 0xF0;
			break;
		}
		switch (line[3])
		{
		case '0':
			output = output | 0x00;
			break;
		case '1':
			output = output | 0x01;
			break;
		case '2':
			output = output | 0x02;
			break;
		case '3':
			output = output | 0x03;
			break;
		case '4':
			output = output | 0x04;
			break;
		case '5':
			output = output | 0x05;
			break;
		case '6':
			output = output | 0x06;
			break;
		case '7':
			output = output | 0x07;
			break;
		case '8':
			output = output | 0x08;
			break;
		case '9':
			output = output | 0x09;
			break;
		case 'A':
			output = output | 0x0A;
			break;
		case 'B':
			output = output | 0x0B;
			break;
		case 'C':
			output = output | 0x0C;
			break;
		case 'D':
			output = output | 0x0D;
			break;
		case 'E':
			output = output | 0x0E;
			break;
		case 'F':
			output = output | 0x0F;
			break;
		}
	}
	if(strcmp(function, "end") == 0) 
	{
		printf("%c%c%c%c", 0xA0, 0x90, 0xFF, 0xFE);
		break;
	}
	if(strcmp(function, "add") == 0) 
	{
		output = output | 0x00;
	}
	if(strcmp(function, "not") == 0) 
	{
		output = output | 0x10;
	}
	if(strcmp(function, "cmp") == 0) 
	{
		output = output | 0x20;
	}
	if(strcmp(function, "and") == 0) 
	{
		output = output | 0x30;
	}
	if(strcmp(function, "or" ) == 0) 
	{
		output = output | 0x40;
	}
	if(strcmp(function, "xor") == 0) 
	{
		output = output | 0x50;
	}
	if(strcmp(function, "shl") == 0) 
	{
		output = output | 0x60;
	}
	if(strcmp(function, "shr") == 0) 
	{
		output = output | 0x70;
	}
	if(strcmp(function, "cpy") == 0) 
	{
		output = output | 0x80;
	}
	if(strcmp(function, "jmp") == 0) 
	{
		output = output & 0xF0;
		output = output | 0x90;
		output = output | ((args[0] & 0x01) << 3);
		output = output | ((args[1] & 0x01) << 2);
		output = output | ((args[2] & 0x01) << 1);
		output = output | (args[3] & 0x01);
	}
	if(strcmp(function, "chf") == 0) 
	{
		output = output & 0xF0;
		output = output | 0xA0;
		output = output | ((args[0] & 0x01) << 3);
		output = output | ((args[1] & 0x01) << 2);
		output = output | ((args[2] & 0x01) << 1);
		output = output | (args[3] & 0x01);
	}
	if(strcmp(function, "lod") == 0) 
	{
		output = output | 0xB0;
	}
	if(strcmp(function, "wrt") == 0) 
	{
		output = output | 0xC0;
	}
	if(strcmp(function, "lda") == 0) 
	{
		output = output | 0xD0;
	}
	if(strcmp(function, "wta") == 0) 
	{
		output = output | 0xE0;
	}
	printf("%c", output);
	}
}
