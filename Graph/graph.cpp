#include<bits/stdc++.h>

using namespace std;

#define MAX_NODE 5

//adjacency list
vector<int> adj_unweighted_undirected[MAX_NODE+1];
vector<int> adj_unweighted_directed[MAX_NODE+1];
vector<pair<int,int> > adj_weighted_undirected[MAX_NODE+1]; //<weight,node>
vector<pair<int,int> > adj_weighted_directed[MAX_NODE+1];

//For edge list graph is assumed undirected
vector<pair<int,int> > edge_list_unweighted; //<node1,node2>
vector<pair<int, pair<int,int> > > edge_list_weighted; //<weight, <node1,node2> >

int main()
{
	/*
	Lets say :
	Node 1 connected to node 2 and node 4
	Node 2 connected to node 5
	Node 3 connected to node 4 and node 5
	*/
	
	/* Representing graph (unweighted & undirected) */
	
	//adj[i][..] = x means there exists an edge from node i to node x
	adj_unweighted_undirected[1].push_back(2); //Do adj[1].push_back(2) and adj[2].push_back(1)
	adj_unweighted_undirected[2].push_back(1);
	adj_unweighted_undirected[1].push_back(4); //Do adj[1].push_back(4) and adj[4].push_back(1)
	adj_unweighted_undirected[4].push_back(1);
	adj_unweighted_undirected[2].push_back(5); //Do adj[2].push_back(5) and adj[5].push_back(2)
	adj_unweighted_undirected[5].push_back(2);
	adj_unweighted_undirected[3].push_back(4); //Do adj[3].push_back(4) and adj[4].push_back(3)
	adj_unweighted_undirected[4].push_back(3);
	adj_unweighted_undirected[3].push_back(5); //Do adj[3].push_back(5) and adj[5].push_back(3)
	adj_unweighted_undirected[5].push_back(3);
	
	edge_list_unweighted.push_back(make_pair(1,2));
	edge_list_unweighted.push_back(make_pair(1,4));
	edge_list_unweighted.push_back(make_pair(2,5));
	edge_list_unweighted.push_back(make_pair(3,4));
	edge_list_unweighted.push_back(make_pair(3,5));
	
	/* Representing graph (unweighted & directed) */
	
	adj_unweighted_directed[1].push_back(2); //Only do adj[1].push_back(2), NO adj[2].push_back(1)
	adj_unweighted_directed[1].push_back(4); //Only do adj[1].push_back(4), NO adj[4].push_back(1)
	adj_unweighted_directed[2].push_back(5); //Only do adj[2].push_back(5), NO adj[5].push_back(2)
	adj_unweighted_directed[3].push_back(4); //Only do adj[3].push_back(4), NO adj[4].push_back(3)
	adj_unweighted_directed[3].push_back(5); //Only do adj[3].push_back(5), NO adj[5].push_back(3)
	
	/*
	Lets say :
	Node 1 connected to node 2 (weight 8) and node 4 (weight 5)
	Node 2 connected to node 5 (weight 9)
	Node 3 connected to node 4 (weight 4) and node 5 (weight 6)
	*/
	
	/* Representing graph (weighted & undirected) */
	
	adj_weighted_undirected[1].push_back(make_pair(8,2)); //Do adj[1].push_back(2) and adj[2].push_back(1) with weight
	adj_weighted_undirected[2].push_back(make_pair(8,1));
	adj_weighted_undirected[1].push_back(make_pair(5,4)); //Do adj[1].push_back(4) and adj[4].push_back(1) with weight
	adj_weighted_undirected[4].push_back(make_pair(5,1));
	adj_weighted_undirected[2].push_back(make_pair(9,5)); //Do adj[2].push_back(5) and adj[5].push_back(2) with weight
	adj_weighted_undirected[5].push_back(make_pair(9,2));
	adj_weighted_undirected[3].push_back(make_pair(4,4)); //Do adj[3].push_back(4) and adj[4].push_back(3) with weight
	adj_weighted_undirected[4].push_back(make_pair(4,3));
	adj_weighted_undirected[3].push_back(make_pair(6,5)); //Do adj[3].push_back(5) and adj[5].push_back(3) with weight
	adj_weighted_undirected[5].push_back(make_pair(6,3));
	
	edge_list_weighted.push_back(make_pair(8,make_pair(1,2)));
	edge_list_weighted.push_back(make_pair(5,make_pair(1,4)));
	edge_list_weighted.push_back(make_pair(9,make_pair(2,5)));
	edge_list_weighted.push_back(make_pair(4,make_pair(3,4)));
	edge_list_weighted.push_back(make_pair(6,make_pair(3,5)));
	
	/* Representing graph (weighted & directed) */
	
	adj_weighted_directed[1].push_back(make_pair(8,2)); //Only do adj[1].push_back(2) with weight, NO adj[2].push_back(1)
	adj_weighted_directed[1].push_back(make_pair(5,4)); //Only do adj[1].push_back(4) with weight, NO adj[4].push_back(1)
	adj_weighted_directed[2].push_back(make_pair(9,5)); //Only do adj[2].push_back(5) with weight, NO adj[5].push_back(2)
	adj_weighted_directed[3].push_back(make_pair(4,4)); //Only do adj[3].push_back(4) with weight, NO adj[4].push_back(3)
	adj_weighted_directed[3].push_back(make_pair(6,5)); //Only do adj[3].push_back(5) with weight, NO adj[5].push_back(3)
	
	/* Print all */
	printf("Unweighted undirected adjacency list :\n");
	
	for(int i=1;i<=MAX_NODE;i++) {
		printf("%d :",i);
		
		for(int j=0;j<(int)adj_unweighted_undirected[i].size();j++){
			printf(" %d",adj_unweighted_undirected[i][j]);
		}
		printf("\n");
	}
	
	printf("\n");
	
	printf("Unweighted edge list :\n");
	
	for(int i=0;i<(int)edge_list_unweighted.size();i++) {
		printf("%d : %d-%d\n",i,edge_list_unweighted[i].first,edge_list_unweighted[i].second);
	}
	
	printf("\n");
	
	printf("Unweighted directed adjacency list :\n");
	
	for(int i=1;i<=MAX_NODE;i++) {
		printf("%d :",i);
		
		for(int j=0;j<(int)adj_unweighted_directed[i].size();j++){
			printf(" %d",adj_unweighted_directed[i][j]);
		}
		printf("\n");
	}
	
	printf("\n");
	
	printf("Weighted undirected adjacency list :\n");
	
	for(int i=1;i<=MAX_NODE;i++) {
		printf("%d :",i);
		
		for(int j=0;j<(int)adj_weighted_undirected[i].size();j++){
			printf(" %d(%d)",adj_weighted_undirected[i][j].second,adj_weighted_undirected[i][j].first);
		}
		printf("\n");
	}
	
	printf("\n");
	
	printf("Weighted edge list :\n");
	
	for(int i=0;i<(int)edge_list_weighted.size();i++) {
		printf("%d : %d-%d(%d)\n",i,edge_list_weighted[i].second.first,edge_list_weighted[i].second.second,edge_list_weighted[i].first);
	}
	
	printf("\n");
	
	printf("Weighted directed adjacency list :\n");
	
	for(int i=1;i<=MAX_NODE;i++) {
		printf("%d :",i);
		
		for(int j=0;j<(int)adj_weighted_directed[i].size();j++){
			printf(" %d(%d)",adj_weighted_directed[i][j].second,adj_weighted_directed[i][j].first);
		}
		printf("\n");
	}
	
	/*
	Note :
	If all edge weight are the same, we can treat the graph as unweighted
	If all edge are bidirectional, we can treat the graph as undirected
	*/
	
	return 0;
}