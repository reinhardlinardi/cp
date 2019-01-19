#include<bits/stdc++.h>

using namespace std;

int n;
int x[10];

bool used[10];
int result[10];

void permutation(int k)
{
	if(k > n)
	{
		for(int i=1;i<k;i++)
		{
			if(i!=1) printf(" ");
			printf("%d",result[i]);
		}
		
		printf("\n");
		
		return;
	}
	
	for(int i=1;i<=n;i++)
	{
		if(!used[i])
		{
			used[i]= true;
			result[k] = x[i];
			permutation(k+1);
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
	
	sort(x+1,x+n+1);
	memset(used,false,sizeof(used)); //memset(array_name,value,sizeof(array_name)), value only -1, 0, true, false
	
	printf("Permutations :\n");
	permutation(1);
	
	return 0;
}