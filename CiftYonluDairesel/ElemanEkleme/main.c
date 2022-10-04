#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node * next;
	struct node * prev;
};
struct node * next;
struct node * start;
struct node * prev;
struct node * temp;
struct node * temp2;

void basaEkle(int sayi)
{
	struct node * eleman=(struct node *)malloc (sizeof(struct node));
	eleman->data=sayi;
	if(start==NULL)
	{
		start=eleman;
		start->next=start;
		start->prev=start;
	}
	else 
	{
		if(start->next==start)
		{
			start->next=eleman;
			start->prev=eleman;
			eleman->next=start;
			eleman->prev=start;
			start=eleman;
		}
		else
		{
			temp=start;
			while(temp->next!=start)
			{
				temp=temp->next;
			}
			temp->next=eleman;
				eleman->next=start;
				eleman->prev=temp;
				start->prev=eleman;
				start=eleman;
		}
	}
}
void listele ()
{
	system("cls");
	if(start==NULL)
	{
		printf ("Listelenilecek Eleman Yok!!");
	}
	else
	{
		temp=start;
		while (temp->next!=start)
		{
			printf ("%d->>",temp->data);
			temp=temp->next;
		}
		printf ("%d",temp->data);
	}
}

void sonaEkle(int sayi)
{
	struct node *eleman=(struct node*)malloc(sizeof(struct node));
	eleman->data=sayi;
	eleman->next=start;
	if (start==NULL)
	{
		start=eleman;
		start->next=start;
		start->prev=start;
	}
	else
	{
		if(start->next==start)
		{
			start->next=eleman;
			start->prev=eleman;
			eleman->next=start;	
			eleman->prev=start;
		}
		else
		{
			temp=start;
			while(temp->next!=start)
			{
				temp=temp->next;
			}
			temp->next=eleman;
			eleman->prev=temp;
			eleman->next=start;
			start->prev=eleman;
		}
	}
}
int main() {
	
	while(1)
	{
		int sayi,secim;
		printf ("\nBasa Eleman Eklemek Icin 1 e Basiniz --> \n");
		printf ("Sona Eleman Eklemek Icin 2 e Basiniz --> \n");
		printf ("Bastan Eleman Silmek Icin 3 e Basiniz --> \n");
		printf ("Sondan Eleman Silmek Icin 4 e Basiniz --> \n");
		printf ("Listelemek Icin 5 e Basiniz --> \n");
		printf ("Eleman Adeti Icin 6 e Basiniz --> \n");
		printf ("Eleman Toplami Icin 1 e Basiniz --> \n");
		printf ("Seciminiz: ");
		scanf ("%d",&secim);
		switch(secim)
		{
			case 1:
			printf("Basa Eklemek Istediginiz Elemani Giriniz: ");
			scanf ("%d",&sayi);		
			basaEkle(sayi);
			break;
			case 2:
			printf ("Sona Eklemek Istediginiz Elemani Giriniz: ");
			scanf("%d",&sayi);
			sonaEkle(sayi);
			break; 
			case 5:
			listele();
			break;
			
		}
}
	return 0;
}
