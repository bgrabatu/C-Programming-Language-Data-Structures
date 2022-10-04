#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node * next;
};
struct node * start;
struct node * temp;

void basaEkle(int veri) {
	struct node * eleman;
	eleman = (struct node * ) malloc (sizeof(struct node));
	eleman->data=veri;
	eleman->next=start;
	start=eleman;
}

void sonaEkle(int veri) {
	struct node * eleman ;
	eleman=(struct node *) malloc (sizeof(struct node));
	eleman->data=veri;
	eleman->next=NULL;
	if(start==NULL) {
		start=eleman;
	}
	else {
		temp=start;
		while(temp->next != NULL) {
			temp=temp->next;
		}
		temp->next= eleman;
	}
}

void arayaEkle (int n,int veri) {
	struct node * eleman;
	eleman= (struct node *)malloc (sizeof(struct node));
	eleman->data=veri;
	temp=start;
	while(temp->next->data != n) {
		temp=temp->next;
	}
	struct node * temp2;
	temp2=(struct node*) malloc (sizeof(struct node));
	temp2=temp->next;
	temp->next=eleman;
	eleman->next=temp2;
}

void bastanSil() {
	if(start==NULL) {
		temp=start->next;
		free(start);
		temp=start;
	}
	else 
	free(start);


}
void yazdir() {
	temp=start;
	while (temp->next!=NULL) {
		printf ("%d",temp->data);
		temp=temp->next;
	}
	printf ("%d",temp->data);
}
int main() {
	int sayi,adet=0,secim,n ;
	while (adet!=6) {
		printf ("\nBasa Eklemek Istiyorsaniz 1 e Basiniz \n");
		printf ("Sona Eklemek Istiyorsaniz 2 e Basiniz \n");
		printf ("Araya Eklemek Istiyorsaniz 3 e Basiniz \n");
		printf("Silmek Icin 4 e Basiniz \n");
		printf ("Secim Yapiniz: \n");
		scanf ("%d",&secim);
		
		switch (secim) {
			case 1: 
			printf ("Basa Eklemek Istediginiz Eleman \n");
			scanf ("%d",&sayi);
			basaEkle(sayi);
			yazdir();
			break;
			case 2:
			printf ("\nSona Eklemek Istediginiz Eleman \n");
			scanf ("%d",&sayi);
			sonaEkle(sayi);
			yazdir();
			break;
			case 3:
			printf ("Hangi Sayýdan Once Girilsin: ");
			scanf ("%d",&n);
			printf ("\nAraya Eklemek Istediginiz Eleman \n");
			scanf ("%d",&sayi);
			arayaEkle(n,sayi);
			yazdir();
			break;
			case 4:
			bastanSil();
			yazdir();
			break;
		}
		adet++;
	}
	return 0;
}
