All Indices of Number
Send Feedback
Given an array of length N and an integer x, you need to find all the indexes where x is present in the input array. Save all the indexes in an array (in increasing order).
Do this recursively. Indexing in the array starts from 0.
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Line 3 : Integer x
Output Format :
indexes where x is present in the array (separated by space)
Constraints :
1 <= N <= 10^3
Sample Input :
5
9 8 10 8 8
8
Sample Output :
1 3 4


/************************************************** SOLUTION ***********************************************/




#include<bits/stdc++.h>
using namespace std;
void findIndexes(int input[],int currIndex, int size, int x, int output[],int &k) {
    if(currIndex==size) 
        
        return;
    
    
    if(input[currIndex]==x) {
        
        output[k]=currIndex;
        k++;
    
    }
    
    findIndexes(input,currIndex+1,size,x,output,k);

}

int allIndexes(int input[], int size, int x, int output[]) { 
    
    int k=0;
    findIndexes(input,0,size,x,output,k);
    return k;

}
