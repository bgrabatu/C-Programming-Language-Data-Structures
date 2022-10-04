#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node * next;
	struct node * prev;
};

struct node * start;
struct node * next;
struct node * prev;
struct node * temp;
struct node * temp2;

void basaEkle(int sayi)
{
	struct node *eleman;
	eleman = (struct node *)malloc(sizeof(struct node));
	eleman->prev=NULL;
	eleman->data=sayi;
	if(start==NULL)
	{
		start=eleman;
		start->next=NULL;
	}
	else
	{
		eleman->next=start;
		start=eleman;
	}
}
void listele()
{
	if(start==NULL)
	{
		printf ("listenilenecek eleman yok!!");
	}
	else 
	{
		temp=start;
		while (temp->next!=NULL)
		{
			printf ("%d-->",temp->data);
			temp=temp->next;
		}
		printf ("%d",temp->data);
	}
}
void sonaEkle(int sayi)
{
	struct node*eleman;
	eleman=(struct node*)malloc (sizeof(struct node ));
	eleman->next=NULL;
	eleman->data=sayi;
	if(start==NULL)
	{
		start=eleman;
		start->next=NULL;
		start->prev=NULL;
	}
	else 
	{
		if(start->next==NULL)
		{
			start->next=eleman;
			eleman->prev=start;
		}
		else 
		{
			temp=start;
			while (temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=eleman;
			eleman->prev=temp;
		}
	}
}
int main() {
	while(1)
	{
		int sayi, secim;
		printf ("\nBasa Eleman Eklemek Icin 1 e Basiniz->>\n");
		printf ("Sona Eleman Eklemek Icin 2 e Basiniz->>\n");
		printf ("Araya Eleman Eklemek Icin 3 e Basiniz->>\n");
		printf ("Bastan Eleman Silmek Icin 4 e Basiniz->>\n");
		printf ("Sondan Eleman Silmek Icin 5 e Basiniz->>\n");
		printf ("Listelemek Icin 6 a Basiniz->>\n");
		printf ("Seciminiz: \n"); 
		scanf ("%d",&secim);	
		switch(secim)
		{
			case 1:
			printf ("Basa Eklemek Istediginiz Degeri Giriniz: ");
			scanf ("%d",&sayi);
			basaEkle(sayi);
			break;
			case 2:
			printf ("Sona Eklemek Istediginiz Degeri Giriniz: ");
			scanf ("%d",&sayi);
			sonaEkle(sayi);
			break;
			case 6:
			listele();
			break;
		}
	}	
	return 0;
}
