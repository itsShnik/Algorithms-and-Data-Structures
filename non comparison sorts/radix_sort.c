#include <stdio.h>
#include <stdlib.h>

void radixSort(int input[],int n);

void countSort(int input[],int n,int exp);

int getMax(int arr[],int n);

int main()
{
	int n,i;
	int input[100];
	printf("\nenter the no. of inputs: ");
	scanf("%d",&n);
	printf("\nenter the inputs:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&input[i]);
	}
	radixSort(input,n);
	printf("\nThe sorted array is:");
	for(i=0;i<n;i++)
	{
		printf("%d ",input[i]);
	}
	printf("\n");
	return 0;
}

int getMax(int arr[],int n)
{
	int max=arr[0];
	for(int i=1;i<n;i++)
		if(arr[i]>max)
			max=arr[i];
	return max;
}

void countSort(int input[],int n,int exp)
{
	int i;
	int count[10]={0};
	int output[100];
	for(i=0;i<n;i++)
	{
		count[(input[i]/exp)%10]++;
	}
	for(i=1;i<10;i++)
	{
		count[i]+=count[i-1];
	}//can add one more loop to make it front to end
	for(i=9;i>=0;i--)
	{
		if(i==0)
			count[i]=0;
		count[i]=count[i-1];
	}
	for(i=0;i<n;i++)
	{
		output[count[(input[i]/exp)%10]]=input[i];
		count[(input[i]/exp)%10]++;
	}
	for(i=0;i<n;i++)
	{
		input[i]=output[i];
	}
}

void radixSort(int input[],int n)
{
	int i;
	int m=getMax(input,n);
	
	for(i=1;m/i>0;i*=10)
	{
		countSort(input,n,i);
	}
}










