#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

cnt1 = 0;
cnt2 = 0;

//자료형 변경할때 char로만 바꾸면 코드 수정이 필요 없음
typedef int element;

//이진탐색트리에서는 data 보다 key라고 부르는 경우가 많음
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

//NULL이 되면 집어 넣음
TreeNode * insertNode(TreeNode * root, element key)
{
	if (root == NULL)
		return makeNode(key);

	//중복된 키가 들어오지 않게 else if로 해야 함
	if (key < root->key)
		root->left = insertNode(root->left, key);
	else if(key > root->key)
		root->right = insertNode(root->right, key);
	//return root가 왜 필요한거지? null일때까지 들어가서 어차피 makeNode로 가서 끝나지 않나?
	return root; //함수가 TreeNode *형이여서 그런가?
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

//전체 노드의 개수
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

//교수님버전 getNodeCount
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
//교수님 버전 getLeafNodeCount
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
	else //찾은 경우
	{
		//오른쪽 자식만 있거나 왼,오 둘다 없는경우
		if (root->left == NULL)
		{
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		//왼쪽 자식만 있는경우
		else if (root->right == NULL)
		{

			TreeNode* temp = root->left;
			free(root);
			return temp;
		}
		//둘다 있는 경우
		else
		{
			TreeNode* temp = minValueNode(root->right);
			root->key = temp->key;//덮어 씌어준다.
			//덮었으니까 중복되지 않게 삭제 해줘야함
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