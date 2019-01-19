#include<bits/stdc++.h>

using namespace std;

/*
Priority queue is a binary heap data structure
Heap data structure has nothing to do with heap memory

In heap data structure, if node A is parent and node B and C are A's children
For max heap : key(A) >= key(B) and key(A) >= key(C)
For min heap : key(A) <= key(B) and key(A) <= key(C)

In max heap, element with largest value will be placed at root
In min heap, element with smallest value will be placed at root

Declaration : priority_queue<type, vector<type>, less/greater<type> > pq_name;
Testing emptiness : pq_name.empty()
Get root element : pq_name.top()
Add element : pq_name.push(element)
Delete root : pq.pop()

Default priority queue : max heap
To set to min heap : use greater<type>
*/

priority_queue< int,vector<int>,greater<int> > pq_min;
priority_queue< int,vector<int>,less<int> > pq_max;

int main()
{
	int x[10]={12,66,34,9,0,23,7,64,33,98};

	for(int i=0;i<10;i++)
	{
		pq_min.push(x[i]);
		pq_max.push(x[i]);
	}
	
	printf("Printing max heap :");
	
	while(!pq_max.empty())
	{
		printf(" %d",pq_max.top());
		pq_max.pop();
	}
	
	printf("\nPrinting min heap :");
	
	while(!pq_min.empty())
	{
		printf(" %d",pq_min.top());
		pq_min.pop();
	}
	
	return 0;
}