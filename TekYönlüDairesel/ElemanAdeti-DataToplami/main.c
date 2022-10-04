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

void bastanSil()
{
	if(start==NULL)
	{
		printf ("Silinecek Deger Bulunamadý!!");
	}
	else 
	{
		if(start->next==start)
		{
			free(start);
			start=NULL;
		}
		else
		{
			last=start;
			while(last->next!=start)
			{
				last=last->next;
			}
			temp=start->next;
			free(start);
			last->next=temp;
			start=temp;
		}
	}
}

void sondanSil()
{
	if(start==NULL)
	{
		printf ("Silinecek Eleman Yok!!");
	}
	else
	{
		if(start->next==start)
		{
			free(start);
			start=NULL;
		}
		else
		{
			last=start;
			while(last->next->next!=start)
			{
				last=last->next;
			}
			temp=last;
			free(last->next);
			last->next=start;
			
		}
	}
}

int elemanSay()
{
	int adet=0;
	if(start==NULL)
	{
		return 0;
	}
	else 
	{
		temp=start;
		while(temp->next!=start)
		{
			adet++;
			temp=temp->next;
		}
		adet++;
	}
	return adet;
}

int dataToplam()
{
	int toplam=0;
	if(start==NULL)
	{
		return 0;
	}
	else 
	{
		temp=start;
		while(temp->next!=start)
		{
			toplam+=temp->data;
			temp=temp->next;
		}
		toplam+=temp->data;
	}
	return toplam;
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
		printf ("Bastan Eleman Silmek Icin->3\n");
		printf ("Sondan Eleman Silmek Icin->4\n");
		printf ("Elemanlari Listelemek Icin->5\n");	
		printf ("Eleman Adeti Icin->6\n");
		printf ("Data Toplami Icin->7\n");
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
			case 3:
			bastanSil();
			break;
			case 4:
			sondanSil();
			break;
			case 5:
			listele();
			break;
			case 6:
			printf("Eleman Adeti: %d",elemanSay());
			break;
			case 7:
			printf("Data Toplamý: %d",dataToplam());
			break;
		}
	}
	
	
	return 0;
}
