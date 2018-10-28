#include <stdio.h>
#include <stdlib.h>

typedef struct _it
{
	int wt;
	int val;
}item ;

int zeroOne(int n, int maxWt, item it[], int frac[]);

int main()
{
	int i,j,n,maxWt;
	
	int frac[50];
	
	printf("enter the weight that the knapsack can carry:\n");
	scanf("%d",&maxWt);
	
	printf("\nenter the no. of available items : ");
	scanf("%d",&n);
	
	item it = (item*)malloc(n * sizeof(item));
	
	for(i=0; i < n; i++)
	{
		printf("\nenter the weight and the value of item %d\n",i+1);
		scanf("%d%d",&it[i].wt,&it[i].val);
	}
	
	zeroOne(n,maxWt,it,frac);
}

int zeroOne(int n, int maxWt, item it[], int frac[])
{
	int i, j;
	
	int knap[n+1][maxWt+1] = {0};
	
	for(i = 0; i <= n; i++)
		for(j = 0; j <= maxWt; j++)
		{
			if(i == 0 || j == 0)
				knap[i][j] = 0;
				
			else if(it[i-1].wt <= maxWt)
				knap[i][j] = max(zeroOne(n-1, j - it[i-1]))
				
		}
}













