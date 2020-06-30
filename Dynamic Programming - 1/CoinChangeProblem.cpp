Coin Change Problem
Send Feedback
You are given an infinite supply of coins of each of denominations D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total number of ways W, in which you can make change for Value V using coins of denominations D.
Note : Return 0, if change isn't possible.
Input Format
Line 1 : Integer n i.e. total number of denominations
Line 2 : N integers i.e. n denomination values
Line 3 : Value V
Output Format
Line 1 :  Number of ways i.e. W
Constraints :
1<=n<=10
1<=V<=1000
Sample Input 1 :
3
1 2 3
4
Sample Output
4
Sample Output Explanation :
Number of ways are - 4 total i.e. (1,1,1,1), (1,1, 2), (1, 3) and (2, 2).



/******************************************************************** SOLUTION ***************************************************************************/



int countWaysToMakeChange(int S[], int m, int n){
    
     int i, j, x, y;
    
    // We need n+1 rows as the table is constructed 
    // in bottom up manner using the base case 0 
    // value case (n = 0)
    
    int table[n+1][m]; 
    // Fill the enteries for 0 value case (n = 0)
    
    for (i=0; i<m; i++) 
        
        table[0][i] = 1;
    
    // Fill rest of the table entries in bottom
    
    // up manner 
    for (i = 1; i < n+1; i++) {
        
        for (j = 0; j < m; j++) { 
            
            // Count of solutions including S[j]
            
            x = (i-S[j] >= 0)? table[i - S[j]][j]: 0;
            
            // Count of solutions excluding S[j]
            
            y = (j >= 1)? table[i][j-1]: 0;
            
            // total count
            table[i][j] = x + y;
        }
    } 
    
    return table[n][m-1];

}



/*
#include <bits/stdc++.h>
using namespace std;

int coin_change_naive(int n, int *d,int numD,int **output)
{
    if(n == 0)
    {
        return 1;
    }
    if(numD == 0)
    {
        return 0;
    }
    if(n < 0)
    {
        return 0;
    }
    if(output[n][numD] > -1)
    {
        return output[n][numD];
    }
    int first = coin_change_naive(n - d[0],d,numD,output);
    int second = coin_change_naive(n,d + 1,numD - 1,output);
    output[n][numD] = first + second;
    return output[n][numD];
}
int countWaysToMakeChange(int denominations[], int numDenominations, int value){

  int **output = new int*[value+1];
    for(int i = 0; i < value+1 ; i++)
    {
        output[i] = new int[numDenominations+1];
        for(int j = 0; j < numDenominations+1; j++)
            output[i][j] = -1;
    }
  	return coin_change_naive(value,denominations,numDenominations,output);


}
*/
