//int his part we also get another way to do in n2 other than the one taught in the class of ag sir

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

int wisIterative(job jb[], int m);

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
	
	//dummy jobs
	j[0].startTime = j[0].finishTime = j[0].weight = 0;
	j[n+1].startTime = j[n+1].finishTime = MAX;
	j[n+1].weight = 0;
	
	for(i = 0; i <= n+1; i++)
	{
		printf("(%d,%d) ",j[i].startTime,j[i].finishTime);
	}
	printf("\n");
	
	ans = wisIterative(j,n+2);
	
	printf("\nmaximum weight is %d: ",ans);
}

int wisIterative(job jb[], int m)
{
	int i,j,k,a,ans,max;

	int **c;
	
	//memory allocation
	c = (int **)malloc(m * sizeof(int *));
	for(i = 0; i < m; i++)
	{
		c[i] = (int *)malloc(m * sizeof(int));
	}
	
		i = 0;//changes: no loop for i,  make i = 0, earlier for(i = 0; i < m; i++)
		for(j = i; j < m; j++)
		{
			if(j - i <= 1)
			{
				c[i][j] = 0;
				continue;
			}
			
			else
			{
				max = -5;
				
				for(k = i+1; k < j; k++)
				{
					
					
					if(jb[k].startTime >= jb[i].finishTime && jb[k].finishTime <= jb[j].startTime)
					{
						//printf("if\n");
						a = c[i][k] + c[k][j] + jb[k].weight;
					}
					else
					{
						//printf("else\n");
						a = c[i][k] + c[k][j];
					}
					
					//printf("a = %d\n",a);
					
					if(max < a)
						max = a;
						
					//printf("i = %d, j = %d, k = %d, c[%d][%d] = %d \n",i,j,k,i,j,max);
				}
			}
		
			c[i][j] = max;
			
		}
		
	printf("\n");
	for(i=0;i<m;i++)
	{	
		for(j=0;j<m;j++)
		{
			printf("%d ",c[i][j]);
		}
		printf("\n");
	}
	
	printf("%d",c[0][m-1]);
		
	ans = c[0][m-1];
	//printf("ans = %d\n",ans);
	free(c);
	
	return ans;
	
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
