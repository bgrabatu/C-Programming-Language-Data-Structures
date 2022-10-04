#include <stdio.h>
#include <stdlib.h>

#define BOY 5

int dizi[BOY];
int bas=-1;
int son=-1;

void elemanEkle(int veri)
{
	if(son==BOY-1)
	{
		printf("Kuyruk Dolu!!");
	}
	else
	{
		if(bas==-1)
		{
			bas=0;
		}
		son++;
		dizi[son]=veri;
	}
}

void elemanCikar()
{
	if(bas==-1 || bas>son)
	{
		printf("Kuyruk Bos!!");
		bas==-1;
		son==-1;
	}
	else
	{
		bas=bas+1;
	}
}

void yazdir()
{
	system("cls");
	if(bas==-1)
	{
		printf("Kuyruk Bos!!");
	}
	else
	{
		int i;
		for(i=bas;i<=son;i++)
		{
			printf ("%d->",dizi[i]);
		}
	}
}

int main() {
	while(1)
	{
		int secim,sayi;
		printf ("\nEleman Eklemek Icin->>1\n");
		printf ("Eleman Silmek Icin->>2\n");
		printf ("Eleman Listelemek Icin->>3\n");
		printf ("Cikis Icin->>4\n");
		printf("Seciminizi Yapiniz: ");
		scanf("%d",&secim);
		switch(secim)
		{
			case 1:
			printf ("Basa Eklenecek Eleman: ");
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
