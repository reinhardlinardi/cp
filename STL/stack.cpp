#include<bits/stdc++.h>

using namespace std;

/*
Declaration : stack<type> stack_name;
Access top element : stack_name.top()
Remove top : stack_name.pop()
Add to stack : stack_name.push(element)
Testing emptiness : stack_name.empty()
*/

stack<int> s;

int main()
{
	int x[10];
	
	for(int i=0;i<10;i++) x[i]=i;
	
	printf("Array :");
	for(int i=0;i<10;i++) printf(" %d",x[i]);
	
	printf("\nArray in reverse order :");
	
	for(int i=0;i<10;i++) s.push(x[i]);
	
	while(!s.empty())
	{
		printf(" %d",s.top());
		s.pop();
	}

	return 0;
}