#include <stdio.h>
#include <stdlib.h>

int LinearSearch(int dizi[],int n,int aranan)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(aranan==dizi[i])
		{
			return i;
		}
		return -1;
	}
}

int main() {
	int n;
	printf("Dizinin Uzunlugunu Giriniz: ");
	scanf("%d",&n);
	int dizi[n];
	int i=0;
	while(i<n)
	{
		printf("Sayi: ");
		scanf("%d",&dizi[i]);
		i++;
	}
	printf("Aranan Elemaný Giriniz: ");
	int aranan;
	scanf("%d",&aranan);
	int toplam=LinearSearch(dizi,n,aranan);
	if(toplam==-1)
	{
		printf("Aranan Eleman Dizide Mevcut Degildir!!");
	}
	else
	{
		printf("Aranan Eleman Dizide Mevcuttur!!");
	}
	return 0;
}
