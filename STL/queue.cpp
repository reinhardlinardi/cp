#include<bits/stdc++.h>

using namespace std;

/*
Declaration : queue<type> queue_name;
Access front : queue_name.front()
Testing emptiness : queue_name.empty()
Add to queue : queue_name.push(element)
Remove front : queue_name.pop()
*/

queue<int> q;

int main()
{
	int x[10]={1,2,3,4,5,6,7,8,9,10};
	
	printf("Array :");
	for(int i=0;i<=9;i++) printf(" %d",x[i]);
	
	printf("\nArray after reversed :");
	for(int i=9;i>=0;i--) q.push(x[i]);
	
	while(!q.empty())
	{
		printf(" %d",q.front());
		q.pop();
	}

	return 0;
}