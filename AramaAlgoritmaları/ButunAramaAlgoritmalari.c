#include <stdio.h>
#include <stdlib.h>

void linearSearch(int arr[],int size,int aranan)
{
	int i;
	for(i=0;i<size;i++)
	{
		if(aranan==arr[i])
		{
			return i;
		}
	}
	return -1;
}
void binarySearch(int arr[],int bas,int son,int aranan)
{
	while(bas<=son)
	{
		int orta;
		orta=(bas+son)/2;
		if(aranan==orta)
		{
			return true;
		}
		else if(aranan<orta)
		{
			bas--;
		}
		else if(aranan>orta)
		{
			bas++;	
		}
	}
	return false;
}

int main(int argc, char *argv[]) {
	return 0;
}
