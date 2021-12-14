#include<stdio.h>
#include<stdlib.h>

int quantoscabem(valormoeda, qtd)
{
	int saida = 0, soma = 0;
	while(soma + valormoeda <= qtd)
	{
		soma = soma + valormoeda;
		saida++;
	}
	return saida;
}

int main()
{
	//tdm = tipos de moedas
	int total, n, i, solucoes;
	
	scanf("%d", &total);
	scanf("%d", &n);

	int tdm[n];

	for(i = 0; i < n; i++)
	{
		scanf("%d", tdm[i]);
	}

	//printf("%d", quantoscabem(5, 30));
	
	//a partir de agora, o programa seguiria a executar quantos cabem em cada um dos tipos de moedas sobre o total, e removeria aquele tipo de moeda quando todas as opções fossem utilizadas, mas... não tive tempo :/
}
