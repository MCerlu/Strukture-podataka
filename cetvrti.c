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
/* Funkcijom CitajIzDatoteke ćemo čitati zapisane koeficijente i eksponente polinoma iz zadane datoteke i unositi ih u listu*/
/*Funkcija kao argument prima pokazivač na datoteku i pokazivač na praznu vezanu listu*/
int CitajIzDatoteke();
/*Funkcija ZbrojiPolinome kao argumente prima 
int ZbrojiPolinome();
int main(void)
{
  
  return 0;
}
