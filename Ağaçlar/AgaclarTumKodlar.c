#include <stdio.h>
#include <stdlib.h>

struct node{
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
}
struct node*elemanEkle(struct node*root,int veri)
{
	if(root==NULL)
	{
		root=kokDugumOlustur(veri);
	}
	else
	{
		if(root->data>veri)
		{
			root->left=elemanEkle(root->left,veri);
		}
		else
		{
			root->right=elemanEkle(root->right,veri);
		}
	}
}
void preOrder(struct node*root)
{
	if(root!=NULL)
	{
		printf("%d",root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}
void inOrder(struct node*root)
{
	if(root!=NULL)
	{
		inOrder(root->left);
		printf("%d",root->data);
		inOrder(root->right);
	}
}
void postOrder(struct node*root)
{
	if(root!=NULL)
	{
		postOrder(root->left);
		postOrder(root->right);
		printf("%d",root->data);
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
		return elemanAdet(root->left)+1+elemanAdet(root->right);
	}
}
void minimumBul(struct node*root)
{
	if(root==NULL)
	{
		return NULL;
	}
	else if(root->left!=NULL)
	{
		return minimumBul(root->left);
	}
	return root;
}
void maksimumBul(struct node*root)
{
	if(root==NULL)
	{
		return NULL;
	}
	else if(root->right!=NULL)
	{
		return maksimumBul(root->right);
	}
	return root;
}
struct node*search(struct node*root,int x)
{
	if(root==NULL || root->data==x)
	{
		return root;
	}
	else if(x>root->data)
	{
		return search(root->right,x);
	}
	else
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
		root->left=delete(root->right,x);
	}
	else
	{
		if(root->right==NULL && root->left==NULL)
		{
			free(root);
			return NULL;	
		}
		else if(root->left==NULL || root->right==NULL)
		{
			struct node*temp;
			if(root->left==NULL)
			{
				temp=root->right;
			}
			else
			{
				temp=root->left;
			}
			free(root);
			return temp;
		}
		else
		{
			struct node*temp=minimumBul(root->right);
			root->data=temp->data;
			root->right=delete(root->right,temp->data);
		}
	}
	return root;
	}
 

int main() {
	return 0;
}
