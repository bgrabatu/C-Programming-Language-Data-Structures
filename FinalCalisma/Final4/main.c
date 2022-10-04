#include <stdio.h>
#include <stdlib.h>

swap(int *x,int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}
void heapify(int arr[],int n,int i) //n eleman sayýsý
{
	//büyük düðüm,sol çocuklar ve sað çocuklar
	int largest=i; //büyük düðüm
	int left=2*i+1; //sol çocuk sayýsý
	int right=2*i+2; //sað cocuk sayýsý
	
	if(left < n && arr[left]>arr[largest])
	{
		largest=left;
	}
	else if(right < n && arr[right]>arr[largest])
	{
		largest=right;
	}
	else if(largest!=i)
	{
		//kök en büyük deðilse takas ve yýðýnlamaya devam edin
		swap(&arr[largest],&arr[i]);
		heapify(arr,n,largest);
	}
}

void heapSort(int arr[],int n) //main fonksiyon için yýðýn sýralama
{
	int i;
	//en büyük yýðýný inþa et
	for(i=n/2-1;i>=0;i--)
	{
		heapify(arr,n,i);
	}
	//heap sort
	for(i=n-1;i>=0;i--)
	{
		swap(&arr[0],&arr[i]);
		//tekrar kökte en yüksek öðeyi elde etmek için kök öðeyi yýðýnla
		heapify(arr,n,0);
	}
}
int main() {
	
	
	
	return 0;
}
