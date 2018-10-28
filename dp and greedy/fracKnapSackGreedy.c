#include <stdio.h>
#include <stdlib.h>

typedef struct _item
{
	float wt;
	float val;
	float rat;
}item;

void mergeSort(item it[], int l, int r);

void merge(item it[], int l, int m, int r);

int main()
{
	int i,j,n;
	
	float maxVal, weightSum = 0, maxWeight, frac[25] = {0}, valSum = 0;
	
	item *it;
	
	printf("enter the maximum weight allowed in the knapasack: ");
	scanf("%f",&maxWeight);
	
	printf("\nenter the no. of items available: ");
	scanf("%d",&n);
	
	it = (item*)malloc(n * sizeof(item));
	
	for(i=0;i<n;i++)
	{
		printf("\nenter the weight and the value of the item %d\n",i+1);
		scanf("%f%f",&it[i].wt,&it[i].val);	
		it[i].rat = (it[i].wt)/(it[i].val);
	}
	
	mergeSort(it,0,n-1);
	
	printf("\nafter sorting based on ratios: \n\n ");
	for(i = 0; i < n; i++)
	{
		printf("item %d:\nvalue = %.0f\nweight = %.0f\nratio = %.0f\n\n", i+1, it[i].val, it[i].wt, it[i].rat);
	}
	
	for(i = 0; i < n; i++)
	{
		if(weightSum + it[i].wt > maxWeight)
		{
			frac[i] = (maxWeight - weightSum)/(it[i].wt);
			valSum += frac[i] *it[i].val; 
			break;
		}
		
		else
		{	
			frac[i] = 1;
			weightSum += it[i].wt;
			valSum += it[i].val;
		}
	}
	
	printf("max value: %.4f\n\n",valSum);
	
	for(i = 0; i < n; i++)
	{
		printf("\nitem %d :\n",i+1);
		printf("fraction of this item: %.4f\n",frac[i]);
		printf("contri to value: %.4f\n", frac[i] * it[i].val);
		printf("contri to weight: %.4f\n", frac[i] * it[i].wt);
	}
}

void mergeSort(item it[], int l, int r)
{
	int m;
	if(l < r)
	{
		m  = (l + r)/2;
		mergeSort(it,l,m);
		mergeSort(it,m+1,r);
		merge(it,l,m,r);
	}
}

void merge(item it[], int l, int m, int r)
{
	int i = 0,j = 0,k = l;
	int n1 = m-l+1, n2 = r-m;
	item *L,*R;
	
	L = (item*)malloc(sizeof(item)*n1);
	R = (item*)malloc(sizeof(item)*n2);
	
	while(i < n1)
	{
		L[i] = it[k];
		i++;
		k++;
	}
	
	while(j < n2)
	{
		R[j] = it[k];
		j++;
		k++;
	}
	
	i = 0;
	j = 0;
	k = l;
	
	while(i < n1 && j < n2)
	{
		if(L[i].rat < R[j].rat)
		{
			it[k] = L[i];
			i++;
			k++;
		}
		
		else
		{
			it[k] = R[j];
			j++;
			k++;
		}
	}
	
	while(i < n1)
	{
		it[k] = L[i];
		i++;
		k++;
	} 	
	
	while(j < n2)
	{
		it[k] = R[j];
		j++;
		k++;
	}	
	
	
	free(L);
	free(R);
}
















