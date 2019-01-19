#include<bits/stdc++.h>

using namespace std;

#define MAX 100 //maximum pattern string length

int lps[MAX]; //longest proper prefix suffix table
string pattern; //pattern string
string test; //test string

int match_index[100]; //array to store index where pattern matches
int match_counter = 0; //how many matches

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
	
	printf("\nLPS table :\n");
	for(int i=0;i<len;i++) printf("%c ",pattern[i]);
	printf("\n");
	for(int i=0;i<len;i++) printf("%d ",lps[i]);
}

void kmp_search()
{
	int p,t; //p = pattern string pointer, t = test string pointer
	int test_len = test.length(); //test string length
	int len = pattern.length();
	
	p = t = 0; //start from beginning
	
	while(t<test_len)
	{
		if(pattern[p]==test[t]) //both character matches
		{
			if(p==len-1) //pattern matches
			{
				match_index[++match_counter] = t-len+1;
				
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
			if(p==0) t++; //advance next character if first pattern character does not match
			else p = lps[p-1]; //move to previous prefix, try again to match
		}
	}
	
	if(match_counter)
	{
		printf("\n\nOccurrences found in index :");
		
		for(int i=1;i<=match_counter;i++)
		{
			if(i!=1) printf(",");
			printf(" %d",match_index[i]);
		}
		
		printf(".\n");
		printf("Total occurrences : %d\n",match_counter);
	}
	else printf("\nNo occurrences found.\n");
}

int main()
{
	//ios_base::sync_with_stdio(false); //make I/O fast
	
	printf("Input pattern string : ");
	getline(cin,pattern); //read until newline
	
	printf("Input test string : ");
	getline(cin,test); //read until newline
	
	if(pattern.length()>test.length()) printf("\nNo occurrences found.\n");
	else
	{
		compute_lps(); //preprocess longest proper prefix suffix table
		kmp_search(); //search when ready
	}

	return 0;
}