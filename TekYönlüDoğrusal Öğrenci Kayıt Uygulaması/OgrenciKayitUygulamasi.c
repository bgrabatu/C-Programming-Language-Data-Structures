#include <stdio.h>
#include <stdlib.h>

struct ogrenci {
	int no;
	char ad[30];
	int vize,final;
	double ort;
	struct ogrenci*next;
};

typedef struct ogrenci node; //ogrenci adý yerine node adýný kullanýcaz ayný þeyi ifade ediyor

node * ekle(node*head)
{
	node*ogr=(node*)malloc(sizeof(node));
	printf("\nOgrencinin Numarasini Giriniz: \n"); scanf("%d",&ogr->no);
	printf("Ogrencinin Adini Giriniz: \n"); scanf("%s",&ogr->ad); //char olduðu için %s yazarýz
	printf("Ogrencinin Vize Puanini Giriniz: \n"); scanf("%d",&ogr->vize);
	printf("Ogrencinin Final Puanini Giriniz: \n"); scanf("%d",&ogr->final);
	
	ogr->ort = ogr->vize * 0.4 + ogr->final * 0.6;
	
	if(head==NULL)
	{
		head=ogr;
		ogr->next=NULL;
		printf("Liste Oluþturuldu,Ilk Ogrenci Kayit Edildi\n");
	}
	else
	{
		ogr->next=head; //baþa eleman ekleme iþlemi yaptýk
		head=ogr;
		printf("Ogrenci Kayit Edildi\n");
	}
	return head;
}
node*sil(node*head)
{
	if(head==NULL)
	{
		printf("Silinecek Ogrenci Yok,Liste Bos\n");
	}
	else
	{
		int ogrNo;
		printf("Silinecek Ogrencinin Numarasini Giriniz: "); scanf("%d",&ogrNo);
		if(head->no==ogrNo && head->next==NULL) //head in no su eþitse kullanýcýdan alýnan no ya ve tek düðüm varsa
		{
			free(head);
			head=NULL;
			printf("Listede Kalan Son Ogrenci Silindi!\n");
		}
		else if(head->no==ogrNo && head->next!=NULL)// head in no su eþitse kullanýcýdan alýnan no ya ve birden fazla düðüm varsa
		{
			node*p=head->next;
			free(head);
			head=p;
			printf("%d Numarali Ogrenci Silindi!\n",ogrNo);
		}
		else
		{
			node*p=head;
			node*q=head;
			while(p->next!=NULL)
			{
				if(q->no==ogrNo)
				{
					q->next=p->next;
					free(p);
					printf("%d Numarali Ogrenci Silindi\n",ogrNo);
					break;
				}
				q=p; //peþpeþe olan düðümleri tutar yani p den sonraki düðüm p nin next i iken q p dir
			p=p->next;
			}
			if(q->no==ogrNo) //Silinecek düðüm son düðüm ise bu iþlemi yaptýk son düðüme girmezdi üst deki if ifadesi
				{
					q->next=NULL;
					free(p);
					printf("%d Numarali Ogrenci Silindi\n",ogrNo);
				}
		}
	}

	return head;
}
node*yazdir(node*head)
{
	system("cls");
	if(head==NULL)
	{
		printf("Yazdirilacak Ogrenci Bulunamadi,Liste Bos\n");
	}
	else
	{
		node*p=head;
		while(p!=NULL)
		{
			printf("****** OGRENCI BILGILERI ******\n");
			printf("Ogrencinin Numarasi: %d\n",p->no);
			printf("Ogrencinin Adi: %d\n",p->ad);
			printf("Ogrencinin Vize Puani: %d\n",p->vize);
			printf("Ogrencinin Final Puani: %d\n",p->final);
			printf("Ogrencinin Sinav Ortalamasi: %d\n",p->ort);
			p=p->next;
			
		}
	}
	return head;
}
node*enYuksekPuan(node*head)
{
	system("cls");
	int buyukOrt=head->ort;
	node*buyukDugum=head;
	if(head==NULL)
	{
		printf("Yazdirilacak Ogrenci Bulunamadi,Liste Bos\n");
	}
	else
	{
		node*p=head;
		while(p!=NULL)
		{
			if(buyukOrt<p->ort)
			{
				buyukOrt=p->ort;
				buyukDugum=p;
			}
			p=p->next;
		}
		printf("****** EN BASARILI OGRENCI ******\n");
		printf("Ogrencinin Numarasi: %d\n",buyukDugum->no);
		printf("Ogrencinin Adi: %d\n",buyukDugum->ad);
		printf("Ogrencinin Vize Puani: %d\n",buyukDugum->vize);
		printf("Ogrencinin Final Puani: %d\n",buyukDugum->final);
		printf("Ogrencinin Ders Notu Ortalamasi: %d\n",buyukDugum->ort);
	}
	return head;
}
int main() {
	int secim;
	node*head=NULL;
	while(1)
	{
		printf("***** OGRENCI KAYIT UYGULAMASI ******\n");
		printf("Ogrenci Eklemek Icin -> 1\n");
		printf("Ogrenci Silmek Icin -> 2\n");
		printf("Ogrenci Bilgirini Yazdirmak Icin -> 3\n");
		printf("En Basarili Ogrenciyi Ogrenmek Icin -> 4\n");
		printf("Cikis ->5\n");
		printf("Seciminizi Yapiniz: "); 
		scanf("%d",&secim);
		switch (secim)
		{
			case 1:
			head=ekle(head);
			break;
			case 2:
			head=sil(head);
			break;
			case 3:
			head=yazdir(head);
			break;
			case 4:
			head=enYuksekPuan(head);
			break;
			case 5:
				exit(0);
				default:("Hatali Secim Yaptiniz!!\n");
		}
	}
	return 0;
}
