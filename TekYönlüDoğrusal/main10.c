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
	if(start!=NULL) {   
		temp=start->next;
		free(start);
		start=temp;	
	}
	else 
	free(start);
}
void sondanSil(){
	if (start->next!=NULL){ 
		temp=start;
		while (temp->next->next!=NULL){
			temp=temp->next;
		}
		free(temp->next);
		temp->next=NULL;
	}
	else 
	bastanSil();
}

void aradanSil (int veri) {
	temp=start;
	if(temp->data==veri){
		bastanSil();
	}
	else {
		struct node * temp2;
		temp2= (struct node* ) malloc (sizeof(struct node));
		
		while (temp->next->data!=veri) {
			temp=temp->next;
		}
		if(temp->next->next==NULL){
			sondanSil();
		}
		else{
			temp2=temp->next->next;
			free(temp->next);
			temp->next=temp2;
		}
	}
	
}

void yazdir() {
	system ("cls"); 
	if(start!=NULL) {
	temp=start;
	while (temp->next!=NULL) {
		printf ("%d",temp->data);
		temp=temp->next;
	}
	printf ("%d",temp->data);
}
else 
printf ("Eleman Yok!!");
}

int main() {
	int sayi,adet=0,secim,n ;
	while (adet!=20) {
		printf ("\nBasa Eklemek Istiyorsaniz 1 e Basiniz \n");
		printf ("Sona Eklemek Istiyorsaniz 2 e Basiniz \n");
		printf ("Araya Eklemek Istiyorsaniz 3 e Basiniz \n");
		printf("Bastan Silmek Icin 4 e Basiniz \n");
		printf("Sondan Silmek Icin 5 e Basiniz \n");
		printf("Aradan Silmek Icin 6 e Basiniz \n");
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
			case 5:
			sondanSil();
			yazdir();
			break;
			case 6:
			printf ("Aradan Silmek Ýstediðiniz Eleman \n");
			scanf ("%d",&sayi);
			aradanSil(sayi);
			yazdir();
			break;
		}
		adet++;
	}
	return 0;
}
