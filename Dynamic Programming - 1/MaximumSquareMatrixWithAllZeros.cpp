Maximum Square Matrix With All Zeros
Send Feedback
Given a n*m matrix which contains only 0s and 1s, find out the size of maximum square sub-matrix with all 0s. You need to return the size of square with all 0s.
Input format :
Line 1 : n and m (space separated positive integers)
Next n lines : m elements of each row (separated by space).
Output Format:
Line 1 : Size of maximum square sub-matrix
Sample Input :
3 3
1 1 0
1 1 1
1 1 1
Sample Output :
1


/******************************************************************** SOLUTION ***************************************************************************/


#include <bits/stdc++.h>
using namespace std;
int findMaxSquareWithAllZeros(int** arr, int row, int col){
    int **dp = new int *[row];
    for(int i = 0; i < row; i++){
        dp[i] = new int[col];
    }

    for(int i = 0; i < row; i++){
        dp[i][0] = arr[i][0] == 1 ? 0 : 1;
    }

    for(int j = 1; j < col; j++){
        dp[0][j] = arr[0][j] == 1 ? 0 : 1;
    }

    for(int i = 1; i < row; i++){
        for(int j = 1; j < col; j++){
            if(arr[i][j] == 0){
                dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]))+1;
            }
            else dp[i][j] = 0;
        }
    }

    int max = 0;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(dp[i][j] > max) max = dp[i][j];
        }
    }

    return max;    
}
