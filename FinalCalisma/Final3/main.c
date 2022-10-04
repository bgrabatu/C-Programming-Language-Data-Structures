#include <stdio.h>
#include <stdlib.h>

void LinearSearch(int arr[],int n,int aranan) //b�t�n diziyi gezer ve bulur
{
	int i;
	for(i=0;i<n;i++) //i ba�tan sonra kadar gezer
	{
		if(aranan==arr[i]) //dizinin her i. eleman�nda aranan de�eri arar bulursa true d�nd�r�r
		{
			return i;
		}
	}
	return -1; //bulamazsa -1 d�nd�r�r
}

bool BinarySearch(int arr[],int bas,int son,int aranan)
{
	while(son>=bas) //son ba�tan k���kse e�er
	{
		int orta=arr[(bas+son)/2]; //orta ad�nda bir de�i�ken tan�mlan�r
		if(aranan==arr[orta]) //aranan de�er ortada ise direkt true d�nd�r�r
		{
			return true;
		}
		else if(aranan>orta) //aranan de�er ortadan b�y�kse ba� artt�r�l�r
		{
			bas++;
		}
		else if(aranan<orta) //aranan de�er ortadan k���kse ba� azalt�l�r
		{
			bas--;
		}
	}
	return false;
}

int main() {
	
	printf("Aranan De�eri Giriniz: ");  //L�NEAR SEARCH MA�N
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
	
	
	
	
	printf("Aranan De�eri Giriniz: "); //B�NARY SEARCH MA�N
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
