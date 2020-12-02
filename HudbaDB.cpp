#include <stdlib.h>
#include <string.h>
#include "HudbaDB.h"

void add(char* Interpret, char* Nazov, int rok, struct t_hudba** uk_prvni)
{
	struct t_hudba* noveAlbum;
	struct t_hudba* aktAlbum;

	noveAlbum = (struct t_hudba*)malloc(sizeof(struct t_hudba));
	strcpy_s(noveAlbum->Interpret, ZNACKA_SIZE, Interpret);
	strcpy_s(noveAlbum->Nazov, ZNACKA_SIZE, Nazov);
	noveAlbum->rok = rok;
	noveAlbum->dalsi = NULL;

	if (*uk_prvni == NULL)
	{
		*uk_prvni = noveAlbum;
		return;
	}
	else if (strcmp(noveAlbum->Interpret, (*uk_prvni)->Interpret) < 0)
	{
		noveAlbum->dalsi = *uk_prvni;
		*uk_prvni = noveAlbum;
		return;
	}

	aktAlbum = *uk_prvni;
	while (aktAlbum)
	{
		if (aktAlbum->dalsi == NULL)
		{
			aktAlbum->dalsi = noveAlbum;
			return;
		}
		else if (strcmp(noveAlbum->Interpret, aktAlbum->dalsi->Interpret) < 0)
		{
			noveAlbum->dalsi = aktAlbum->dalsi;
			aktAlbum->dalsi = noveAlbum;
			return;
		}
		aktAlbum = aktAlbum->dalsi;
	}
}

void del(char* Interpret, struct t_hudba** uk_prvni)
{
	struct t_hudba* aktAlbum;

	while (*uk_prvni && strcmp((*uk_prvni)->Interpret, Interpret) == 0)
	{
		struct t_hudba* newPrvni = (*uk_prvni)->dalsi;
		free(*uk_prvni);
		*uk_prvni = newPrvni;
	}

	aktAlbum = *uk_prvni;
	while (aktAlbum && aktAlbum->dalsi)
	{
		if (strcmp(aktAlbum->dalsi->Interpret, Interpret) == 0)
		{
			struct t_hudba* newDalsi = aktAlbum->dalsi->dalsi;
			free(aktAlbum->dalsi);
			aktAlbum->dalsi = newDalsi;
		}
		aktAlbum = aktAlbum->dalsi;
	}
}