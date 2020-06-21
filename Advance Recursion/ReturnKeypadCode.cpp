Return Keypad Code
Send Feedback
Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.
Note : 1. The order of strings are not important.
2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.
Input Format :
Integer n
Output Format :
All possible strings in different lines
Constraints :
1 <= n <= 10^6
Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf


/**************************************** SOLUTION *************************************/


#include <string>
using namespace std;
string a[]={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};


int keypad(int num, string output[]){
   if(num==0)
   {
       output[0]="";
       return 1;
   }
    int b=num%10;
    num=num/10;
    int c=keypad(num,output);
    for(int i=0;i<a[b-2].size()*c;i++)
    {output[c+i]=output[i%c];
    }
    int i=0;
    for(int j=0;j<a[b-2].size();j++)
    {
        for(;i<c*(j+1);i++)
            output[i]=output[i]+a[b-2][j];
    }
    return c*a[b-2].size();
}
