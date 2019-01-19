#include<bits/stdc++.h>

using namespace std;

/*
To generate permutation, we can use next_permutation or prev_premutation.
next_permutation goes forward (based on ASCII), while prev_permutation go backward.

Advantages :
If we find identical numbers, next_permutation or prev_permutation is smart enough.
They won't re-generate if the permutation has been generated before (because of identical numbers).
*/

int x[8];
vector<int> z;

int main()
{
	//enumerate the value
	x[1]=1;
	x[2]=4;
	x[3]=2;
	x[4]=5;
	x[5]=3;
	
	sort(x+1,x+6); //sort ascending

	for(int i=5;i>=1;i--) z.push_back(x[i]); //copy to vector in reversed order
	
	/* ALWAYS USE DO WHILE WHEN USING next_permutation AND prev_permutation */
	/* next_permutation AND prev_permutation does not change the array/vector itself */
	
	printf("Ascending order (no identical numbers) :\n");
	
	do
	{
		for(int i=1;i<=5;i++) printf("%d",x[i]);
		printf("\n");
	}
	while(next_permutation(x+1,x+6));
	
	printf("\nDescending order (no identical numbers) :\n");
	
	do
	{
		for(int i=0;i<5;i++) printf("%d",z[i]);
		printf("\n");
	}
	while(prev_permutation(z.begin(),z.end()));
	
	/* Now lets make identical numbers */
	z[4] = 2; //z[3] also 2
	x[1] = 2; //x[2] also 2
	
	/* Do it once more */
	
	printf("\nAscending order (with identical numbers) :\n");
	
	do
	{
		for(int i=1;i<=5;i++) printf("%d",x[i]);
		printf("\n");
	}
	while(next_permutation(x+1,x+6));
	
	printf("\nDescending order (with identical numbers) :\n");
	
	do
	{
		for(int i=0;i<5;i++) printf("%d",z[i]);
		printf("\n");
	}
	while(prev_permutation(z.begin(),z.end()));
	
	return 0;
}