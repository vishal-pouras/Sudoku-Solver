#include <iostream>
using namespace std;
#define GRID_FULL make_pair(9,9)


bool isValid(int sudoku[9][9],int row, int col, int digit)
{
    for(int j=0;j<9;j++)
        if(sudoku[row][j]==digit && j!=col) return false;
    for(int i=0;i<9;i++)
        if(sudoku[i][col]==digit && i!=row) return false;
    int boxStartRow = row-row%3;
    int boxStartCol = col-col%3;
    for (int r = 0; r < 3; r++)  
    {
        for (int c = 0; c < 3; c++)  
            if (sudoku[r + boxStartRow][c + boxStartCol] == digit && r!=row && c!=col)  
                return false;  
    }

    return true;
}
void printGrid(int grid[9][9])  
{  
    for (int row = 0; row < 9; row++)  
    {  
    for (int col = 0; col < 9; col++)  
            cout << grid[row][col] << " ";  
        cout << endl; 
    }  
} 

pair<int, int> get_unassigned_location(int sudoku[9][9])
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(sudoku[i][j]==0)
                return make_pair(i,j);
        }
    }
    return GRID_FULL;
}

bool sudokuUtil(int sudoku[9][9])
{
    if(GRID_FULL == get_unassigned_location(sudoku))
    {
        return true;
    }
    pair<int, int> row_and_col = get_unassigned_location(sudoku);
    int row = row_and_col.first;
    int col = row_and_col.second;
    for(int digit = 1;digit<=9;digit++)
    {
        if(isValid(sudoku,row,col,digit))
        {
            sudoku[row][col] = digit;
            if(sudokuUtil(sudoku))
                return true;
            sudoku[row][col] = 0;
        }
    }
    return false;
}

int main() {
	//code
	int t;
	cin>>t;
	for(int tt=0;tt<t;tt++)
	{
	    int sudoku[9][9];
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
                cin>>sudoku[i][j];
        if(sudokuUtil(sudoku))
        {
            //cout<<"solution is\n";
            printGrid(sudoku);
        }
            
	}
}