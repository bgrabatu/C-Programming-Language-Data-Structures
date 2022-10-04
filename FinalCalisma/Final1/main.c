#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node*left;
	struct node*right;	
};

struct node*kokDugumOlustur(int veri)
{
	struct node*root=(struct node*)malloc(sizeof(struct node));
	root->data=veri;
	root->left=NULL;
	root->right=NULL;
	
	return root;
}
struct node*elemanEkle(struct node*root,int veri)
{
	if(root==NULL)
	{
		root=kokDugumOlustur(veri);
	}
	else
	{
		if(veri<root->data)
		{
			root->left=elemanEkle(root->left,veri);
		}
		else
		{
			root->right=elemanEkle(root->right,veri);
		}
	}
	return root;
}

void preOrder(struct node*root)//kök baþta
{
	if(root!=NULL)
	{	
	printf("Root: %d",root->data);
	preOrder(root->left);
	preOrder(root->right);
	}
}
void inOrder(struct node*root)//kök ortada
{
	if(root!=NULL)
	{
	inOrder(root->left);
	printf("Root:%d",root->data);
	inOrder(root->right);
	}	
}
void postOrder(struct node*root)//kök sonda
{
	if(root!=NULL)
	{
	postOrder(root->left);
	postOrder(root->right);
	printf("Root:%d",root->data);
	}
}

int elemanAdet(struct node*root)
{
	if(root==NULL)
	{
		return 0;
	}
	else
	{
		return elemanAdet(root->left) + 1 + elemanAdet(root->right);
	}
}
struct node*find_minimum(struct node*root)
{
	if(root==NULL)
	{
		return NULL;
	}
	else if(root->left!=NULL)
	{
		return find_minimum(root->left);
	}
	return root;
}
struct node*find_maximum(struct node*root)
{
	if(root==NULL)
	{
		return NULL;
	}
	else if(root->right!=NULL)
	{
		return find_maximum(root->right);
	}
	return root;
}
struct node*search(struct node*root,int x) //x aranan deðer
{
	if(root==NULL || root->data==x)
	{
		return root;
	}
	else if(x>root->data)
	{
		return search(root->right,x);
	}
	else if(x<root->data)
	{
		return search(root->left,x);
	}
}
struct node*delete(struct node*root,int x)
{
	if(root==NULL)
	{
		return NULL;
	}
	else if(x>root->data)
	{
		root->right=delete(root->right,x);
	}
	else if(x<root->data)
	{
		root->left=delete(root->left,x);
	}
	else
	{
		if(root->left==NULL && root->right==NULL) //çocuksuz ise
		{
			free(root);
			return NULL;
		}
		else if(root->left==NULL || root->right==NULL) //tek çocuklu ise
		{
			struct node*temp;
			if(root->left==NULL) //rootun leftinde çocuk yoksa rootun right ýndan silicez
			{
				temp=root->right;
			}
			else  //rootun rightinde çocuk yoksa rootun leftinden silicez
			{
				temp=root->left;
			}
			free(root);
			return temp;
			}
		else
		{
			struct node*temp=find_minimum(root->right);
			root->data=temp->data;
			root->right=delete(root->right,temp->data);
		}
	}
	return root;
}
int main() {
	struct node*eleman=NULL;
	int sayi;
	int i;
	while (i<7)
	{
		printf("Sayi Giriniz: \n");
		scanf("%d",&sayi);
		eleman=elemanEkle(eleman,sayi);
		i++;
	}
	printf("\n PreOrder: ");
	preOrder(eleman);
	printf("\n InOrder: ");
	inOrder(eleman);
	printf("\n PostOrder: ");
	postOrder(eleman);
	printf("\n Eleman Adet: ");
	elemanAdet(eleman);
	
	return 0;
}
