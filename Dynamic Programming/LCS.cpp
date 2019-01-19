#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

//fungsi dari dp
int lcs(string a,string b,int n,int m,int dp[101][101]){
  //kalau sudah ada di memo
  if(dp[n][m]!=-1)
    return dp[n][m];

  //kalau belum ada di memo
  else{
    //basis
    if(n==0||m==0)
      dp[n][m]=0;
    //kasus-kasus uji
    else if(a[n]==b[m])
      dp[n][m]=1+lcs(a,b,n-1,m-1,dp);
    else
      dp[n][m]=max(lcs(a,b,n-1,m,dp),lcs(a,b,n,m-1,dp));
    return dp[n][m];
  }
}

int main(){
  //CONTOH INPUT
  string a="abcdefg";
  string b="azeg";

  //PEMBUATN ARRAY MEMO
  int dp[101][101];
  for(int i=1;i<=100;i++){
    for(int j=1;j<=100;j++)
      dp[i][j]=-1;
  }

  cout<<lcs(a,b,a.length(),b.length(),dp)<<endl;
}
