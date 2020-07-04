Largest Piece
Send Feedback
Its Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's . But Gary wants the biggest piece of '1's and no '0's . A piece of cake is defined as a part which consist of only '1's, and all '1's share an edge with eachother on the cake. Given the size of cake N and the cake , can you find the size of the biggest piece of '1's for Gary ?
Constraints :
1<=N<=50
Input Format :
Line 1 : An integer N denoting the size of cake 
Next N lines : N characters denoting the cake
Output Format :
Size of the biggest piece of '1's and no '0's
Sample Input :
2
11
01
Sample Output :
3


/*************************************************************** SOLUTION *******************************************************************************/



#include <iostream>

using namespace std;
#include<iostream>
#include<vector>
#include<climits>


static int rowNbr[] = {-1, 1, 0, 0}; 
static int colNbr[] = {0, 0, 1, -1};


//To check if the index is an eligible index for our cake
bool iseligible(char cake[][55], int x, int y, int** visited, int n)
{
    // if(x == 0 && y == 4)
    //     cout << "Chirag" << endl;
    //cout << x << " " << y << endl;
    if(x<0 || x>=n || y<0 || y>=n|| visited[x][y] == 1 || cake[x][y] == '0' ){
        return 0;
    }
    else
        return 1; 
}

//Returns the maximum peice of cake that can be taken starting from x,y
int solver(int n, char cake[][55], int** visited, int x, int y){
    int sum=0;
    
    for(int k=0;k<4;k++){
        if(iseligible(cake,x+rowNbr[k], y+colNbr[k], visited, n)){

            visited[x+rowNbr[k]][y+colNbr[k]]=1;
            sum=sum+solver(n, cake, visited, x+rowNbr[k], y+colNbr[k]);
        }
    }
    return 1+sum;
}


//passes index of each one to solver as starting point and returns max of all 
int solve(int n,char cake[][55])
{
    int** visited = new int*[n];
    for(int i=0;i<n;i++){
        visited[i]=new int[n];
        for(int j=0;j<n; j++){
            visited[i][j]=0;
        }
    }
    
    int count=INT_MIN;
    int result=0;
    for(int i=0;i<n;i++){

        for(int j=0;j<n;j++){

            if(iseligible(cake, i, j, visited, n)){

                //cout << i << " " << j << endl;
                visited[i][j]=1;
                result = solver(n, cake, visited, i, j);

                count = max(result, count);
            }
        }
    }
    
    return count;
}
