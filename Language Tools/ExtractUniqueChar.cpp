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


#include<unordered_set>

string uniqueChar (string str) {
    string answer;
    unordered_set<char> charSet;
    
    for (char ch: str) {
        if (charSet.find(ch)==charSet.end()) {
            answer.push_back(ch);
            charSet.insert(ch);
        }
    }
    
    return answer;
}
