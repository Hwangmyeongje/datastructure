#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int element;

typedef struct TreeNode
{
	element key;
	struct TreeNode* left,*right;
}TreeNode;

TreeNode* makeNode(element key)
{
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->key = key;
	node->left = node->right = NULL;
	return node;
}

TreeNode* findNode(TreeNode* root, element key)
{
	TreeNode* p = root;
	if (root == NULL)
		return NULL;
	if (root->key == key)
		return root;
	p = findNode(root->left,key);
	if (p)
		return p;
	return findNode(root->right, key);
}

void insertNode(TreeNode* root, element key,int left,int right)
{
	TreeNode* p = findNode(root, key);
	if (left != 0)
		p->left = makeNode(left);
	if (right != 0)
		p->right = makeNode(right);
}


void preOrder(TreeNode* root)
{
	if (root)
	{
		printf(" %d", root->key);
		preOrder(root->left);
		preOrder(root->right);
	}
}

void treeSearch(TreeNode* root, char* s)
{
	TreeNode* p = root;
	printf(" %d", p->key);

	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] == NULL)
			break;
		if (s[i] == 'L')
		{
			p = p->left;
			printf(" %d", p->key);
		}
		else if (s[i] == 'R')
		{
			p = p->right;
			printf(" %d", p->key);
		}
			
	}
	printf("\n");
}

int main()
{
	int n, key, left, right,m;
	TreeNode* root;
	scanf("%d", &n);
	scanf("%d %d %d", &key, &left, &right);
	root = makeNode(key);
	root->left = makeNode(left);
	root->right = makeNode(right);
	for (int i = 1; i < n; i++)
	{
		scanf("%d %d %d", &key, &left, &right);
		insertNode(root, key, left, right);
	}
	//preOrder(root);
	//printf("\n");
	//
	scanf("%d", &m);
	char search[101];
	for (int i = 0; i < m; i++)
	{
		getchar();
		scanf("%s", search);
		treeSearch(root, search);
	}

	return 0;
}
/*
9
5 3 9
3 8 15
8 0 2
2 0 0
15 0 0
9 7 10
7 12 0
12 0 0
10 0 0
3
RLL
LL
*/