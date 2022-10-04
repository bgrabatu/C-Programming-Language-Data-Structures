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

void preOrder(struct node*root)
{
	if(root!=NULL)
	{
		printf("%d ",root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}
void inOrder(struct node*root)
{
	if(root!=NULL)
	{
		inOrder(root->left);
		printf("%d ",root->data);
		inOrder(root->right);
	}
}
void postOrder(struct node*root)
{
	if(root!=NULL)
	{
		postOrder(root->left);
		postOrder(root->right);
		printf("%d ",root->data);
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
struct node*find_minimum(struct node*root)
{
	if(root==NULL)
	{
		return NULL;
	}
	else if (root->left!=NULL)
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
		return search (root->left,x);
	}
}
struct node*delete(struct node*root,int y)
{
	if(root==NULL)
	{
		return NULL;
	}
	else if(y>root->data)
	{
		root->right=delete(root->right,y);
	}
	else if(y<root->data)
	{
		root->left=delete(root->left,y);
	}
	else
	{
		if(root->left==NULL && root->right==NULL)
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
			else if(root->right==NULL)
			{
				temp=root->left;
			}
			free(root);
			return temp;
		}
		else
		{
			struct node*temp=find_minimum(root->right);
			temp->data=root->data;
			root->right=delete(root->right,temp->data);
		}
	}
}
int main() {
	struct node*root;
	struct node*eleman=NULL;
	int sayi,i=0;
	
	while(i<7)
	{
		printf("Sayi Giriniz: \n");
		scanf("%d",&sayi);
		eleman=elemanEkle(eleman,sayi);
		i++;
	}
	printf("\n preOrder: ");
	preOrder(eleman);
	printf("\n inOrder: ");
	inOrder(eleman);
	printf("\n postOrder: ");
	postOrder(eleman);
	printf("\n");
	find_minimum(root);
	
	
	return 0;
}
