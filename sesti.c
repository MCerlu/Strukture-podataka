#define CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
struct element;
typedef struct element *Pozicija;
struct element{
    int x;
    Pozicija next;}
void Stog();
void Red();
int Pop();
int main(void)
{
    
    int izbor;
    printf("Zelite li simulirati rad stoga ili rad reda?");
    printf("\n 1.RED");
    printf("\n 2.STOG");
    printf("Unesite 1 ili 2 za izbor:");
    scanf("%d",&izbor);
    switch(izbor){
        case 1:
            printf("\n Odabrali ste simulaciju rada reda.")
            Red();
            break;
        case 2:
            printf("\n Odabrali ste simulaciju rada stoga.");
            Stog();
            break;
    }
    return 0;
}
void Stog()
{
    element *Head;
	Head = (element*)malloc(sizeof(element));
	if (!Head)
		return -1;
	Head->next = NULL;
    
    int n,elm;
    printf("Sto zelite raditi nad stogom?(1-unos novog elementa,2-skidanje elementa sa stoga,3-izlaz)");
    do
    {
    printf("\n Unesite vas izbor: ");
    scanf("%d",&n);
    if(n==1)
    {
           printf("Unesite element:");
           scanf("%d",&elm);
           Pozicija P=(element*)malloc(sizeof(element));
           p.x=elm;
           p->next = head->next;
	       head->next = p;
           
    }
    else if(n==2)
    {
        
    }
    }while(n!=3);
}
