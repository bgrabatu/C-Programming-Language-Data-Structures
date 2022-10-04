#include <stdio.h>
#include <stdlib.h>

struct dugum {
	int veri;
	struct dugum * gosterici;
};

struct dugum * bas=NULL;
struct dugum * gecici=NULL;

void basaEkle(int sayi){
	struct dugum * eklenecek ;
	eklenecek = (struct dugum *)malloc(sizeof(struct dugum));
	eklenecek->veri=sayi;
	eklenecek->gosterici=bas;
	bas=eklenecek;
}
void yazdir() 
{
	gecici=bas;
	while (gecici->gosterici != NULL) {
		printf("%d",gecici->veri);
		gecici=gecici->gosterici;
	}
	printf("%d",gecici->veri);
}


int main() {
	
	int sayi;
	printf("Bir sayý giriniz :");
	scanf ("%d",&sayi);
	basaEkle(sayi);
	yazdir();
	
	return 0;
}
