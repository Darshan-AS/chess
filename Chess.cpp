// Chess.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Board.h"
#include <algorithm>

Board chessBoard;

string getPieceName(Piece * piece) {
	string name;
	if (piece == nullptr)
	{
		name = "-";
		return name;
	} 
	else if (dynamic_cast<Pawn*>(piece))
		name = "pawn";
	else if (dynamic_cast<Knight*>(piece))
		name = "knight";
	else if (dynamic_cast<Bishop*>(piece))
		name = "bishop";
	else if (dynamic_cast<Rook*>(piece))
		name = "rook";
	else if (dynamic_cast<Queen*>(piece))
		name = "queen";
	else if (dynamic_cast<King*>(piece))
		name = "king";

	if (piece->getColor() == Piece::COLOR_WHITE)
		transform(name.begin(), name.end(), name.begin(), ::toupper);
		
	return name;
}

void printBoard() {
	string name;
	for (int i = 0; i < Board::MAX_ROWS; i++)
	{
		for (int j = 0; j < Board::MAX_COLUMNS; j++)
		{
			Piece * piece = chessBoard.getPieceAt(Position(i, j));
			name = getPieceName(piece);
			cout << name << "\t";
		}
		cout << "\n\n";
	}
}

int main()
{
	cout << "Welocme to Chess!\n\n";

	printBoard();
	cout << "\n\n";
	Piece * p = chessBoard.getPieceAt(Position(1, 0));
	vector<Position> v = p->getValidMoves(Position(1, 0));
	chessBoard.movePieceTo(Position(1, 0), v[0]);
	printBoard();

	return 0;
}

