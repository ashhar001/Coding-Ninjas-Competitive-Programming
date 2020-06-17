Extract Unique characters
Send Feedback
Given a string, you need to remove all the duplicates. That means, the output string should contain each character only once. The respective order of characters should remain same.
Input format :
String S
Output format :
Output String
Constraints :
0 <= Length of S <= 10^8
Sample Input 1 :
ababacd
Sample Output 1 :
abcd
Sample Input 2 :
abcde
Sample Output 2 :
abcde

/************************************************** SOLUTION ***********************************************/


#include<cstring>
#include<algorithm>
#include<iostream>
#include<set>
#include<unordered_map>

char* uniqueChar(char *str){
   unordered_map<char,int> unique;
    char *res=new char[50000];
    int k=0;
    for(int i=0;i<strlen(str);i++)
    {
        if(unique[str[i]]==0)
        {
            res[k]=str[i];
            k++;
            unique[str[i]]++;
        }
    }
    return res;

}
