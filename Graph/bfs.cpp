#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <queue>

using namespace std;
const int nmax=100;

//contoh algortima bfs
//contoh menggunakan graph of integer
void bfs(vector<int> adj[],int start,bool visited[]){
  //buat variabel local queue
  queue<int>q;

  //mulai bfs
  q.push(start);
  int currentNode;

  //loop hingga queue kosong
  while(!q.empty()){
    //ambil front dari queue
    currentNode=q.front();
    q.pop();
    visited[currentNode]=true;

    //DO SOMETHING HERE
    //DEPEND ON PROBLEM

    //traverse semua teman-teman dari node ini jika visited false
    for(int i=0;i<adj[currentNode].size();i++){
      if(visited[adj[currentNode][i]]==false){
        visited[adj[currentNode][i]]=true;
        q.push(adj[currentNode][i]);
      }
    }

  }
}

int main(){
  //declare variable untuk graph
  vector<int> adj[nmax+1];
  bool visited[nmax+1];
  int node,edge;
  int n1,n2;

  //assign false untuk semua value visited
  for(int i=1;i<=nmax;i++)
    visited[i]=false;
  
  //baca graph
  cin>>node>>edge;
  //untuk directed graph hapus sebuah push_back
  for(int i=1;i<=edge;i++){
    cin>>n1>>n2;
    adj[n1].push_back(n2);
    adj[n2].push_back(n1);
  }

  //jalankan dengan memanggil fungsi bfs
  bfs(adj,1,visited);
}
