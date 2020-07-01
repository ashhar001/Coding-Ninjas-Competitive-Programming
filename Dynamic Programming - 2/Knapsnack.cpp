Knapsnack - Problem
Send Feedback
A thief robbing a store and can carry a maximal weight of W into his knapsack. There are N items and ith item weigh wi and is of value vi. What is the maximum value V, that thief can take ?
Space complexity should be O(W).
Input Format :
Line 1 : N i.e. number of items
Line 2 : N Integers i.e. weights of items separated by space
Line 3 : N Integers i.e. values of items separated by space
Line 4 : Integer W i.e. maximum weight thief can carry
Output Format :
Line 1 : Maximum value V
Constraints
1 <= N <= 10^4
1<= wi <= 100
1 <= vi <= 100
Sample Input 1 :
4
1 2 4 5
5 4 8 6
5
Sample Output :
13


/******************************************************************** SOLUTION ***************************************************************************/


#include<bits/stdc++.h>
using namespace std;

int knapsack(int *weights,int *values,int n,int maxWeight)
{
    int *dp[2];
        dp[0] = new int[maxWeight+1];
        dp[1] = new int[maxWeight+1];
    for(int i = 0; i <= maxWeight ; i++)
    {
        dp[0][i] = 0;
    }   
    dp[1][0] = 0;
    bool k = 1;
    int w;
    for(int i = 1; i <= n ; i++ , k=!k)
    {
        w = 0;
        while(w < weights[i-1])
        {
            dp[k][w] = dp[!k][w];
            w++;
        }
        while(w <= maxWeight){
            dp[k][w] = max(dp[!k][w],values[i-1] + dp[!k][w-weights[i-1]]);
            w++;
        }
    }
    return dp[!k][maxWeight];
}
