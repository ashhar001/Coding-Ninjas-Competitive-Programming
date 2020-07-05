Code : BFS Traversal
Send Feedback
Given an undirected and disconnected graph G(V, E), print its BFS traversal.
Here you need to consider that you need to print BFS path starting from vertex 0 only.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Note : 1. Take graph input in the adjacency matrix.
2. Handle for Disconnected Graphs as well
Input Format :
Line 1: Two Integers V and E (separated by space)
Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.
Output Format :
BFS Traversal (separated by space)
Constraints :
2 <= V <= 1000
1 <= E <= 1000
Sample Input 1:
4 4
0 1
0 3
1 2
2 3
Sample Output 1:
0 1 3 2



/******************************************************** SOLUTION *****************************************************/



#include <bits/stdc++.h>
using namespace std;

void BFS(int **graph,int n,int sv,int *visited)
{
    queue<int> que;
    que.push(sv);
    visited[sv] = 1;

    while(!que.empty())
    {
        int v = que.front();
        que.pop();
        cout<<v<<" ";

        for(int i = 0; i < n; i++)
        {
            if(i == sv)
            {
                continue;
            }
            
            if(graph[v][i] == 1 && !visited[i]) 
            {
                visited[i] = 1;
                que.push(i);
            }

        }
    }
}

void bfs_disconnected(int **graph,int n)
{
    int *visited = new int[n];
    memset(visited,0,sizeof(visited));

    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            BFS(graph,n,i,visited);
        }
    }

    delete [] visited;
}


int main() {
    int n,e;
    cin >> n >> e;

    int **graph = new int*[n];
    for(int i = 0;i < n; i++)
    {
        graph[i] = new int[n];
        for(int j = 0; j < n; j++)
            graph[i][j] = 0;
    }

    for(int i = 0; i < e; i++)
    {
        int f,s;
        cin >> f >> s;
        graph[f][s] = 1;
        graph[s][f] = 1;
    }

    bfs_disconnected(graph,n);

    return 0;
}
