#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct node {
	int data;
	struct node* left;
	struct node* right;
};

struct node* createNode(int data) {
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void inOrder(struct node* node) {
	if(node == NULL) {
		return;
	}
	inOrder(node->left);
	printf("%d ", node->data);
	inOrder(node->right);
}

void preOrder(struct node* node) {
	if(node == NULL)
		return;
	printf("%d ", node->data);
	preOrder(node->left);
	preOrder(node->right);
}

void postOrder(struct node* node) {
	if(node == NULL) 
		return;
	postOrder(node->left);
	postOrder(node->right);
	printf("%d ", node->data);
}

int main() {
	struct node* root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	root->left->left = createNode(4);
	root->left->right = createNode(5);
	printf("Preorder: ");
	preOrder(root);
	printf("Inorder: ");
	inOrder(root);
	printf("Postorder: ");
	return 0;
	postOrder(root);
}
