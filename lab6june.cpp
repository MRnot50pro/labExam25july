#include <bits/stdc++.h>
using namespace std;
struct node {
	int key;
	struct node *left, *right;
};
struct node* newNode(int item)
{
	struct node *temp= (struct node*)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
void inorder(struct node* root)
{
	if (root == NULL) return;
		inorder(root->left);
		cout << root->key<<" ";
		inorder(root->right);

}
void search(struct node* node, int key)
{
    if(node==NULL)
    {
        cout<<"NOT FOUND"<<endl;
        return;
    }
    if(node->key==key)
    {
        cout<<"Found"<<endl;
        return;
    }
    if(key<node->key) search(node->left,key);
    else search(node->right,key);
};
struct node* insert(struct node* node, int key)
{
	if (node == NULL)
		return newNode(key);
	if (key < node->key)
		node->left = insert(node->left, key);
	else
		node->right = insert(node->right, key);
}
struct node* minValueNode(struct node* node)
{
	struct node* current = node;
	while (current && current->left != NULL) current = current->left;
	return current;
}
struct node* deleteNode(struct node* root, int key)
{
	if (root == NULL)
		return root;
	if (key < root->key)
		root->left = deleteNode(root->left, key);
	else if (key > root->key)
		root->right = deleteNode(root->right, key);
	else {
		if (root->left==NULL && root->right==NULL)
			return NULL;
		else if (root->left == NULL) {
			struct node* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			struct node* temp = root->left;
			free(root);
			return temp;
		}
		struct node* temp = minValueNode(root->right);
		root->key = temp->key;
		root->right = deleteNode(root->right, temp->key);
	}
	return root;
}
void print(node *root, int space)
{
    if (root == NULL)
        return;
    space += 5;
    print(root->right, space);
    for (int i = 5; i < space; i++) cout<<" ";
    cout<<root->key<<"\n";
    print(root->left, space);
}
int main()
{
	struct node* root = NULL;
	root = insert(root, 50);
	root = insert(root, 30);
	root = insert(root, 20);
	root = insert(root, 40);
	root = insert(root, 70);
	root = insert(root, 60);
	root = insert(root, 80);
	root = insert(root, 10);
	root = insert(root, 25);
	root = insert(root, 35);
	root = insert(root, 45);
	root = insert(root, 55);
	root = insert(root, 65);
	root = insert(root, 75);
	root = insert(root, 85);

    print(root,0);
	root = deleteNode(root, 30);

	cout<<"DOWN IS LEFT, UP IS RIGHT\n"<<endl;
	print(root,0);
	return 0;
}

