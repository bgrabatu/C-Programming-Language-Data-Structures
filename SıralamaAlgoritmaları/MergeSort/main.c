#include <stdio.h>
#include <stdlib.h>
int a[]={7,1,5,3,2,4,8,0,9,6};
int b[10];

void birlestir(int bas,int orta,int son)
{
	int i,j,k;
	for(i=bas;i<=son;i++)
	b[i]=a[i];
	i=bas;
	j=orta+1;
	k=bas;
	while (i<=orta && j<=son)
	{
	if(b[i]<=b[j])
	a[k++]=b[i++];
	else
	a[k++]=b[j++];
	}
	while(i<=orta)
	a[k++]=b[i++];
	}
	

void bol(int bas,int son)
{
	if(bas<son)
	{
		int orta;
		orta=(bas+son)/2;
		bol(bas,orta);
		bol(orta+1,son);
		
		birlestir(bas,orta,son);
	}
}
int main() {
	bol(0,9);
	int i;
	for(i=0;i<=9;i++)
	{
		printf("%d ",a[i]);
	}
	
	return 0;
}
