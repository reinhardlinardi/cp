#include<bits/stdc++.h>

using namespace std;

int n,q;
int l,r;
int x[100005];
int sum[100005];

/*
Simple problem, but you may get TLE :

Problem :
Given N (1<=N<=10^5) integers, and Q (1<=Q<=10^5) queries.
For each query, what is the sum of i-th integer..j-th integer (inclusive)?

Naive solution : compute from i to j for each query, worst O(n^2) -> TLE
Can we remember sum[i][j]? No, too many states, 10^5 + 10^5-1 + .. + 2 + 1 = (10^5+1)(5*10^4) states
How to solve this problem? Using prefix sum.
*/

int main()
{
	printf("Number of integers : ");
	scanf("%d",&n);
	
	printf("Integers : ");
	
	sum[0] = 0; //important
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x[i]);
		sum[i]=sum[i-1]+x[i]; //sum[i] = sum from index 0 until i, even there is no integer in index 0
	}
	
	printf("Number of queries : ");
	scanf("%d",&q);
	
	printf("Queries :\n");
	
	for(int i=1;i<=q;i++)
	{
		scanf("%d %d",&l,&r);
		printf("%d\n",sum[r]-sum[l-1]); //sum from index l until r (inclusive)
	}
	
	return 0;
}