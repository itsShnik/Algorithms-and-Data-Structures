//heapsort and heaps
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void buildHeap(int H[],int A[],int arrLength);

int insert(int H[],int length,int key);

void findMax(int H[]);

int extractMax(int H[],int length);

void displayHeap(int H[],int length);

void downSift(int H[],int length,int index);

int parent(int i);

int left(int i);

int right(int i);

void swap(int *x,int* y);

int max(int x,int y);

int downsift_count = 0;

int main()
{
	int H[100]={0},num,i,ch,length;
	int *A;
	printf("\nenter the no. of elements you want in your initial heap: ");
	scanf("%d",&num);
	A=(int*)malloc(sizeof(int)*num);
	printf("\nenter the elements into the array: \n");
	for(i=0;i<num;i++)
		scanf("%d",&A[i]);
	length=num;
	buildHeap(H,A,num);
	
	printf("downsift count = %d\n",downsift_count);
	
	printf("\n the heap is constructed, now what so you want to do?");
	printf("\n***********************\n");
	printf("*1.insert             *\n");
	printf("*2.findMax            *\n");
	printf("*3.extract max        *\n");
	printf("*4.display            *\n");
	printf("*5.exit               *\n");
	printf("***********************\n");
	while(1)
	{
		printf("\nenter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nenter the value:");
				scanf("%d",&num);
				length=insert(H,length,num);
				break;
			case 2:
				findMax(H);
				break;
			case 3:
				length=extractMax(H,length);
				break;
			case 4:
				displayHeap(H,length);
				break;
			case 5:
				exit(0);
				break;
			default:
				printf("\nwrong choice");
		}
	}
	
}

void buildHeap(int H[],int A[],int arrLength)
{
	int i;
	for(i=1;i<=arrLength;i++)
	{
		H[i]=A[i-1];
	}	
	for(i=arrLength/2;i>=1;i--)//change arrLength/2
	{
		downSift(H,arrLength,i);
	}
}

int insert(int H[],int length,int key)
{
	int index;
	length++;
	index=length;
	H[length]=key;
	while(H[parent(index)]<H[index] && index!=1)
	{
		swap(&(H[parent(index)]),&(H[index]));
		index/=2;
	}
	return length;
}

void findMax(int H[])
{
	printf("\n%d",H[1]);
}

int extractMax(int H[],int length)
{
	H[1]=H[length];
	length--;
	int index=1;
	downSift(H,length,index);
	return length;
}

void displayHeap(int H[],int length)
{
	int i;
	for(i=1;i<=length;i++)
		printf("%d ",H[i]);
	printf("\n");
}

/*void downSift(int H[],int length,int index)
{
	int c_index=0;//error in next line: what if deleting from a level up 
	while( (int)(log(index)/log(2)) < (int)(log(length)/log(2)) && ((H[left(index)]>H[index]) || (H[right(index)]>H[index])) )
	{
		int cmax=max(H[left(index)],H[right(index)]);
		if(H[left(index)]==cmax)
			c_index=left(index);
		else
			c_index=right(index);
		swap(&(H[index]),&H[c_index]);
		if(c_index == left(index))
			index=2*index;
		else
			index=2*index+1;
		printf("**************\n");
		displayHeap(H,length);
	}
}*/
void downSift(int H[],int length,int index)
{
	
	downsift_count++;	
	
	//printf("yes\n");
	int l,r,largest;
	l=left(index);
	r=right(index);
	if(l<=length && H[l]>H[index])
		largest = l;
	else
		largest = index;
	if(r<=length && H[r]>H[largest])
		largest=r;
	if(largest!=index)
	{
		swap(&H[largest],&H[index]);
		downSift(H,length,largest);
	}
}
		

int parent(int i)
{
	return i/2;
}

int left(int i)
{
	return 2*i;
}

int right(int i)
{
	return 2*i+1;
} 

void swap(int* x,int* y)
{
	int temp=*x;
	*x=*y;
	*y=temp;
}

int max(int x,int y)
{
	if(x>y)
		return x;
	else
		return y;
}



