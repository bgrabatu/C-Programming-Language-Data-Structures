#include <stdio.h>
#include <stdlib.h>


//BA�A EKLE BA�TAN �IKAR



struct node{
	int data;
	struct node*next;	
};

struct node * temp=NULL;
struct node * top=NULL;
void push(int veri) //ELEMAN EKLEME
{
	struct node * eleman;
	eleman=(struct node*)malloc(sizeof(struct node)); //eklenecek d���m olu�turuldu ve yer ay�r�ld�
	eleman->data=veri; //eleman�n datas� veri olmu� oldu
	
	if(top==NULL) //en ba�taki d���m bo�sa
	{
		top=eleman; //ba�a eleman� atar�z ve nexti null olur
		top->next=NULL;
	}
	else //e�er d���m varsa
	{
		eleman->next=top; //ba�a eklemek i�in eleman�n nexti top olur ve top eleman olur yani en ba�a ge�mi� olur
		top=eleman;
	}
}
void pop() //S�LME
{
	if(top==NULL) //ba�taki d���m bo�sa silincek eleman yok
	{
		printf ("Silinecek Eleman Bulunamad�!! \n");
	}
	else //e�er birden fazla d���m varsa
	{
		printf ("Silinen Eleman: %d\n",top->data); //en ba�tan silice�imiz i�in silinen veri top un datas� olur
		temp=top->next; //temp i toptan sonraki d���me atar�z
		free(top);//top u sileriz
		top=temp;//ve ba�taki d���m temp olur
	}
}
void print()
{
	system("cls");
	if(top==NULL)
	{
		printf ("Yazdirilacak Eleman Yok!! \n");
	}
	else
	{
		temp=top;
		while(temp->next!=NULL)
		{
			printf("%d \n",temp->data);
			temp=temp->next;
		}
		printf("%d \n",temp->data);
	}
}
void peek() //EN TEPEDEK� DE�ER
{
	if(top==NULL) //d���m bo�sa eleman yok
	{
		printf("Eleman Yok Stack Bos!! \n");
	}
	else //d���m varsa direkt top d���m�n datas� al�n�r
	{
		printf("En Tepedeki Eleman: %d \n",top->data);
	}
}
int main() {
	
	while(1)
	{
		int secim,sayi;
		printf ("Eleman Eklemek Icin->>1 \n");
		printf ("Eleman Silmek Icin->>2\n");
		printf ("Listelemek Icin->>3\n");
		printf ("Top Degeri Listelemek Icin->>4\n");
		printf ("Cikis Yapmak Icin->>5\n");
		printf ("Seciminizi Yapiniz: \n");
		scanf("%d",&secim);
		switch(secim)
		{
			case 1:
			printf("Eklenecek Elemani Yaziniz: ");
			scanf("%d",&sayi);
			push(sayi);
			break;
			case 2:
			pop();
			break;
			case 3:
			print();
			break;
			case 4:
			peek();
			break;
			case 5:
			return 0;
			
		}
	}
	
	
	
	return 0;
}
