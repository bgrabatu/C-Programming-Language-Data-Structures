#include <stdio.h>
#include <stdlib.h>
void swap(int*x,int*y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}
void bubbleSort(int arr[], int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				swap (&arr[j],&arr[j+1]);
			}
		}
	}
}
void yazdir(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
}

int main() {

	int arr[]={1,5,0,4,9,8,2,3,7};
	int n=sizeof(arr)/sizeof(arr[0]);
	bubbleSort(arr,n);
	yazdir(arr,n);
	return 0;
}
