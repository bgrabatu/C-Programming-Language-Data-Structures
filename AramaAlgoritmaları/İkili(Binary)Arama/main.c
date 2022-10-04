#include <stdio.h>
#include <stdlib.h>

int binarySearch(int dizi[],int bas,int son,int aranan)
{
	while(son>=bas)
	{
	
	int orta=dizi[(bas+son)/2];
	
		if(orta==aranan)
		{
			return 1;
		}
		if(orta>aranan)
		{
			bas++;
		}
		if(orta<aranan)
		{
			bas--;
		}
	}
	return -1;
}

int main() {
	int n;
	printf("Dizi Uzunlugunu Giriniz: ");
	scanf("%d",&n);
	int dizi[n];
	int i=0;
	while(i<n)
	{
		printf("Sayi: ");
		scanf("%d",&dizi[i]);
		i++;
	}
	printf("Aranan Degeri Giriniz: ");
	int aranan;
	scanf("%d",&aranan);
	int sonuc=binarySearch(dizi,0,n-1,aranan);
	if(sonuc==-1)
	{
		printf("Aranan Deger Dizide Yoktur!!");
	}
	else
	{
		printf("Aranan Deger Dizide Mevcuttur!!");
	}
	return 0;
}
