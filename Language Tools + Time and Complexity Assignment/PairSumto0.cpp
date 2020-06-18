Pair sum to 0
Send Feedback
Given a random integer array A of size N. Find and print the pair of elements in the array which sum to 0.
Array A can contain duplicate elements.
While printing a pair, print the smaller element first.
That is, if a valid pair is (6, -6) print "-6 6". There is no constraint that out of 5 pairs which have to be printed in 1st line. You can print pairs in any order, just be careful about the order of elements in a pair.
Input format :
Line 1 : Integer N (Array size)
Line 2 : Array elements (separated by space)
Output format :
Line 1 : Pair 1 elements (separated by space)
Line 2 : Pair 2 elements (separated by space)
Line 3 : and so on
Constraints :
0 <= N <= 10^4
Sample Input:
5
2 1 -2 2 3
Sample Output :
-2 2
-2 2


/*************************************** SOLUTION *********************************************/


#include <bits/stdc++.h>
using namespace std;
void PairSum(int *input, int n) {	 
    unordered_map<int, int> m1;
	for (int i = 0; i < n; ++i)
	{
		if(m1[0-input[i]]==0){
			m1[input[i]]++;
            
		}else{
            m1[input[i]]++;
		}
	}
    
    unordered_map<int, int>::iterator it=m1.begin();
    while(it!=m1.end()){
        int total = 0;
        int left = it->second;
        int right = m1[-it->first];
        total = left*right;
        while(total>0){
            cout << min(it->first, -it->first)<<" "<< max(it->first, -it->first) << '\n';
            total--;
        }
        m1[it->first]=0;
        m1[-it->first]=0;
        it++;
        
    }
}

