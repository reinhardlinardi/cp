#include<bits/stdc++.h>

using namespace std;

/*
STL Sort : O(n log n)

Syntax :
sort(first_element_address,last_element_address+1) -> ascending without compare function
sort(first_element_address,last_element_address+1,greater<type>()) -> descending without compare function
sort(first_element_address,last_element_address+1,compare_function_name) -> sorted based on your compare function (must satisfy strict weak ordering)
sort(vector_name.begin(),vector_name.end()) -> ascending without compare function
sort(vector_name.begin(),vector_name.end(),greater<type>()) -> descending without compare function
sort(vector_name.begin(),vector_name.end(),compare_function_name) -> sorted based on your compare function (must satisfy strict weak ordering)

Reverse : just to reverse the order, first becomes last, last becomes first
reverse(first_element_address,last_element_address+1)
reverse(vector_name.begin(),vector_name.end())

For function with first_element_address and last_element_address+1 -> +1 here is required because the range is [first,last)
first is inclusive and last is exclusive, so to be correct we use last = last_element_address+1
*/

int x[101];
vector<int> z;

bool cmp(const int &a,const int &b) //return value must be boolean, to be safe use const type&
{
	if((abs(a)%2==0 && abs(b)%2==0) || (abs(a)%2==1 && abs(b)%2==1)) return a < b; //compare value if both even or both odd
	else if(abs(a)%2==0 && abs(b)%2==1) return false; //a < b always false
	else return true; //a < b always true
}

int main()
{
	int n;
	int val;
	
	printf("Number of items : ");
	scanf("%d",&n);
	
	printf("Items value : ");
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&val);
		x[i]=val;
		z.push_back(val);
	}
	
	printf("\nArray before sorted:");
	for(int i=1;i<=n;i++) printf(" %d",x[i]);
	printf("\n");
	
	sort(x+1,x+n+1);
	
	printf("Array after sorted (ascending) :");
	for(int i=1;i<=n;i++) printf(" %d",x[i]);
	printf("\n");
	
	reverse(x+1,x+n+1);
	
	printf("Array after reversed (descending) :");
	for(int i=1;i<=n;i++) printf(" %d",x[i]);
	printf("\n");
	
	printf("\nVector before sorted:");
	for(int i=0;i<n;i++) printf(" %d",z[i]);
	printf("\n");
	
	sort(z.begin(),z.end(),greater<int>());
	
	printf("Vector after sorted (descending) :");
	for(int i=0;i<n;i++) printf(" %d",z[i]);
	printf("\n");
	
	reverse(z.begin(),z.end());
	
	printf("Vector after reversed (ascending) :");
	for(int i=0;i<n;i++) printf(" %d",z[i]);
	printf("\n");
	
	/* Make compare function */
	/* All odd numbers are lesser than even numbers */
	
	sort(x+1,x+n+1,cmp);
	
	printf("\nArray sorted with compare function (ascending) :");
	for(int i=1;i<=n;i++) printf(" %d",x[i]);
	printf("\n");
	
	sort(z.begin(),z.end(),cmp);
	
	printf("Vector sorted with compare function (ascending) :");
	for(int i=0;i<n;i++) printf(" %d",z[i]);
	printf("\n");
	
	return 0;
}