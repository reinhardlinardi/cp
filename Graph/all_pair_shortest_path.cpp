#include<bits/stdc++.h>

#define INF 123456789

using namespace std;

/*
All pair shortest path generate every shortest path between 2 nodes
WARNING : Complexity O(V^3) !!!

Best used when V (number of nodes) <= 100
*/

vector< pair<int,int> > adj[21];
int dist[21][21];

int main()
{
	int a,b,c;
	int m,n;
	
	printf("How many nodes do you have? "); scanf("%d",&m);
	
	for(int i=1;i<=m;i++) {
		for(int j=1;j<=m;j++) {
			dist[i][j] = INF;
		}
	}
	
	for(int i=1;i<=m;i++) dist[i][i]=0;
	
	printf("How many triples do you have? "); scanf("%d",&n);
	printf("Input triples, node1 <space> node2 <space> weight.\n");
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		adj[a].push_back(make_pair(c,b));
		dist[a][b] = c;
	}
	
	/* The algorithm */
	
	for(int k=1;k<=m;k++)
	{
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(dist[i][k] + dist[k][j] < dist[i][j]) dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
	
	/* Printing part */
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(j!=1) printf(" ");
			printf("%d\n",dist[i][j]);
		}
		
		printf("\n");
	}
	
	printf("\n");
	
	return 0;
}