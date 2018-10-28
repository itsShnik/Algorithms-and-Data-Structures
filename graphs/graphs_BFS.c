#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

typedef struct _node
{
	int data;
	struct _node * next;
}node;

typedef struct _queue
{
	node *head;
	node *rear;
}queue;

void traverse(int **mat, int s, int v);

void createNewNode(node **temp);

void initialize(queue *q);

void enqueue(queue *q, int v);

node* dequeue(queue *q);

int isEmpty(queue *q);

void display(queue *q);

void initialize2(node **list, int n);

void traverse2(node** list, int s, int v);

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
	
	printf("\nenter the start vertex index:\n");
	scanf("%d",&s);
	
	printf("\ntraversing the tree\n");
	traverse(mat,s,v);
	
	
	/*queue *q;
	
	q = (queue *)malloc(sizeof(queue));
	initialize(q);
	
	for(i = 0; i < 5; i++)
	{
		enqueue(q,p);
		display(q);
		p++;
		printf("empty = %d\n",isEmpty(q));
	}
	
	
	for(i = 0; i < 5; i++)
	{
		dequeue(q);
		display(q);
		p++;
		printf("empty = %d\n",isEmpty(q));
	}*/
	
	
	
	//adjacent linked list part
	
	node **list;
	node *temp;
	
	printf("enter the no. of nodes: \n");
	scanf("%d",&v);
	
	list = (node **)malloc(sizeof(node*) * (v+1));
	
	initialize2(list,v+1);
	
	printf("enter the no. of edges: \n");
	scanf("%d",&e);
	
	printf("enter the pair of vertices connected by an edge:\n");
	for(i = 0; i < e; i++)
	{
		scanf("%d%d",&x,&y);
		
		createNewNode(&temp);
		temp -> data = y;
		temp -> next = list[x];
		list[x] = temp;
		//printf("val1 = %d\n",temp -> data);
		//printf("val2 = %d\n",list[x] -> data);
		temp = NULL;
		free(temp);

		
		createNewNode(&temp);
		temp -> data = x;
		temp -> next = list[y];
		list[y] = temp;
		temp = NULL;
		free(temp);
	}
	
	//printf("head = %d\n",list[1] -> data);
	
	//printing the adjacent list
	/*for(i = 1; i <= v; i++)
	{
		temp = list[i];
		printf("%d:: ",i);
		while(temp != NULL)
		{
			if(temp -> next != NULL)
				printf("%d -> ",temp -> data);
			else
				printf("%d\n",temp -> data);
				
			temp = temp -> next;
		}
		
	}*/
	
	printf("enter the start vertex: \n");
	scanf("%d",&s);
	
	traverse2(list,s,v);
}

void traverse(int **mat, int s, int v)
{
	int i,j,u,count = 1;
	
	node *temp;
	
	int d[100] = {MAX};
	int vis[100] = {0};
	int pie[100] ={0};

	//printf("yes\n");
	
	queue *q;
	
	//printf("yes\n");
	q = (queue *)malloc(sizeof(queue));
	initialize(q);
	
	//printf("yes\n");
	
	vis[s] = 1;
	d[s] = 0;
	pie[s] = 0;
	
	//printf("yes\n");
	//printf("%d\n",s);
	enqueue(q,s);
	

	while(!isEmpty(q))
	{
		//printf("yes\n");
		//printf("%d\n",q -> head -> data);
		//printf("%d\n",isEmpty(q));
		
		temp = dequeue(q);
		u = temp -> data;
		
		for(i = 1; i <= v; i++)
		{
			if(mat[u][i] == 1 && vis[i] == 0)
			{
				vis[i] = 1;
				d[i] = d[u] + 1;
				pie[i] = u;
				count++;
				enqueue(q,i);
				printf("vertex found : %d\n",i);
			}
			
		}
	}
	
	for(i = 1; i <= count; i++)
	{
		printf("node %d\n",i);
		printf("distance from start: %d\n",d[i]);
		printf("parent node: %d\n",pie[i]);
		
	}
}

void initialize(queue *q)
{
	//q = (queue *)malloc(sizeof(queue));
	q -> head = NULL;
	q -> rear = NULL;
}

void traverse2(node** list, int s, int v)
{
	int i,j,u,count = 1;
	
	node *temp;
	
	int d[100] = {MAX};
	int vis[100] = {0};
	int pie[100] ={0};

	//printf("yes\n");
	
	queue *q;
	
	//printf("yes\n");
	q = (queue *)malloc(sizeof(queue));
	initialize(q);
	
	//printf("yes\n");
	
	vis[s] = 1;
	d[s] = 0;
	pie[s] = 0;
	
	//printf("yes\n");
	//printf("%d\n",s);
	enqueue(q,s);
	

	while(!isEmpty(q))
	{
		//printf("yes\n");
		//printf("%d\n",q -> head -> data);
		//printf("%d\n",isEmpty(q));
		
		temp = dequeue(q);
		u = temp -> data;
		
		temp = NULL;
		temp = list[u];
		
		while(temp != NULL)
		{
			if(vis[temp -> data] == 0)
			{
				vis[temp -> data] = 1;
				d[temp -> data] = d[u] + 1;
				pie[temp -> data] = u;
				count++;
				enqueue(q,temp -> data);
				printf("vertex found : %d\n",temp -> data);
			}
			
			temp = temp -> next;
		}
	}
	
	for(i = 1; i <= count; i++)
	{
		printf("node %d\n",i);
		printf("distance from start: %d\n",d[i]);
		printf("parent node: %d\n",pie[i]);
		
	}
}

void initialize2(node **list, int n)
{
	while(n--)
	{
		list[n] = NULL;
	}
}

void createNewNode(node **temp)
{
	*temp = (node *)malloc(sizeof(node));
}

void enqueue(queue *q, int v)
{
	node *temp;
	//node *temp = (node *)malloc(sizeof(node));
	createNewNode(&temp);
	temp -> data = v;
	temp -> next = NULL;
	
	if(q->head == NULL)
	{
		
		q -> head = temp;
		q -> rear = temp;
	}
	
	else
	{
		q -> rear -> next = temp;
		q -> rear = temp;
	}	
}

node * dequeue(queue *q)
{

	//printf("dequeue\n");
	//printf("head = %d",(q -> head) -> data);
	node *ret;

	ret = q -> head;
		
	if(q -> head != NULL && q -> head ->next != NULL)
	{
		q -> head = q -> head -> next;
	}
	else
	{
		q -> head = NULL;
		q -> rear = NULL;
	}
	//printf("dequeue\n");
	return ret;	
}

int isEmpty(queue *q)
{
	if(q -> head == NULL)
		return 1;
	
	else 
		return 0;
}

void display(queue *q)
{
	node *temp;
	
	temp = q -> head;
	
	while(temp!=NULL)
	{
		printf("%d",temp->data);
		temp = temp->next;
	}
	printf("\n");
}
