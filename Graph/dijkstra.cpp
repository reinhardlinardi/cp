#include<bits/stdc++.h>

#define INF 123456789

using namespace std;

vector<pair<int,int> > adj[21]; //<weight,node>
priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > pq;

int dist[21]; //current minimum distance from source

int main()
{
	int a,b,c;
	int n,m;
	int s,d;
	
	printf("How many nodes do you have? ");
	scanf("%d",&m);
	printf("How many triples do you have? ");
	scanf("%d",&n);
	
	printf("Input triples, node1 <space> node2 <space> weight.\n");
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		adj[a].push_back(make_pair(c,b));
	}
	
	printf("Source : "); scanf("%d",&s);
	printf("Destination : "); scanf("%d",&d);
	
	for(int i=1;i<=m;i++) dist[i]=INF;
	dist[s]=0;
	pq.push(make_pair(0,s));
	
	int v,u,w,e;
	
	while(!pq.empty())
	{
		w = pq.top().first; //total weight
		v = pq.top().second; //current vertex to be processed
		pq.pop();
		
		if(w==dist[v]) //if weight = current minimum
		{
			for(int i=0;i<(int)adj[v].size();i++)
			{
				e = adj[v][i].first; //edge weight to u
				u = adj[v][i].second; //next vertex
				
				if(w + e < dist[u])
				{
					dist[u] = w + e;
					pq.push(make_pair(dist[u],u));
				}
			}
		}
	}
	
	if(dist[d]==INF) printf("Destination unreachable.\n");
	else printf("Shortest distance = %d\n",dist[d]);
	
	return 0;
}