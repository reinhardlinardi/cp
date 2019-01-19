#include<bits/stdc++.h>

using namespace std;

int n;
int val[105];

int sum = 0;
int ans = 0;

int main()
{
	printf("How many items do you have? ");
	scanf("%d",&n);
	
	printf("Items value : ");
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&val[i]);
	}
	
	for(int i=1;i<=n;i++)
	{
		sum += val[i];
		ans = max(ans,sum);
		
		if(sum < 0) sum = 0;
	}
	
	printf("Max 1D sum : %d\n",ans);
	
	return 0;
}