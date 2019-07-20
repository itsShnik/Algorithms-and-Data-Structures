#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

typedef struct _node{
	int val;
	struct _node* parent;
	struct _node* left;
	struct _node* right;
}node, *nodePointer;

nodePointer insert(nodePointer root, int val);

void inorder(nodePointer root);

void preorder(nodePointer root);

nodePointer search(nodePointer root, int val);

nodePointer deleteB(nodePointer root, int num);

nodePointer findMin(nodePointer root);

nodePointer findMax(nodePointer root);

nodePointer inoSuc(nodePointer root, int num);

int main(){
	//preprocessing
	nodePointer root = NULL;

	int n, num;
	//cout << "enter some values to create a Binary search tree:" << endl;
	cin >> n;
	int A[n];
	for(int i = 0; i < n; i++){
		cin >> A[i];
		root = insert(root, A[i]);
	}
	//printing the tree
	cout << "printing the tree :: inorder" << endl;
	inorder(root);
	cout << endl;
	cout << "printing the tree :: preorder" << endl;
	preorder(root);
	cout << endl;

	//Now providing the choice to choose any operation
	//choice menu
	printf("********************************\n");
	printf("*1. Insert a number:           *\n");
	printf("*2. Search for a number:       *\n");
	printf("*3. Inorder:                   *\n");
	printf("*4. Preorder:                  *\n");
	printf("*5. Delete a number:           *\n");
	printf("*6. Find Min:                  *\n");
	printf("*7. Find Max:                  *\n");
	printf("*8. Find Inorder Successor:    *\n");
	printf("********************************\n");

	int ch;
	nodePointer temp = NULL;
	while(cin >> ch){
		switch(ch){
			case 1: cin >> num;
					root = insert(root, num);
					cout << "operation done!!" << endl;
					break;
			case 2: cin >> num;
					temp = search(root, num);
					if(temp == NULL){
						cout << "Not Found" << endl;
					}else{
						cout << "Found!" << endl;
					}
					break;
			case 3: cout << "Inorder traversal: " << endl;
					inorder(root);
					cout << endl;
					break;
			case 4: cout << "Preorder traversal: " << endl;
					preorder(root);
					cout << endl;
					break;
			case 5: cin >> num;
					root = deleteB(root, num);
					cout << "operation done!!" << endl;
					break;
			case 6: cout << "min value in the tree:" << endl;
					temp = findMin(root);
					cout << "min = " << temp -> val << endl;
					break;
			case 7: cout << "max value in the tree:" << endl;
					temp = findMax(root);
					cout << "max = " << temp -> val << endl;
					break;
			case 8: cin >> num;
					temp = inoSuc(root, num);
					if(temp != NULL){
						cout << "Inorder successor : " << temp -> val << endl;
					}else{
						cout << "No inorder successor because it is the max element" << endl;
					}
					break;
			default: cout << "Invalid choice" << endl;
					break;
		}
	}
}

nodePointer insert(nodePointer root, int val){
	if(root == NULL){
		nodePointer temp = (nodePointer)malloc(sizeof(node));
		temp -> val = val;
		temp -> left = NULL;
		temp -> right = NULL;
		temp -> parent = NULL;
		root = temp;
		return root;
	}else{
		nodePointer temp = root;
		while(true){
			if(val == temp -> val){
				cout << "The node you are trying to insert already exists!" << endl;
				return root;
			}else if(val > temp -> val){
				if(temp -> right == NULL){
					nodePointer tempR = (nodePointer)malloc(sizeof(node));
					tempR -> val = val;
					tempR -> parent = temp;
					temp -> right = tempR;
					tempR -> right = tempR -> left = NULL;
					return root;
				}else{
					temp = temp -> right;
				}
			}else{
				if(temp -> left == NULL){
					nodePointer tempL = (nodePointer)malloc(sizeof(node));
					tempL -> val = val;
					tempL -> parent = temp;
					tempL -> right = tempL -> left = NULL;
					temp -> left = tempL;
					return root;
				}else{
					temp = temp -> left;
				}
			}
		}
	} 
}

void inorder(nodePointer root){
	if(root != NULL){
		inorder(root -> left);
		cout << root -> val << " ";
		inorder(root -> right);
	}
}

void preorder(nodePointer root){
	if(root != NULL){
		cout << root -> val << " ";
		inorder(root -> left);		
		inorder(root -> right);
	}
}

nodePointer search(nodePointer root, int val){
	nodePointer temp = root;
	while(true){
		if(temp == NULL){
			printf("Not Found!\n");
			return NULL;
		}else if(temp -> val < val){
			temp = temp -> right;
		}else if(temp -> val > val){
			temp = temp -> left;
		}else{
			printf("Found!\n");
			return temp;
		}
	}
}

nodePointer deleteB(nodePointer root, int num){
	nodePointer temp = search(root, num);
	if(temp == root){
		if(temp -> left != NULL){
			nodePointer temp_min = findMax(temp -> left);
			temp_min -> right = root -> right;
			if(temp_min == temp_min -> parent -> right){
				temp_min -> left = root -> left;
				temp_min -> parent -> right = NULL; 
			}
			temp_min -> parent = NULL;
			root = temp_min;
			return root;
		}else if(temp -> right != NULL){
			nodePointer temp_min = findMin(temp -> right);
			temp_min -> left = root -> left;
			if(temp_min == temp_min -> parent -> left){
				temp_min -> right = root -> right;
				temp_min -> parent -> left = NULL; 
			}
			temp_min -> parent = NULL;
			root = temp_min;
			return root;
		}else{
			root = NULL;
			return root;
		}
	}
	else if(temp -> left == NULL && temp -> right == NULL){
		if(temp == temp -> parent -> left){
			temp -> parent -> left = NULL;
			return root;
		}else{
			temp -> parent -> right = NULL;
			return root;
		}
	}else if(temp -> left != NULL && temp -> right == NULL){
		if(temp == temp -> parent -> left){
			temp -> parent -> left = temp -> left;
			temp -> left -> parent = temp -> parent;
			return root;
		}else{
			temp -> parent -> right = temp -> left;
			temp -> left -> parent = temp -> parent;
			return root;
		}
	}else if(temp -> left == NULL && temp -> right != NULL){
		if(temp == temp -> parent -> left){
			temp -> parent -> left = temp -> right;
			temp -> right -> parent = temp -> parent;
			return root;
		}else{
			temp -> parent -> right = temp -> right;
			temp -> right -> parent = temp -> parent;
			return root;
		}
	}else{
		nodePointer temp_ino = findMin(temp -> right);
		temp_ino -> left = temp -> left;
		if(temp_ino == temp_ino -> parent -> left){
			temp_ino -> right = root -> right;
			temp_ino -> parent -> left = NULL;
		}
		temp_ino -> parent = temp -> parent;
		if(temp == temp -> parent -> left){
			temp_ino = temp -> parent -> left;
		}else{
			temp_ino = temp -> parent -> right;
		}
		return root;
	}
}

nodePointer findMin(nodePointer root){
	nodePointer temp = root;
	while(true){
		if(temp -> left == NULL){
			return temp;
		}else{
			temp = temp -> left;
		}
	}
}

nodePointer findMax(nodePointer root){
	nodePointer temp = root;
	while(true){
		if(temp -> right == NULL){
			return temp;
		}else{
			temp = temp -> right;
		}
	}
}

nodePointer inoSuc(nodePointer root, int num){
	nodePointer temp = search(root, num);
	if(temp -> right != NULL){
		return findMin(temp -> right);
	}else{
		while(temp != root){
			if(temp == temp -> parent -> left){
				return temp -> parent;
			}else{
				temp = temp -> parent;
			}
		}
		return NULL;
	}
}