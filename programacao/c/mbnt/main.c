#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct
{
	char desenho;
	int x;
	int y;
} boneco;

void desenha(int largura, char *tela, boneco p[]);
void limpatela(int largura, char *tela);
boneco move(boneco p);

int main()
{
	int largura = 20, i, j, primeiro = 0;
	char *tela = malloc(largura * largura);

	limpatela(largura, tela);
	
	boneco ps[2];
	ps[0].x = 3;
	ps[0].y = 8;	
	ps[0].desenho = 'o';	

	ps[1].x = 5;
	ps[1].y = 5;	
	ps[1].desenho = 'w';	

	while(ps[0].x != ps[1].x || ps[0].y != ps[1].y)
	{
		desenha(largura, tela, ps);
		printf("--------------------#\n");
		primeiro++;
		limpatela(largura, tela);
		ps[0] = move(ps[0]);
	}
	printf("parabens voce ganhou!!!\n");
}

void desenha(int largura, char *tela, boneco p[])
{
	int i, j;
	for(i = 0; i < 2; i++)
		*(tela + (p[i].y * largura) + p[i].x) = p[i].desenho;

	for(i = 0; i < largura; i++)
	{
		for(j = 0; j < largura; j++)
		{
			putchar(*(tela + (i * largura) + j));
		}
		putchar('|');
		putchar('\n');
	}
}

void limpatela(int largura, char *tela)
{
	int i, j;
	for(i = 0; i < largura; i++)
		for(j = 0; j < largura; j++)
			*(tela + (i * largura) + j) = ' ';
}

boneco move(boneco p)
{
	char c = getchar();
	switch(c)
	{
		case 'h':
			p.x--;
			break;
		case 'j':
			p.y++;
			break;
		case 'k':
			p.y--;
			break;
		case 'l':
			p.x++;
			break;
	}
	return p;
}
