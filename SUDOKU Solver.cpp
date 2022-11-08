#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


bool BlockChecking(int TileRow, int TileColumn, int Number, vector <vector <int>> SUDOKUMATRIX){
//check whether num is present in 3x3 box or not
   for (int row = 0; row < 3; row++)
      for (int col = 0; col < 3; col++)
         if (SUDOKUMATRIX[TileRow+row][TileColumn+col] == Number)
            return false;
   return true;
}
bool RowChecking(int row, int Number, vector <vector <int>> SUDOKUMATRIX){ //check whether num is present in row or not
   for (int col = 0; col < 9; col++)
      if (SUDOKUMATRIX[row][col] == Number)
         return false;
   return true;
}
bool ColumnChecking(int col, int Number, vector <vector <int>> SUDOKUMATRIX){ //check whether num is present in col or not
   for (int row = 0; row < 9; row++)
      if (SUDOKUMATRIX[row][col] == Number)
         return false;
   return true;
}
bool ValidityCheck(int row, int col, int Number, vector <vector <int>> SUDOKUMATRIX){
   //when item not found in col, row and current 3x3 box
   return RowChecking(row, Number, SUDOKUMATRIX) && ColumnChecking(col, Number, SUDOKUMATRIX) && BlockChecking(row - row%3 ,
col - col%3, Number, SUDOKUMATRIX);
}



void PrintThePuzzle(vector <vector <int>> SUDOKUMATRIX){ //print the sudoku grid after solve
   for (int row = 0; row < 9; row++){
      for (int col = 0; col < 9; col++){
         if(col == 3 || col == 6)
            cout << " "<<char(219)<<char(219)<<" ";
         cout << SUDOKUMATRIX[row][col] <<" ";
      }
      if(row == 2 || row == 5){
         cout << endl;
         for(int i = 0; i<9; i++)
            cout << char(219)<<char(219)<<char(219);
      }
      cout << endl;
   }
}
bool EmptyCellFinder(int &row, int &col, vector <vector <int>> &SUDOKUMATRIX){ 
   for (row = 0; row < 9; row++)
      for (col = 0; col < 9; col++)
         if (SUDOKUMATRIX[row][col] == 0) 
            return true;
   return false;
}
bool SolvingThePuzzle(vector <vector <int>> &SUDOKUMATRIX){
   int row, col;
   if (!EmptyCellFinder(row, col, SUDOKUMATRIX))
      return true; 
   for (int Number = 1; Number <= 9; Number++){ 
      if (ValidityCheck(row, col, Number, SUDOKUMATRIX)){ 
         SUDOKUMATRIX[row][col] = Number;
         if (SolvingThePuzzle(SUDOKUMATRIX))
            return true;
         SUDOKUMATRIX[row][col] = 0; 
      }
   }
   return false;
}
int main(){
	
vector <vector <int>> SUDOKUMATRIX;

ifstream file;
file.open("Puzzle.txt");

for(int i=0;i<9;i++)
{
	vector <int> temp;
	for(int j=0;j<9;j++)
	{
		int input;
		file>>input;
		temp.push_back(input);
	}
	SUDOKUMATRIX.push_back(temp);
}
	
	
	
   if (SolvingThePuzzle(SUDOKUMATRIX) == true)
      PrintThePuzzle(SUDOKUMATRIX);
   else
      cout << "No solution exists";
}
