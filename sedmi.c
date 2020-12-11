#define CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<conio.h>
struct element;
typedef struct element *Pozicija;
struct element{
    int x;
    Pozicija next;}
int main(void)
{
  char* buffer=NULL;
  int value=0;
  int broj;
  int count=0;
  char filename[]="postfix.txt";
  FILE *fp=NULL;
  int max=0;
  
  element *Head;
	Head = (element*)malloc(sizeof(element));
	if (!Head)
		return -1;
	Head->next = NULL;
  
  
 
  buffer=(char*)malloc(1000*sizeof(char));
 
  fp=fopen(filename,"r");
  memset(buffer,"\0",1000);
  buffer=fgets(buffer,1000,fp);
  
  fclose(fp);
  
  
   
   value=sscanf(buffer,"%d%N",&broj,&count);
   buffer+=count;
   Pozicija number=(element*)malloc(sizeof(element));
   number->x=broj;
   
   number->next=head->next;
   head->next=number;
   
  
  
  
  
}

