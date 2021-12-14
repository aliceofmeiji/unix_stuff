#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct People
{
	int id;
	char name[255];
} Person;

typedef struct Houses
{
	int id;
	Person owner;
	Person inhabitant[4];
	char address[255];
} House;

int main()
{
	House blue_house;
	Person mariah, reimu;
	mariah.id = 1;
	reimu.id = 2;
	strcpy(reimu.name, "Reimu Hakurei");
	strcpy(mariah.name, "Mariah");

	printf("%s, %s\n", mariah.name, reimu.name);

	blue_house.owner = mariah;
	blue_house.inhabitant[0] = mariah;
	blue_house.inhabitant[1] = reimu;
	blue_house.owner = blue_house.inhabitant[0];
	printf("%s\n", blue_house.owner.name);

	blue_house.owner = blue_house.inhabitant[1];
	printf("%s\n", blue_house.owner.name);
}
