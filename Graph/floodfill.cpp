#include<bits/stdc++.h>

using namespace std;

#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"
#define BLUE "\x1B[34m"
#define MAGENTA "\x1B[35m"
#define CYAN  "\x1B[36m"
#define WHITE "\x1B[37m"
#define RESET "\x1B[0m"

int row,col;
char dummy;
char x[55][55];

int ccs;
int cc_num[55][55];
bool visited[55][55];

int dx[4] = {0,1,0,-1}; //assume we can only go NEWS
int dy[4] = {-1,0,1,0};

void dfs(int y,int z,int num)
{
	int nx,ny;
	
	visited[y][z] = true;
	cc_num[y][z] = num;
	
	for(int i=0;i<4;i++)
	{
		ny = y+dy[i];
		nx = z+dx[i];
		
		if(ny>=1 && ny<=row && nx>=1 && nx<=col)
		{
			if(!visited[ny][nx] && (x[y][z] == x[ny][nx])) dfs(ny,nx,num);
		}
	}
}

int main()
{
	printf("Enter grid size :\n");
	printf("Rows : "); scanf("%d",&row);
	printf("Columns : "); scanf("%d",&col);
	
	printf("\nEnter grid detail. Use '#' for walls and '.' for paths.\n");
	
	scanf("%c",&dummy);
	
	for(int i=1;i<=row;i++)
	{
		for(int j=1;j<=col;j++)
		{
			scanf("%c",&x[i][j]);
		}
		
		scanf("%c",&dummy);
	}
	
	memset(visited,false,sizeof(visited));
	
	for(int i=1;i<=row;i++)
	{
		for(int j=1;j<=col;j++)
		{
			if(!visited[i][j])
			{
				ccs++;
				dfs(i,j,ccs);
			}
		}
	}
	
	printf("\nNumber of connected components : %d\n",ccs);
	
	if(ccs<=6)
	{
		printf("\nVisualization :\n");
		
		for(int i=1;i<=row;i++)
		{
			for(int j=1;j<=col;j++)
			{
				switch(cc_num[i][j])
				{
					case 1 :
						printf(RED "%c" RESET,x[i][j]);
						break;
						
					case 2 :
						printf(GREEN "%c" RESET,x[i][j]);
						break;
							
					case 3 :
						printf(YELLOW "%c" RESET,x[i][j]);
						break;
								
					case 4 :
						printf(BLUE "%c" RESET,x[i][j]);
						break;
									
					case 5 :
						printf(MAGENTA "%c" RESET,x[i][j]);
						break;
										
					case 6 :
						printf(CYAN "%c" RESET,x[i][j]);
						break;
				}
			}
			
			printf("\n");
		}
		
		printf("\n");
	}
	
	return 0;
}