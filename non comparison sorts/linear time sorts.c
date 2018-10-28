//linear time sorts-counting sort
#include <stdio.h>
#include <stdlib.h>

void countSort(int input[],int n,int k);

int main()
{
	int n,k,i;
	int input[100];
	printf("\nenter the no. of inputs: ");
	scanf("%d",&n);
	printf("\nThe range of the integers in this input array is (0-k). Enter k: ");
	scanf("%d",&k);
	printf("\nenter the inputs:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&input[i]);
	}
	countSort(input,n,k);
	printf("\nThe sorted array is:");
	for(i=0;i<n;i++)
	{
		printf("%d ",input[i]);
	}
	printf("\n");
	return 0;
}

void countSort(int input[],int n,int k)
{
	int i;
	int count[100];
	int output[100];
	for(i=0;i<=k;i++)
	{
		count[i]=0;
	}
	for(i=0;i<n;i++)
	{
		count[input[i]]++;
	}
	for(i=1;i<=k;i++)
	{
		count[i]+=count[i-1];
	}//can add one more loop to make it front to end
	for(i=0;i<n;i++)
	{
		output[count[input[i]]-1]=input[i];
		count[input[i]]--;
	}
	for(i=0;i<n;i++)
	{
		input[i]=output[i];
	}
}
