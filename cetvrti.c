#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct _polinom;
typedef struct _polinom *Pozicija;
typedef _polinom{
  int koef;
  int exp;
  Pozicija *next;
}Polinom;
int CitajIzDatoteke();
int ZbrojiPolinome();
int main(void)
{
  
  return 0;
}
