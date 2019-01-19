#include<bits/stdc++.h>

using namespace std;

/*
Pair consists of 2 elements, first and second.
Elements in pair are bounded each other, so the pair will always remains.

Declaration :
pair<type,type> pair_name -> basic
pair<type, pair<type,type> > pair_name -> second contains pair<type,type>
pair<pair<type,type>, type> pair_name -> first contains pair<type,type>
pair< pair<type,type>, pair<type,type> > pair_name -> both first and second contains pair<type,type>
pair<type,type> pair_name[x] -> array of pair with x elements

pair_name.first -> access first element
pair_name.second -> access second element
pair_name.first.second -> access second of first (if exists)
pair_name.second.second -> access second of second (if exists)
pair_name[x].first -> access first of xth element

To add pair use pair_name = make_pair(a,b);
To add pair to array of pairs use pair_name[x] = make_pair(a,b);

When array of pair is sorted, priority always starts from first, then second.
*/

pair<int,int> x;
pair<int,int> y[5];
pair< pair<int,int>,pair<int,int> > z;

int main()
{
	int a,b,c,d;
	
	printf("Assign a pair<int,int> with : ");
	scanf("%d %d",&a,&b);
	
	x = make_pair(a,b);
	printf("x contains <%d,%d>\n",x.first,x.second);
	
	printf("\nAssign a pair< pair<int,int>, pair<int,int> > with : ");
	scanf("%d %d %d %d",&a,&b,&c,&d);
	
	z = make_pair(make_pair(a,b),make_pair(c,d));
	printf("z contains < <%d,%d> , <%d,%d> >\n",z.first.first,z.first.second,z.second.first,z.second.second);
	
	printf("\nAdd (1,2),(1,4),(2,3),(3,2),(0,8) to array of pair.\n");
	y[0] = make_pair(1,2);
	y[1] = make_pair(1,4);
	y[2] = make_pair(2,3);
	y[3] = make_pair(3,2);
	y[4] = make_pair(0,8);
	
	printf("Before sorted :");
	for(int i=0;i<5;i++)
	{
		if(i) printf(",");
		printf("(%d,%d)",y[i].first,y[i].second);
	}
	printf("\n");
	
	sort(y,y+5); //sort like usual
	
	printf("After sorted :");
	for(int i=0;i<5;i++)
	{
		if(i) printf(",");
		printf("(%d,%d)",y[i].first,y[i].second);
	}
	printf("\n");
	
	return 0;
}