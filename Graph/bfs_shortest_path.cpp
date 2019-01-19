#include<bits/stdc++.h>

using namespace std;

#define BLUE "\x1B[34m"
#define RED "\x1B[31m"
#define YELLOW "\x1B[33m"
#define CYAN  "\x1B[36m"
#define RESET "\x1B[0m"
#define GREEN "\x1B[32m"

int r,c;
int grid[21][21];

pair<int,int> start; //<y,x>
pair<int,int> finish; //<y,x>

/* BFS */
queue< pair<int,int> > q;
bool visited[21][21];
int dist[21][21];

int dx[4]={1,0,-1,0}; //move limited to up, down, right, left
int dy[4]={0,1,0,-1};

/* Optional */
pair<int,int> prev[21][21];
bool part_of_path[21][21];

void bfs()
{
	int py,px,ny,nx;
	pair<int,int> temp;
	
	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		ny = temp.first;
		nx = temp.second;
		visited[ny][nx] = true;
		
		if(ny==finish.first && nx==finish.second) break;
		
		for(int i=0;i<4;i++)
		{
			py = ny+dy[i];
			px = nx+dx[i];
			
			if(py>=1 && py<=r && px>=1 && px<=c)
			{
				if(!visited[py][px])
				{
					q.push(make_pair(py,px));
					dist[py][px] = dist[ny][nx]+1;
					prev[py][px] = make_pair(ny,nx);
				}
			}
		}
	}
}

int main()
{
	int x,y,z;
	char dummy,cc;
	
	printf("Row : "); scanf("%d",&r);
	printf("Columns : "); scanf("%d",&c);
	printf("Draw you maze. Use '#' (wall), '.' (path), 'S' (start), 'D' (destination).\n");
	
	/* Get input */
	
	scanf("%c",&dummy);
	
	for(int i=1;i<=r;i++)
	{
		for(int j=1;j<=c;j++)
		{
			scanf("%c",&cc);
			
			grid[i][j]=cc;
			if(grid[i][j]=='S') start = make_pair(i,j);
			if(grid[i][j]=='D') finish = make_pair(i,j);
			if(grid[i][j]=='#') visited[i][j]=true;
			else visited[i][j]=false;
		}
		
		scanf("%c",&dummy);
	}
	
	memset(dist,-1,sizeof(dist));
	dist[start.first][start.second] = 0;
	q.push(start);
	
	bfs();
	
	/* Printing path */
	if(dist[finish.first][finish.second]==-1) printf(RED "\nDestination unreachable from starting point.\n" RESET);
	else
	{
		memset(part_of_path,false,sizeof(part_of_path));
		
		y = finish.first;
		x = finish.second;
		
		while(y!=start.first || x!=start.second)
		{
			z = y;
			y = prev[y][x].first;
			x = prev[z][x].second;
			
			part_of_path[y][x] = true;
		}
		
		printf(GREEN "\nShortest distance = %d\n" RESET,dist[finish.first][finish.second]);
		printf(GREEN "\nShortest path :\n" RESET);
		
		for(int i=1;i<=r;i++)
		{
			for(int j=1;j<=c;j++)
			{
				if(grid[i][j]=='#') printf(RED "%c" RESET,grid[i][j]);
				else if(grid[i][j]=='S' || grid[i][j]=='D') printf(BLUE "%c" RESET,grid[i][j]);
				else if(part_of_path[i][j]) printf(CYAN "%c" RESET,grid[i][j]);
				else printf(YELLOW "%c" RESET,grid[i][j]);
			}
			
			printf("\n");
		}
		
		printf("\n");
	}
	
	return 0;
}