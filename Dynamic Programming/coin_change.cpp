#include<bits/stdc++.h>

#define INF 123456789

using namespace std;

int n;
int c;
int coin[10];

int memo[1005];
vector<int> coins;
bool found = false;

int cc(int x)
{
	int minimum = INF;
	
	if(x<0) return INF;
	else if(x==0) return 0;
	else if(memo[x]!=-1) return memo[x];
	else
	{
		for(int i=1;i<=n;i++)
		{
			minimum = min(minimum,1+cc(x-coin[i]));
		}
	}
	
	return memo[x] = minimum;
}

void trace(int x)
{
	if(x<0)
	{
		coins.pop_back();
		return;
	}
	else if(x==0)
	{
		for(int i=0;i<(int)coins.size();i++)
		{
			printf(" %d",coins[i]);
		}
		
		found = true;
		
		return;
	}
	
	for(int i=1;i<=n;i++)
	{
		if(memo[x]-1==memo[x-coin[i]])
		{
			coins.push_back(coin[i]);
			trace(x-coin[i]);
		}
		
		if(found) break;
	}
}

int main()
{
	printf("How many types of coins? ");
	scanf("%d",&n);
	
	printf("Coin values : ");
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&coin[i]);
	}
	
	printf("Value to be changed : ");
	scanf("%d",&c);
	
	memset(memo,-1,sizeof(memo));
	memo[0] = 0;
	printf("Minimal number of coins : %d\n",cc(c));

	printf("Coins used :");
	trace(c);
	printf("\n");

	return 0;
}