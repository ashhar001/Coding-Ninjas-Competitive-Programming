Print Keypad Combinations Code
Send Feedback
Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
Note : The order of strings are not important. Just print different strings in new lines.
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


#include <iostream>
#include <string>
using namespace std;

void printKeypadHelper(int num,string output,string options[10]){
    if(num==0){
        cout<<output<<endl;
        return;
    }
    int digit = num%10;
    int i = 0;
    while(i<options[digit].length()){
        printKeypadHelper(num/10,options[digit][i]+output,options);
        i++;
    }
    return;
}
void printKeypad(int num){
    string options[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    printKeypadHelper(num,"",options);
    return;
}
