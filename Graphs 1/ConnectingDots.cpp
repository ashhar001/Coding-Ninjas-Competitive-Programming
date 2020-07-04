Connecting Dots
Send Feedback
Gary has a board of size NxM. Each cell in the board is a coloured dot. There exist only 26 colours denoted by uppercase Latin characters (i.e. A,B,...,Z). Now Gary is getting bore and wants to play a game. The key of this game is to find a cycle that contain dots of same colour. Formally, we call a sequence of dots d1, d2, ..., dk a cycle if and only if it meets the following condition:
1. These k dots are different: if i ≠ j then di is different from dj.
2. k is at least 4.
3. All dots belong to the same colour.
4. For all 1 ≤ i ≤ k - 1: di and di + 1 are adjacent. Also, dk and d1 should also be adjacent. Cells x and y are called adjacent if they share an edge.
Since Gary is colour blind, he wants your help. Your task is to determine if there exists a cycle on the board.
Assume input to be 0-indexed based.
Input Format :
Line 1 : Two integers N and M, the number of rows and columns of the board
Next N lines : a string consisting of M characters, expressing colors of dots in each line. Each character is an uppercase Latin letter.
Output Format :
Return 1 if there is a cycle else return 0
Constraints :
2 ≤ N, M ≤ 50
Sample Input :
3 4
AAAA
ABCA
AAAA
Sample Output :
1



/*************************************************************** SOLUTION *******************************************************************************/


#include<bits/stdc++.h>
using namespace std;
#define MAXN 51
int moveX[4] = {-1, 0, 1, 0};
int moveY[4] = {0, -1, 0, 1};
bool isCyclePresent(char board[][MAXN], int n, int m, int sourceX, int sourceY, int x, int y, int count, bool **isVisited){
    for(int i = 0; i < 4; i++){
        int nextX = x+moveX[i];
        int nextY = y+moveY[i];

        if(nextX == sourceX && nextY == sourceY && count >= 4) return true;
    }

    for(int i = 0; i < 4; i++){
        int nextX = x+moveX[i];
        int nextY = y+moveY[i];

        if(nextX >= 0 && nextX < n && nextY >= 0 && nextY < m){
            if(board[nextX][nextY] == board[x][y] && !isVisited[nextX][nextY]){
                isVisited[nextX][nextY] = true;
                if(isCyclePresent(board, n, m, sourceX, sourceY, nextX, nextY, count+1, isVisited)){
                    return true;
                }
                isVisited[nextX][nextY] = false;
            }
        }
    }

    return false;
}
int solve(char board[][MAXN],int n, int m)
{
	bool **isVisited = new bool *[n];
    for(int i = 0; i < n; i++){
        isVisited[i] = new bool[m];
        for(int j = 0; j < m; j++) isVisited[i][j] = false;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!isVisited[i][j]){
                isVisited[i][j] = true;
                if(isCyclePresent(board, n, m, i, j, i, j, 1, isVisited)) return 1;
                isVisited[i][j] = false;
            }
        }
    }

    return 0;
}
