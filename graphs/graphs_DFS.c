#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

typedef struct _node
{
	int data;
	struct _node * next;
}node;

void traverse(int **mat, int v);

void dfs_visit(int **mat, int i, int vis[100], int v, int* time, int d[100], int f[100], int pie[100] );

void iterative_traverse(int **mat, int v);

void dfs_visit2(int **mat, int i, int vis[100], int v, int* time, int d[100], int f[100], int pie[100] );

void push(node **top, int data);

void pop(node **top);

int top_element(node *top);

void display(node *top);

int isEmpty(node *top);

int main()
{
	int v,e,s,i,j,x,y,p = 0;
	
	printf("enter the no. of vertices\n");
	scanf("%d",&v);
	
	//printf("yes\n");
	
	int **mat;
	mat = (int **)malloc((v+1) * sizeof(int*));
	for(i = 0; i <= v; i++)
	{
		mat[i] = (int *)malloc((v+1) * sizeof(int));
		
	}
	
	for(i = 0; i < v+1; i++)
		for (j = 0; j < v+1; j++)
			mat[i][j] = 0;
			
	//printing thhe matrix
	for(i = 0; i < v+1; i++)
	{
		for (j = 0; j < v+1; j++)
		{
			printf("%d ",mat[i][j]);
		}
		printf("\n");
	}
	
	printf("\nenter the no. of edges:\n");
	scanf("%d",&e);
	
	printf("enter the pair of vertices connected by an edge:\n");
	for(i = 0; i < e; i++)
	{
		scanf("%d%d",&x,&y);
		mat[x][y] = mat[y][x] = 1;
	}
	
	for(i = 0; i < v+1; i++)
	{
		for (j = 0; j < v+1; j++)
		{
			printf("%d ",mat[i][j]);
		}
		printf("\n");
	}
	
	traverse(mat,v);
	
	iterative_traverse(mat,v);
	
}

void traverse(int **mat, int v)
{
	int i,j,u,time = 0;
	
	int d[100] = {MAX};
	int vis[100] = {0};
	int pie[100] ={0};
	int f[100] = {MAX};
		
	for(i = 1; i <= v; i++)
	{
		if(vis[i] == 0)
		{	
			dfs_visit(mat,i,vis,v,&time,d,f,pie);
			//count++;
		}
	}	
	
	for(i = 1; i <= v; i++)
	{
		printf("vertex %d:\n",i);
		printf("parent node : %d\n",pie[i]);
		printf("discovery time: %d\n",d[i]);
		printf("finishing time: %d\n\n",f[i]);
	}
}

void dfs_visit(int **mat, int i, int vis[100],int v, int *time,int d[100], int f[100], int pie[100])
{
	vis[i] = 1;
	(*time)++;
	d[i] = *time;
	
	int j;
	
	for(j = 1; j <= v; j++)
	{
		if(mat[i][j] == 1 && vis[j] == 0)
		{
			vis[j] = 1;
			pie[j] = i;
			dfs_visit(mat,j,vis,v,time,d,f,pie);
		}
	}
	
	(*time)++;
	f[i] = *time;
}

void iterative_traverse(int **mat, int v)
{
	int i,j,u,time = 0;
	
	int d[100] = {MAX};
	int vis[100] = {0};
	int pie[100] ={0};
	int f[100] = {MAX};
		
	for(i = 1; i <= v; i++)
	{
		if(vis[i] == 0)
		{	
			dfs_visit2(mat,i,vis,v,&time,d,f,pie);
			//count++;
		}
	}	
	
	for(i = 1; i <= v; i++)
	{
		printf("vertex %d:\n",i);
		printf("parent node : %d\n",pie[i]);
		printf("discovery time: %d\n",d[i]);
		printf("finishing time: %d\n\n",f[i]);
	}
}


void dfs_visit2(int **mat, int i, int vis[100],int v, int *time,int d[100], int f[100], int pie[100])
{
	int ele,j,flag = 1;

	node *top = NULL;
	
	vis[i] = 1;
	(*time)++;
	d[i] = *time;
	
	push(&top,i);
	
	while(!isEmpty(top))
	{
		//printf("yes\n");
		
		flag = 1;
		
		ele = top_element(top);
		
		for(j = 1; j <= v; j++)
		{
			
			if(mat[ele][j] == 1 && vis[j] == 0)
			{
				vis[j] = 1;
				pie[j] = ele;
				
				(*time)++;
				d[j] = *time;
				
				flag = 0;
				push(&top,j);
				break;
			}
		}
		
		if(flag)
		{
			(*time)++;
			f[ele] = *time;
			pop(&top);
		}
	}
}

void push(node **top, int val)
{
	node *temp = (node *)malloc(sizeof(node));
	
	temp -> data = val;
	temp -> next = *top;
	
	*top = temp;
	
	temp = NULL;
	free(temp);
}

void pop(node **top)
{
	if(isEmpty(*top))
	{
		printf("trying to pop from an empty stack\n");
		return;
	}
	
	node *temp = *top;
	
	*top = (*top) -> next;
	
	free(temp);
}

int top_element(node *top)
{
	return top -> data;
}

void display(node *top)
{
	node *temp = top;
	
	while(temp != NULL)
	{
		printf("%d ",temp -> data);
		temp = temp -> next;
	}
	
	printf("\n");
}

int isEmpty(node *top)
{
	if(top == NULL)
		return 1;
		
	else
		return 0;
}


