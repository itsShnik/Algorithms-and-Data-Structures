#include <stdio.h>
#include <stdlib.h>
#define MAX 10000

typedef struct _job
{
	int startTime;
	int finishTime;
	int weight;
}job;

void mergeSort(job j[], int l, int r);

void merge(job j[], int l, int m, int r);

int wisIterative(job jb[], int n);

int prev(job j[], int n);

int main()
{
	int i,n,ans;
	
	printf("enter the no.of jobs:\n");
	scanf("%d",&n);
	
	job *j = (job*)malloc(n * sizeof(job));
	
	printf("\nenter the startTime, finishTime and the wweight of each job:\n");
	
	for(i = 1; i <= n; i++)
	{
		scanf("%d%d%d",&j[i].startTime,&j[i].finishTime,&j[i].weight);
	}
	
	//sort on basis of finishTime
	mergeSort(j,1,n);
	
	wisIterative(j,n);
}

int wisIterative(job jb[], int n)
{
	int *W = (int *)malloc((n+1)*sizeof(int));
	
	W = {0};
	w[1] = jb[1].weight;

	int max = 100000, i;
	
	//creating and storing previous
	int *p = (int *)malloc(sizeof(int)*(n));
	p = {0};
	
	
	
	for(i = 2; i <= n; i++)
	{
		W[i] = max(W[i-1],p)
	}
}

void mergeSort(job j[], int l, int r)
{
	int m;
	if(l < r)
	{
		m  = (l + r)/2;
		mergeSort(j,l,m);
		mergeSort(j,m+1,r);
		merge(j,l,m,r);
	}
}

void merge(job jb[], int l, int m, int r)
{
	int i = 0,j = 0,k = l;
	int n1 = m-l+1, n2 = r-m;
	job *L,*R;
	
	L = (job*)malloc(sizeof(job)*n1);
	R = (job*)malloc(sizeof(job)*n2);
	
	while(i < n1)
	{
		L[i] = jb[k];
		i++;
		k++;
	}
	
	while(j < n2)
	{
		R[j] = jb[k];
		j++;
		k++;
	}
	
	i = 0;
	j = 0;
	k = l;
	
	while(i < n1 && j < n2)
	{
		if(L[i].finishTime < R[j].finishTime)
		{
			jb[k] = L[i];
			i++;
			k++;
		}
		
		else
		{
			jb[k] = R[j];
			j++;
			k++;
		}
	}
	
	while(i < n1)
	{
		jb[k] = L[i];
		i++;
		k++;
	} 	
	
	while(j < n2)
	{
		jb[k] = R[j];
		j++;
		k++;
	}	
	
	
	free(L);
	free(R);
}











