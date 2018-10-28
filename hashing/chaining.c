#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node* next;
}NODE, *NODEPTR;
 
 int hashFun(int key,int m)
 {
 	return key%m;
 }
 
int searchFun(NODEPTR HT[100],int key,int size)
{
	 int index=hashFun(key,size);
	 NODEPTR temp=HT[index];
	 while(temp!=NULL)
	 {
	 	if(temp->data==key)
	 	{
	 		return 1;
	 	}
	 	temp=temp->next;
	 }
	 return 0;
 }
 
 void insertFun(NODEPTR HT[100],int key,int size)
 {
 	if(searchFun(HT,key,size))
 	{
 		printf("\nkey already there\n");
 		return;
 	}
 	int index=hashFun(key,size);
 	NODEPTR newNode = (NODEPTR)malloc(sizeof(NODE));
 	newNode->data=key;
 	newNode->next=HT[index];
 	HT[index]=newNode;
 }
 
 int searchFun(NODEPTR HT[100],int key,int size)
 {
 	 int index=hashFun(key,size);
 	 NODEPTR temp=HT[index];
 	 while(temp!=NULL)
 	 {
 	 	if(temp->data==key)
 	 	{
 	 		return 1;
 	 	}
 	 	temp=temp->next;
 	 }
 	 return 0;
 }
 
 void deleteFun(NODEPTR HT[100],int key,int size)
 {
 	int index=hashFun(key,size);
 	NODEPTR temp=HT[index];
 	if(HT[index]==NULL)
 	{
 		printf("\nthe key you were trying to delete isn't available\n");
 		return;
 	}
 	else if(HT[index]->data==key)
 	{
 		HT[index]=HT[index]->next;
 		printf("\nkey deleted\n");
		return;
 	}
 	else
 	{
 		while(temp!=NULL)
 		{
 			if(temp->next->data==key)
 			{
 				temp->next=temp->next->next;
 				printf("\nkey deleted\n");
 				return;
 			}	
 			temp=temp->next;
 		}
 		printf("\nthe key you wanted to delete isn't available\n");
 	}
 }
 
int main()
{
	NODEPTR hashTable[100];
	int i,ch,num,size;
	printf("enter the size of the table: ");
	scanf("%d",&size);
	for(i=0;i<size;i++)
	{
		hashTable[i]=NULL;
	}
	printf("\n******************\n");
	printf("*1.insert	 *\n");
	printf("*2.search	 *\n");
	printf("*3.delete   	*\n");
	printf("*4.exit	    	*\n");
	printf("******************\n");
	
	while(1)
	{
		printf("\nenter your choice:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nenter a number: ");
				scanf("%d",&num);
				insertFun(hashTable,num,size);
				break;
			case 2:
				printf("\nenter a key to search: ");
				scanf("%d",&num);
				if(searchFun(hashTable,num,size))
					printf("\nfound\n");
				else
					printf("\nnot found\n");
				break;
			case 3:
				printf("\nenter a key to delete: ");
				scanf("%d",&num);
				deleteFun(hashTable,num,size);
				break;
			case 4:
				exit(0);
			default: 
				printf("\nwrong choice\n");
					
		}
	}
}
