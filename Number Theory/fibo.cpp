#include<bits/stdc++.h>

using namespace std;

#define div 1000000007
#define LL long long

map <int,int> memo;

int square(int q)
{
	return ((LL)(q%div) * (LL)(q%div))%div;
}

int fibo(int n)
{
	int k;
	
	if(memo.count(n)) return memo[n];
	if(n==0 || n==1) return n;
	
	(n & 1)? k=(n+1)/2 : k = n/2;
	
	if(n & 1) return memo[n] = ((LL)(square(fibo(k)%div))%div + (LL)(square(fibo(k-1)%div)))%div;
	else memo[n] = ((LL)(fibo(k)%div)*(((2*(LL)(fibo(k-1)%div))%div + (LL)(fibo(k)%div))%div))%div;
}

int main()
{
	int x;
	
	printf("Enter a number : ");
	scanf("%d",&x);
	printf("Fibonnaci(%d) value (mod 10^9+7) = %d\n",x,fibo(x));

	return 0;
}