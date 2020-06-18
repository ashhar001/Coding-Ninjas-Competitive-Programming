Longest consecutive Sequence
Send Feedback
You are given with an array of integers that contain numbers in random order. Write a program to find the longest possible sequence of consecutive numbers using the numbers from given array.
You need to return the output array which contains consecutive elements. Order of elements in the output is not important.
Best solution takes O(n) time.
If two sequences are of equal length then return the sequence starting with the number whose occurrence is earlier in the array.
Input Format :
Line 1 : Integer n, Size of array
Line 2 : Array elements (separated by space)
Constraints :
0 <= n <= 10^8
Sample Input 1 :
13
2 12 9 16 10 5 3 20 25 11 1 8 6 
Sample Output 1 :
8 
9 
10 
11 
12
Sample Input 2 :
7
3 7 2 1 9 8 1
Sample Output 2 :
7
8
9
Explanation: Sequence should be of consecutive numbers. Here we have 2 sequences with same length i.e. [1, 2, 3] and [7, 8, 9], but output should be [7, 8, 9] because the starting point of [7, 8, 9] comes first in input array.
Sample Input 3 :
7
15 24 23 12 19 11 16
Sample Output 3 :
15 
16


/*************************************** SOLUTION *********************************************/


#include<vector>
#include<algorithm>
#include<iostream>
#include<unordered_map>
#include <vector>
using namespace std;

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n){
	unordered_map<int,int> countMap;
    vector<int> results;

    for(int i=0;i<n;i++)
    {
        countMap[arr[i]]++;
    }

    int start_element=0,n_elements=0;

    for(int i=0;i<n;i++)
    {
        if(countMap.find(arr[i]-1)==countMap.end())
        {
            int next_consecutive_element=arr[i];
            while(countMap.find(next_consecutive_element)!=countMap.end())
                next_consecutive_element++;

            if(n_elements<next_consecutive_element-arr[i])
            {
                n_elements=next_consecutive_element-arr[i];
                start_element=arr[i];
            }

        }
    }

    for(int i=start_element;i<start_element+n_elements;i++)
        results.push_back(i);
    return results;
}
