#include <stdio.h>
#include <stdlib.h>

#define BOY 10
struct yigin {
	int dizi[BOY];
	int indis;
};

struct yigin y1;

void elemanEkleme(int sayi)
{
	if(y1.indis==BOY -1)
	{
		printf ("Yigin Dolu!!\n");
	}
	else
	{
		y1.indis++;
		y1.dizi[y1.indis]=sayi;
	}
}
void elemanCikar()
{
	if(y1.indis==-1)
	{
		printf ("Yigin Bos!!\n");
	}
	else
	{
		int cikanSayi=y1.dizi[y1.indis];
		y1.indis--;
		printf ("%d Sayisi Yigindan Cikarildi\n",cikanSayi);
	}
}

void yazdir()
{
	system("cls");
	if(y1.indis==-1)
	{
		printf ("Yigin Bos Yazdirilicak Eleman Yok!!\n");
	}
	else
	{
		int i;
		for(i=y1.indis;i>-1;i--)
		{
			printf ("%d\n",y1.dizi[i]);
		}
	}
}

int main() {
	
	int secim,sayi;
	while(1) 
	{
	
	printf ("Eleman Eklemek Icin-->1 \n");
	printf ("Eleman Silmek Icin-->2 \n");
	printf ("Elemanlari Yazdirmak Icin-->3 \n");
	printf ("Cikis Yapmak Icin-->4 \n");
	printf ("Seciminizi Yapiniz: \n");
	scanf ("%d",&secim);
	switch (secim)
	{
		case 1:
		printf ("Eklemek Istediginiz Elemani Giriniz: ");
		scanf ("%d",&sayi);
		elemanEkleme(sayi);
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
