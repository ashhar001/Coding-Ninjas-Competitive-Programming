Sudoku Solver
Send Feedback
Given a 9*9 sudoku board, in which some entries are filled and others are 0 (0 indicates that the cell is empty), you need to find out whether the Sudoku puzzle can be solved or not i.e. return true or false.
Input Format :
9 Lines where ith line contains ith row elements separated by space
Output Format :
 true or false
Sample Input :
9 0 0 0 2 0 7 5 0 
6 0 0 0 5 0 0 4 0 
0 2 0 4 0 0 0 1 0 
2 0 8 0 0 0 0 0 0 
0 7 0 5 0 9 0 6 0 
0 0 0 0 0 0 4 0 1 
0 1 0 0 0 5 0 8 0 
0 9 0 0 7 0 0 0 4 
0 8 2 0 4 0 0 0 6
Sample Output :
true


/********************************************* SOLUTION ****************************************************/


bool checkPossible(int board[][9],int row,int col,int val)
{
    for(int i=0;i<9;i++)
    {
        if(board[row][i]==val)
            return false;

        if(board[i][col]==val)
            return false;
    }

    int row_start=(row/3)*3;
    int col_start=(col/3)*3;

    int row_end=row_start+3;
    int col_end=col_start+3;

    for(int i=row_start;i<row_end;i++)
    {
        for(int j=col_start;j<col_end;j++)
        {
            if(board[i][j]==val)
                return false;
        }
    }
    
    return true;
}

bool gridFull(int board[][9],int &row,int &col)
{
    for(row=0;row<9;row++)
        for(col=0;col<9;col++)
            if(board[row][col] == 0)
                return false;
    return true;
}

void printBoard(int board[][9])
{
    cout<<"\nSolved!!"<<endl;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool sudokuSolver(int board[][9]){
    int row,col;

    if(gridFull(board,row,col))
    {
        // printBoard(board);
        return true;
    }    
    
    for(int i=1;i<=9;i++)
    {
        if(checkPossible(board,row,col,i))
        {
            board[row][col]=i;

            if(sudokuSolver(board))
                return true;
            
            board[row][col]=0;
        }
    }

    return false;
}
