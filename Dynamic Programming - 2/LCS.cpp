LCS - Problem
Send Feedback
Given 2 strings of S1 and S2 with lengths m and n respectively, find the length of longest common subsequence.
A subsequence of a string S whose length is n, is a string containing characters in same relative order as they are present in S, but not necessarily contiguous. Subsequences contain all the strings of length varying from 0 to n. E.g. subsequences of string "abc" are - "",a,b,c,ab,bc,ac,abc.
Input Format :
Line 1 : String S1
Line 2 : String s2
Output Format :
Line 1 : Length of lcs
Sample Input :
adebc
dcadb
Sample Output :
3
	
	
/******************************************************************** SOLUTION ***************************************************************************/
	
	
#include<iostream> 
#include<cstring>
using namespace std; 
int lcs(string s, string t){
    int m = s.size();
    int n = t.size();
    int **ans = new int*[m+1];
    for(int i = 0; i <= m; i++) { 
        ans[i] = new int[n+1];
    }
    // First row 
    for(int j = 0; j <= n; j++) {
        ans[0][j] = 0;
    }
    // First col 
    for(int i = 0; i <= m; i++) {
        ans[i][0] = 0;
    }
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(s[m-i] == t[n-j]) {
                ans[i][j] = 1 + ans[i-1][j-1];
            }
            else {
                ans[i][j] = max(ans[i-1][j], ans[i][j-1]); 
            }
        }
    }
    return ans[m][n];
}
