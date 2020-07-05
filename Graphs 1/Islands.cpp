Islands
Send Feedback
An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island to any other island in the same group . Given N islands (numbered from 1 to N) and two lists of size M (u and v) denoting island u[i] is connected to island v[i] and vice versa . Can you count the number of connected groups of islands.
Constraints :
1<=N<=100
1<=M<=(N*(N-1))/2
1<=u[i],v[i]<=N
Input Format :
Line 1 : Two integers N and M
Line 2 : List u of size of M
Line 3 : List v of size of M
Output Return Format :
The count the number of connected groups of islands
Sample Input :
2 1
1
2
Sample Output :
1 



/******************************************************** SOLUTION *****************************************************/



#include <bits/stdc++.h>

using namespace std;

void DFS(int** arr, int* visited, int n, int sv){

	visited[sv] = 1;

	for (int i = 0; i < n; ++i)
	{
		if (i==sv)
		{
			continue;
		}
		if (arr[sv][i] == 1 && visited[i] == 0)
		{
			DFS(arr, visited, n, i);
		}
	}

	return;
}
int solve(int n,int m,vector<int>u,vector<int>v)
{
	int** arr = new int*[n];
	for (int i = 0; i < n; ++i)
	{
		arr[i] = new int[n];
		for (int j = 0; j < n; ++j)
		{
			arr[i][j] = 0;
		}
	}



	for (int i = 0; i < m; ++i)
	{
		arr[u[i]-1][v[i]-1] = 1;
		arr[v[i]-1][u[i]-1] = 1;
	}


	int* visited = new int[n];

	for (int i = 0; i < n; ++i)
	{
		visited[i] = 0;
	}

	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		if (visited[i]==0)
		{
			count++;
			DFS(arr, visited, n, i);
		}
	}

	return count;

}
