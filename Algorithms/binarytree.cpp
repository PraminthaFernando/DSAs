#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

struct node *newNode(int data){ //creating a new node
  struct node *temp = (struct node *) malloc(sizeof(struct node));
   temp->key = data;
   temp->left = NULL;
	 temp->right = NULL;
   return temp;
}

// Inorder traversal
void traverseInOrder(struct node *root) { // traversing the tree inorder traversing
	if(root != NULL){ // check whether the current node is not NULL
		traverseInOrder(root->left); // traverse through the left child
		cout << root->key << " ";
		traverseInOrder(root->right); // traverse through the right child
	}
}

// Insert a node
struct node *insertNode(struct node *node, int key) {
  if (node == NULL) return newNode(key);
	if(key <= node->key){	// insert elements less than or eaqual the left of the current node
		node->left = insertNode(node->left, key);
	}
	else{	// insert elements less than or eaqual the right of the current node
		node->right = insertNode(node->right, key);
	}
	return node;
}

struct node* minNode(struct node* node)
{
	struct node* minValNode = node; // node to store the minimum value node in the given root
	while (minValNode != NULL && minValNode->left != NULL){
		minValNode = minValNode->left;
	}
	return minValNode;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
	// base case
	if (root == NULL)
			return root;

	if (key < root->key)
			root->left = deleteNode(root->left, key);

	else if (key > root->key)
			root->right = deleteNode(root->right, key);

	else {
		if (root->left == NULL and root->right == NULL)
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

	struct node* temp = minNode(root->right);

	root->key = temp->key;

	root->right = deleteNode(root->right, temp->key);
	}
	return root;
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}