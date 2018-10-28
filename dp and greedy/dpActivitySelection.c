#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
typedef struct _job
{
	int startTime;
	int finishTime;
}job;

void mergeSort(job j[], int l, int r);

void merge(job j[], int l, int m, int r);

int acsIterative(job j[], int n);

int main()
{
	int i,n,ans;
	
	job *j;
	
	printf("enter the no. of jobs :");
	scanf("%d",&n);
	
	j = (job*)malloc(sizeof(job)*(n+2));
	
	j[0].finishTime = 0;
	j[0].startTime = 0;
	
	for(i=1;i<=n;i++)
	{
		printf("\nenter the startTime and finishTime and finishTime forjob %d\n:",i);
		scanf("%d%d",&j[i].startTime,&j[i].finishTime);
	}
	
	j[n+1].finishTime = MAX;
	j[n+1].startTime = MAX;
	
	/*for(i=0;i<n+2;i++)
	{
		printf("%d_start =%d, %d_finish = %d\n",i,j[i].startTime,i,j[i].finishTime);
	}*/
	
	//sort on basis of finish time
	mergeSort(j,0,n+1);
	
	for(i=1;i<n+1;i++)
	{
		printf("(%d,%d) ",j[i].startTime,j[i].finishTime);
	}
	printf("\n");
	
	ans = acsIterative(j,n);
	
	printf("\n The size of set of maximum compatible jobs is: %d\n",ans);
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

int acsIterative(job jb[], int n)
{
	int i,j,k,max,a,ans;

	int **c;
	
	c = (int**)malloc(sizeof(int*)*(n+2));
	for(i=0;i<n+2;i++)
	{
		c[i] = (int*)malloc(sizeof(int)*(n+2));
	}
	
	for(i=0;i<n+2;i++)
		for(j=0;j<n+2;j++)
		{
			c[i][j] = 0;
		}
	
	for(i=0;i<n+2;i++)
	{	
		for(j=0;j<n+2;j++)
		{
			printf("%d ",c[i][j]);
		}
		printf("\n");
	}
	
	
	for(i = 0; i <= n+1; i++)//changes: made i bottom to top
		for(j = i; j <= n+1; j++)
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
							a = c[i][k] + c[k][j] + 1;
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
	for(i=0;i<n+2;i++)
	{	
		for(j=0;j<n+2;j++)
		{
			printf("%d ",c[i][j]);
		}
		printf("\n");
	}
		
	ans = c[0][n+1];
	
	free(c);
	return ans;
}

















