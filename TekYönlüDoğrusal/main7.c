#include <stdio.h>
#include <stdlib.h>

	struct node {
		int data;
		struct node * next;
	};

struct node * start;
struct node * temp;

void bastanSil () {
	if (start!=NULL) {
		temp=start->next;
		free(start);
		temp=start;
	}
	else 
	free(start);
}



int main() {
	int sayi,adet=0,secim,n;
	while(6==6) {
		printf ("bastan eleman silmeki için 4 \n");
		printf ("secim yapiniz: \n");
		scanf ("%d",&secim);
		
		switch(secim ){
			case 4:
			bastanSil();
			break;
		}
		adet++;
	}
	return 0;
}
