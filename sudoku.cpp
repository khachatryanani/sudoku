
#include "sudoku.h"
#include <iostream>


bool Sudoku::isOkForRow(int row, int n)
	{
		for (int i = 0; i < 9; i++)
		{
			if (sudoku[row][i] == n)
			{
				return false;
			}
		}
		return true;
	}
	bool Sudoku::isOkForCol(int col, int n)
	{
		for (int i = 0; i < 9; i++)
		{
			if (sudoku[i][col] == n)
			{
				return false;
			}
		}
		return true;
	}
	bool Sudoku::isOkForBox(int startRow, int startCol, int n)
	{
		for (int i = startRow; i < (startRow + 3);i++)
		{
			for (int j = startCol; j < (startCol + 3); j++)
			{
				if (sudoku[i][j] == n)
				{
					return false;
				}
			}
		}
		return true;
	}
	bool Sudoku::isOk(int row, int col, int n)
	{
		return isOkForRow(row, n) && isOkForCol(col, n) && isOkForBox(row - (row % 3), col - (col % 3), n);
	}

	Sudoku::Sudoku() {};
	void Sudoku::enterDigits()
	{
		
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++) 
			{
				std::cin >> sudoku[i][j];
			}
		}
	};

	bool Sudoku::Solve()
	{
		bool foundEmtpy = false;
		int row, col;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (sudoku[i][j] == -1)
				{
					foundEmtpy = true;
					row = i;
					col = j;
					break;
				}
			}
			if (foundEmtpy)
			{
				break;
			}
		}
		if (!foundEmtpy)
		{
			return true;
		}
		for (int n = 1; n <= 9; n++)
		{
			if (isOk(row, col, n))
			{
				sudoku[row][col] = n;
				if (Solve())
				{
					return true;
				}
				sudoku[row][col] = -1;
			}

		}
		return false;
	}
	void Sudoku::Print()
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				std::cout << sudoku[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}


