String Search
Send Feedback
Given two strings S and T, write a function to find if T is present as a substring inside S or not. If yes, return the starting index otherwise return -1.
Input format :

Line 1 : String S

Line 2 : String T

Sample Input 1:
WelcomeBack
come 
Sample Output 1:
3
Sample Input 2:
WelcomeBack
code
Sample Output 2:
-1
	
	
/*********************************** SOLUTION ********************************************/

	
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unordered_map<int, int> umapii;
typedef unordered_map<int, bool> umapib;
typedef unordered_map<string, int> umapsi;
typedef unordered_map<string, string> umapss;
typedef map<string, int> mapsi;
typedef map<pair<int, int>, int> mappiii;
typedef map<int, int> mapii;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef unordered_set<int> useti;

#define uset unordered_set
#define it iterator
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define f first
#define s second
#define MOD 1000000007


int findString(char S[], char T[]) {
	int length = strlen(T);
	int n = strlen(S);


	vector<int> pitable(length, 0);
	int i = 0;
	int j = i+1;

	while(j<length && i<length){
		if (T[i]==T[j])
		{
			pitable[j] = i+1;
			i++;
			j++;
		}else
		{
			if (i!=0)
			{
				i = pitable[i-1];

			}
			j++;
		}
	}

	

	int p = 0;
	int q = 0;
	while(q<length && p<n){
		if (S[p] == T[q])
		{
			p++;
			q++;
		}else
		{
			
			if (q==0)
			{
				p++;
				continue;
			}
			q = pitable[q-1];
		}
	}

	if (q==length)
	{
		return p-length;
	}


	return -1;

}
