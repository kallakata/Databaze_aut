#include <stdio.h>
#include <ctype.h>              
#include <stdlib.h>				
#include "HudbaDB.h"

struct t_hudba* prvni = NULL;

void OnAdd()
{
	char my_name[ZNACKA_SIZE];
	char my_interpret[ZNACKA_SIZE];
	int my_year;

	printf("\nNazev : ");
	scanf_s("%s", my_name, ZNACKA_SIZE);
	while (getchar() != '\n');
	printf("\nInterpret : ");
	scanf_s("%s", my_interpret, ZNACKA_SIZE);
	while (getchar() != '\n');
	printf("\nRok : ");
	scanf_s("%d", &my_year);
	while (getchar() != '\n');
	add(my_interpret, my_name, my_year, &prvni);
}

void OnDel()
{
	char my_interpret[ZNACKA_SIZE];

	printf("\nInterpret : ");
	scanf_s("%s", my_interpret, ZNACKA_SIZE);
	while (getchar() != '\n');
	del(my_interpret, &prvni);
}

void ShowAlb()
{
	struct t_hudba* aktAlbum = prvni;
	printf("\n\n");
	while (aktAlbum)
	{
		printf("%s %d %s \n", aktAlbum->Interpret, aktAlbum->rok, aktAlbum->Nazov);
		aktAlbum = aktAlbum->dalsi;
	}
	getchar();
}
void FilterShowAlb()
{
	struct t_hudba* aktAlbum = prvni;
	char pismeno[10];
	printf("Zadejte prvni pismeno Interpreta: ");
	scanf_s("%s", pismeno, 10);
	while (getchar() != '\n');



	while (aktAlbum)
	{
		char* interpret = aktAlbum->Interpret;
		if (interpret[0] == pismeno[0])
		{
			printf(" %s %s %d\n", aktAlbum->Interpret, aktAlbum->Nazov, aktAlbum->rok);

		}
		aktAlbum = aktAlbum->dalsi;
	}
	getchar();
}

int main()
{
	char  cmd;

	do
	{
		system("cls");
		printf("A: Pridat     ");
		printf("D: Smazat     ");
		printf("P: Tisk     ");
		printf("F: Filter Tisku	    ");
		printf("Q: Konec\n\n");

		cmd = tolower(getchar());
		while (getchar() != '\n');

		switch (cmd)
		{
		case 'a':
			OnAdd();
			break;
		case 'd':
			OnDel();
			break;
		case 'p':
			ShowAlb();
			break;
		case 'f':
			FilterShowAlb();
			break;
		}
	} while (cmd != 'q');
	return 0;
}
