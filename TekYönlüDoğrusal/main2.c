#include <stdio.h>
#include <stdlib.h>

struct dugum {
	int veri;
	struct dugum * gosterici ;
};

struct dugum * bas =NULL;
struct dugum * gecici =NULL;

void sonaEkle ( int sayi ){
	struct dugum * eklenecek;
	eklenecek=(struct dugum*)malloc(sizeof(struct dugum));
	eklenecek->veri=sayi;
	eklenecek->gosterici=NULL;
		if (bas==NULL){
			bas=eklenecek;
		}
		else {
			gecici=bas;
			while(gecici->gosterici!=NULL){
				gecici=gecici->gosterici;
			}
			gecici->gosterici=eklenecek;
		}
}

void yazdir() {
	gecici=bas;
	while(gecici->gosterici!=NULL){
		printf ("%d",gecici->veri);
	}
	printf ("%d",gecici->veri);
}

int main() {
	int sayi;
	printf ("Bir sayý giriniz: ");
	scanf ("%d",&sayi);
	sonaEkle(sayi);
	yazdir ();
	
	
	
	return 0;
}








