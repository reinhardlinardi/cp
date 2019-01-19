#include<bits/stdc++.h>

using namespace std;

/*
upper_bound and lower_bound is built-in binary search function in C++.
upper_bound returns address of element which is larger (>) than value.
lower_bound returns address of element which is larger or equal (>=) than value.

In order to get the original index :
0-based indexing : - <array_name>
0-based indexing : - <vector_name>.begin()
1-based indexing : - <array_name>

Syntax :
idx = lower_bound(first_element_address,last_element_adress+1,value) - <array_name>;
idx = upper_bound(first_element_address,last_element_adress+1,value) - <array_name>;

idx = lower_bound(vector_name.begin(),vector_name.end(),value) - <vector_name>.begin();
idx = upper_bound(vector_name.begin(),vector_name.end(),value) - <vector_name>.begin();
*/

int a[11]; //use 1-based indexing
vector<int> b; //vector always use 0-based indexing

int main()
{
	int idx_a,idx_b;
	int searched[10]={-2,0,1,2,4,8,11,17,20,24};
	
	for(int i=1;i<=10;i++) //put first 10 even numbers in array and vector
	{
		a[i]=2*i;
		b.push_back(2*i);
	}
	
	printf("Array elements :\n");
	printf("Index :"); for(int i=1;i<=10;i++) printf(" %d",i);
	printf("\n");
	printf("Value :"); for(int i=1;i<=10;i++) printf(" %d",a[i]);
	printf("\n");
	
	printf("Vector elements :\n");
	printf("Index :"); for(int i=0;i<10;i++) printf(" %d",i);
	printf("\n");
	printf("Value :"); for(int i=0;i<10;i++) printf(" %d",b[i]);
	printf("\n");
	
	printf("\nSearching for element -2, 0, 1, 2, 4, 8, 11, 17, 20, 24 ...\n\n");
	
	for(int i=0;i<10;i++)
	{
		idx_a = lower_bound(a+1,a+11,searched[i]) - a;
		idx_b = lower_bound(b.begin(),b.end(),searched[i]) - b.begin();
		printf("Lower bound result for %d : index %d in array, index %d in vector\n",searched[i],idx_a,idx_b);
		idx_a = upper_bound(a+1,a+11,searched[i]) - a;
		idx_b = upper_bound(b.begin(),b.end(),searched[i]) - b.begin();
		printf("Upper bound result for %d : index %d in array, index %d in vector\n",searched[i],idx_a,idx_b);
		printf("\n");
	}
	
	return 0;
}