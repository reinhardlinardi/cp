#include<bits/stdc++.h>

using namespace std;

/* Compute a^b in log(n) */
/* Called exponentiation by squaring */

int square(int k)
{
	return k*k;
}

int exponent(int p,int q)
{
	if(q==0) return 1;
	if(q==1) return p;
	
	if(q%2) return p*exponent(p,q-1);
	else return square(exponent(p,q/2));
}

int main()
{
	int a,b;
	
	printf("Compute the number : ");
	scanf("%d",&a);
	
	printf("To the power of : ");
	scanf("%d",&b);
	
	printf("Result = %d\n",exponent(a,b));
	
	return 0;
}