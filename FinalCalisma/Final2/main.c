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

void bubbleSort(int arr[],int n) //ikili kar��la�t�rma algoritmas� j yi kar��la�t�r�r�z
{
	int i,j;
	for(i=0;i<n;i++) //i yi en ba�tan ba�lat�r�z ve en sona kadar g�t�r�r�z
	{
		for(j=1;j<n-1;j++) //j 1 den ba�lar ve son d���me kadar gider
		{
			if(arr[j-1]>arr[j])//i=0 iken j=0 ve j=1 kar��la�t�r�l�r i=1 iken j=1 ve j=2 kar��la�t�r�l�r
			{
				swap(&arr[j-1],&arr[j]);
			}
		}
	}
}
void selectionSort(int arr[],int n) //en k���k de�eri arar ve ba�a koyar
{
	int i,j,min;
	for(i=0;i<n;i++)
	{
		min=i; //min 0. indexe tan�mland�
		for(j=i+1;j<n;j++) //i=0 iken j=1 olmak zorunda
		{
			if(arr[j]<arr[min]) //1.indexteki de�er 0. indexteki de�erden k���kse art�k minimum de�er 1. indexteki say� olur
			{
				min=j;
			}
		}
		swap(&arr[j],&arr[min]); //de�i�tirme i�lemi uygulan�r
	}
}

void insertionSort(int arr[],int n) //sa�daki de�eri soldaki de�er ile k�yaslar ve yer de�i�tirir. J leri kar��la�t�r�r�z
{
	int i,j;
	for(i=1;i<n;i++) //ba�taki de�eri almaz ��nk� sa�daki de�er ile soldaki de�eri kar��la�t�r�r zaten
	{
		for(j=i;j>0;j--) //j=1 den ba�lar ve azalarak devam eder 
		{
			if(arr[j]<arr[j-1])//j=1 iken j-1=0 olur yani sa�daki de�er ile soldaki de�eri k�yaslar bu �ekilde ilk de�eri de katar
			{
				swap(&arr[j],&arr[j-1]); //ko�ul sa�lan�rsa yer de�i�tirme i�lemi uygulan�r
			}
		}
	}
}

void quickSort(int arr[],int bas,int son) //ortanca de�er tan�mlan�r ve onunla k�yaslan�r
{
	int i,j,temp,pivot;
	i=bas;
	j=son;
	pivot=arr[(i+j)/2];

do
{
	while(arr[i]<pivot) //dizinin i. eleman� pivottan k���kse pivota yak�nla�t�r�l�r
	{
		i++;
	}
	while(arr[j]>pivot) //dizinin j. eleman� pivottan b�y�kse pivota yak�nla�t�r�l�r
	{
		j--;
	}
	if(i<=j) // e�er i j den k���k veya e�itse swap i�lemi uygulan�r
	{
		temp=arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
		i++;
		j--;
	}
}while(i<j);
if(i<son) //i sondan k���kse
{
	quickSort(arr,i,son); 
}
else if(j>bas) //j ba�tan b�y�kse
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
	for(i=bas;i<=son;i++) //i bastan ba�lamal� ve sona kadar gitmeli her eleman� da b ye atmal�
	{
		b[i]=a[i]; //a dizisini b ye kopyalad�k
	}
	i=bas;//b i�in
	j=orta+1;//b i�in
	k=bas;//a i�in
	
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
