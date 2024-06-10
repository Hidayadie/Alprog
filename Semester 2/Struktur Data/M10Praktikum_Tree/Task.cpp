#include <iostream>
using namespace std;
struct node {
	char data;
	node *left, *right;
};

node *root = NULL;

void addNode(node **root, char isi) {
	if ((*root) == NULL) {
		node *baru;
		baru		= new node;
		baru->data	= isi;
		baru->left	= NULL;
		baru->right	= NULL;
		(*root)		= baru;
	}
}
void preorder (node *root) {
		if (root!=NULL) {
		cout<<root->data<<" ";
		preorder (root ->left);
		preorder (root ->right);
		}
}
void inorder (node *root) {
		if (root!=NULL) {
		inorder (root->left);
		cout<<root->data<<" ";
		inorder (root->right);
		}
}
void postorder (node *root) {
		if (root!=NULL) {
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<" ";
		}
}
int main () {
	char isi;
	cout << "\n\tPosisi Awal Binary Tree\n"
		 << "----------------------------------\n"
		 << "                  A\n"
		 << "                 / \\\n"
		 << "                M    I\n"
		 << "               /    / \\\n"
		 << "              K    J   Z\n"
		 << "             / \\\n"
		 << "            O   M\n"
		 << "           / \\\n"
		 << "          Y   K\n\n";

	addNode(&root, isi = 'A');

	addNode(&root->left, isi = 'M');
	addNode(&root->right, isi = 'I');

	addNode(&root->left->left, isi = 'K');
	addNode(&root->right->right, isi = 'Z');
	addNode(&root->right->left, isi = 'J');

	addNode(&root->left->left->left, 'O');
	addNode(&root->left->left->right, 'M');

	addNode(&root->left->left->left->left, 'Y');
	addNode(&root->left->left->left->right, 'K');

	cout << "Preorder\t: "; 	preorder(root);
	cout << "\n"
		 << "Inorder\t\t: "; 	inorder(root);
	cout << "\n"
		 << "PostOrder\t: ";	postorder(root);
}
