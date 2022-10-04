#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[],int size)
{
	int i,j;
	for(i=0;i<size;i++)
	{
		for(j=1;j<size-1;j++)
		{
			if(arr[j-1]>arr[j])
			{
				swap(&arr[j-1],&arr[j]);
			}
		}
	}
}
void selectionSort(int arr[],int size)
{
	int i,j,min;
	for(i=0;i<size;i++)
	{
		min=i;
		for(j=i+1;j<size;j++)
		{
			if(arr[j]<arr[min])
			{
				min=j;
			}
		}
		swap(&arr[j],&arr[min]);
	}
}
void insertionSort(int arr[],int size)
{
	int i,j;
	for(i=1;i<size;i++)
	{
		for(j=i;j>0;j--)
		{
			if(arr[j-1]>arr[j])
			{
				swap(&arr[j-1],&arr[j]);
			}
		}
	}
}
void quickSort(int arr[],int bas,int son)
{
	int i,j,pivot,temp;
	i=bas;
	j=son;
	pivot=arr[(i+j)/2];
	
	do
	{
		while(arr[i]<pivot)
		{
			i++;
		}
		while(arr[j]>pivot)
		{
			j--;
		}
		if(i<=j)
		{
			int temp;
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
			i++;
			j--;
		}
	}while(i<j);
	if(i<son)
	{
		quickSort(arr,i,son);
	}
	if(j>bas)
	{
		quickSort(arr,bas,j);
	}
}
int a[]={7,1,5,3,2,4,8,0};
int b[8];
void bol(int bas,int son)
{
	int orta;
	orta=(bas+son)/2;
	bol(bas,orta);
	bol(orta+1,son);
	birlestir(bas,orta,son);
}
void birlestir(int bas,int orta,int son)
{
	int i,j,k;
	for(i=bas;i<=son;i++)
	{
		b[i]=a[i];
	}
	i=bas; //b için
	j=orta+1; //b için
	k=bas; //a için
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

void swap(int*x,int*y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}


int main(int argc, char *argv[]) {
	return 0;
}
