// Chess.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ChessBoard.h"

int main()
{
	cout << "Welocme to Chess!\n";

	ChessBoard chessBoard;

	cout << "Current state of Chess Board:\n";
	int count = 0;
	for (int row = 0; row < chessBoard.getRowSize(); row++)
	{
		cout << "\n\n";
		for (int column = 0; column < chessBoard.getColumnSize(); column++)
		{
			cout << chessBoard.getPieceAt(row, column) << "\t";
		}
	}
	cout << count;

    return 0;
}

