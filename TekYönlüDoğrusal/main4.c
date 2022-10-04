#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node * next ;
};

struct node * start ;
struct node * temp ;

void basaEkle ( int veri ) {
	struct node * eleman ;
	eleman = (struct node *) malloc (sizeof(struct node));
	eleman->data=veri;
	eleman->next=start;
	start=eleman;
}

void sonaEkle (int veri ) {
	struct node * eleman ;
	eleman = (struct node *) malloc (sizeof(struct node));
	eleman->data=veri;
	eleman->next=NULL;
	
	if(start==NULL) {
		start=eleman;
	}
	else {
		temp=start;
		while (start->next != NULL) {
			temp=temp->next;
		}
		temp->next;
	}
 }
 
 void arayaEkle(int n,int veri) {
 	struct node * eleman;
 	eleman= (struct node *)malloc (sizeof(struct node));
 	eleman->data=veri;
 	
 	temp=start;
 	while(temp->next = veri != n) {
 		temp=temp->next;
	 }
	 
	struct node * temp2;
	temp2=(struct node *)malloc(sizeof(struct node));
	temp2=temp->next;
	temp->next=eleman;
	temp->next=temp2;
 }
 
 void yazdir () {
 	temp=start;
 	while (start->next != NULL) {
 		printf ("%d",temp->data);
 		temp=temp->next;
	 }
	 printf ("%d",temp->data);
 }





int main() {
	
	int adet,sayi,secim;
	while (adet !=6) {
		printf ("ba�tan eleman eklemek i�in 1 \n");
		printf ("sondan eleman eklemek i�in 2 \n");
		printf ("se�iminizi yap�n�z : \n");
		scanf ("%d",&secim);
		
		switch (secim) {
			case 1: 
			printf ("ba�a eklenecek eleman� giriniz: \n");
			scanf ("%d",&sayi);
			void basaEkle(sayi);
			yazdir();
			break;
			
			case 2:
			printf ("sona eklenecek eleman� giriniz: \n");
			scanf ("%d",&sayi);
			void sonaEkle(sayi);
			yazdir();
			break;
		}
		adet++;
}
	return 0;
	
	
	
	
	
	
	
}
