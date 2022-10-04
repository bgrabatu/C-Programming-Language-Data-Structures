#include <stdio.h>
#include <stdlib.h>


//SONDAN EKLE BA�TAN S�L METODU


struct node {
	int data;
	struct node * next;
};
struct node * temp;
struct node * front;
struct node * rear;

void elemanEkle(int veri) 
{
	struct node*eleman=(struct node*)malloc(sizeof(struct node)); //eklenecek d���m� olu�turur ve yer ay�r�r�z
	eleman->data=veri; //eleman�n datas�da veri olur
	if(front==NULL) //d���m yoksa direkt front eleman olur ayn� zamanda rear da eleman olur 
	{
		front=eleman;
		front->next=front;
		rear=eleman;
		rear->next=NULL;
	}
	else if(front->next==front) //e�er bir tane d���m varsa rear �n nexti eleman olur front un nexti de rear olm� olur
	{
		rear->next=eleman;
		rear=eleman;
		front->next=rear;
	}
	else //birden fazla eleman varsa
	{
		rear->next=eleman; //rear�n nexti eleman olur en son d���m eleman olm� olur yani
		rear=eleman;
		rear->next=NULL;
	}
}
void elemanCikar()
{
	if(front==NULL) //d���m yoksa kuyruk bo�tur
	{
		printf("Kuyruk Bos!!");
	}
	else //d���m varsa 
	{
		temp=front->next; //temp i ba�tan sonraki d���me atar�z ve ba�takini sileriz
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
