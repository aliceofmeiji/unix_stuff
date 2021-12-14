#include <stdio.h>
#include <stdlib.h>

void draw_picross(int *screen, int *map, int size)
{
	int i, j;
	for(i = 0; i < size; i++)
	{
		for(j = 0; j < size; j++)
		{
			//printf("%d", *((screen + i*size) +j));
			if( *((screen + i*size) + j) == 0)
			{
				printf("  ");
			}
			else
			{
				printf("██");
			}
		}
		for(j = 0; j < size; j++)
		{
			if( *((map + i*size) + j) != 0)
			{
				printf(" %d", *((map + i*size) + j) );
			}
		}
		printf("\n");
	}

	for(i = 0; i < size; i++)
	{
		for(j = 0; j < size; j++)
		{
			if(*(((map + j*size) + i) + size*size) != 0)
			{
				printf(" %d", *(((map + j*size) + i) + size*size) );
			}
			else
			{
				printf("  ");
			}
		}
		printf("\n");
	}
}

void update_picross(int *screen, int size)
{
	int i, j;
	scanf("%d %d", &i, &j);

	if( *((screen + i*size) + j) == 0)
	{
		*((screen + i*size) + j) = 1;
	}
	else
	{
		*((screen + i*size) + j) = 0;
	}

}

int check_picross(int *screen, int *map, int size)
{
	int i, j, last, now, total;
	total = 0;
	last = 0;
	for(i = 0; i < size; i++)
	{
		for(j = 0; j < size; j++)
		{
			now = *((screen + i*size) + j);
			if(now == 1)
			{
				total++;
			}
			else
			{
				if(last == 1)
				{
					*((map + i*size) + j) = total;
					total = 0;
				}
			}
			last = now;
		}
		if(total != 0)
		{
			*((map + i*size) + j - 1) = total;
		}
		total = 0;
		last = 0;
	}

	for(i = 0; i < size; i++)
	{
		for(j = 0; j < size; j++)
		{
			now = *((screen + j*size) + i);
			if(now == 1)
			{
				total++;
			}
			else
			{
				if(last == 1)
				{
					*((map + i*size) + j + size*size) = total;
					total = 0;
				}
			}
			last = now;
		}
		if(total != 0)
		{
			*((map + i*size) + j - 1 + size*size) = total;
		}
		total = 0;
		last = 0;
	}
}

int equal_maps(int *map1, int *map2, int size)
{
	int i, j, ok = 1;
	for(i = 0; i < 2*size; i++)
	{
		for(j = 0; j < size; j++)
		{
			if( *((map1 + i*size) + j) != *((map2 + i*size) + j) )
			{
				ok = 0;
			}
		}
	}	
	return ok;
}

void fix_map(int *map, int size)
{
	int i, j, last_num;
	int buf[size];

	for(i = 0; i < 2*size; i++)
	{
		for(j = 0; j < size; j++)
		{
			buf[j] = 0;
		}
		
		last_num = 0;
		for(j = 0; j < size; j++)
		{
			if( *((map + i*size) +j) != 0)
			{
				buf[last_num] = *((map + i*size) + j);
				last_num++;
			}
		}

		for(j = 0; j < size; j++)
		{
			*((map + i*size) + j) = buf[j];
		}
		
	}
}

void clear_screen(int *screen, int size)
{
	int i, j;
	for(i = 0; i < size; i++)
	{
		for(j = 0; j < size; j++)
		{
			*((screen + i*size) + j) = 0;
		}
	}
}

void clear_map(int *map, int size)
{
	int side, i, j;
	for(i = 0; i < size; i++)
	{
		for(j = 0; j < size; j++)
		{
			*((map + i*size) + j) = 0;
		}
	}

	for(i = 0; i < size; i++)
	{
		for(j = 0; j < size; j++)
		{
			*((map + i*size) + j + size*size) = 0;
		}
	}
}

int main(int argc, char *argv[])
{
	int game_status, size, i, j, buff;
	size = strtol(argv[1], NULL, 10);
	int screen[size][size];

	int map[2][size][size];
	int usermap[2][size][size];

	FILE *file;
	file = fopen(argv[2], "r");
	
	for(i = 0; i < size; i++)
	{
		for(j = 0; j < size; j++)
		{
			fscanf(file, "%d", &buff);
			map[0][i][j] = buff;
			/*
			while(!feof (file))
			{
				fscanf(file, "%d", &buff);
				printf("%d", buff);
				map[0][i][j] = buff;
			}
			*/
		}
	}

	for(i = 0; i < size; i++)
	{
		for(j = 0; j < size; j++)
		{
			fscanf(file, "%d", &buff);
			map[1][i][j] = buff;
			/*
			while(!feof (file))
			{
				fscanf(file, "%d", &buff);
				map[1][i][j] = buff;
			}
			*/
		}
	}
	
	fclose(file);

	clear_screen(&screen[0][0], size);	
	clear_map(&usermap[0][0][0], size);	
	fix_map(&map[0][0][0], size);
	
	game_status = 1;
	while(game_status == 1)
	{
		//fix_map(&usermap[0][0][0], size);
		//fix_map(&map[0][0][0], size);
		for(i = 0; i < size*4; i++)
		{
			printf("—");
		}
		printf("\n");

		draw_picross(&screen[0][0], &map[0][0][0], size);
		clear_map(&usermap[0][0][0], size);	
		update_picross(&screen[0][0], size);
		check_picross(&screen[0][0], &usermap[0][0][0], size);
		fix_map(&usermap[0][0][0], size);
		fix_map(&map[0][0][0], size);
		if(equal_maps(&map[0][0][0], &usermap[0][0][0], size) == 1)
		{
			//printf("wowow\n");
			game_status = 0;
		}
		//printf("%d\n", equal_maps(&map[0][0][0], &usermap[0][0][0], size));
		//if(check_picross(&screen[0][0], &map[0][0][0], size))
	}
	draw_picross(&screen[0][0], &map[0][0][0], size);
	printf("sina pona a!\n");
	/*	
	for(i = 0; i < size; i++)
	{
		for(j = 0; j < size; j++)
		{
			printf("%d", screen[i][j]);
		}
		printf("\n");
	}
	*/
}
