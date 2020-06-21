Remove Duplicates Recursively
Send Feedback
Given a string S, remove consecutive duplicates from it recursively.
Input Format :
String S
Output Format :
Output string
Constraints :
1 <= |S| <= 10^3
where |S| represents the length of string
Sample Input 1 :
aabccba
Sample Output 1 :
abcba
Sample Input 2 :
xxxyyyzwwzzz
Sample Output 2 :
xyzwz


/**************************************** SOLUTION *************************************/


void remove(char *input, int newIndex,int index) {
    if(input[index]=='\0') {
        input[newIndex]=input[index-1];
        input[newIndex+1]='\0'; 
        return;
    }
    if(input[index]==input[index-1]) {
        remove(input,newIndex,index+1); 
        return;
    }
    else input[newIndex]=input[index-1];
    remove(input,newIndex+1,index+1);
}
void removeConsecutiveDuplicates(char *input) {
    remove(input,0,1);
}
