#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct TreeNode {
    int id;
    int data;
    struct TreeNode* left, * right;
}TreeNode;

TreeNode* makeNode(int id, int size, TreeNode* left, TreeNode* right) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->id = id;
    node->data = size;
    node->left = left;
    node->right = right;

    return node;
}
void folderSize(TreeNode* root) {//날라가는 node번호
    printf("%d", root->data);//root node출력
    if (root->left != NULL)
        printf("%d", root->left->data);//left node출력
    if (root->right != NULL)
        printf("%d", root->right->data);//right node출력
}
void preOrder(TreeNode* root) {//data->left->right
    if (root) {
        printf(" %d", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void inOrder(TreeNode* root) {//left->data->right
    if (root) {
        inOrder(root->left);
        printf(" %d", root->data);
        inOrder(root->right);
    }
}
void postOrder(TreeNode* root) {//left->right->data
    if (root) {
        postOrder(root->left);
        postOrder(root->right);
        printf(" %d", root->data);
    }
}
TreeNode* findNodeByID(TreeNode* root, int id) {
    TreeNode* p = (TreeNode*)malloc(sizeof(TreeNode));
    if (root) {
        if (root->id == id)
            return root;//원하던 id를 찾은 경우
        p = findNodeByID(root->left, id);//아니라면 왼쪽에서부터 다시 찾기
        if (p != NULL)
            return p;//원하던 id를 찾은 경우

        p = findNodeByID(root->right, id);//아니라면 왼쪽에서부터 다시 찾기
        if (p != NULL)
            return p;//원하던 id를 찾은 경우
    }
    return NULL;
}
void print(TreeNode* root, int order) {
    if (order == 1)
        preOrder(root);
    if (order == 2)
        inOrder(root);
    if (order == 3)
        postOrder(root);

}
int main() {


    TreeNode* F4 = makeNode(4, 70, NULL, NULL);//밑에서부터 만들어가야한다(자식node->부모node)
    TreeNode* F5 = makeNode(5, 90, NULL, NULL);
    TreeNode* F7 = makeNode(7, 130, NULL, NULL);
    TreeNode* F8 = makeNode(8, 80, NULL, NULL);
    TreeNode* F2 = makeNode(2, 30, F4, F5);
    TreeNode* F6 = makeNode(6, 120, F7, F8);
    TreeNode* F3 = makeNode(3, 50, NULL, F6);
    TreeNode* F1 = makeNode(1, 20, F2, F3);


    int id, order;
    scanf("%d %d", &order, &id);//전위,중위,후위->root node의 id

    TreeNode* p = findNodeByID(F1, id);//rootnode와 id를 전달
    if (p == NULL)
        printf("-1");//찾지 못한경우
    else
        print(p, order);//찾은경우
    return 0;
}