#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int value;
	struct node *left;
	struct node *right;
	struct node *parent;
}
NODE, *NODEPTR;

NODEPTR search(int val, NODEPTR root)
{
	if(root -> value == val)
		return root;
	else if(val > root -> value)
		return search(val, root -> right);
	else
		return search(val, root -> left);
			
}

NODEPTR leftRotate(NODEPTR root, NODEPTR N);

NODEPTR rightRotate(NODEPTR root, NODEPTR N);

NODEPTR makeRoot(NODEPTR root, NODEPTR N);

NODEPTR sameOrientation(NODEPTR root, NODEPTR N);

NODEPTR oppositeOrientation(NODEPTR root, NODEPTR N);

NODEPTR insert(int val, NODEPTR root);

NODEPTR lift(NODEPTR root, NODEPTR N);

void preorder(NODEPTR root);

void inorder(NODEPTR root);

int main()
{
	int i,j,n,val;
	
	printf("enter the no.of nodes\n");
	scanf("%d",&n);
	
	NODEPTR root = NULL,N;
	
	for(i = 0; i < n; i++)
	{
		scanf("%d",&val);
	
		root = insert(val, root);
		
		//printf("after inserting %d\n",val);
		//inorder(root);
		
		N = search(val,root);
		//printf("n - value = %d\n",N -> value);
		root = lift(root, N);
		
		printf("root = %d\n",root -> value);
		
		//printf("after performing lift: \n");
		//inorder(root);
		//printf("\n");
	}
	
	printf("final tree\n");
	printf("inorder: \n");
	inorder(root);
	printf("preorder\n");
	preorder(root);
	printf("\n");
	//printf("left = %d, left_parent = %d\n",root -> left -> value, root -> right -> right -> parent -> value);
	
	/*root = leftRotate(root, root -> left);
	
	printf("after left rotating\n");
	inorder(root);
	printf("\n");
	
	root = rightRotate(root, root);
	
	printf("after right rotating\n");
	inorder(root);
	printf("\n");
	
	printf("after sameorientation\n");
	root = sameOrientation(root, root -> right -> right);
	//printf("root = %d\n",root -> value);
	inorder(root);
	printf("\n");*/
}

NODEPTR leftRotate(NODEPTR root, NODEPTR N)
{
	if(N -> right == NULL)
		return root;
	
	NODEPTR rc = N -> right;
	
	if(root != N)
	{
		rc -> parent = N -> parent;
		
		if(N == N -> parent -> right)
			N -> parent -> right = rc;
		
		else
			N-> parent -> left = rc;
	}
	
	else
	{
		rc -> parent = NULL;	
		root = rc;
	}
		
	if(rc -> left != NULL)
	{
		rc -> left -> parent = N;
	}

	N -> right = rc -> left;
			
	rc -> left = N;
	N -> parent = rc;
	
	return root;
}

NODEPTR rightRotate(NODEPTR root, NODEPTR N)
{
	if(N -> left == NULL)
		return root;
	
	NODEPTR lc = N -> left;
	
	if(root != N)
	{
		lc -> parent = N -> parent;
		
		if(N == N -> parent -> left)
			N -> parent -> left = lc;
		
		else
			N-> parent -> right = lc;
	}
	
	else
	{
		root = lc;
		lc -> parent = NULL;
	}
		
	if(lc -> right != NULL)
	{
		lc -> right -> parent = N;
	}
	
	N -> left = lc -> right;
	
	lc -> right = N;
	N -> parent = lc;
	
	return root;
}

NODEPTR makeRoot(NODEPTR root, NODEPTR N)
{
	if(N == N -> parent -> left)
		return rightRotate(root, N -> parent);
	
	else
		return leftRotate(root, N -> parent);
}

NODEPTR sameOrientation(NODEPTR root, NODEPTR N)
{
	if(N == N -> parent -> left && N -> parent == N -> parent -> parent -> left)
	{
		root = rightRotate(root,N -> parent -> parent);
		root = rightRotate(root,N -> parent);
		
	}
	
	if(N == N -> parent -> right && N -> parent == N -> parent -> parent -> right)
	{
		root = leftRotate(root,N -> parent -> parent);
		//printf("root = %d\n",root -> value);
		//inorder(root);
		//printf("N -> parent = %d\n",N -> parent -> value);
		root = leftRotate(root,N -> parent);
		//printf("root = %d\n",root -> value);
		inorder(root);
		
	}
	
	return root;
}

NODEPTR oppositeOrientation(NODEPTR root, NODEPTR N)
{
	if(N == N -> parent -> left && N -> parent == N -> parent -> parent -> right)
	{
		root = rightRotate(root,N -> parent);
		root = leftRotate(root,N -> parent);
	}
	
	if(N == N -> parent -> right && N -> parent == N -> parent -> parent -> left)
	{
		root = leftRotate(root,N -> parent);
		root = rightRotate(root,N -> parent);
	}
	
	return root;
}

NODEPTR insert(int val, NODEPTR root)
{
	if(root == NULL)
	{
		root = (NODEPTR)malloc(sizeof(NODE));
	
		root -> value = val;
		root -> left = root -> right = NULL;
		root -> parent = NULL;
	}
	
	else if(val > root -> value)
	{
		if(root -> right != NULL)
			root -> right = insert(val,root -> right);
		else
		{
			root -> right = (NODEPTR)malloc(sizeof(NODE));
			
			root -> right -> value = val;
			root -> right -> parent = root;
			root -> right -> right = root -> right -> left = NULL;	
		}	
	}
		
	else
	{
		if(root -> left != NULL)
			root -> left = insert(val,root -> left);
		
		else
		{
			root -> left = (NODEPTR)malloc(sizeof(NODE));
			
			root -> left -> value = val;
			root -> left -> parent = root;
			root -> left -> right = root -> left -> left = NULL;	
		}		
	}
		
	return root;	
	
}

void inorder(NODEPTR root)
{
	if(root != NULL)
	{
		
		//printf("yed\n");
		inorder(root -> left);
		printf("%d ",root -> value);
		/*if(root -> parent != NULL)
			printf("parent = %d\n\n", root ->parent -> value);*/
		inorder(root -> right);
	}
}

void preorder(NODEPTR root)
{
	
	if(root != NULL)
	{
		printf("%d ",root -> value);
		//printf("yed\n");
		preorder(root -> left);
		
		/*if(root -> parent != NULL)
			printf("parent = %d\n\n", root ->parent -> value);*/
		preorder(root -> right);
	}
}


NODEPTR lift(NODEPTR root, NODEPTR N)
{
	//printf("N = %d\n",N -> value);
	while(root != N)
	{
		//printf("yes\n");
		if(root == N -> parent)
		{	
			//printf("makeroot:\n");
			root = makeRoot(root, N);
			//printf("done\n");
			//inorder(root);
		}
	
		else if(root != N -> parent && (N == N -> parent -> left && N -> parent == N -> parent -> parent -> left || N == N -> parent -> right && N -> parent == N -> parent -> parent -> right))
		{
			//printf("same:\n");
			root =  sameOrientation(root, N);
			if(root == N)
				break;
			//inorder(root);
			//return root;
		}
	
		else if(root != N -> parent && (N == N -> parent -> left && N -> parent == N -> parent -> parent -> right || N == N -> parent -> right && N -> parent == N -> parent -> parent -> left))
		{
			//printf("opposite:\n");
			root =  oppositeOrientation(root,N);
			if(root == N)
				break;
			//inorder(root);
			//return root;
		}
		
	}
	
	return root;
}





