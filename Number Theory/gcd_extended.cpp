#include<bits/stdc++.h>

using namespace std;

int gcd_extended(int x,int y,int *cx,int *cy) //cx.x + cy.y = gcd(x,y)
{
	if(y==0)
	{
		*cx = 1;
		*cy = 0;
		return x;
	}
	else
	{
		int dx,dy; //dx.y + dy.(x%y) = gcd(y,x%y) = gcd(x,y)
		int result = gcd_extended(y,x%y,&dx,&dy);
		
		*cx = dy;
		*cy = dx - dy*(x/y);
		
		return result;
	}
}

/* Explanation :
cx.x + cy.y = dx.y + dy.(x%y)
        	= dx.y + dy (x - (x/y)*y)
        	= dx.y + dy.x - dy.y.(x/y)
        	= dy.x + (dx - dy(x/y)).y
cx.x = dy.x -> cx = dy
cy.y = (dx - dy(x/y)).y -> cy = dx - dy(x/y)

Base case (y=0) :
cx.x + cy.0 = gcd(x,0) = x
cx = 1, cy = 0
*/

int main()
{
	int a,b;
	int c1,c2; //c1*a + c2*b = gcd(a,b)
	
	printf("Enter 2 positive numbers : ");
	scanf("%d %d",&a,&b);
	
	if(a>b) //make a<=b, swap
	{
		a ^= b;
		b ^= a;
		a ^= b;
	}
	
	/* Case : a^-1 (mod b) = .. */
	
	if(gcd_extended(a,b,&c1,&c2)!=1) printf("Modular multiplicative inverse does not exists.\n");
	else
	{
		if(c1<0) c1 = b - (abs(c1)%b); //c1 may be negative, better make it positive
		printf("Modular multiplicative inverse of %d (mod %d) is = %d.\n",a,b,c1);
	}
	
	/* c1*a + c2*b = gcd(a,b) may be used to solve linear diophantine equation */
	
	return 0;
}