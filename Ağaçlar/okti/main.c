#include <stdio.h>
#include <stdlib.h>
struct node {
	
	int data;
	struct node * left;
	struct node * right;
	
};


struct node * kokdugumolustur(int veri){
	
	struct node * root;
	root=(struct node* )malloc(sizeof(struct node));
	root->data=veri;
	root->left=NULL;
	root->right=NULL;
	 
	 return root;
	 
	
}

struct node * elemanekle(struct node * root , int veri)
{
	if ( root ==NULL)
	{
		root=kokdugumolustur(veri);
	}
	else
	{
		if(veri<root->data)
         {
           root->left=elemanekle(root,veri); 	
	    }		
		else
		{
			root->right =elemanekle(root,veri);
		}
		
return root;		
		
	}
	
	
	
	
}


void preorder (struct node * root ) // baþta kök olduðu için printf komutu gelir
{
	if (root !=NULL)
	{
		printf ("%d", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

 void inorder (struct node * root ) // ortada kök olduðu için 
{
	
	if (root !=NULL)
	{
		inorder (root->left);
		printf ("%d", root->data);
		inorder (root->right);
		
	}
	
	
}

void postorder (struct node * root) // kök sonda olduðu için 

{
   if (root !=NULL)	
    {
    	postorder(root->left);
    	postorder(root->right);
    	printf("%d",root->data);
	}
}





int main() {
	
	struct node * eleman=NULL;
	int sayi , i =0;
	while (i<7)
	{
		printf ("sayi giriniz : \n");
		scanf("%d",&sayi);
		eleman=elemanekle(eleman , sayi);
		i++;
	}
	printf(" \n preorder :");
	preorder(eleman );
	
	printf(" \n inorder :");
	inorder(eleman );

	printf(" \n postorder :");
	postorder(eleman );
	
	
	
	
	
	
	return 0;
}
