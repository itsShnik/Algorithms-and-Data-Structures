#include <stdio.h>
#include <stdlib.h>

void printLcs(char x[16], int b[16][16],int m,int n);

int maxLength(char x[16], int m, char y[16], int n, int c[16][16], int b[16][16]);

int max(int x, int y);

int maxLengthIterative(char x[16], int m, char y[16], int n, int c[16][16], int b[16][16]);

int main()
{
	char x[16], y[16];
	int m,n,i,j,l;
	
	int c[16][16],b[16][16];
	
	//initializing the arrays
	for(i=0;i<=15;i++)
		for(j=0;j<=15;j++)
		{
			c[i][j] = 0;
			b[i][j] = 0;
		}
	printf("\nenter the length of the string 1: ");
	scanf("%d",&m);
	printf("enter the string 1: \n");
	scanf("%s",x);
	
	printf("\nenter the length of the string 2: ");
	scanf("%d",&n);
	printf("enter the string 2: \n");
	scanf("%s",y);
	
	/*x = (char*)malloc(sizeof(char)*(m+1));
	y = (char*)malloc(sizeof(char)*(n+1));*/
	
	l = maxLengthIterative(x,m,y,n,c,b);
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			printf("%d ",c[i][j]);
		printf("\n");
	}
	
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			printf("%d ",b[i][j]);
		printf("\n");
	}
	
	printf("\nThe length of the max sized subsequence in X and Y is %d\n",l);
		
	
	
	printf("the longest common subseqeunce is : ");
	printLcs(x,b,m,n);
	printf("\n");
}

/*int maxLength(char x[15], int i, char y[15], int j, int c[16][16], int b[16][16])
{
	if(i == 0 || j == 0)
	{
		b[i][j] = 0;
		return 0;
	}	
	
	if(c[i][j] != -2)
		return c[i][j];
	
	else if(x[i-1] == y[j-1])
	{
		b[i][j] = -5;
		c[i][j] =  1 + maxLength(x,i-1,y,j-1,c,b);
		return c[i][j];
	}
	
	else
	{
		if(maxLength(x,i,y,j-1,c,b) > maxLength(x,i-1,y,j,c,b))
		{
			b[i][j] = 10;
			c[i][j] = c[i][j-1];
			return c[i][j];
		}
		else
		{
			b[i][j] = 20;
			c[i][j] = c[i-1][j];
			return c[i][j];
		}
	}
}*/

int maxLengthIterative(char x[16], int m, char y[16], int n, int c[16][16], int b[16][16])
{
	int i,j;
	for(i=0;i<n;i++)
	{
		c[0][i] = 0;
		b[0][i] = 0; 
	}
	
	for(i=1;i<m;i++)
	{
		c[i][0] = 0;
		b[i][0] = 0; 
	}
	
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
		{
			if(x[i-1] == y[j-1])
			{	
				b[i][j] = -5;
				c[i][j] = 1 + c[i-1][j-1];
			}
			
			else if(c[i-1][j] > c[i][j-1])
			{
				b[i][j] = 20;
				c[i][j] = c[i-1][j];
			}
			
			else
			{
				b[i][j] = 10;
				c[i][j] = c[i][j-1];
			}
		}
	
	return c[m][n];
}

int max(int x, int y)
{
	return (x > y) ? x : y;
}

void printLcs(char x[16], int b[16][16],int m,int n)
{
	if(m == 0 || n == 0)
	{	
		return;
	}
	if(b[m][n] == -5)
	{
		printLcs(x,b,m-1,n-1);
		printf("%c",x[m-1]);
	}
	else if(b[m][n] == 10)
	{	
		return printLcs(x,b,m,n-1);
	}
	else 
	{
		return printLcs(x,b,m-1,n);
	}
}
