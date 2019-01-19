#include<bits/stdc++.h>

using namespace std;

int gcd(int p,int q)
{
	if(q==0) return p;
	else return gcd(q,p%q);
}

int main()
{
	int a,b;
	
	printf("Enter 2 numbers : ");
	scanf("%d %d",&a,&b);
	printf("GCD of %d and %d is %d\n",a,b,gcd(a,b));
	printf("LCM of %d and %d is %d\n",a,b,a/gcd(a,b)*b); //avoid overflow

	return 0;
}