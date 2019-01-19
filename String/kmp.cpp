#include<bits/stdc++.h>

using namespace std;

#define MAX 100 //maximum pattern string length
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"
#define BLUE "\x1B[34m"
#define MAGENTA "\x1B[35m"
#define CYAN  "\x1B[36m"
#define WHITE "\x1B[37m"
#define RESET "\x1B[0m"

int lps[MAX]; //longest proper prefix suffix table
string pattern; //pattern string
string test; //test string

void compute_lps() //compute longest proper prefix suffix table
{
	int i,j; //i = prefix iterator, j = suffix iterator
	int len = pattern.length();
	
	i = 0; //prefix starts from first character
	j = 1; //suffix starts from 2nd character
	lps[0] = 0; //first character have no proper prefix suffix
	
	while(j<len) //for every pattern string character
	{
		if(pattern[i]==pattern[j]) //if current prefix = current suffix
		{
			lps[j]=lps[j-1]+1; //longest prefix suffix = longest prefix suffix of previous character + 1
			i++; //advance prefix pointer
		}
		else
		{
			if(pattern[j]==pattern[0]) lps[j]=1; //same with first character
			else lps[j]=0; //no proper prefix suffix
			
			i=lps[j]; //reset prefix pointer based on lps[j], 1st character if mismatch and 2nd character if match
		}
		
		j++; //continue to next character
	}
	
	/* Testing part */
	printf("\n");
	printf("LPS table :\n");
	
	for(int i=0;i<len;i++)
	{
		if(i) printf(" "); //formatting only
		printf("%c ",pattern[i]);
	}
	
	printf("\n");
	
	for(int i=0;i<len;i++)
	{
		if(i) printf(" "); //formatting only
		if(lps[i]==0) printf(RED "%d" RESET,lps[i]);
		else printf(GREEN "%d" RESET,lps[i]);
		if(lps[i]<10) printf(" "); //formatting only
	}
}

void kmp_search()
{
	int p,t; //p = pattern string pointer, t = test string pointer
	int test_len = test.length(); //test string length
	int len = pattern.length();
	int match_counter = 0;
	
	p = t = 0; //start from beginning
	
	while(t<test_len)
	{
		/* Testing part here */
		printf("\n");
		printf("\nMatching pattern to test at p = %d and t = %d ...\n",p,t);
		
		printf("\n");
		for(int i=0;i<test_len;i++)
		{
			if(i%10==0) printf(CYAN "%d" RESET,i/10);
			else printf(" ");
		}
		printf("\n");
		for(int i=0;i<test_len;i++) printf(CYAN "%d" RESET,i%10);
		printf("\n");
		for(int i=0;i<test_len;i++)
		{
			if(i<(t-p) || i>=(t-p)+len) printf("%c",test[i]);
			else if(i==t && pattern[p]!=test[t]) printf(RED "%c" RESET,test[i]);
			else if((i==t && pattern[p]==test[t]) || i<t) printf(GREEN "%c" RESET,test[i]);
			else printf(YELLOW "%c" RESET,test[i]);
		}
		printf("\n");
		for(int i=1;i<=t-p;i++) printf(" ");
		for(int i=0;i<len;i++)
		{
			if(i==p && pattern[p]!=test[t]) printf(RED "%c" RESET,pattern[i]);
			else if((i==p && pattern[p]==test[t]) || i<=p) printf(GREEN "%c" RESET,pattern[i]);
			else printf(YELLOW "%c" RESET,pattern[i]);
		}
		printf("\n");
		for(int i=1;i<=t-p;i++) printf(" ");
		for(int i=0;i<len;i++) printf(CYAN "%d" RESET,i%10);
		printf("\n");
		for(int i=1;i<=t-p;i++) printf(" ");
		for(int i=0;i<len;i++)
		{
			if(i%10==0) printf(CYAN "%d" RESET,i/10);
			else printf(" ");
		}
		printf("\n");
		
		if(pattern[p]==test[t]) //both character matches
		{
			/* Testing part here */ printf(GREEN "\nMatch." RESET);
			
			if(p==len-1) //pattern matches
			{
				printf(GREEN "\nOccurrence found in index %d." RESET,t-len+1); //occurrence position : t+len-1
				match_counter++; //optional
				
				if(lps[p]==0) p = 0; //return to first character, prepare to search next match
				else 
				{
					p = lps[p]; //return to previous prefix, prepare to match next character
					t++; //advance next character
				}

				if(p==0) t++; //if pattern only one character, advance one character
			}
			else
			{
				//only a part of pattern prefix matches
				p++;
				t++; //advance next character
			}
		}
		else //pattern and test character do not match
		{
			/* Testing part here */ printf(RED "\nMismatch." RESET);
			
			if(p==0) t++; //advance next character if first pattern character does not match
			else p = lps[p-1]; //move to previous prefix, try again to match
		}
	}
	
	if(match_counter) printf(GREEN "\nTotal occurrences : %d\n" RESET,match_counter);
	else printf(RED "\nNo occurrences found.\n" RESET);
}

int main()
{
	//ios_base::sync_with_stdio(false); //make I/O fast
	
	printf("Input pattern string : ");
	getline(cin,pattern); //read until newline
	
	printf("Input test string : ");
	getline(cin,test); //read until newline

	if(pattern.length()>test.length()) printf(RED "No occurrences found.\n" RESET);
	else
	{
		compute_lps(); //preprocess longest proper prefix suffix table
		kmp_search(); //search when ready
	}

	return 0;
}