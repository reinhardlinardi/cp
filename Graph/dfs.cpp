#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>

using namespace std;
const int nmax=100;

//fungsi dfs
//misal graph of integer
void dfs(int node,vector<int> adj[],bool visited[nmax+1]){
  //check visited array first
  if(visited[node]==false){
    visited[node]=true;

    //do something here
    //depend on problem

    //traverse this node neighbour
    for(int i=0;i<adj[node].size();i++)
      dfs(adj[node][i],adj,visited);
  }
}

int main(){
  //declare variable
  vector<int> adj[nmax+1];
  int node,edge;
  int x,y;
  bool visited[nmax+1];
  cin>>node>>edge;

  //read graph and assign them
  //for directed graph just delete one of the push_back
  for(int i=1;i<=edge;i++){
    cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  //set the visited array as all false
  for(int i=1;i<=nmax;i++)
    visited[i]=false;

  //try 1 as the starting node
  dfs(1,adj,visited);
  
  return 0;
}
