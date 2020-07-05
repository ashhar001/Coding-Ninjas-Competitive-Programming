Coding Ninjas
Send Feedback
Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .
There is a path from any cell to all its neighbouring cells. A neighbour may share an edge or a corner.
Input Format :
Line 1 : Two space separated integers N  and M, where N is number of rows and M is number of columns in the matrix.
Next N lines : N rows of the matrix. First line of these N line will contain 0th row of matrix, second line will contain 1st row and so on
Assume input to be 0-indexed based
Output Format :
Return 1 if there is a path which makes the sentence “CODINGNINJA” else return 0.
Constraints :
1 <= N <= 100
1 <= M <= 100
Sample Input :
2 11
CXDXNXNXNXA
XOXIXGXIXJX
Sample Output :
1



/******************************************************** SOLUTION *****************************************************/



#include<string>
bool printDFS(char Graph[][MAXN],int i,int j,int N,int M,bool **visited,string S)
{
    //cout<<sv<<" ";
    if(S[0]=='\0') return true;
    if(i<0||i>=N||j<0||j>=M) return false;
    visited[i][j]=true;
    
    if(j>0){if(!visited[i][j-1]&&Graph[i][j-1]==S[0]){
            visited[i][j-1]=true;   
           if(printDFS(Graph,i,j-1,N,M,visited,S.substr(1))) return true;
           else visited[i][j-1]=false;
    }}
    if(j>0&&i>0){
        if(!visited[i-1][j-1]&&Graph[i-1][j-1]==S[0]){
            visited[i-1][j-1]=true;   
           if(printDFS(Graph,i-1,j-1,N,M,visited,S.substr(1))) return true;
           else visited[i-1][j-1]=false;
       }
    }    
   if(i>0){ if(!visited[i-1][j]&&Graph[i-1][j]==S[0]){
            visited[i-1][j]=true;   
           if(printDFS(Graph,i-1,j,N,M,visited,S.substr(1))) return true;
           else visited[i-1][j]=false;
    }}
   if(j<M-1&&i>0){if(!visited[i-1][j+1]&&Graph[i-1][j+1]==S[0]){
            visited[i-1][j+1]=true;   
           if(printDFS(Graph,i-1,j+1,N,M,visited,S.substr(1))) return true;
           else visited[i-1][j+1]=false;
    }}
   if(j<M-1) { if(!visited[i][j+1]&&Graph[i][j+1]==S[0]){
            visited[i][j+1]=true;   
           if(printDFS(Graph,i,j+1,N,M,visited,S.substr(1))) return true;
           else visited[i][j+1]=false;
    }}
    if(i<N-1&&j<M-1) {if(!visited[i+1][j+1]&&Graph[i+1][j+1]==S[0]){
            visited[i+1][j+1]=true;   
           if(printDFS(Graph,i+1,j+1,N,M,visited,S.substr(1))) return true;
           else visited[i+1][j+1]=false;
    }}
    if(i<N-1) {if(!visited[i+1][j]&&Graph[i+1][j]==S[0]){
            visited[i+1][j]=true;   
           if(printDFS(Graph,i+1,j,N,M,visited,S.substr(1))) return true;
           else visited[i+1][j]=false;
    }}
    if(j>0&&i<N-1){if(!visited[i+1][j-1]&&Graph[i+1][j-1]==S[0]){
            visited[i+1][j-1]=true;   
           if(printDFS(Graph,i+1,j-1,N,M,visited,S.substr(1))) return true;
           else visited[i+1][j-1]=false;
    }}
    return false;
}
int solve(char Graph[][MAXN],int N, int M)
{
	// Write your code here.
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
         if(Graph[i][j]=='C'){
            bool** visited=new bool*[N];
            for(int f=0;f<N;f++){
                visited[f]=new bool[M];
                for(int y=0;y<M;y++) visited[f][y]=false;
            }
            string s="ODINGNINJA";
            if(printDFS(Graph,i,j,N,M,visited,s)) {
                for(int k=0;k<N;k++) delete [] visited[k];
                delete [] visited;
                return 1;
            }
            for(int k=0;k<N;k++) delete [] visited[k];
                delete [] visited; 
         }  
        }
    }
    return 0;
}
