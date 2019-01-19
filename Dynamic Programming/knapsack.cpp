#include<bits/stdc++.h>

using namespace std;

int n;
int weight[25];
int price[25];
int max_weight;

int memo[25][105];

int knapsack(int idx,int wmax)
{
	if(idx > n) return 0;
	else if(weight==0) return 0;
	else if(memo[idx][wmax]!=0) return memo[idx][wmax];
	else if(wmax-weight[idx]<0) return knapsack(idx+1,wmax);
	else return memo[idx][wmax] = max(knapsack(idx+1,wmax),price[idx]+knapsack(idx+1,wmax-weight[idx]));
}

int main()
{
	printf("How many items do you have? ");
	scanf("%d",&n);

	printf("Items value : ");
	for(int i=1;i<=n;i++) scanf("%d",&price[i]);

	printf("Items weight : ");
	for(int i=1;i<=n;i++) scanf("%d",&weight[i]);
	
	printf("Maximum weight allowed : ");
	scanf("%d",&max_weight);
	
	memset(memo,0,sizeof(memo));
	printf("Maximum value : %d\n",knapsack(1,max_weight));
	
	return 0;
}