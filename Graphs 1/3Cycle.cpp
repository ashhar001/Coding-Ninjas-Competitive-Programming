3 Cycle
Send Feedback
Given a graph with N vertices (numbered from 1 to N) and Two Lists (U,V) of size M where (U[i],V[i]) and (V[i],U[i]) are connected by an edge , then count the distinct 3-cycles in the graph. A 3-cycle PQR is a cycle in which (P,Q), (Q,R) and (R,P) are connected an edge.
Input Format :
Line 1 : Two integers N and M
Line 2 : List u of size of M
Line 3 : List v of size of M
Return Format :
The count the number of 3-cycles in the given Graph
Constraints :
1<=N<=100
1<=M<=(N*(N-1))/2
1<=u[i],v[i]<=N
Sample Input:
3 3
1 2 3
2 3 1
Sample Output:
1
	
	
	
/*************************************************************** SOLUTION *******************************************************************************/
	
	
#include<iostream>
using namespace std;
int helper(int i, int** matrix, int n, int* visited, int & count){
    for(int j=1;j<n+1;j++){
        if(visited[j]==0 && matrix[i][j]==1){
            for(int k=1;k<n+1;k++){
                if(visited[k]==0 && matrix[j][k]==1 && matrix[k][i]==1){
                count++;
                }
            }
        }
   
    }
     return count/2;
}
int solve(int n,int m,vector<int>u,vector<int>v)
{
	//Creating matrix
    int** matrix = new int*[n+1];
    
    for(int i=0;i<=n;i++){
        matrix[i] = new int[n+1];
        
        for(int j=0;j<=n;j++){
            matrix[i][j]=0;
        }
        
    }
    
    for(int i=0;i<m;i++){
        matrix[u.at(i)][v.at(i)]=1;
        matrix[v.at(i)][u.at(i)]=1;
       
        
        
    }
    //Make visisted matrix
    int* visited = new int[n+1];
    
    for(int i=0;i<n+1;i++){
        visited[i] = 0;
    }
    
    //Look for cycle in each element
    int sum=0;
    for(int i = 1; i<=n; i++){
        visited[i]=1;
        int count=0;
        sum=sum+helper(i,matrix, n,visited, count);
    }
    
    return sum;
}
