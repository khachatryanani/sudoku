#include <iostream>
#include "sudoku.h"


int main()
{
	std::cout << "Enter 9x9 matrix for sudoku!\nUse -1 for empty cells.\n";
	Sudoku sd;
	sd.enterDigits();
	if (sd.Solve()) 
	{ 
		sd.Print(); 
	}
	else 
	{
		std::cout << "This example has no solution((";
	};
}


