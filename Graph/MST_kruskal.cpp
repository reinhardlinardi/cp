#include<bits/stdc++.h>

using namespace std;

int e,n;
int cnt,mst;
vector<pair<int,pair<int,int> > > edge_list;

/*
Union-Find Disjoint Sets
Simple data structure to check cycle for Kruskal algorithm
Each node has a representative node, in this code called parent
When all nodes are disjoint, initialize node's representative to itself
When we connect two nodes, pick one node's representative to be the representative of all nodes
To check cycle, check both nodes representatives
If both representatives are the same, they are going to make a cycle, otherwise not.

Kruskal algorithm :
Sort edge based on weight ascendingly
Add next edge to current minimum spanning tree if no cycle will be formed.

To check cycle effeciently, we use Union-Find Disjoint Sets (UFDS) data structure.
*/

int parent[105]; //node representative

void create_disjoint_sets()
{
	for(int i=1;i<=n;i++) parent[i]=i;
}

void union_set(int p,int q)
{
	parent[q] = parent[p];
}

int find_parent(int p)
{
	if(parent[p]==p) return p;
	else return parent[p]=find_parent(parent[p]);
}

bool is_same_set(int p,int q)
{
	return find_parent(p)==find_parent(q);
}

int main()
{
	/*
	For MST problem to be valid
	If there are N nodes, the graph has M edges
	Where N-1 <= M <= N(N-1)/2
	
	N-1 egdes -> tree
	N(N-1)/2 -> complete graph
	*/
	
	int a,b,c;
	
	printf("Input number of nodes : "); scanf("%d",&n);
	printf("Input number of edges : "); scanf("%d",&e);
	printf("Input edges info, weight <space> node1 <space> node2 :\n");
	
	for(int i=1;i<=e;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		edge_list.push_back(make_pair(a,make_pair(b,c)));
	}
	
	sort(edge_list.begin(),edge_list.end());
	create_disjoint_sets();
	cnt = 0; //number of selected edges
	mst = 0; //minimum cost
	
	for(int i=0;i<e;i++)
	{
		if(cnt==n-1) break;
		
		if(!is_same_set(edge_list[i].second.first,edge_list[i].second.second))
		{
			cnt++;
			mst+=edge_list[i].first;
			union_set(edge_list[i].second.first,edge_list[i].second.second);
		}
	}
	
	printf("Minimum spanning tree : %d\n",mst);

	return 0;
}