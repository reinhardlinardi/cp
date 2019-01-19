#include<bits/stdc++.h>

using namespace std;

/*
C++ STL Map is actually a Red Black Tree.
It is one of Balanced Binary Search Tree variants.

Declaration :
map <key_type,value_type> map_name;

Add node to map / update node :
map[key] = value

if key does not exists, add to map
if key exists, update value
implication : key is unique

Time complexity : O(log n)
Space complexity : O(n)

Checking element : map_name.count
0 -> not in map
1 -> in map
*/

map <string,int> nilai;

int main()
{
	int n;
	int x;
	string s;
	string names[50];
	
	printf("Jumlah mahasiswa : ");
	scanf("%d",&n);
	
	printf("Masukkan nama dan nilai :\n");
	
	for(int i=1;i<=n;i++)
	{
		cin >> s;
		cin >> x;
		nilai[s] = x;
		names[i]=s;
	}
	
	sort(names+1,names+n+1);
	
	for(int i=1;i<=n;i++)
	{
		printf("\n%s %d",names[i].c_str(),nilai[names[i]]);
	}
	
	printf("\n");
	printf("\nNilai devin : ");
	
	if(nilai.count("devin")) printf("%d\n",nilai["devin"]);
	else printf("-\n");
	
	return 0;
}