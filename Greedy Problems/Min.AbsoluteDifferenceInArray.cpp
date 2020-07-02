Min. Absolute Difference In Array
Send Feedback
Given an integer array A of size N, find and return the minimum absolute difference between any two elements in the array.
We define the absolute difference between two elements ai, and aj (where i != j ) is |ai - aj|.
Input format :
Line 1 : Integer N, Array Size
Line 2 : Array elements (separated by space)
Output Format :
Minimum difference
Constraints :
1 <= N <= 10^6
Sample Input :
5
2 9 0 4 5
Sample Input :
1
	
	
/********************************************* SOLUTION ****************************************************************/
	
	
#include <bits/stdc++.h>
using namespace std;

int minAbsoluteDiff(int arr[], int n) {

    sort(arr,arr+n);
    int minDiff = INT_MAX;
    for(int i = 1; i < n; i++)
    {
        if(abs(arr[i]-arr[i-1]) < minDiff)
            minDiff = arr[i]-arr[i-1];
    }
    return minDiff;
}
