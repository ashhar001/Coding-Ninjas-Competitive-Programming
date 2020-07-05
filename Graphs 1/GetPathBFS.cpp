Code : Get Path - BFS
Send Feedback
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using BFS and print the shortest path available.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
Note : Save the input graph in Adjacency Matrix.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Two integers a and b, denoting that there exists an edge between vertex a and vertex b (separated by space)
Line (E+2) : Two integers v1 and v2 (separated by space)
Output Format :
Path from v1 to v2 in reverse order (separated by space)
Constraints :
2 <= V <= 1000
1 <= E <= 1000
0 <= v1, v2 <= V-1
Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
3 0 1
Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :



/******************************************************** SOLUTION *****************************************************/



#include <queue> 
#include <iostream> 
#include <unordered_map> 
using namespace std; 

vector<int>* getPath(int** edges, int n, int sv, int ev) 
{ 	queue<int> bfsQ; 
	bool * visited = new bool[n]; 
	for (int i = 0; i < n; i++) {
	 visited[i] = false;
	}

	bfsQ.push(sv);

	visited[sv] = true; 
	bool done = false; 
	unordered_map<int, int> parent; 
	while (!bfsQ.empty() && !done) { 
	 	int front = bfsQ.front(); 
	 	bfsQ.pop(); 
	 	for (int i = 0; i < n; i++) { 
	 		if (edges[front][i] && !visited[i]) { 
	 			parent[i] = front; bfsQ.push(i); 
	 			visited[i] = true; if (i == ev) { 
	 				done = true; 
	 				break; 
	 			} 
	 		} 
	 	} 
	} 
	delete [] visited; 
	if (!done) { 
		return NULL; 
	} else { 
	 	vector<int>* output = new vector<int>(); 
	 	int current = ev; 
	 	output->push_back(ev); 
	 	while (current != sv) { 
	 		current = parent[current]; 
	 		output->push_back(current); 
	 	} return output; 
	} 
	} 



	int main() { 
		int n; 
		int e; 
		cin >> n >> e; 
		int** edges = 
		new int*[n]; 
		for (int i = 0; i < n; i++) {
		 edges[i] = new int[n]; 
		 for (int j = 0; j < n; j++) { 
		 	edges[i][j] = 0; 
		 } 
		} for (int i = 0; i < e; i++) { 
			int f, s; 
			cin >> f >> s; 
			edges[f][s] = 1; edges[s][f] = 1; } 
			int sv, ev; 
			cin >> sv >> ev; 
			vector<int>* output = getPath(edges, n, sv, ev); 
			if (output != NULL) { 
				for (int i = 0; i < output->size(); i++) { 
					cout << output->at(i) << " "; 
				} delete output; 
			} for (int i = 0; i < n; i++) { 
				delete [] edges[i]; 
			} delete [] edges; 
		}
