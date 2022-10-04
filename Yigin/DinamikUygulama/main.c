#include <stdio.h>
#include <stdlib.h>


//BAÞA EKLE BAÞTAN ÇIKAR



struct node{
	int data;
	struct node*next;	
};

struct node * temp=NULL;
struct node * top=NULL;
void push(int veri) //ELEMAN EKLEME
{
	struct node * eleman;
	eleman=(struct node*)malloc(sizeof(struct node)); //eklenecek düðüm oluþturuldu ve yer ayýrýldý
	eleman->data=veri; //elemanýn datasý veri olmuþ oldu
	
	if(top==NULL) //en baþtaki düðüm boþsa
	{
		top=eleman; //baþa elemaný atarýz ve nexti null olur
		top->next=NULL;
	}
	else //eðer düðüm varsa
	{
		eleman->next=top; //baþa eklemek için elemanýn nexti top olur ve top eleman olur yani en baþa geçmiþ olur
		top=eleman;
	}
}
void pop() //SÝLME
{
	if(top==NULL) //baþtaki düðüm boþsa silincek eleman yok
	{
		printf ("Silinecek Eleman Bulunamadý!! \n");
	}
	else //eðer birden fazla düðüm varsa
	{
		printf ("Silinen Eleman: %d\n",top->data); //en baþtan siliceðimiz için silinen veri top un datasý olur
		temp=top->next; //temp i toptan sonraki düðüme atarýz
		free(top);//top u sileriz
		top=temp;//ve baþtaki düðüm temp olur
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
void peek() //EN TEPEDEKÝ DEÐER
{
	if(top==NULL) //düðüm boþsa eleman yok
	{
		printf("Eleman Yok Stack Bos!! \n");
	}
	else //düðüm varsa direkt top düðümün datasý alýnýr
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
