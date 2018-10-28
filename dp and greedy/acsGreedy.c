#include <stdio.h>
#include <stdlib.h>

typedef struct _job
{
	int st;
	int fin;
}job;

void mergeSort(job j[], int l, int r);

void merge(job j[], int l, int m, int r);

int main()
{
	int i,j,n,length = 1,jobArr[25],count = 0;
	
	job *jb;
	
	printf("enter the no. of jobs: ");
	scanf("%d",&n);
	
	jb = (job *)malloc(sizeof(job)*n);
	
	for(i = 0; i < n; i++)
	{
		printf("\nenter the start time and finish time for job %d",i+1);
		scanf("%d%d",&jb[i].st,&jb[i].fin);
	}
	
	mergeSort(jb,0,n-1);
	
	jobArr[count] = 0;
	count++;
	
	i = 0;
	for(j = 1; j < n; j++)
	{
		if(jb[j].st >= jb[i].fin)
		{
			length++;
			jobArr[count] = j;
			count++;
			i = j;
		}
	}
	
	printf("\n\nthe size of set of maximum compatible jobs is %d",length);
	printf("\nAnd the jobs that are part of this set are :\n\n");
	
	for(i = 0; i < length; i++)
	{
		printf("job %d : (st =%d, fin = %d)\n",i+1,jb[jobArr[i]].st,jb[jobArr[i]].fin);
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
		if(L[i].fin < R[j].fin)
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
