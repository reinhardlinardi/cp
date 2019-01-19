#include<bits/stdc++.h>

using namespace std;

int n,c;
int x[10];

bool used[10];
int result[10];

void combination(int k,int idx)
{
	if(k > c)
	{
		for(int i=1;i<k;i++)
		{
			if(i!=1) printf(" ");
			printf("%d",result[i]);
		}
		
		printf("\n");
		
		return;
	}
	
	for(int i=idx+1;i<=n;i++)
	{
		if(!used[i])
		{
			used[i]= true;
			result[k] = x[i];
			combination(k+1,i);
			used[i]= false;
		}
	}
}

int main()
{
	printf("Number of unique integers : ");
	scanf("%d",&n);
	
	printf("Integer values : ");
	for(int i=1;i<=n;i++) scanf("%d",&x[i]);
	
	printf("Generate combinations of : ");
	scanf("%d",&c);
	
	sort(x+1,x+n+1);
	memset(used,false,sizeof(used)); //memset(array_name,value,sizeof(array_name)), value only -1, 0, true, false
	
	printf("Combinations :\n");
	combination(1,0);
	
	return 0;
}