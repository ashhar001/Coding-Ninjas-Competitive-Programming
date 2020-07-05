Code : All connected components
Send Feedback
Given an undirected graph G(V,E), find and print all the connected components of the given graph G.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
You need to take input in main and create a function which should return all the connected components. And then print them in the main, not inside function.
Print different components in new line. And each component should be printed in increasing order (separated by space). Order of different components doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.
Output Format :
Different components in new line
Constraints :
2 <= V <= 1000
1 <= E <= 1000
Sample Input 1:
4 2
0 1
2 3
Sample Output 1:
0 1 
2 3 
Sample Input 2:
4 3
0 1
1 3 
0 3
Sample Output 2:
0 1 3 
2



/******************************************************** SOLUTION *****************************************************/


#include <iostream>


#include <bits/stdc++.h> 
using namespace std; 
void connected(bool** edges, int n, int sv, int *visited)
{
    int init=sv;
    
    while(init<n){
    if(visited[init]!=0){
        init++;
        continue;
    }
    visited[init] = 1;
    queue<int> q;
    q.push(init);
    init++;
        vector<int> v1;
    while(!q.empty())
    {
        int x = q.front();
        v1.push_back(x);
        
        q.pop();
        
        for(int i=0;i<n;i++)
        {
            if(edges[x][i] && !visited[i] )
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
        sort(v1.begin(), v1.end());
        for(int i=0;i<v1.size();i++){
            cout<<v1[i]<<" ";
        }
        cout<<endl;
    }
    
    return;
   
}
int main()
{
    int V, E;
    cin >> V >> E;
    
    bool** edges = new bool*[V];
    for(int i=0; i<V; i++){
        edges[i]=new bool[V];
        for(int j=0;j<V;j++){
            edges[i][j]=0;
        }
    }
    
    for(int i=0;i<E;i++){
        int f,s;
        cin>>f;
        cin>>s;
        
        edges[f][s]=1;
        edges[s][f]=1;
        
        
    }

    int *visited = new int[V];
    for(int i=0;i<V;i++)
    	visited[i] = 0;
    
    connected(edges, V, 0 , visited);

  return 0;
}
