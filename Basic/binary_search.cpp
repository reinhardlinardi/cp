#include<bits/stdc++.h>

using namespace std;

/*
Basic binary search :
We know we have an element, but we don't know where.
For ease, let assume our elements are unique.
We can do binary search to locate the element if the array is sorted.
*/

int n;
int val;
int elements[105];

int binary_search(int value)
{
	int l,r,mid; // l = left, r = right, mid = middle
	
	l = 1;
	r = n;
	
	while(l<=r)
	{
		mid = (l+r)/2;
		
		if(elements[mid]==value) break; //value found, index = mid
		else if(elements[mid]>value) r = mid-1; // mid too high
		else l = mid+1; //mid too low
	}
	
	return mid;
}

int main()
{
	printf("Number of elements : ");
	scanf("%d",&n);

	printf("Elements (sorted ascending order) : ");
	
	for(int i=1;i<=n;i++) scanf("%d",&elements[i]);
	
	printf("Search for element : ");
	scanf("%d",&val);
	
	printf("Element %d found in index %d\n",val,binary_search(val));

	return 0;
}