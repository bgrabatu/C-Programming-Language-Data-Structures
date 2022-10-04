#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node*left;
	struct node*right;
};

struct node*kokDugumOlustur(int veri)
{
	struct node* root=(struct node*)malloc(sizeof(struct node));
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
			root->left=elemanEkle(root->left,veri); //recursive iþlem
		}
		else
		{
			root->right=elemanEkle(root->right,veri); //recursive iþlem
		}
	}
	return root;
}

int main() {
	return 0;
}
