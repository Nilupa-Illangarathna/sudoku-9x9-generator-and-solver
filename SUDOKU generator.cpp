#include <iostream>
#include <ctime>
#include <fstream>
#define size 9

using namespace std;
int puzzle[size][size];

class Sudoku
{
    public:

    bool CheckTheValue(int row, int col, int r, int c, int Value)
    {
    	bool return_val=false;
    	for (int col = 0; col < size; col++)
        if (puzzle[row][col] == Value)
        {
        	return_val=true;
		}
        
        for (int row = 0; row < size; row++)
        if (puzzle[row][col] == Value)
        {
        	return_val=true;
		}

        int TileRow = r - r % 3;
        int TileColumn = c - c % 3;
        for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (puzzle[row+TileRow][col+TileColumn] == Value)
    	    {
	        	return_val=true;
			}
		return return_val;
	}

    bool SubArrayExistance(int r, int c, int Value)
    {
        int TileRow = r - r % 3;
        int TileColumn = c - c % 3;
        for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
                if (puzzle[row+TileRow][col+TileColumn] == Value)
                    return true;
        return false;
    }

	//check the possibility to enter the value into the cell
    bool SafeToEnter(int row, int col, int num)
    {
        return !CheckTheValue(row,col,row,col,num );
    }

	//Fill the diagonal first
    void fill_Diagonal(int cr, int cc)
    {
        for (int row = 0; row < 3; row++)
            for (int col = 0; col < 3; col++)
            {
                int num;
                do
                {
                    num = 1 + rand() % 9;   //number between 1 and 9
                } while (SubArrayExistance(row+cr, col+cc, num));
                puzzle[row+cr][col+cc]=num;
            }
    }

	//Fill the rest of the grid
    bool fill_Remaining(int row, int col)
    {

        if (col>=size && row<size-1)
        {
            row++;
            col = 0;
        }
        if (row>=size && col>=size)
            return true;
    
        if (row < 3)
        {
            if (col < 3)
                col = 3;
        }
        else if (row < size-3)
        {
            if (col==(int)(row/3)*3)
                col +=  3;
        }
        else
        {
            if (col == size-3)
            {
                row++;
                col = 0;
                if (row>=size)
                    return true;
            }
        }
    
        for (int num = 1; num<=size; num++)
        {
            if (SafeToEnter(row, col, num))
            {
                puzzle[row][col] = num;
                if (fill_Remaining(row, col+1))
                    return true;
    
                puzzle[row][col] = 0;
            }
        }
        return false;
    }

    void generator()
    {
        fill_Diagonal(0, 0); 
        fill_Diagonal(3, 3); 
        fill_Diagonal(6, 6);
        fill_Remaining(0, 3);
    }


    void removeSomeNumbers(int Cellcount)
    {
        
        for (int row = 0; row < size; row++)
        {
            int count = 0;
            while (count < Cellcount)
            {
                int cell= rand() % 9;
                if(puzzle[row][cell]!=0)
                {
                    puzzle[row][cell] = 0;
                    count++;
                }
            }  
        }
                            
    }

    void printPuzzle()
    {		
    
    cout<<endl<<endl<<endl;
        for (int row = 0; row < size; row++){
        	cout<<"\t";
            for (int col = 0; col < size; col++){
                if(col == 3 || col == 6)
                    cout << char(219)<<char(219);
                cout << puzzle[row][col]<<" ";

            }
            if(row == 2 || row == 5){
                cout << endl;
                cout<<"\t";
                for(int i = 0; i<size; i++)
                    cout <<char(219)<<char(219)<<char(219);
            }
            cout << endl;
        }
        cout << "\n\n";
    }
    
    //Send the data into the TEXT file
    void ToTheTextFile()
    {
    	ofstream file;
		file.open("Puzzle.txt");
	
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
				file<<puzzle[i][j]<<" ";
			}
			file<<endl;
		}
	}
};


int main()
{
srand(time(NULL));
    for (int row = 0; row < size; row++)
        for (int col; col < size; col++)
            puzzle[row][col] = 0;   //intialize the puzzel with 0

    int missing;    //missing cells
    do
    {
        cout << "Enter how many elements(2,3 or 4) should be removed from each row : ";
        cin >> missing;
    } while (missing<2 || missing>4);

    Sudoku s;  
    s.generator();  
    s.removeSomeNumbers(missing);
    s.printPuzzle(); 
    s.ToTheTextFile();

    return 0;
}
