#include <stdio.h>
#include <stdlib.h>


void swap(int *x,int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}
void yazdir(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d->",arr[i]);
	}
}

void bubbleSort(int arr[],int n) //ikili karþýlaþtýrma algoritmasý j yi karþýlaþtýrýrýz
{
	int i,j;
	for(i=0;i<n;i++) //i yi en baþtan baþlatýrýz ve en sona kadar götürürüz
	{
		for(j=1;j<n-1;j++) //j 1 den baþlar ve son düðüme kadar gider
		{
			if(arr[j-1]>arr[j])//i=0 iken j=0 ve j=1 karþýlaþtýrýlýr i=1 iken j=1 ve j=2 karþýlaþtýrýlýr
			{
				swap(&arr[j-1],&arr[j]);
			}
		}
	}
}
void selectionSort(int arr[],int n) //en küçük deðeri arar ve baþa koyar
{
	int i,j,min;
	for(i=0;i<n;i++)
	{
		min=i; //min 0. indexe tanýmlandý
		for(j=i+1;j<n;j++) //i=0 iken j=1 olmak zorunda
		{
			if(arr[j]<arr[min]) //1.indexteki deðer 0. indexteki deðerden küçükse artýk minimum deðer 1. indexteki sayý olur
			{
				min=j;
			}
		}
		swap(&arr[j],&arr[min]); //deðiþtirme iþlemi uygulanýr
	}
}

void insertionSort(int arr[],int n) //saðdaki deðeri soldaki deðer ile kýyaslar ve yer deðiþtirir. J leri karþýlaþtýrýrýz
{
	int i,j;
	for(i=1;i<n;i++) //baþtaki deðeri almaz çünkü saðdaki deðer ile soldaki deðeri karþýlaþtýrýr zaten
	{
		for(j=i;j>0;j--) //j=1 den baþlar ve azalarak devam eder 
		{
			if(arr[j]<arr[j-1])//j=1 iken j-1=0 olur yani saðdaki deðer ile soldaki deðeri kýyaslar bu þekilde ilk deðeri de katar
			{
				swap(&arr[j],&arr[j-1]); //koþul saðlanýrsa yer deðiþtirme iþlemi uygulanýr
			}
		}
	}
}

void quickSort(int arr[],int bas,int son) //ortanca deðer tanýmlanýr ve onunla kýyaslanýr
{
	int i,j,temp,pivot;
	i=bas;
	j=son;
	pivot=arr[(i+j)/2];

do
{
	while(arr[i]<pivot) //dizinin i. elemaný pivottan küçükse pivota yakýnlaþtýrýlýr
	{
		i++;
	}
	while(arr[j]>pivot) //dizinin j. elemaný pivottan büyükse pivota yakýnlaþtýrýlýr
	{
		j--;
	}
	if(i<=j) // eðer i j den küçük veya eþitse swap iþlemi uygulanýr
	{
		temp=arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
		i++;
		j--;
	}
}while(i<j);
if(i<son) //i sondan küçükse
{
	quickSort(arr,i,son); 
}
else if(j>bas) //j baþtan büyükse
{
	quickSort(arr,bas,j);
}
}
//MERGE SORT

int a[]={7,4,7,8,3,9,2,1};
int b[8];
void bol(int bas,int son)
{
	int orta;
	orta=(bas+son)/2;
	bol(bas,orta);
	bol(orta+1,son);
}
void birlestir(int bas,int orta,int son)
{
	int i,j,k;
	for(i=bas;i<=son;i++) //i bastan baþlamalý ve sona kadar gitmeli her elemaný da b ye atmalý
	{
		b[i]=a[i]; //a dizisini b ye kopyaladýk
	}
	i=bas;//b için
	j=orta+1;//b için
	k=bas;//a için
	
	while(i<=orta && j<=son)
	{
		if(b[i]<=b[j])
		{
			a[k++]=b[i++];
		}
		else
		{
			a[k++]=b[j++];
		}
	}
	while(i<=orta)
	{
		a[k++]=b[i++];
	}
}

int main() {
	return 0;
}
