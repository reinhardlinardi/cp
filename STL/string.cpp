#include<bits/stdc++.h>

using namespace std;

/*
String vs array of char :
String                    Array of char
Dynamic (no limit)        Static
Using cin only            Cin and scanf
Compare using ==          Must use strcmp
Compare using < > <= >=   Must compare per character
Copy using assign (=)     Must use strcpy or copy per character
Concatenation using +     Cannot do that

Declaration :
string string_name; -> string with name string_name, no length limitation
string string_name[x]; -> array of string with name string_name and array size x
*/

char a[80];
char b[80];
string x,y;

int main()
{
	scanf("%s",a); //read char array a
	scanf("%s",b); //read char array b
	
	printf("\nChar array a : %s\n",a); //print char array a
	printf("Char array b : %s\n",b); //print char array b
	
	x = a; //assign string x with char array a content
	y = ""; //assign y with empty string
	
	cout << "\nString x : " << x << endl; //print string x
	printf("String y : %s\n",y.c_str()); //print string y using printf
	
	y += 'a'; //add with character
	cout << "String y + 'a' : " << y << endl;

	y += "xyz"; //add with string
	cout << "String y + \"xyz\" : " << y << endl << endl;
	
	if(strcmp(a,b)==0) printf("Char array a and b are equal\n");
	else printf("Char array a and b are not equal\n");
	
	x = "abc";
	y = "abc";
	
	if(x==y) printf("String x and y are equal\n"); //x == y
	else printf("String x and y are not equal\n"); //x != y
	
	x = "ajkgd";
	y = "baxcac";
	
	if(x<y) printf("String x is lexicographically less than y\n"); //x < y
	else printf("String x is lexicographically more than or equal to y\n"); //x >= y
	
	x = "cjkgd";
	y = "cjkgb";
	
	if(x<=y) printf("String x is lexicographically less than or equal to y\n"); // x <= y
	else printf("String x is lexicographically more than y\n"); // x > y
	
	sort(a,a+strlen(a)); //sort char array a;
	sort(x.begin(),x.end()); //sort characters in string
	
	reverse(b,b+strlen(b)); //reverse char array b;
	reverse(y.begin(),y.end()); //reverse characters in string
	
	cout << "Array char a = " << a << endl;
	cout << "Array char b = " << b << endl;
	cout << "String x = " << x << endl;
	cout << "String y = " << y << endl;
	
	strcpy(a,x.c_str()); //strcpy(destination,source), string.c_str() -> convert string to array of char
	printf("\nArray char a now = %s\n",a);
	
	return 0;
}