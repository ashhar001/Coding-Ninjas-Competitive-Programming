Number Of Balanced BTs
Send Feedback
Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
This number can be huge, so return output modulus 10^9 + 7.
Write a simple recursive solution.
Input Format :
Integer h
Output Format :
Count % 10^9 + 7
Input Constraints :
1 <= h <= 40
Sample Input 1:
3
Sample Output 1:
15
Sample Input 2:
4
Sample Output 2:
315
	
	
/********************************************************* SOLUTION *************************************************************************/
	

	
#include <cmath> 

int balancedBTs(int h) {
    
    if(h <= 1) {
        
        return 1;
    
    }
    
    int mod = (int) (pow(10, 9)) + 7; 
    int x = balancedBTs(h - 1);
    int y = balancedBTs(h - 2);
    int temp1 = (int)(((long)(x)*x) % mod);
    int temp2 = (int)((2* (long)(x) * y) % mod);
    int ans = (temp1 + temp2) % mod; return ans;

}


/*
#include<bits/stdc++.h>
using namespace std;
int balancedBTs(int h) {
  if(h==0 || h==1){
		return 1;
	}

	int m = 1000000000 + 7;    //1000000000 = pow(10,9)
	int x = balancedBTs(h-1);
	int y = balancedBTs(h-2);

	long res1 = (long)x*x;
	long res2 = (long)x*y*2;

	int ans1 = (int)(res1%m);
	int ans2 = (int)(res2%m);

	int ans = (ans1+ans2)%m;

	return ans;
}
*/
