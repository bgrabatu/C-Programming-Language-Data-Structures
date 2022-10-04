#include <stdio.h>
#include <stdlib.h>

swap(int *x,int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}
void heapify(int arr[],int n,int i) //n eleman say�s�
{
	//b�y�k d���m,sol �ocuklar ve sa� �ocuklar
	int largest=i; //b�y�k d���m
	int left=2*i+1; //sol �ocuk say�s�
	int right=2*i+2; //sa� cocuk say�s�
	
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
		//k�k en b�y�k de�ilse takas ve y���nlamaya devam edin
		swap(&arr[largest],&arr[i]);
		heapify(arr,n,largest);
	}
}

void heapSort(int arr[],int n) //main fonksiyon i�in y���n s�ralama
{
	int i;
	//en b�y�k y���n� in�a et
	for(i=n/2-1;i>=0;i--)
	{
		heapify(arr,n,i);
	}
	//heap sort
	for(i=n-1;i>=0;i--)
	{
		swap(&arr[0],&arr[i]);
		//tekrar k�kte en y�ksek ��eyi elde etmek i�in k�k ��eyi y���nla
		heapify(arr,n,0);
	}
}
int main() {
	
	
	
	return 0;
}
