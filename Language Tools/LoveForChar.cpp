Love for Characters
Send Feedback
Ayush loves the characters ‘a’, ‘s’, and ‘p’. He got a string of lowercase letters and he wants to find out how many times characters ‘a’, ‘s’, and ‘p’ occurs in the string respectively. Help him find it out.
Input:
First line contains an integer denoting length of the string.
Next line contains the string.
Constraints:
1<=n<=10^5
‘a’<= each character of string <= ‘z’
Output:
Three space separated integers denoting the occurrence of letters ‘a’, ‘s’ and ‘p’ respectively.
Sample Input:
6
aabsas
Sample output:
3 2 0
	
	
/************************************************** SOLUTION ***********************************************/
	
	
#include <bits/stdc++.h>

using namespace std;


int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	int n;
	cin>>n;
	string s;
	std::cin>>s;

	unordered_map<char, int> m1;

	for (int i = 0; i < s.size(); ++i)
	{
		m1[s[i]]++;
	}

	cout << m1['a']<<" "<<m1['s']<<" "<<m1['p'] << '\n';

	return 0 ; 

}
