char add(char ra, char rb, char *flags)
{
	char saida = ra + rb + *flags;
	*flags = 0;
	if((saida < ra) || (saida < rb))
	{*flags = 1;}
	return saida;
}
char add1(char ra, char *flags)
{
	char saida = ra + 1 + *flags;
	*flags = 0;
	if((saida < ra))
	{*flags = 1;}
	return saida;
}
char add0(char ra, char *flags)
{
	char saida = ra + 0 + *flags;
	*flags = 0;
	if((saida < ra))
	{*flags = 1;}
	return saida;
}
