#include <stdio.h>
#include <stdlib.h>


//SONDAN EKLE BAÞTAN SÝL METODU


struct node {
	int data;
	struct node * next;
};
struct node * temp;
struct node * front;
struct node * rear;

void elemanEkle(int veri) 
{
	struct node*eleman=(struct node*)malloc(sizeof(struct node)); //eklenecek düðümü oluþturur ve yer ayýrýrýz
	eleman->data=veri; //elemanýn datasýda veri olur
	if(front==NULL) //düðüm yoksa direkt front eleman olur ayný zamanda rear da eleman olur 
	{
		front=eleman;
		front->next=front;
		rear=eleman;
		rear->next=NULL;
	}
	else if(front->next==front) //eðer bir tane düðüm varsa rear ýn nexti eleman olur front un nexti de rear olmþ olur
	{
		rear->next=eleman;
		rear=eleman;
		front->next=rear;
	}
	else //birden fazla eleman varsa
	{
		rear->next=eleman; //rearýn nexti eleman olur en son düðüm eleman olmþ olur yani
		rear=eleman;
		rear->next=NULL;
	}
}
void elemanCikar()
{
	if(front==NULL) //düðüm yoksa kuyruk boþtur
	{
		printf("Kuyruk Bos!!");
	}
	else //düðüm varsa 
	{
		temp=front->next; //temp i baþtan sonraki düðüme atarýz ve baþtakini sileriz
		free(front);
		front=temp;
	}
}
void yazdir()
{
	system("cls");
	if(front==NULL)
	{
		printf("Kuyruk Bos!!");
	}
	else
	{
		temp=front;
		while (temp->next!=NULL)
		{
			printf ("%d->",temp->data);
			temp=temp->next;
		}
		printf("%d",temp->data);
	}
}

int main() {
	while(1)
	{
		int secim,sayi;
		printf ("\nEleman Eklemek Icin ->> 1\n");
		printf ("Eleman Silmek Icin ->> 2\n");
		printf ("Eleman Listelemek Icin ->> 3\n");
		printf ("Cikis Icin ->> 4\n");
		printf("Seciminizi Yapiniz: ");
		scanf("%d",&secim);
		switch(secim)
		{
			case 1:
			printf ("Eklemek Istediginiz Elemani Giriniz: ");
			scanf("%d",&sayi);
			elemanEkle(sayi);
			break;
			case 2:
			elemanCikar();
			break;
			case 3:
			yazdir();
			break;
			case 4:
			return 0;
		}

	}

	return 0;
}
