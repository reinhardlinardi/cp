#include<bits/stdc++.h>

using namespace std;

/*
Vector is dynamic array, no need for size declaration
Vector always starts from index 0

Syntax :
vector<type> vector_name; -> vector of type
vector<type> vector_name[x]; -> array of vector of type with size x

Operations commonly used :
vector_name.push_back(x) -> add x to vector
vector_name.back() -> access last element of vector (last in)
vector_name.clear() -> delete all elements in vector
vector_name.size() -> get vector size, type = size_t, cast to int before using
vector_name[x] -> access xth element of vector
*/

vector<int> x;

void vector_status()
{
	printf("\n");
	printf("Vector size = %d\n",(int)x.size());
	printf("Vector elements :");
	
	for(int i=0;i<(int)x.size();i++)
	{
		printf(" %d",x[i]);
	}
	
	printf("\n");
	printf("\n");
}

int main()
{
	printf("Add 1,2,3,4,5 to vector.\n");
	x.push_back(1);
	x.push_back(2);
	x.push_back(3);
	x.push_back(4);
	x.push_back(5);
	vector_status();
	
	printf("Get last element of vector.\n");
	printf("Vector last element = %d\n",x.back());
	
	printf("\nClear vector.\n");
	x.clear();
	vector_status();
	
	return 0;
}