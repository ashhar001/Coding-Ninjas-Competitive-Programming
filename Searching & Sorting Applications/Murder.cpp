Murder
Send Feedback
Once detective Saikat was solving a murder case. While going to the crime scene he took the stairs and saw that a number is written on every stair. He found it suspicious and decides to remember all the numbers that he has seen till now. While remembering the numbers he found that he can find some pattern in those numbers. So he decides that for each number on the stairs he will note down the sum of all the numbers previously seen on the stairs which are smaller than the present number. Calculate the sum of all the numbers written on his notes diary.
Answer may not fit in integer . You have to take long.
Input
First line gives T, number of test cases.

2T lines follow.

First line gives you the number of stairs N

Next line gives you N numbers written on the stairs.
Output
For each test case output one line giving the final sum for each test case.
Constraints
T<=10

1<=N<=10^5

All numbers will be between 0 and 10^6.
Sample Input:
1
5
1 5 3 6 4
Sample Output:
15
Explanation:
For the first number, the contribution to the sum is 0.
For the second number, the contribution to the sum is 1.
For the third number, the contribution to the sum is 1.
For the fourth number, the contribution to the sum is 9 (1+5+3).
For the fifth number, the contribution to the sum is 4 (1+3).
Hence the sum is 15 (0+1+1+9+4).


/********************************************************** SOLUTION *******************************************************/



#include <bits/stdc++.h>

using namespace std;
long long merge(vector<long long> &v, long long start, long long mid, long long end){
	
	long long sum = 0;
	long long i = start;
	long long j = mid+1;
	

	while(j<=end && i<=mid){
	
		if (v.at(j)>v.at(i))
		{
		
			sum += (end-j+1)*v.at(i);
			i++;
		}else{
			j++;
		}

	}
	return sum;

}

long long go(vector<long long> &v, long long start, long long end){

	if (start>=end)
	{
		return 0;
	}
	long long mid = (start+end)/2;

	long long left = go(v, start, mid);
	long long right = go(v, mid+1, end);

	sort(v.begin()+start, v.begin()+mid+1);
	sort(v.begin()+mid+1, v.begin()+end+1);
	
	return left+right+merge(v, start, mid, end);

}


int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ;

	long long t;
	cin>>t;

	while(t--){
		long long n;
		cin>>n;
		long long m = n;

		std::vector<long long> v;
		while(n--){
			long long a;
			cin>>a;
			v.push_back(a);
		}

		cout << go(v, 0, m-1) << '\n';
	}

	return 0 ; 
}
