/**
Napisati program koji prvo proèita koliko redaka ima datoteka, tj. koliko ima studenata
zapisanih u datoteci. Nakon toga potrebno je dinamièki alocirati prostor za niz struktura
studenata (ime, prezime, bodovi) i uèitati iz datoteke sve zapise. Na ekran ispisati ime,
prezime,apsolutni i relativni broj bodova.
Napomena: Svaki redak datoteke sadrži ime i prezime studenta, te broj bodova na kolokviju.
relatvan_br_bodova = br_bodova/max_br_bodova*100
**/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define STRMAX 1024
//definicija strukture
typedef struct _student {
	char ime[STRMAX];
	char prezime[STRMAX];
	int bodovi;
} Student;
//deklaracije funkcija koje cemo koristiti
int prebrojiStudente(char * filename);
int unosStudenata(char * filename, Student * studenti, int br_stud);
int pronadiMax(Student * studenti, int br_stud);
int ispisStudenata(Student * studenti, int br_stud, int maxbodovi);

int main(void)
{
	int br_stud = 0, maxbodovi = 0;
	char filename[] = "studenti.txt";//datoteka iz koje citamo podatke
	Student * studenti;

	br_stud = prebrojiStudente(filename);
	studenti = (Student *)malloc(br_stud*sizeof(Student));//alokacija memorije za niz struktura

	unosStudenata(filename, studenti, br_stud);//unos studenata iz datoteke u niz strukture studenti
	maxbodovi = pronadiMax(studenti, br_stud);

	ispisStudenata(studenti, br_stud, maxbodovi);

	return 0;
}

int prebrojiStudente(char * filename)
{
	FILE * fp = NULL;
	int br_stud = 0;
	char dbuffer[STRMAX];

	fp = fopen(filename, "r");

	if (fp == NULL)
		return -1;

	while (fgets(dbuffer, STRMAX, fp))
		br_stud++;
	
	fclose(fp);

	return br_stud;
}
//prepisujemo studente iz datoteke u memoriju u niz struktura
int unosStudenata(char * filename, Student * studenti, int br_stud)
{
	FILE * fp = NULL;
	int i = 0;

	fp = fopen(filename, "r");

	if(fp == NULL)
		return -1;

	for(i = 0; i<br_stud; i++)
		fscanf(fp, "%d %s %s", &(studenti[i].bodovi), studenti[i].ime, studenti[i].prezime);

	fclose(fp);

	return 0;
}
//trazimo studenta sa najvecim brojem bodova tako sto prolazimo po nizu struktura 
int pronadiMax(Student * studenti, int br_stud)
{
	int i = 0;
	int max = studenti[i].bodovi;

	for(i=1; i<br_stud; i++) 
		if (studenti[i].bodovi > max)
			max = studenti[i].bodovi;

	return max;
}
//za svakog studenta u nizu ispisujemo ime, prezime,apsolutni i relativni broj bodova
int ispisStudenata(Student * studenti, int br_stud, int maxbodovi)
{
	int i = 0;

	for (i=0; i<br_stud; i++) {
		double relativni = ((double)studenti[i].bodovi/maxbodovi)*100;
		printf("Ime: %s\nPrezime: %s\nApsolutni broj bodova: %d\nRelativni broj bodova: %.3lf\n\n",\
		studenti[i].ime, studenti[i].prezime, studenti[i].bodovi, relativni);
	}

	return 0;
}
