#include <stdio.h>
#include <stdlib.h>
void selectionSort(int arr[],int n)
{
	int i,j,min;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(arr[min]>arr[j])
			{
				min=j;
			}
		}
		swap(&arr[min],&arr[i]);
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
	int arr[]={3,5,1,0,4,2,6,9,7,8};
	int n=sizeof(arr)/sizeof(arr[0]);
	selectionSort(arr,n);
	display(arr,n);
	return 0;
}
