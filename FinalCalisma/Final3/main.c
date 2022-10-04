#include <stdio.h>
#include <stdlib.h>

void LinearSearch(int arr[],int n,int aranan) //bütün diziyi gezer ve bulur
{
	int i;
	for(i=0;i<n;i++) //i baþtan sonra kadar gezer
	{
		if(aranan==arr[i]) //dizinin her i. elemanýnda aranan deðeri arar bulursa true döndürür
		{
			return i;
		}
	}
	return -1; //bulamazsa -1 döndürür
}

bool BinarySearch(int arr[],int bas,int son,int aranan)
{
	while(son>=bas) //son baþtan küçükse eðer
	{
		int orta=arr[(bas+son)/2]; //orta adýnda bir deðiþken tanýmlanýr
		if(aranan==arr[orta]) //aranan deðer ortada ise direkt true döndürür
		{
			return true;
		}
		else if(aranan>orta) //aranan deðer ortadan büyükse baþ arttýrýlýr
		{
			bas++;
		}
		else if(aranan<orta) //aranan deðer ortadan küçükse baþ azaltýlýr
		{
			bas--;
		}
	}
	return false;
}

int main() {
	
	printf("Aranan Deðeri Giriniz: ");  //LÝNEAR SEARCH MAÝN
	int aranan;
	scanf("%d",&aranan);
	int sonuc=LinearSearch(arr,n,aranan);
	if(sonuc==-1)
	{
		printf("Aranan Eleman Dizide Yok");
	}
	else
	{
		printf("Aranan Eleman Dizide Var");
	}
	
	
	
	
	printf("Aranan Deðeri Giriniz: "); //BÝNARY SEARCH MAÝN
	int aranan;
	scanf("%d",&aranan);
	int sonuc=BinarySearch(arr,0,n-1,aranan);
	if(sonuc)
	{
		printf("Aranan Eleman Dizide Var");
	}
	else
	{
		printf("Aranan Eleman Dizide Yok");
	}
	return 0;
}
