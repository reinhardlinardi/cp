#include<bits/stdc++.h>

using namespace std;

int n;
int items[105];

int memo[105];
int ans = 0;

int LIS(int x)
{
	int result = 0;
	
	if(x==1) return 1;
	else if(memo[x]!=0) return memo[x];
	else
	{
		for(int i=1;i<x;i++)
		{
			if(items[x]>items[i]) result = max(result,1+LIS(i));
		}
	}
	
	return memo[x] = result;
}

int main()
{
	printf("How many items do you have? ");
	scanf("%d",&n);
	
	printf("Items value : ");
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&items[i]);
	}
	
	/* DP way */
	
	memset(memo,0,sizeof(memo));
	
	for(int i=1;i<=n;i++)
	{
		ans = max(ans,LIS(i));
	}
	
	printf("Longest increasing subsequence (DP) : %d\n",ans);
	
	/* Binary search way */
	ans = 0;
	int idx;
	int z[105];
	
	int cnt = 1;
	z[1]=items[1];
	
	for(int i=2;i<=n;i++)
	{
		idx = lower_bound(z+1,z+cnt+1,items[i])-z;
		z[idx] = items[i];
		if(idx > cnt) cnt++;
	}
	
	printf("Longest increasing subsequence (binary search) : %d\n",cnt);

	return 0;
}