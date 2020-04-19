#include <iostream>


void  printMatrix(int(*matrix)[4], int rows, int columns, int start) {
	if (matrix == NULL || rows <= 0 || columns <= 0)
		return;
	//先从左到右打印
	for (int i = start; i < columns - start; ++i)
		std::cout << matrix[start][i]<<"  ";
	//从上往下打印
	for (int i = start+1; i < rows - start; ++i)
		std::cout << matrix[i][columns - start-1] << "  ";
	//从右往左打印
	for(int i= columns - start-1 ;i>start;--i)
		std::cout << matrix[rows-1-start][i-1] << "  ";
	//从下往上打印
	for(int i= rows  - start-1;i>start+1;--i)
		std::cout << matrix[i-1][start] << "  ";
	std::cout << std::endl;
}

void printMatrixClockwisely(int (*matrix)[4],int rows,int columns) {
	if (matrix == NULL || rows <= 0 || columns <= 0)
		return;
	int start = 0;
	while (columns > start * 2 && rows > start * 2) {
		printMatrix(matrix, rows, columns, start);
		++start;
	}

}

void printMatrixClockwiselyTest() {
	//int m[4][4] = { {0,1,2,3},{5,6,7,8},{9,10,11,12},{13,14,15,16} },rows=4,columns=4;
	int m[1][4] = { {0,1,2,3} }, rows = 1, columns = 4;
	printMatrixClockwisely(m, rows, columns);
}