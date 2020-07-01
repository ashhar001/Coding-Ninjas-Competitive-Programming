Edit Distance - Problem
Send Feedback
Given two strings s and t of lengths m and n respectively, find the Edit Distance between the strings. Edit Distance of two strings is minimum number of steps required to make one string equal to other. In order to do so you can perform following three operations only :
1. Delete a character

2. Replace a character with another one

3. Insert a character
Note - Strings don't contain spaces
Input Format :
Line 1 : String s
Line 2 : String t
Output Format :
Line 1 : Edit Distance value
Constraints
1<= m,n <= 20
Sample Input 1 :
abc
dc
Sample Output 1 :
2



/******************************************************************** SOLUTION ***************************************************************************/


#include<iostream>
#include<cstring>
using namespace std;
#include <bits/stdc++.h>
int editDistance(string s1, string s2){
    int m = s1.size();
	int n = s2.size();

	vector<vector<int>>dp(m+1, vector<int>(n+1, 0));

	for (int i = 0; i < m+1; ++i)
	{
		dp[i][n] = m-i;
	}


	for (int i = 0; i < n+1; ++i)
	{
		dp[m][i] = n-i;
	}

	//dp[m][n] = 0;

	for (int i = m-1; i >= 0; --i)
	{
		for (int j = n-1; j >= 0; --j)
		{
			if(s1[i]==s2[j]){
				dp[i][j] = dp[i+1][j+1];
			}else{

				dp[i][j] = min(1+dp[i+1][j+1], min(1+dp[i+1][j], 1+dp[i][j+1]));
			}
		}
	}
	return dp[0][0];

}
