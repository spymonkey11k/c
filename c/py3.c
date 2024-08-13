// a. Design and implement C/C++ Program to solve All-Pairs Shortest Paths problem 

# include <stdio.h> 
void main()
{
	int n, i, j, k;
	int Floyd[10][10], Cost[10][10];

	printf("\n*tPROGRAM TO IMPLEMENT FLOYD'S ALGORITHMt*\n");
	
	printf("\nEnter the number of vertices\n");
	scanf("%d",&n);
	printf("\nEnter the Cost adjacency Matrix\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&Cost[i][j]);
	printf("\nInput Graph\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",Cost[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			Floyd[i][j] = Cost[i][j];
		}
	}

	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(Floyd[i][j] > (Floyd[i][k] + Floyd[k][j]))
					Floyd[i][j] = (Floyd[i][k] + Floyd[k][j]);
			}
		}
	}
	printf("\nAll Pair Shortest Path Matrix\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",Floyd[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
}


// b. Design and implement C/C++ Program to find the transitive closure using Warshall's
// algorithm.
# include <stdio.h> 


void main()
{
	int n, i, j, k;
	int path[10][10], adj[10][10];

	printf("\n*tPROGRAM TO IMPLEMENT WARSHALL 'S ALGORITHMt*\n");
	
	printf("\nEnter the number of vertices\n");
	scanf("%d",&n);
	printf("\nEnter the  adjacency Matrix\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&adj[i][j]);
	printf("\nInput Graph\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",adj[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			path[i][j] = adj[i][j];
		}
	}

	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				
               if (path[i][j] || (path[i][k] && path[k][j]))
					path[i][j] = 1;
			}
		}
	}
	printf("\n Path Matrix /Transitive closure\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",path[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
}
