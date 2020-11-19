#pragma once
class Sudoku
{
private:
	const int size = 9;
	static int sudoku[size][size];

	bool isOkForRow(int row, int n);
	
	bool isOkForCol(int col, int n);
	
	bool isOkForBox(int startRow, int startCol, int n);
	
		
	bool isOk(int row, int col, int n);
	
public:
	Sudoku();
	void enterDigits();

	bool Solve();
	
	void Print();
	
};

