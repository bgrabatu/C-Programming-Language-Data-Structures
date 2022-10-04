#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[],int n)
{
	int i,j;
	for(i=1;i<n;i++)
	{
		for(j=i;j>0;j--)
		{
			if(arr[j]<arr[j-1])
			{
				swap(&arr[j],&arr[j-1]);
			}
		}
	}
}
void swap(int*x,int*y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}
void display(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
}
int main() {
	int arr[]={1,3,2,0,4,9,7,8,5,6};
	int n=sizeof(arr)/sizeof(arr[0]);
	
	insertionSort(arr,n);
	display(arr,n);	
	
	return 0;
}
