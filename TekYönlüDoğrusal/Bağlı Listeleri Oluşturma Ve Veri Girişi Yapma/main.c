#include <stdio.h>
#include <stdlib.h>

struct dugum {
	int veri;
	struct dugum * gosterici;
};

int main() {

	struct dugum * bir ;
	bir = (struct dugum *) malloc (sizeof (struct dugum));
	struct dugum * iki ;
	iki = (struct dugum *)malloc(sizeof(struct dugum));
	struct dugum * uc ;
	uc =(struct dugum *)malloc (sizeof(struct dugum));

	bir->veri=31;
	bir->gosterici=iki;
	iki->veri=69;
	iki->gosterici=uc;
	uc -> veri=62;
	uc ->gosterici=NULL;

	printf ("%d-%d-%d",bir->veri,iki->veri,uc->veri);



	return 0;
}
