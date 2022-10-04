#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node * next;
};

struct node * temp;
struct node * start;
struct node * prev;
struct node * last;

void basaEkle(int sayi)
{
	struct node * eleman ;
	eleman=(struct node*)malloc(sizeof(struct node));
	eleman->data=sayi;
	if (start==NULL){
		start=eleman;
		start->next=start;
	}
	else 
	{
		temp=start;
		while (temp->next!=start) 
		{
			temp=temp->next;
		}
		temp->next=eleman;
		eleman->next=start;
		start=eleman;
	}
}
void sonaEkle (int sayi)
{
	struct node * eleman;
	eleman=(struct node *)malloc(sizeof(struct node));
	eleman->data=sayi;
	if(start==NULL)
	{
		start=eleman;
		start->next=start;
	}
	else 
	{
		temp=start;
		while (temp->next!=start)
		{
			temp=temp->next;
		}
		temp->next=eleman;
		eleman->next=start;
	}
}

void listele() 
{
	system("cls");
	if(start==NULL)
	{
		printf ("Listelenilecek Eleman Yok!!");
	}
	else 
	{
		temp=start;
		while(temp->next!=start)
		{
			printf ("%d->",temp->data);
			temp=temp->next;
		}
		printf ("%d",temp->data);
	}
}
int main() {
	while (1)
	{
		int secim,sayi;
		printf ("\nBasa Eleman Eklemek Icin->1\n");
		printf ("Sona Eleman Eklemek Icin->2\n");
		printf ("Araya Eleman Eklemek Icin->3\n");
		printf ("Elemanlari Listelemek Icin->4\n");
		printf ("SECIMINIZI YAPINIZ:\n");
		scanf ("%d",&secim);
		
		switch(secim) 
		{
			case 1:
			printf ("Basa Eklenecek Elemani Giriniz-> ");
			scanf ("%d",&sayi);
			basaEkle(sayi);
			break;
			case 2:
			printf ("Sona Eklenecek Elemani Giriniz-> ");
			scanf ("%d",&sayi);
			sonaEkle(sayi);
			break;
			case 4:
			listele();
			break;
		}
	}
	
	
	return 0;
}
