#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

cnt1 = 0;
cnt2 = 0;

//�ڷ��� �����Ҷ� char�θ� �ٲٸ� �ڵ� ������ �ʿ� ����
typedef int element;

//����Ž��Ʈ�������� data ���� key��� �θ��� ��찡 ����
typedef struct TreeNode
{
	element key;
	struct TreeNode* left, * right;
}TreeNode;

TreeNode* makeNode(element key)
{
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->key = key;
	node->left = node->right = NULL;
	return node;
}

//NULL�� �Ǹ� ���� ����
TreeNode * insertNode(TreeNode * root, element key)
{
	if (root == NULL)
		return makeNode(key);

	//�ߺ��� Ű�� ������ �ʰ� else if�� �ؾ� ��
	if (key < root->key)
		root->left = insertNode(root->left, key);
	else if(key > root->key)
		root->right = insertNode(root->right, key);
	//return root�� �� �ʿ��Ѱ���? null�϶����� ���� ������ makeNode�� ���� ������ �ʳ�?
	return root; //�Լ��� TreeNode *���̿��� �׷���?
}

void preOrder(TreeNode * root)
{
	if (root)
	{
		printf(" %d", root->key);
		preOrder(root->left);
		preOrder(root->right);
	}
	printf("\n");
}

//��ü ����� ����
int getNodeCount(TreeNode *root)
{
	if (root)
	{
		cnt1 += 1;
		getNodeCount(root->left);
		getNodeCount(root->right);
	}
	return cnt1;
}

//�����Թ��� getNodeCount
int getNodeCount2(TreeNode*root)
{
	int count = 0;
	if (root != NULL)
		count = 1 + getNodeCount(root->left) + getNodeCount(root->right);
	return count;
}

int getLeafNodeCount(TreeNode* root)
{
	if (root)
	{
		if ((root->left == NULL) && (root->right == NULL))
			cnt2 += 1;
		getLeafNodeCount(root->left);
		getLeafNodeCount(root->right);
	}
	return cnt2;
}
//������ ���� getLeafNodeCount
int getLeafNodeCount2(TreeNode* root)
{
	int count = 0;
	if (root != NULL)
	{
		if (root->left == NULL && root->right == NULL)
			return 1;
		else count = getLeafNodeCount(root->left) + getLeafNodeCount(root->right);
	}
	return count;
}

TreeNode* minValueNode(TreeNode* root)
{
	TreeNode* p = root;
	while (p->left != NULL)
		p = p->left;
	return p;
}

TreeNode *deleteNode(TreeNode * root, element key)
{
	if (root == NULL)
		return NULL;
	if (key < root->key)
		root->left = deleteNode(root->left, key);
	else if (key > root->key)
		root->right = deleteNode(root->right, key);
	else //ã�� ���
	{
		//������ �ڽĸ� �ְų� ��,�� �Ѵ� ���°��
		if (root->left == NULL)
		{
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		//���� �ڽĸ� �ִ°��
		else if (root->right == NULL)
		{

			TreeNode* temp = root->left;
			free(root);
			return temp;
		}
		//�Ѵ� �ִ� ���
		else
		{
			TreeNode* temp = minValueNode(root->right);
			root->key = temp->key;//���� �����ش�.
			//�������ϱ� �ߺ����� �ʰ� ���� �������
			root->right = deleteNode(root->right, temp->key);
		}
	}
	return root;
}


int main()
{
	TreeNode* root = NULL;
	root = insertNode(root, 35); root = insertNode(root, 68);
	root = insertNode(root, 99); root = insertNode(root, 18);
	root = insertNode(root, 7); root = insertNode(root, 3);
	root = insertNode(root, 12); root = insertNode(root, 26);
	root = insertNode(root, 22); root = insertNode(root, 30);

	//preOrder(root);
	printf("Node Count : %d, Leaf Node Count :%d \n", getNodeCount(root), getLeafNodeCount(root));
	deleteNode(root, 30);
	deleteNode(root, 26);
	deleteNode(root, 18);

	return 0;
}