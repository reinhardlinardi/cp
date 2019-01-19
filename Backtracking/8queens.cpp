#include<bits/stdc++.h>

using namespace std;

int row[8]={1,2,3,4,5,6,7,8};
int col[8];
int cnt;

bool used[8];

bool check_queen(int p,int q) //true = queen can attack each other
{
	bool result = false;
	
	for(int i=1;i<p;i++)
	{
		if(q==col[i-1] || (abs(row[i-1]-p) == abs(col[i-1]-q))) result = result || true;
	}
	
	return result;
}

void queens(int k)
{
	if(k > 8)
	{
		for(int i=0;i<8;i++)
		{
			for(int j=1;j<=8;j++)
			{
				if(j==col[i]) printf("Q");
				else printf(".");
			}
			
			printf("\n");
		}
		
		printf("\n");
		cnt++;
		
		return;
	}
	
	for(int i=1;i<=8;i++)
	{
		if(!check_queen(k,i) && !used[i-1])
		{
			used[i-1]=true;
			col[k-1]=i;
			queens(k+1);
			used[i-1]=false;
		}
	}
}

int main()
{
	memset(used,false,sizeof(used));
	queens(1);
	
	printf("Number of ways : %d\n",cnt);

	return 0;
}