#pragma once
#define ZNACKA_SIZE 21

struct t_hudba
{
    char  Nazov[ZNACKA_SIZE];
    char  Interpret[ZNACKA_SIZE];
    int   rok;
    struct t_hudba* dalsi;
};

void add(char* Interpret, char* Nazov, int rok, struct t_hudba** uk_prvni);
void del(char* Interpret, struct t_hudba** uk_prvni);

